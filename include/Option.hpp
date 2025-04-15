#pragma once

class Option
{
public:
    Option(double strike, double maturity)
        : strike_(strike), maturity_(maturity) {}

    virtual ~Option() = default;

    // Pure virtual method for calculating payoff
    virtual double payoff(double ST) const = 0;

    // Getters
    double getStrike() const { return strike_; }
    double getMaturity() const { return maturity_; }

protected:
    double strike_;   // Strike price (K)
    double maturity_; // Time to maturity (T)
};