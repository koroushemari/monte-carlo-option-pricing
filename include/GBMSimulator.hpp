#pragma once

#include <vector>
#include <random>
#include <cmath>

class GBMSimulator
{
public:
    GBMSimulator(double initialPrice, double drift, double volatility, double timeStep);

    // Simulate a single price path
    std::vector<double> simulatePath(int numSteps);

    // Getters
    double getInitialPrice() const { return initialPrice_; }
    double getDrift() const { return drift_; }
    double getVolatility() const { return volatility_; }
    double getTimeStep() const { return timeStep_; }

private:
    double initialPrice_;
    double drift_;
    double volatility_;
    double timeStep_;

    // Random number generation
    std::random_device rd_;
    std::mt19937 gen_;
    std::normal_distribution<double> normalDist_;
};
