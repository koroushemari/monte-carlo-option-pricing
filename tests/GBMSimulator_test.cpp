#define BOOST_TEST_MODULE GBMSimulatorTest
#include <boost/test/unit_test.hpp>
#include "GBMSimulator.hpp"
#include <cmath>

BOOST_AUTO_TEST_SUITE(GBMSimulatorTests)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    double initialPrice = 100.0;
    double drift = 0.05;
    double volatility = 0.2;
    double timeStep = 1.0 / 252.0;

    GBMSimulator simulator(initialPrice, drift, volatility, timeStep);

    BOOST_TEST(simulator.getInitialPrice() == initialPrice);
    BOOST_TEST(simulator.getDrift() == drift);
    BOOST_TEST(simulator.getVolatility() == volatility);
    BOOST_TEST(simulator.getTimeStep() == timeStep);
}

BOOST_AUTO_TEST_CASE(SimulatePathTest)
{
    double initialPrice = 100.0;
    double drift = 0.05;
    double volatility = 0.2;
    double timeStep = 1.0 / 252.0;
    int numSteps = 10;

    GBMSimulator simulator(initialPrice, drift, volatility, timeStep);
    std::vector<double> path = simulator.simulatePath(numSteps);

    // Check path length
    BOOST_TEST(path.size() == numSteps + 1);

    // Check initial price
    BOOST_TEST(path[0] == initialPrice);

    // Check that all prices are positive
    for (double price : path)
    {
        BOOST_TEST(price > 0.0);
    }
}

BOOST_AUTO_TEST_CASE(ZeroVolatilityTest)
{
    double initialPrice = 100.0;
    double drift = 0.05;
    double volatility = 0.0; // Zero volatility
    double timeStep = 1.0 / 252.0;
    int numSteps = 10;

    GBMSimulator simulator(initialPrice, drift, volatility, timeStep);
    std::vector<double> path = simulator.simulatePath(numSteps);

    // With zero volatility, price should follow deterministic path
    double expectedPrice = initialPrice * std::exp(drift * timeStep * numSteps);
    BOOST_TEST(std::abs(path.back() - expectedPrice) < 1e-10);
}

BOOST_AUTO_TEST_SUITE_END()