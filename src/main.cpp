#include <iostream>
#include <format>
#include "input.hpp"
#include <cmath>

int main (){
    
    
    std::cout << "Calculating real roots for a quadratic equation written in form: \n";
    std::cout << "ax^2 + bx + c = 0\n";
    
    double a = cli::prompt_for_double("Please enter a = ");
    double b = cli::prompt_for_double("Please enter b = ");
    double c = cli::prompt_for_double("Please enter c = ");

    if (a == 0){
        std::cout << "The equation collapses into a linear equation, since a = 0. \n";
        if (b == 0){
            std::cout << "The equation has no real roots.\n";
            return 0;
        } else {
            std::cout << "x = " << std::format("{:.2f}\n", c * -1.0 / b);
            return 0;
        }
    }

    double D = b * b - (4 * a * c);

    //std::cout << "[DEBUG] D = " << D << "\n";

    if (D < 0){
        std::cout << "The equation has no real roots.\n";
        return 0;
    } else if (D == 0){
        std::cout << "The equation has one real root.\n";
        std::cout << "x = " << std::format("{:.4f}\n", b * -1 / (2*a));
        return 0;
    } else {
        //std::cout << "[DEBUG] sqrt(D) = " << std::sqrt(D) << "\n";
        //std::cout << "[DEBUG] -b = " << b*(-1) << "\n";
        //std::cout << "[DEBUG] -b + sqrt(D) = " << b*(-1) + std::sqrt(D) << "\n";
        //std::cout << "[DEBUG] -b - sqrt(D) = " << b*(-1) - std::sqrt(D) << "\n";
        std::cout << "The equation has two real roots.\n";
        std::cout << "x1 = " << std::format("{:.4f}\n", (b*-1 + std::sqrt(D)) / (2*a));
        std::cout << "x2 = " << std::format("{:.4f}\n", (b*-1 - std::sqrt(D)) / (2*a));
        return 0;
    }
}