cmake_minimum_required(VERSION 3.20)

### set the project name and programming language ###
project(AnalyticalGeometry VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 20)

### Add the include paths inside the project ###
include_directories(src)

# Run test if this is the main project
if(PROJECT_IS_TOP_LEVEL)
  file(GLOB_RECURSE ALL_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
  )

  # Add a custom target for clang-format
  add_custom_target(clang-format-check
    COMMAND ${CMAKE_COMMAND} -E echo "Running clang-format..."
    COMMAND clang-format  --dry-run --verbose -i ${ALL_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  # Optional: to ensure .clang-format file is found in the source root
  )

  # Add a custom target for clang-format
  add_custom_target(clang-format-apply
    COMMAND ${CMAKE_COMMAND} -E echo "Running clang-format..."
    COMMAND clang-format -i ${ALL_SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  # Optional: to ensure .clang-format file is found in the source root
  )
  
  # Add tests only if this is the main project
  add_subdirectory(libraries/googletest)
  enable_testing()
  add_executable(MyTest src/test.cpp)
  target_link_libraries(MyTest gtest gtest_main)

  set(BENCHMARK_ENABLE_TESTING OFF)
  add_subdirectory(libraries/benchmark)
  include_directories(libraries/half/half)
  add_executable(MyBenchmark src/benchmark.cpp)
  target_link_libraries(MyBenchmark benchmark)
endif()