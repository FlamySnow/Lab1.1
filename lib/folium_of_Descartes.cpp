//
// Created by peachy_ash on 15.09.2021.
//
#include "folium_of_Descartes.hpp"

namespace fancyCurve {

    double foliumOfDescartes::distanceToCenter (double angle) const {
        if (!correct(angle))
            throw std::invalid_argument("Angle must be from 0 to 2Pi");
        double c = cos(angle), s = sin(angle);
        double a = c*c*c + s*s*s;
        if (angle == (7 * M_PI / 4) || angle == (3 * M_PI / 4))
            throw std::invalid_argument("Division by zero!");
        double d = n * c * s / a;
        if (d < 0)
            return 0;
        return d;
    }

    void foliumOfDescartes::print() const {
        if (n == 0) {
            std::cout << "x^3 + y^3 = 0" << std::endl;
            return;
        }
        if (n == 1) {
            std::cout << "x^3 + y^3 = xy" << std::endl;
            return;
        }
        std::cout << "x^3 + y^3 = " << n << "xy" << std::endl;
    }
}