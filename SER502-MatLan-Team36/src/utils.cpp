#include "utils.h"
#include <iostream>

double stringToDouble(const std::string& str) {
    try {
        return std::stod(str);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid number format: " << str << std::endl;
        return 0.0;
    }
}
