#include "GBMSimulator.hpp"
#include "CallOption.hpp"
#include "PutOption.hpp"
#include "MonteCarloEngine.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

int main()
{
    // Market parameters
    double S0 = 100.0;   // Initial stock price
    double K = 100.0;    // Strike price
    double T = 1.0;      // Time to maturity (1 year)
    double r = 0.05;     // Risk-free rate (5%)
    double sigma = 0.2;  // Volatility (20%)
    int numSteps = 252;  // Number of time steps (daily)
    int numSims = 10000; // Number of simulations

    // Create options
    CallOption callOption(K, T);
    PutOption putOption(K, T);

    // Create Monte Carlo engines
    MonteCarloEngine callEngine(callOption, r, numSims, numSteps);
    MonteCarloEngine putEngine(putOption, r, numSims, numSteps);

    // Calculate option prices
    double callPrice = callEngine.calculate(S0, sigma);
    double putPrice = putEngine.calculate(S0, sigma);

    // Print results
    std::cout << "Monte Carlo Option Pricing Results:\n";
    std::cout << "--------------------------------\n";
    std::cout << "Parameters:\n";
    std::cout << "S0 = " << S0 << " (Initial stock price)\n";
    std::cout << "K  = " << K << " (Strike price)\n";
    std::cout << "T  = " << T << " (Time to maturity)\n";
    std::cout << "r  = " << r << " (Risk-free rate)\n";
    std::cout << "σ  = " << sigma << " (Volatility)\n\n";

    std::cout << "Results:\n";
    std::cout << "Call Option Price: " << std::fixed << std::setprecision(4) << callPrice << "\n";
    std::cout << "Put Option Price:  " << std::fixed << std::setprecision(4) << putPrice << "\n";

    return 0;
}
