FILE (GLOB_RECURSE APUS_CORE_SOURCE *.cpp *.hpp)

# Include bison and flex
find_package (BISON REQUIRED)
find_package (FLEX  REQUIRED)

bison_target (APUS_PARSER ${CMAKE_CURRENT_SOURCE_DIR}/lang/parser.yy  ${CMAKE_CURRENT_SOURCE_DIR}/lang/parser.cpp VERBOSE ${PROJECT_BINARY_DIR}/parser.log)
flex_target  (APUS_SCANNER ${CMAKE_CURRENT_SOURCE_DIR}/lang/scanner.ll ${CMAKE_CURRENT_SOURCE_DIR}/lang/scanner.cpp)
add_flex_bison_dependency (APUS_SCANNER APUS_PARSER)

list (REMOVE_ITEM APUS_CORE_SOURCE "lang/scanner.cpp")
list (REMOVE_ITEM APUS_CORE_SOURCE "lang/parser.cpp")
list (REMOVE_ITEM APUS_CORE_SOURCE "lang/parser.hpp")
set (APUS_CORE_SOURCE ${APUS_CORE_SOURCE} ${BISON_APUS_PARSER_OUTPUTS} ${FLEX_APUS_SCANNER_OUTPUTS})

add_library (apus SHARED ${APUS_CORE_SOURCE})
target_link_libraries (apus ${ICU_LIBRARIES})

set_target_properties (
    apus PROPERTIES
    VERSION             ${APUS_VERSION}
    CLEAN_DIRECT_OUTPUT 1
#    COMPILE_FLAGS       ${LLVM_CXXFLAGS}
#    LINK_FLAGS          ${LLVM_CXXFLAGS}
)

install (TARGETS apus DESTINATION lib)
