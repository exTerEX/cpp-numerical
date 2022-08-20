cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

enable_testing()

project(
  cppnumerical
  VERSION 0.1.0
  LANGUAGES CXX
)

find_package(OpenMP)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  include(CTest)

  if(BUILD_TESTING)
    add_subdirectory(tests)
  endif()

  set(CMAKE_CXX_CLANG_TIDY clang-tidy --fix)
endif()
