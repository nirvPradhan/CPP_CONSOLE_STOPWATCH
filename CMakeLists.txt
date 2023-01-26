# CMakeList.txt : CMake project for CPP_CONSOLE_STOPWATCH, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPP_CONSOLE_STOPWATCH")

# Add source to this project's executable.
add_executable (CPP_CONSOLE_STOPWATCH "main.cpp" "Stopwatch.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP_CONSOLE_STOPWATCH PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
