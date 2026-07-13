cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)

include(FetchContent)
FetchContent_Declare(
    serial_cpp
    GIT_REPOSITORY https://github.com/ami-iit/serial_cpp.git
    GIT_TAG v1.3.4 # or use the tag or commit you prefer
)

FetchContent_MakeAvailable(serial_cpp)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()
# Set the project name
set(CMAKE_PROJECT_NAME READ_SENSORS)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/serial_wrapper/serial_wrapper.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    serial_cpp::serial_cpp
)
