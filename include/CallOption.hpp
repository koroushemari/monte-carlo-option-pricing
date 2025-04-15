#pragma once
#include "Option.hpp"
#include <algorithm>

class CallOption : public Option
{
public:
    CallOption(double strike, double maturity)
        : Option(strike, maturity) {}

    // Implement payoff for call option: max(ST - K, 0)
    double payoff(double ST) const override
    {
        return std::max(ST - strike_, 0.0);
    }
};