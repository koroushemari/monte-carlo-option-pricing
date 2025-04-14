#include "GBMSimulator.hpp"

GBMSimulator::GBMSimulator(double initialPrice, double drift, double volatility, double timeStep)
    : initialPrice_(initialPrice), drift_(drift), volatility_(volatility), timeStep_(timeStep), gen_(rd_()), normalDist_(0.0, 1.0)
{
}

std::vector<double> GBMSimulator::simulatePath(int numSteps)
{
    std::vector<double> path;
    path.reserve(numSteps + 1);
    path.push_back(initialPrice_);

    double currentPrice = initialPrice_;
    for (int i = 0; i < numSteps; ++i)
    {
        // Generate random normal variable
        double z = normalDist_(gen_);

        // GBM formula: S(t) = S(0) * exp((μ - σ²/2)t + σ√t * Z)
        double exponent = (drift_ - 0.5 * volatility_ * volatility_) * timeStep_ +
                          volatility_ * std::sqrt(timeStep_) * z;

        currentPrice *= std::exp(exponent);
        path.push_back(currentPrice);
    }

    return path;
}
