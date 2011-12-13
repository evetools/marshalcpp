//==========================================================================
// Name        : dbrow.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */
#include "dbrow.h"

namespace evetools {

namespace marshal {

namespace generator {

dbrow::dbrow() : m_name("default"), m_row(NULL) {
}

dbrow::dbrow(const std::string& name, const python::pydbrow* row) :
	m_name(name), m_row(row) {

	init();
}

dbrow::dbrow(const dbrow&) : m_name("default"), m_row(NULL) {
}

dbrow::~dbrow() {
}

void dbrow::init() {
	createInclude();
	createSource();

	std::stringstream outpath;
	outpath << "../src/model/";

	std::stringstream incoutpath;
	incoutpath << outpath.str();
	incoutpath << m_name;
	incoutpath << ".h";

	std::stringstream srcoutpath;
	srcoutpath << outpath.str();
	srcoutpath << m_name;
	srcoutpath << ".cpp";

	std::ofstream incout(incoutpath.str().c_str());
	std::ofstream srcout(srcoutpath.str().c_str());

	incout.write(m_include.str().c_str(), m_include.str().length());
	srcout.write(m_source.str().c_str(), m_source.str().length());

	incout.close();
	srcout.close();
}

void dbrow::createInclude() {

	m_include << "//==========================================================================" << std::endl;
	m_include << "// Name        : " << m_name << ".h" << std::endl;
	m_include << "// Version     : 0.0.1" << std::endl;
	m_include << "//==========================================================================" << std::endl;
	m_include << std::endl;
	m_include << "/**" << std::endl;
	m_include << "* Copyright (C)2011 by Gregor Anders All rights reserved." << std::endl;
	m_include << "*" << std::endl;
	m_include << "* This code is free software; you can redistribute it and/or modify it under" << std::endl;
	m_include << "* the terms of the BSD license (see the file LICENSE.txt included with the" << std::endl;
	m_include << "* distribution)." << std::endl;
	m_include << "*/" << std::endl;
	m_include << std::endl;

	std::string upper(m_name);

	std::transform(upper.begin(), upper.end(), upper.begin(), toupper);

	m_include << "#ifndef EVETOOLS_MODEL_" << upper << "_H_"<< std::endl;
	m_include << "#define EVETOOLS_MODEL_" << upper << "_H_"<< std::endl;
	m_include << std::endl;

	m_include << "#include \"../python/py.h\""<< std::endl;
	m_include << std::endl;
	m_include << std::endl;

	m_include << "namespace evetools {"<< std::endl;
	m_include << std::endl;
	m_include << "namespace model {"<< std::endl;
	m_include << std::endl;
	m_include << std::endl;

	m_include << "class " << m_name << " {"<< std::endl;

	m_include << std::endl;
	m_include << "public:" << std::endl;
	m_include << "\t" << m_name << "();"<< std::endl;
	m_include << "\t" << m_name << "( ";

	const python::pytuple* columns = m_row->header()->asDBRowDescriptor()->getColumns();

	python::pytuple::const_iterator columnsCurrent = columns->begin();
	python::pytuple::const_iterator columnsEnd = columns->end();

	std::string type;
	std::stringstream properties;
	std::stringstream methods;

	for (; columnsCurrent != columnsEnd; ++columnsCurrent) {

		const python::pytuple* column = (*columnsCurrent)->asTuple();

		switch (column->at(1)->asInt()->value()) {
			case python::DBTYPE_INT8:
				type = "int8_t";
				break;
			case python::DBTYPE_UINT8:
				type = "uint8_t";
				break;
			case python::DBTYPE_INT16:
				type = "int16_t";
				break;
			case python::DBTYPE_UINT16:
				type = "uint16_t";
				break;
			case python::DBTYPE_INT32:
				type = "int32_t";
				break;
			case python::DBTYPE_UINT32:
				type = "uint32_t";
				break;
			case python::DBTYPE_INT64:
				type = "int64_t";
				break;
			case python::DBTYPE_UINT64:
				type = "uint64_t";
				break;
			case python::DBTYPE_FLOAT:
				type = "float";
				break;
			case python::DBTYPE_DOUBLE:
				type = "double";
				break;
			case python::DBTYPE_BOOL:
				type = "bool";
				break;
			case python::DBTYPE_CURRENCY:
				type = "int64_t";
				break;
			case python::DBTYPE_WINFILETIME:
				type = "int64_t";
				break;
			case python::DBTYPE_STRING:
			case python::DBTYPE_WSTRING:
				type = "std::string";
				break;
			case python::DBTYPE_EMPTY:
				break;
			default:
				throw std::runtime_error("Not implemented DB Type in Generator");
		}
		properties << "\t" << type << " m_" << column->at(0)->asBuffer()->str() << ";" << std::endl;

		std::string methodName(column->at(0)->asBuffer()->str());
		std::transform(methodName.begin(), methodName.begin() + 1, methodName.begin(), toupper);

		methods << "\tvoid set" << methodName << "(const " << type << "& " << column->at(0)->asBuffer()->str() << ");" << std::endl;
		methods << "\t" << type << " get" << methodName << "() const;" << std::endl;

		if (column->at(1)->asInt()->value() == python::DBTYPE_WINFILETIME) {
			methods << "\t" << type << " get" << methodName << "UNIX() const;" << std::endl;
		}

		if (column->at(1)->asInt()->value() == python::DBTYPE_CURRENCY) {
			methods << "\tdouble get" << methodName << "InISK() const;" << std::endl;
		}

		m_include << "const " << type << "& " << column->at(0)->asBuffer()->str();

		if (columnsCurrent + 1 != columnsEnd) {
			m_include << ", ";
		}
	}
	m_include << " );"<< std::endl;

	m_include << "\t~" << m_name << "();"<< std::endl;
	m_include << std::endl;

	m_include << "\tstatic " << m_name << "* create(python::pydbrow&);"<< std::endl;
	m_include << std::endl;

	m_include << methods.str();
	m_include << std::endl;

	m_include << "private:" << std::endl;
	m_include << std::endl;

	m_include << properties.str();
	m_include << std::endl;

	m_include << "}; /* class " << m_name << " */"<< std::endl;
	m_include << std::endl;
	m_include << std::endl;

	m_include << "} /* namespace model */"<< std::endl;
	m_include << std::endl;
	m_include << "} /* namespace evetools */"<< std::endl;
	m_include << std::endl;

	m_include << "#endif /* EVETOOLS_MODEL_" << upper << "_H_ */" << std::endl;
	m_include << std::endl;
}

void dbrow::createSource() {

	m_source << "//==========================================================================" << std::endl;
	m_source << "// Name        : " << m_name << ".cpp" << std::endl;
	m_source << "// Version     : 0.0.1" << std::endl;
	m_source << "//==========================================================================" << std::endl;
	m_source << std::endl;
	m_source << "/**" << std::endl;
	m_source << "* Copyright (C)2011 by Gregor Anders All rights reserved." << std::endl;
	m_source << "*" << std::endl;
	m_source << "* This code is free software; you can redistribute it and/or modify it under" << std::endl;
	m_source << "* the terms of the BSD license (see the file LICENSE.txt included with the" << std::endl;
	m_source << "* distribution)." << std::endl;
	m_source << "*/" << std::endl;
	m_source << std::endl;

	std::string upper(m_name);

	std::transform(upper.begin(), upper.end(), upper.begin(), toupper);

	m_source << "#include \"" << m_name << ".h\"" << std::endl;
	m_source << std::endl;
	m_source << std::endl;

	m_source << "namespace evetools {"<< std::endl;
	m_source << std::endl;
	m_source << "namespace model {"<< std::endl;
	m_source << std::endl;
	m_source << std::endl;

	m_source << m_name << "::" << m_name << "( ";

	std::stringstream sets;
	std::stringstream setsd;
	std::stringstream create;

	create << m_name << "* " << m_name << "::create(python::pydbrow& row) {" << std::endl;
	create << std::endl;
	create << "\t" << m_name << "* object = new " << m_name << "();" << std::endl;
	create << "\tconst python::pybase* pyBase = NULL;" << std::endl;
	create << std::endl;

	const python::pytuple* columns = m_row->header()->asDBRowDescriptor()->getColumns();

	python::pytuple::const_iterator columnsCurrent = columns->begin();
	python::pytuple::const_iterator columnsEnd = columns->end();

	std::string type;
	std::string dtype;
	std::string ptype;
	std::string pmethod;
	std::stringstream properties;
	std::stringstream methods;

	for (; columnsCurrent != columnsEnd; ++columnsCurrent) {

		const python::pytuple* column = (*columnsCurrent)->asTuple();

		switch (column->at(1)->asInt()->value()) {
			case python::DBTYPE_INT8:
				type = "int8_t";
				ptype = "INT";
				dtype = "0";
				pmethod = "asInt";
				break;
			case python::DBTYPE_UINT8:
				type = "uint8_t";
				ptype = "UINT";
				dtype = "0";
				pmethod = "asUInt";
				break;
			case python::DBTYPE_INT16:
				type = "int16_t";
				ptype = "INT";
				dtype = "0";
				pmethod = "asInt";
				break;
			case python::DBTYPE_UINT16:
				type = "uint16_t";
				ptype = "UINT";
				dtype = "0";
				pmethod = "asUInt";
				break;
			case python::DBTYPE_INT32:
				type = "int32_t";
				dtype = "0";
				pmethod = "asInt";
				break;
			case python::DBTYPE_UINT32:
				type = "uint32_t";
				dtype = "0";
				ptype = "UINT";
				pmethod = "asUInt";
				break;
			case python::DBTYPE_INT64:
				type = "int64_t";
				dtype = "0";
				ptype = "LONG";
				pmethod = "asLong";
				break;
			case python::DBTYPE_UINT64:
				type = "uint64_t";
				dtype = "0";
				ptype = "ULONG";
				pmethod = "asULong";
				break;
			case python::DBTYPE_FLOAT:
				type = "float";
				dtype = "0.0f";
				ptype = "FLOAT";
				pmethod = "asFloat";
				break;
			case python::DBTYPE_DOUBLE:
				type = "double";
				dtype = "0.0f";
				ptype = "DOUBLE";
				pmethod = "asDouble";
				break;
			case python::DBTYPE_BOOL:
				type = "bool";
				dtype = "false";
				ptype = "BOOL";
				pmethod = "asBool";
				break;
			case python::DBTYPE_CURRENCY:
				type = "int64_t";
				dtype = "0";
				ptype = "LONG";
				pmethod = "asLong";
				break;
			case python::DBTYPE_WINFILETIME:
				type = "int64_t";
				ptype = "LONG";
				dtype = "0";
				pmethod = "asLong";
				break;
			case python::DBTYPE_STRING:
			case python::DBTYPE_WSTRING:
				type = "std::string";
				dtype = "std::string(\"\")";
				ptype = "BUFFER";
				pmethod = "asBuffer";
				break;
			case python::DBTYPE_EMPTY:
				break;
			default:
				throw std::runtime_error("Not implemented DB Type in Generator");
		}
		m_source << "const " << type << "& " << column->at(0)->asBuffer()->str();
		sets << "m_" << column->at(0)->asBuffer()->str() << "(" << column->at(0)->asBuffer()->str() << ")";
		setsd << "m_" << column->at(0)->asBuffer()->str() << "("<< dtype << ")";

		if (columnsCurrent + 1 != columnsEnd) {
			m_source << ", ";
			sets << ", ";
			setsd << ", ";
		}

		std::string methodName(column->at(0)->asBuffer()->str());
		std::transform(methodName.begin(), methodName.begin() + 1, methodName.begin(), toupper);

		create << "\tpyBase = row.dict()->at(\"" << column->at(0)->asBuffer()->str() << "\");" << std::endl;
		create << "\tif (!pyBase) {" << std::endl;
		create << "\t\tthrow std::runtime_error(\"Parsing DB Row.\");" << std::endl;
		create << "\t}" << std::endl;
		create << "\tif (!pyBase->isNone()) {" << std::endl;
		create << "\t\tif (!pyBase->" << pmethod << "()) {" << std::endl;
		create << "\t\t\tthrow std::runtime_error(\"Parsing DB Row.\");" << std::endl;
		create << "\t\t}" << std::endl;
		if (type.compare("std::string") == 0) {
			create << "\t\tif (!pyBase->" << pmethod << "()->size() > 0) {" << std::endl;
			create << "\t\t\tobject->set" << methodName << "(pyBase->" << pmethod << "()->str());" << std::endl;
			create << "\t\t}" << std::endl;
		} else {
			create << "\t\tobject->set" << methodName << "(pyBase->" << pmethod << "()->value());" << std::endl;
		}
		create << "\t}" << std::endl;
		create << std::endl;

		methods << "void " << m_name << "::set" << methodName << "(const " << type << "& " << column->at(0)->asBuffer()->str() << ") {" << std::endl;
		methods << "\tm_" << column->at(0)->asBuffer()->str() << " = " << column->at(0)->asBuffer()->str() << ";" << std::endl;
		methods << "}" << std::endl;
		methods << std::endl;

		methods << type << " " << m_name << "::get" << methodName << "() const {" << std::endl;
		methods << "\treturn (m_" << column->at(0)->asBuffer()->str() << ");" << std::endl;
		methods << "}" << std::endl;
		methods << std::endl;

		if (column->at(1)->asInt()->value() == python::DBTYPE_WINFILETIME) {
			methods << type << " " << m_name << "::get" << methodName << "UNIX() const {" << std::endl;
			methods << "\treturn ((m_" << column->at(0)->asBuffer()->str() << " / 10000000) -  11644473600LL);" << std::endl;
			methods << "}" << std::endl;
			methods << std::endl;
		}

		if (column->at(1)->asInt()->value() == python::DBTYPE_CURRENCY) {
			methods << "double " << m_name << "::get" << methodName << "InISK() const {" << std::endl;
			methods << "\treturn ((double)m_" << column->at(0)->asBuffer()->str() << " / 10000.0f);" << std::endl;
			methods << "}" << std::endl;
			methods << std::endl;
		}

	}
	create << "\treturn (object);" << std::endl;
	create << "}" << std::endl;

	m_source << ") : " << std::endl << sets.str() << "{" << std::endl << "}" << std::endl;
	m_source << std::endl;
	m_source << m_name << "::~" << m_name << "() {" << std::endl << "}" << std::endl;
	m_source << std::endl;

	m_source << m_name << "::" << m_name << "() : " << std::endl;
	m_source << setsd.str() << " {" << std::endl;
	m_source << "}" << std::endl;
	m_source << std::endl;


	m_source << methods.str();
	m_source << std::endl;

	m_source << create.str();
	m_source << std::endl;

	m_source << "} /* namespace model */"<< std::endl;
	m_source << std::endl;
	m_source << "} /* namespace evetools */"<< std::endl;
	m_source << std::endl;
}


} /* namespace generator */

} /* namespace marshal */

} /* namespace evetools */
