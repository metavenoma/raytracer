cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Add GLFW and OpenGL
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Include directories
include_directories(includes)

# Define a library for shared sources
add_library(raytracer_lib
    sources/Tuple.cpp
    sources/Matrix.cpp
	sources/Color.cpp
	sources/Canvas.cpp
	sources/utils/tick.cpp
	sources/utils/hadamardProduct.cpp
	sources/utils/equal.cpp
	sources/utils/canvasToPpm.cpp
)

# Include directories for raytracer_lib
target_include_directories(raytracer_lib PUBLIC includes)

# Link the library with GLFW and OpenGL
target_link_libraries(raytracer_lib glfw OpenGL::GL)

# Add the main raytracer executable
add_executable(raytracer sources/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_lib)

# Google Test setup with FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test executable
file(GLOB_RECURSE TEST_FILES tests/*.cpp)
add_executable(tests ${TEST_FILES})

# Link test executable with Google Test libraries and raytracer_lib
target_link_libraries(tests PRIVATE gtest gtest_main raytracer_lib)

# Enable testing in CMake
enable_testing()
add_test(NAME RayTracerTests COMMAND tests)

