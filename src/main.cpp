#include "GBMSimulator.hpp"
#include <iostream>
#include <iomanip>

int main()
{
    // Parameters for the simulation
    double initialPrice = 100.0;   // Initial stock price
    double drift = 0.05;           // Annual drift (5%)
    double volatility = 0.2;       // Annual volatility (20%)
    double timeStep = 1.0 / 252.0; // Daily time step (252 trading days)
    int numSteps = 252;            // Simulate for one year

    // Create simulator
    GBMSimulator simulator(initialPrice, drift, volatility, timeStep);

    // Generate and print price path
    std::vector<double> path = simulator.simulatePath(numSteps);

    std::cout << "Simulated Stock Price Path:\n";
    std::cout << "Day\tPrice\n";
    std::cout << "----------------\n";

    for (size_t i = 0; i < path.size(); ++i)
    {
        std::cout << i << "\t" << std::fixed << std::setprecision(2) << path[i] << "\n";
    }

    return 0;
}
