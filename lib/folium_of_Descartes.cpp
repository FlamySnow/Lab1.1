//
// Created by peachy_ash on 15.09.2021.
//
#include "folium_of_Descartes.hpp"

namespace fancyCurve {
    foliumOfDescartes::foliumOfDescartes (double a) {
        if (a <= 0)
            throw invalid_argument("Parameter 'n' must be more than zero");
        n = a;
    }

    foliumOfDescartes& foliumOfDescartes::set_n (double a) {
        if (a <= 0)
            throw invalid_argument("Parameter 'n' must be more than zero");
        n = a;
        return *this;
    }

    double foliumOfDescartes::distanceToCenter (double angle) const {
        if (!correct(angle))
            throw std::invalid_argument("Angle must be from 0 to 2*Pi");
        double c = cos(angle), s = sin(angle);
        double d = c*c*c + s*s*s;
        if (d == 0)
            throw std::invalid_argument("Division by zero!");
        return n * c * s / d;
    }

    void foliumOfDescartes::print() const {
        cout << "x^3 + y^3 = " << n << "xy" << endl;
    }
}