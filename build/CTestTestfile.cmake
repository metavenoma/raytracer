# CMake generated Testfile for 
# Source directory: /home/capim/projects/raytracer
# Build directory: /home/capim/projects/raytracer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RayTracerTests "/home/capim/projects/raytracer/build/tests")
set_tests_properties(RayTracerTests PROPERTIES  _BACKTRACE_TRIPLES "/home/capim/projects/raytracer/CMakeLists.txt;51;add_test;/home/capim/projects/raytracer/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
