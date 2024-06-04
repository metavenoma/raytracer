cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Add GLFW
find_package(glfw3 REQUIRED)

# Include directories
include_directories(includes)

# Add the source files
add_executable(raytracer
	sources/main.cpp
	sources/Tuple.cpp
	sources/Utils.cpp
)

# Link against GLFW
target_link_libraries(raytracer glfw)
