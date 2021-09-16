//
// Created by peachy_ash on 15.09.2021.
//

#ifndef LAB_1_1_FOLIUM_OF_DESCARTES_HPP
#define LAB_1_1_FOLIUM_OF_DESCARTES_HPP
#define _USE_MATH_DEFINES
#include "iostream"
#include "cmath"

using std::cout;
using std::invalid_argument;
using std::cin;
using std::endl;

namespace fancyCurve {
    class foliumOfDescartes {
    private:
        double n; //parameter
    public:
        //constructor
        foliumOfDescartes (double a = 1);
        //setter
        foliumOfDescartes& set_n (double a);
        //getter
        double get_n () const {return n;}
        //return side of square
        double getSide () const {return n / sqrt(2);}
        //return distance to center in dependence of angle
        double distanceToCenter (double angle) const;
        //return radius of curvature in the top of the folium
        double topRadius () const {return n / (8 * sqrt(2));}
        // -//- in the node point
        double nodeRadius () const {return n / 2;}
        //square of loop
        double squareOfLoop () const {return n * n / 6;}
        //the largest diameter of the loop
        double diameterOfLoop () const {return n * sqrt(4 * sqrt(3) - 6) / 3;}
        //distance from the loop to the largest diameter
        double distanceToDiameter () const {return n / sqrt(6);}
        //print equation
        void print () const;
    };

    inline bool correct (double a) {
        return !(a < 0 || a >= 2 * M_PI);
    }

    template <class T>
    int getNum (T &a){
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }
}

#endif //LAB_1_1_FOLIUM_OF_DESCARTES_HPP