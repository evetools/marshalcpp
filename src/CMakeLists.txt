SET( PROJECT_NAME                   "evemarshal" )

SET( PROJECT_MAJOR                  0 )
SET( PROJECT_MINOR                  0 )
SET( PROJECT_RELEASE                2 )
SET( PROJECT_VERSION                ${PROJECT_MAJOR}.${PROJECT_MINOR}.${PROJECT_RELEASE})

SET( TARGET_DUMPER_NAME             "dumpmarshal" )
SET( TARGET_MARKETORDERS_NAME       "marketorders" )
SET( TARGET_MARKETHISTORY_NAME      "markethistory" )
SET( TARGET_REGIONBEST_NAME         "regionbest" )
SET( TARGET_INVTYPES_NAME           "invtypes" )
SET( TARGET_MAPREGIONS_NAME         "mapregions" )
SET( TARGET_MEMCHECKMARSHAL_NAME    "memcheckmarshal" )

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
    "${LIBRARY_INCLUDE_DIR}/python/pyfloat.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyglobal.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyint.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyuint.h"
    "${LIBRARY_INCLUDE_DIR}/python/pylist.h"
    "${LIBRARY_INCLUDE_DIR}/python/pylong.h"
    "${LIBRARY_INCLUDE_DIR}/python/pyulong.h"
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
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/markethistory.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/regionbest.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/invtypes.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/mapregions.h"
    "${LIBRARY_INCLUDE_DIR}/marshal/loader/csvvisitor.h")

SET( INCLUDE_GENERATOR
    "${LIBRARY_INCLUDE_DIR}/marshal/generator/dbrow.h")

SET( INCLUDE_MODEL
    "${LIBRARY_INCLUDE_DIR}/model/marketorder.h"
    "${LIBRARY_INCLUDE_DIR}/model/markethistory.h"
    "${LIBRARY_INCLUDE_DIR}/model/regionbest.h"
    "${LIBRARY_INCLUDE_DIR}/model/mapregion.h"
    "${LIBRARY_INCLUDE_DIR}/model/invtype.h")

SET( INCLUDE_MODEL_LOADER
    "${LIBRARY_INCLUDE_DIR}/model/loader/marketorders.h"
    "${LIBRARY_INCLUDE_DIR}/model/loader/markethistory.h"
    "${LIBRARY_INCLUDE_DIR}/model/loader/regionbest.h"
    "${LIBRARY_INCLUDE_DIR}/model/loader/invtypes.h"
    "${LIBRARY_INCLUDE_DIR}/model/loader/mapregions.h")

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
    "${LIBRARY_SOURCE_DIR}/python/pyfloat.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pydouble.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyglobal.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyint.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyuint.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pylist.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pylong.cpp"
    "${LIBRARY_SOURCE_DIR}/python/pyulong.cpp"
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
    "${LIBRARY_SOURCE_DIR}/marshal/loader/markethistory.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/regionbest.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/mapregions.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/invtypes.cpp"
    "${LIBRARY_SOURCE_DIR}/marshal/loader/csvvisitor.cpp")

SET( SOURCE_GENERATOR
    "${LIBRARY_SOURCE_DIR}/marshal/generator/dbrow.cpp")

SET( SOURCE_MODEL
    "${LIBRARY_SOURCE_DIR}/model/marketorder.cpp"
    "${LIBRARY_SOURCE_DIR}/model/markethistory.cpp"
    "${LIBRARY_SOURCE_DIR}/model/regionbest.cpp"
    "${LIBRARY_SOURCE_DIR}/model/mapregion.cpp"
    "${LIBRARY_SOURCE_DIR}/model/invtype.cpp")

SET( SOURCE_MODEL_LOADER
    "${LIBRARY_SOURCE_DIR}/model/loader/marketorders.cpp"
    "${LIBRARY_SOURCE_DIR}/model/loader/markethistory.cpp"
    "${LIBRARY_SOURCE_DIR}/model/loader/regionbest.cpp"
    "${LIBRARY_SOURCE_DIR}/model/loader/invtypes.cpp"
    "${LIBRARY_SOURCE_DIR}/model/loader/mapregions.cpp")

SET( SOURCE_DUMPER          "${SOURCE_DIR}/dumpmarshal.cpp" )

SET( SOURCE_MARKETORDERS    "${SOURCE_DIR}/marketorders.cpp" )

SET( SOURCE_MARKETHISTORY   "${SOURCE_DIR}/markethistory.cpp" )

SET( SOURCE_REGIONBEST      "${SOURCE_DIR}/regionbest.cpp" )

SET( SOURCE_INVTYPES        "${SOURCE_DIR}/invtypes.cpp" )

SET( SOURCE_MEMCHECKMARSHAL "${SOURCE_DIR}/memcheckmarshal.cpp" )

SET( SOURCE_MAPREGIONS      "${SOURCE_DIR}/mapregions.cpp" )

INCLUDE_DIRECTORIES( ${ZLIB_INCLUDE_DIR} )

INCLUDE_DIRECTORIES( ${INCLUDE_DIR} )

ADD_LIBRARY( ${LIBRARY_NAME}
             ${INCLUDE_PYTHON}              ${SOURCE_PYTHON}
             ${INCLUDE_MARSHAL}             ${SOURCE_MARSHAL}
             ${INCLUDE_LOADER}              ${SOURCE_LOADER}
             ${INCLUDE_GENERATOR}           ${SOURCE_GENERATOR}
             ${INCLUDE_MODEL}               ${SOURCE_MODEL}
             ${INCLUDE_MODEL_LOADER}        ${SOURCE_MODEL_LOADER} )

SET_TARGET_PROPERTIES( ${LIBRARY_NAME} PROPERTIES SOVERSION ${LIBRARY_MAJOR} VERSION ${LIBRARY_VERSION} )

ADD_EXECUTABLE( ${TARGET_DUMPER_NAME}                   ${SOURCE_DUMPER} )
ADD_EXECUTABLE( ${TARGET_MARKETORDERS_NAME}             ${SOURCE_MARKETORDERS} )
ADD_EXECUTABLE( ${TARGET_MARKETHISTORY_NAME}            ${SOURCE_MARKETHISTORY} )
ADD_EXECUTABLE( ${TARGET_REGIONBEST_NAME}               ${SOURCE_REGIONBEST} )
ADD_EXECUTABLE( ${TARGET_MEMCHECKMARSHAL_NAME}          ${SOURCE_MEMCHECKMARSHAL} )
ADD_EXECUTABLE( ${TARGET_INVTYPES_NAME}                 ${SOURCE_INVTYPES} )
ADD_EXECUTABLE( ${TARGET_MAPREGIONS_NAME}               ${SOURCE_MAPREGIONS} )

TARGET_LINK_LIBRARIES( ${LIBRARY_NAME}                  ${ZLIB_LIBRARIES} )

TARGET_LINK_LIBRARIES( ${TARGET_DUMPER_NAME}            ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_MARKETORDERS_NAME}      ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_MARKETHISTORY_NAME}     ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_REGIONBEST_NAME}        ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_MEMCHECKMARSHAL_NAME}   ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_INVTYPES_NAME}          ${LIBRARY_NAME} )
TARGET_LINK_LIBRARIES( ${TARGET_MAPREGIONS_NAME}        ${LIBRARY_NAME} )

INSTALL( FILES ${INCLUDE_COMMON}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/common" )
INSTALL( FILES ${INCLUDE_COMMON_UTF8}           DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/common/utf8" )
INSTALL( FILES ${INCLUDE_PYTHON}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/python" )
INSTALL( FILES ${INCLUDE_MARSHAL}               DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/marshal" )
INSTALL( FILES ${INCLUDE_LOADER}                DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/marshal/loader" )
INSTALL( FILES ${INCLUDE_GENERATOR}             DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/marshal/generator" )
INSTALL( FILES ${INCLUDE_MODEL}                 DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/model" )
INSTALL( FILES ${INCLUDE_MODEL_LOADER}          DESTINATION "include/${LIBRARY_NAME}-${LIBRARY_VERSION}/model/loader" )

INSTALL( TARGETS ${LIBRARY_NAME}    LIBRARY     DESTINATION lib )

INSTALL( TARGETS ${TARGET_DUMPER_NAME}          DESTINATION bin )
INSTALL( TARGETS ${TARGET_MARKETORDERS_NAME}    DESTINATION bin )
INSTALL( TARGETS ${TARGET_MARKETHISTORY_NAME}   DESTINATION bin )
INSTALL( TARGETS ${TARGET_REGIONBEST_NAME}      DESTINATION bin )
INSTALL( TARGETS ${TARGET_MEMCHECKMARSHAL_NAME} DESTINATION bin )
INSTALL( TARGETS ${TARGET_INVTYPES_NAME}        DESTINATION bin )
INSTALL( TARGETS ${TARGET_MAPREGIONS_NAME}      DESTINATION bin )
