cmake_minimum_required(VERSION 3.0.0)
project(shapeshifter-test VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)


FetchContent_Declare(
  lyra
  GIT_REPOSITORY    https://github.com/bfgroup/Lyra.git
  GIT_TAG           1.6
  GIT_SHALLOW       1
)
FetchContent_MakeAvailable(lyra)



add_executable(shapeshifter-test
  src/main.cpp
  src/worker.cpp
  src/string-funcs.cpp
  )


# testing.

# GoogleTest requires at least C++11
FetchContent_Declare(
  googletest
  # URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           release-1.11.0
  GIT_SHALLOW       1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(shapeshifter-test PRIVATE 
  lyra
)

enable_testing()

add_executable(shapeshifter-test-tests)

target_include_directories(shapeshifter-test-tests PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_sources(shapeshifter-test-tests PRIVATE
  src/worker.cpp
  tests/worker-test.cpp
  src/string-funcs.cpp
  tests/string-funcs-test.cpp
)

target_link_libraries(shapeshifter-test-tests PRIVATE 
  gmock_main
)

include(GoogleTest)
