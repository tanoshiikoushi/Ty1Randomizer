file(GLOB CPP_SOURCES "*.cpp")
file(GLOB H_HEADERS "../include/*.h")

add_executable(Ty1Randomizer ${CPP_SOURCES})
target_compile_features(Ty1Randomizer PUBLIC cxx_std_17)
target_include_directories(Ty1Randomizer PUBLIC ../include)
set_target_properties(Ty1Randomizer PROPERTIES CXX_EXTENSIONS OFF
										  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
target_link_libraries(Ty1Randomizer KIni -static)

source_group (
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${H_HEADERS})