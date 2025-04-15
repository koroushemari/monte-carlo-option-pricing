#pragma once
#include "Option.hpp"
#include <algorithm>

class PutOption : public Option
{
public:
    PutOption(double strike, double maturity)
        : Option(strike, maturity) {}

    // Implement payoff for put option: max(K - ST, 0)
    double payoff(double ST) const override
    {
        return std::max(strike_ - ST, 0.0);
    }
};