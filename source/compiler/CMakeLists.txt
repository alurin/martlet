file (GLOB_RECURSE APUS_COMPILER_SOURCE *.cpp *.cxx *.cc *.C *.c *.h *.hpp)

add_executable(apusc ${APUS_COMPILER_SOURCE})
set_target_properties (apusc PROPERTIES
    VERSION ${APUS_VERSION}
    CLEAN_DIRECT_OUTPUT 1
)

install(TARGETS apusc DESTINATION bin)
