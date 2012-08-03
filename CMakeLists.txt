# project definition
cmake_minimum_required (VERSION 2.6)
project (martlet)

# make sure the user doesn't play dirty with symlinks
get_filename_component(srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
get_filename_component(bindir "${CMAKE_BINARY_DIR}" REALPATH)

# disallow in-source builds
if (${srcdir} STREQUAL ${bindir})
    file (REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/CMakeCache.txt ${CMAKE_SOURCE_DIR}/CMakeFiles)

    # disable in-source builds
    if (EXISTS ${CMAKE_SOURCE_DIR}/CMakeCache.txt OR
        EXISTS ${CMAKE_SOURCE_DIR}/CMakeFiles)
        message (ERROR "CMakeCache.txt or CMakeFiles exists in source directory!")
    endif ()
    message (FATAL_ERROR "In-source builds are forbidden!")
endif (${srcdir} STREQUAL ${bindir})

# the version number.
set (APUS_NAME "Apus")
set (APUS_CODENAME "${PROJECT_NAME}")
set (APUS_COPYRIGHT_YEARS "2012")
set (APUS_VERSION_MAJOR 0)
set (APUS_VERSION_MINOR 1)
set (APUS_VERSION_PATCH 0)
set (APUS_VERSION_TYPE "dev")
if ("${APUS_VERSION_TYPE}" STREQUAL "")
    set (APUS_VERSION_STRING "${APUS_VERSION_MAJOR}.${APUS_VERSION_MINOR}.${APUS_VERSION_PATCH}")
else ("${APUS_VERSION_TYPE}" STREQUAL "")
    set (APUS_VERSION_STRING "${APUS_VERSION_MAJOR}.${APUS_VERSION_MINOR}.${APUS_VERSION_PATCH}-${APUS_VERSION_TYPE}")
endif ("${APUS_VERSION_TYPE}" STREQUAL "")

# debugging options
set (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release

OPTION(Debug "Enable debug build for source" OFF )
STRING(TOUPPER CMAKE_BUILD_TYPE _TYPE)

if (Debug OR  _TYPE STREQUAL "DEBUG")
    set (Debug ON)
    set (APUS_DEBUG 1)
    set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
    set (APUS_OUTPUT_DIR ${PROJECT_SOURCE_DIR} "/debug")
else (Debug OR  _TYPE STREQUAL "DEBUG")
    set (Debug OFF)
    set (APUS_RELEASE 1)
    set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
    set (APUS_OUTPUT_DIR )
    set (APUS_OUTPUT_DIR ${PROJECT_SOURCE_DIR} "/release")
endif (Debug OR  _TYPE STREQUAL "DEBUG")

# project input paths
set (APUS_INCLUDE_DIR       ${PROJECT_SOURCE_DIR} "/include")
set (APUS_SOURCE_DIR        ${PROJECT_SOURCE_DIR} "/source")
set (SF_VENDOR_PATH         ${PROJECT_SOURCE_DIR} "/vendor")

# project output paths
set (EXECUTABLE_OUTPUT_PATH ${APUS_OUTPUT_DIR} "/bin")
set (LIBRARY_OUTPUT_PATH    ${APUS_OUTPUT_DIR} "/lib")


# includes files
INCLUDE_DIRECTORIES("${MAINFOLDER}/include")

# include subdirectories
ADD_SUBDIRECTORY(source/core)
ADD_SUBDIRECTORY(source/compiler)
