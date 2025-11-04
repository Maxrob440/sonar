include(CTest)
include(FetchContent)

# Fetch googletest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Test target: compile the needed sources directly
add_executable(randomdistancereadertest
  randomdistancereadertest.cpp
  ${CMAKE_SOURCE_DIR}/randomdistancereader.cpp
  ${CMAKE_SOURCE_DIR}/distancereader.cpp
)
add_executable(directionreadertest
  directionreadertest.cpp
  ${CMAKE_SOURCE_DIR}/directionreader.cpp)
# So #include "randomdistancereader.h" works
target_include_directories(randomdistancereadertest PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(directionreadertest PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_definitions(directionreadertest PRIVATE UNIT_TESTING)
# Link against gtest main (provides main())
target_link_libraries(randomdistancereadertest PRIVATE GTest::gtest_main)
target_link_libraries(directionreadertest PRIVATE GTest::gtest_main)
# Let CTest discover and run the tests
include(GoogleTest)

gtest_discover_tests(randomdistancereadertest)
gtest_discover_tests(directionreadertest)

