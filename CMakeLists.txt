# project definition
cmake_minimum_required (VERSION 2.6)
project (martlet)

# make sure the user doesn't play dirty with symlinks
get_filename_component(APUS_MAIN_DIR  "${CMAKE_SOURCE_DIR}" REALPATH)
get_filename_component(APIS_CMAKE_DIR "${CMAKE_BINARY_DIR}" REALPATH)

# disallow in-source builds
if (${APUS_MAIN_DIR} STREQUAL ${APIS_CMAKE_DIR})
    file (REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/CMakeCache.txt ${CMAKE_SOURCE_DIR}/CMakeFiles)

    # disable in-source builds
    if (EXISTS ${CMAKE_SOURCE_DIR}/CMakeCache.txt OR
        EXISTS ${CMAKE_SOURCE_DIR}/CMakeFiles)
        message (ERROR "CMakeCache.txt or CMakeFiles exists in source directory!")
    endif ()
    message (FATAL_ERROR "In-source builds are forbidden!")
endif (${APUS_MAIN_DIR} STREQUAL ${APIS_CMAKE_DIR})

# the version number.
set (APUS_NAME "Apus")
set (APUS_CODENAME "${PROJECT_NAME}")
set (APUS_COPYRIGHT_YEARS "2012")
set (APUS_VERSION_MAJOR 0)
set (APUS_VERSION_MINOR 1)
set (APUS_VERSION_PATCH 0)
set (APUS_VERSION_TYPE "dev")
set (APUS_VERSION ${APUS_VERSION_MAJOR}.${APUS_VERSION_MINOR}.${APUS_VERSION_PATCH})
if ("${APUS_VERSION_TYPE}" STREQUAL "")
    set (APUS_VERSION_STRING ${APUS_VERSION_MAJOR}.${APUS_VERSION_MINOR}.${APUS_VERSION_PATCH})
else ("${APUS_VERSION_TYPE}" STREQUAL "")
    set (APUS_VERSION_STRING ${APUS_VERSION_MAJOR}.${APUS_VERSION_MINOR}.${APUS_VERSION_PATCH}-${APUS_VERSION_TYPE})
endif ("${APUS_VERSION_TYPE}" STREQUAL "")

# debugging options
set (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release

OPTION(Debug "Enable debug build for source" OFF )
STRING(TOUPPER CMAKE_BUILD_TYPE _TYPE)

if (Debug OR  _TYPE STREQUAL "DEBUG")
    set (Debug ON)
    set (APUS_DEBUG 1)
    set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
else (Debug OR  _TYPE STREQUAL "DEBUG")
    set (Debug OFF)
    set (APUS_RELEASE 1)
    set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif (Debug OR  _TYPE STREQUAL "DEBUG")
set (APUS_BUILD_DIR "${APUS_MAIN_DIR}")

# project input paths
set (APUS_INCLUDE_DIR       "${APUS_MAIN_DIR}/include")
set (APUS_SOURCE_DIR        "${APUS_MAIN_DIR}/source")
set (SF_VENDOR_PATH         "${APUS_MAIN_DIR}/vendor")

# project output paths
set (EXECUTABLE_OUTPUT_PATH "${APUS_BUILD_DIR}/bin")
set (LIBRARY_OUTPUT_PATH    "${APUS_BUILD_DIR}/lib")

# project search paths
list (APPEND CMAKE_PREFIX_PATH "${APUS_MAIN_DIR}")
set (CMAKE_MODULE_PATH "${APUS_MAIN_DIR}/tool/cmake")

# project cmake components
include (ExternalProject)
include (UninstallTarget)
include (DocumentationTargets)

# include subdirectories
include_directories (${APUS_INCLUDE_DIR})
add_subdirectory ("${APUS_SOURCE_DIR}/core")
add_subdirectory ("${APUS_SOURCE_DIR}/compiler")

# add install targets
file (GLOB _APUS_INCLUDES ${APUS_INCLUDE_DIR})
foreach (loop_var IN LISTS _APUS_INCLUDES)
    install (DIRECTORY "${APUS_INCLUDE_DIR}/${loop_var}" DESTINATION "include")
endforeach (loop_var IN LISTS _APUS_INCLUDES)
