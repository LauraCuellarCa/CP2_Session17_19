include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

#SESSION 17
add_executable(test_STLexercises test_STLexercises.cpp) # Compile a test source


#HERE LINK AGAINST THE LIBRARIES

#SESSION 13
gtest_discover_tests(test_STLexercises)            # Register the tests to gtest
