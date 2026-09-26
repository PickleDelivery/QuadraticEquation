#ifndef QUADRATIC_EQUATION_INPUT_HPP
#define QUADRATIC_EQUATION_INPUT_HPP

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace cli {

inline double prompt_for_double(const std::string& prompt)
{
    std::string line;
    double value;

    while (true) {
        std::cout << prompt;

        if (!std::getline(std::cin, line)) {
            throw std::runtime_error("No input available while reading a number.");
        }

        std::istringstream input(line);
        char extra;
        if (input >> value && !(input >> extra) && std::isfinite(value)) {
            return value;
        }

        std::cout << "Please enter a valid finite number.\n";
    }
}

}

#endif