//
// Created by peachy_ash on 15.09.2021.
//

#ifndef LAB_1_1_FOLIUM_OF_DESCARTES_HPP
#define LAB_1_1_FOLIUM_OF_DESCARTES_HPP
#include "iostream"
#include "cmath"
#include <cstdlib>

typedef enum {
    ok,
    incorrect_input,
    eof
} errorType;

namespace fancyCurve {
    class foliumOfDescartes {
    private:
        double n; //parameter
    public:
        //constructor
        explicit inline foliumOfDescartes (double a = 1) {n = a;};
        //setter
        inline foliumOfDescartes& set_n (double a) {n = a; return *this;};
        //getter
        [[nodiscard]] inline double get_n () const {return n;}
        //return side of square
        [[nodiscard]] inline double getSide () const {return fabs(n / sqrt(2));}
        //return distance to center in dependence of angle
        [[nodiscard]] double distanceToCenter (double angle) const;
        //return radius of curvature in the top of the folium
        [[nodiscard]] inline double topRadius () const {return fabs(n / (8 * sqrt(2)));}
        // -//- in the node point
        [[nodiscard]] inline double nodeRadius () const {return fabs(n / 2);}
        //square of loop
        [[nodiscard]] inline double squareOfLoop () const {return n * n / 6;}
        //the largest diameter of the loop
        [[nodiscard]] inline double diameterOfLoop () const {return fabs(n * sqrt(4 * sqrt(3) - 6) / 3);}
        //distance from the loop to the largest diameter
        [[nodiscard]] inline double distanceToDiameter () const {return fabs(n / sqrt(6));}
        //print equation
        void print () const;
    };

    inline bool correct (double a) {
        return !(a < 0 || a >= 2 * M_PI);
    }

    template <class T>
    errorType getNum (T &a){
        std::cin >> a;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return incorrect_input;
        }
        if (std::cin.eof())
            return eof;
        return ok;
    }
}

#endif //LAB_1_1_FOLIUM_OF_DESCARTES_HPP