cmake_minimum_required(VERSION 3.10)
project(OBD1_Suite C)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")

# Define the executable
add_executable(obd1_suite ${SOURCES})