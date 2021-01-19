file(GLOB CPP_SOURCES "*.cpp")

add_executable(Ty1Randomizer ${CPP_SOURCES})
target_compile_features(Ty1Randomizer PUBLIC cxx_std_17)
set_target_properties(Ty1Randomizer PROPERTIES CXX_EXTENSIONS OFF
										  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
target_link_libraries(Ty1Randomizer KIni -static)