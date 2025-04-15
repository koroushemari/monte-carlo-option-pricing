#include "GBMSimulator.hpp"

/*
 * Constructor for Geometric Brownian Motion (GBM) Simulator
 *
 * Parameters and member variables:
 * ------------------------------
 * initialPrice_ (S(0)): The starting price of the stock
 *                      Example: 100.0 means $100 initial stock price
 *
 * drift_ (μ): The expected return rate (annual)
 *            Example: 0.05 means 5% expected annual return
 *
 * volatility_ (σ): The standard deviation of returns (annual)
 *                 Example: 0.2 means 20% annual volatility
 *
 * timeStep_ (t): The time increment for each simulation step
 *               Example: 1/252 means daily steps (252 trading days in a year)
 *
 * gen_: Mersenne Twister random number generator (std::mt19937)
 *      Used to generate random numbers for the simulation
 *      Seeded with rd_() for non-deterministic sequences
 *
 * normalDist_: Standard normal distribution (mean=0, std=1)
 *             Generates Z values in the GBM formula
 *             These Z values follow a bell curve centered at 0
 *
 * GBM Formula: S(t) = S(0) * exp((μ - σ²/2)t + σ√t * Z)
 * where:
 * - S(t) is the stock price at time t
 * - S(0) is initialPrice_
 * - μ is drift_
 * - σ is volatility_
 * - t is timeStep_
 * - Z is generated by normalDist_
 */
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
        double z = normalDist_(gen_);

        // GBM formula: S(t) = S(0) * exp((μ - σ²/2)t + σ√t * Z)
        double exponent = (drift_ - 0.5 * volatility_ * volatility_) * timeStep_ +
                          volatility_ * std::sqrt(timeStep_) * z;

        currentPrice *= std::exp(exponent);
        path.push_back(currentPrice);
    }

    return path;
}
