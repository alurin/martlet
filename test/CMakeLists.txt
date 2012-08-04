find_package (UnitTestPlusPlus REQUIRED)
include_directories (${UnitTestPlusPlus_INCLUDE_DIRS})
link_directories (${UnitTestPlusPlus_LIBRARY_DIRS})

file (GLOB_RECURSE test_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
set (test_LIBS ${Boost_LIBRARIES} ${UnitTestPlusPlus_LIBRARIES} apus)
set (test_BIN ${PROJECT_NAME}-unittests)

add_executable (${test_BIN} ${test_SRCS})
target_link_libraries (${test_BIN} ${test_LIBS})

add_custom_target (check ALL "${APUS_BUILD_DIR}/bin/${test_BIN}" DEPENDS ${test_BIN} COMMENT "Executing unit tests..." VERBATIM SOURCES ${test_SRCS})
add_custom_target (test "${APUS_BUILD_DIR}/bin/${test_BIN}" DEPENDS ${test_BIN} COMMENT "Executing unit tests..." VERBATIM SOURCES ${test_SRCS})

find_program( VALGRIND valgrind)
if (VALGRIND)
    add_custom_target (
        valgrind
        COMMAND ${VALGRIND} --leak-check=full --leak-resolution=med ${APUS_BUILD_DIR}/bin/${test_BIN}
        DEPENDS ${test_BIN}
        COMMENT "Executing unit tests with valgrind checks..." VERBATIM
        SOURCES ${test_SRCS})
endif (VALGRIND)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
