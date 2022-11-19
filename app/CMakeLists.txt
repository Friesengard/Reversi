cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE ON)
# ===== Name =====
set (TARGET_NAME "reversi")
project(TARGET_NAME)
message(STATUS "Start of TARGET: ${TARGET_NAME}")

# ===== Paths =====
set (SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/source")
set (BUILD_DIR "${CMAKE_CURRENT_LIST_DIR}/build")
set (OUTPUT_DIR "${BUILD_DIR}/output")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# ===== Add executable =====
add_executable(${TARGET_NAME})

# ===== Flags =====
target_compile_options (${TARGET_NAME} PRIVATE -std=c++11)
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# ===== Sources =====
unset(TARGET_SOURCES)
unset(TARGET_HEADERS)

# find C header files recursively
file(GLOB_RECURSE TMP "${SOURCE_DIR}/*.h")
list(APPEND TARGET_HEADERS ${TMP})

# find C source files recursively
file(GLOB_RECURSE TMP "${SOURCE_DIR}/*.c")
list(APPEND TARGET_SOURCES ${TMP})

# find C++ header files recursively
file(GLOB_RECURSE TMP "${SOURCE_DIR}/*.hpp")
list(APPEND TARGET_HEADERS ${TMP})

# find C++ source files recursively
file(GLOB_RECURSE TMP "${SOURCE_DIR}/*.cpp")
list(APPEND TARGET_SOURCES ${TMP})

message(STATUS "TARGET_SOURCES:")
message(STATUS ${TARGET_SOURCES})

message(STATUS "TARGET_HEADERS:")
message(STATUS ${TARGET_HEADERS})

target_sources(${TARGET_NAME} PRIVATE ${TARGET_SOURCES})

# ===== Includes =====
target_include_directories(${TARGET_NAME}
  PRIVATE
    ${SOURCE_DIR}
)
