cmake_minimum_required(VERSION 3.10)
project(MonteCarloOptionPricing VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost package
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/tests
)

# Add source files
add_executable(monte_carlo_simulator 
    src/main.cpp
    src/GBMSimulator.cpp
)

# Add test executable
add_executable(unit_tests
    tests/GBMSimulator_test.cpp
    src/GBMSimulator.cpp
)

# Link Boost test framework to test executable
target_link_libraries(unit_tests PRIVATE Boost::unit_test_framework)

# Enable testing
enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)
