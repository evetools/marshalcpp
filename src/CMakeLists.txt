SET( PROJECT_NAME                   "evemarshal" )

SET( PROJECT_MAJOR                  0 )
SET( PROJECT_MINOR                  0 )
SET( PROJECT_RELEASE                1 )
SET( PROJECT_VERSION                ${PROJECT_MAJOR}.${PROJECT_MINOR}.${PROJECT_RELEASE})

SET( TARGET_DUMPER_NAME             "dumpmarshal" )
SET( TARGET_MARKETORDERS_NAME       "marketorders" )
SET( TARGET_REGIONBEST_NAME         "regionbest" )

SET( LIBRARY_NAME                   ${PROJECT_NAME} )
SET( LIBRARY_MAJOR                  ${PROJECT_MAJOR} )
SET( LIBRARY_MINOR                  ${PROJECT_MINOR} )
SET( LIBRARY_RELEASE                ${PROJECT_RELEASE} )
SET( LIBRARY_VERSION                ${LIBRARY_MAJOR}.${LIBRARY_MINOR}.${LIBRARY_RELEASE})

SET( INCLUDE_DIR                    "${PROJECT_SOURCE_DIR}/src" )
SET( SOURCE_DIR                     "${PROJECT_SOURCE_DIR}/src" )

SET( LIBRARY_INCLUDE_DIR            ${INCLUDE_DIR} )
SET( LIBRARY_SOURCE_DIR             ${SOURCE_DIR} )

SET( INCLUDE_PYTHON
    "${LIBRARY_INCLUDE_DIR}/python/py.h"
    "${LIBRARY_INCLUDE_DIR}/python/pybase.h"
    "${LIBRARY_INCLUDE_DIR}/python/pybool.h"
    "${LIBRARY_INCLUDE_DIR}/python/pybuffer.h"
    "${LIBRARY_INCLUDE_DIR}/python/pycontainer.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydbcrowset.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydbrow.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydbrowdescriptor.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydbrowlist.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydict.h"
    "${LIBRARY_INCLUDE_DIR}/python/pydouble.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyglobal.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyint.h"
    "${LIBRARY_INCLUDE_DIR}/python/pylist.h"
    "${LIBRARY_INCLUDE_DIR}/python/pylong.h"
    "${LIBRARY_INCLUDE_DIR}/python/pynone.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyobject.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyobjectex.h"
    "${LIBRARY_INCLUDE_DIR}/python/pytuple.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyvisitor.h" )

SET( INCLUDE_MARSHAL
    "${LIBRARY_INCLUDE_DIR}/marshal/dumpvisitor.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/istream.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/reader.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/streamiterator.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/strings.h")

SET( INCLUDE_LOADER
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/marketorders.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/regionbest.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/csvvisitor.h")

SET( INCLUDE_COMMON_UTF8
    "${LIBRARY_INCLUDE_DIR}/common/utf8/checked.h"
    "${LIBRARY_INCLUDE_DIR}/common/utf8/core.h"
    "${LIBRARY_INCLUDE_DIR}/common/utf8/unchecked.h" )

SET( INCLUDE_COMMON
    "${LIBRARY_INCLUDE_DIR}/common/utf8.h" )

SET( SOURCE_PYTHON
    "${LIBRARY_SOURCE_DIR}/python/pybool.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pybase.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pybuffer.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pycontainer.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydbcrowset.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydbrow.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydbrowdescriptor.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydbrowlist.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydict.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydouble.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyglobal.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyint.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pylist.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pylong.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pynone.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyobject.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyobjectex.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pytuple.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyvisitor.cpp" )

SET( SOURCE_MARSHAL
    "${LIBRARY_SOURCE_DIR}/marshal/dumpvisitor.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/istream.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/reader.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/streamiterator.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/strings.cpp" )

SET( SOURCE_LOADER
    "${LIBRARY_SOURCE_DIR}/marshal/loader/marketorders.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/regionbest.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/csvvisitor.cpp")

SET( SOURCE_DUMPER          "${SOURCE_DIR}/dumpmarshal.cpp" )

SET( SOURCE_MARKETORDERS    "${SOURCE_DIR}/marketorders.cpp" )

SET( SOURCE_REGIONBEST      "${SOURCE_DIR}/regionbest.cpp" )

INCLUDE_DIRECTORIES( ${ZLIB_INCLUDE_DIR} )

INCLUDE_DIRECTORIES( ${INCLUDE_DIR} )

ADD_LIBRARY( ${LIBRARY_NAME}
             ${INCLUDE_PYTHON}     ${SOURCE_PYTHON}
             ${INCLUDE_MARSHAL}    ${SOURCE_MARSHAL}
             ${INCLUDE_LOADER}     ${SOURCE_LOADER} )

SET_TARGET_PROPERTIES( ${LIBRARY_NAME} PROPERTIES SOVERSION ${LIBRARY_MAJOR} VERSION ${LIBRARY_VERSION} )

ADD_EXECUTABLE( ${TARGET_DUMPER_NAME}               ${SOURCE_DUMPER} )
ADD_EXECUTABLE( ${TARGET_MARKETORDERS_NAME}         ${SOURCE_MARKETORDERS} )
ADD_EXECUTABLE( ${TARGET_REGIONBEST_NAME}           ${SOURCE_REGIONBEST} )

TARGET_LINK_LIBRARIES( ${LIBRARY_NAME}              ${ZLIB_LIBRARIES} )

TARGET_LINK_LIBRARIES( ${TARGET_DUMPER_NAME}        ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_MARKETORDERS_NAME}  ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_REGIONBEST_NAME}    ${LIBRARY_NAME} )

INSTALL( FILES ${INCLUDE_COMMON}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/common" )
INSTALL( FILES ${INCLUDE_COMMON_UTF8}           DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/common/utf8" )
INSTALL( FILES ${INCLUDE_PYTHON}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/python" )
INSTALL( FILES ${INCLUDE_MARSHAL}               DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/marshal" )
INSTALL( FILES ${INCLUDE_LOADER}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/loader" )

INSTALL( TARGETS ${LIBRARY_NAME}    LIBRARY     DESTINATION lib )

INSTALL( TARGETS ${TARGET_DUMPER_NAME}          DESTINATION bin )
INSTALL( TARGETS ${TARGET_MARKETORDERS_NAME}    DESTINATION bin )
INSTALL( TARGETS ${TARGET_REGIONBEST_NAME}      DESTINATION bin )
