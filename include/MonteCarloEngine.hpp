#pragma once
#include "Option.hpp"
#include "GBMSimulator.hpp"
#include <vector>
#include <cmath>

class MonteCarloEngine
{
public:
    MonteCarloEngine(const Option &option, double riskFreeRate, int numSimulations, int numSteps)
        : option_(option), riskFreeRate_(riskFreeRate), numSimulations_(numSimulations), numSteps_(numSteps)
    {
    }

    double calculate(double S0, double sigma)
    {
        double timeStep = option_.getMaturity() / numSteps_;
        GBMSimulator simulator(S0, riskFreeRate_, sigma, timeStep);

        double sumPayoffs = 0.0;

        // Run simulations
        for (int i = 0; i < numSimulations_; ++i)
        {
            std::vector<double> path = simulator.simulatePath(numSteps_);
            double ST = path.back(); // Final price
            sumPayoffs += option_.payoff(ST);
        }

        // Calculate average payoff and discount
        double averagePayoff = sumPayoffs / numSimulations_;
        return averagePayoff * std::exp(-riskFreeRate_ * option_.getMaturity());
    }

private:
    const Option &option_; // Reference to the option
    double riskFreeRate_;  // Risk-free rate (r)
    int numSimulations_;   // Number of simulations
    int numSteps_;         // Number of time steps per path
};