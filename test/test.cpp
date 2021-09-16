//
// Created by peachy_ash on 15.09.2021.
//
#include "../lib/folium_of_Descartes.hpp"
#include "gtest/gtest.h"
using namespace fancyCurve;

TEST(Constructors, DefaultConstructor){
    foliumOfDescartes f;
    ASSERT_EQ(1, f.get_n());
}

TEST(Constructors, InitConstructor){
    foliumOfDescartes f (3);
    ASSERT_EQ(3, f.get_n());
}

TEST(Constructors, TestException){
    ASSERT_ANY_THROW(foliumOfDescartes f (-1));
}

TEST(Methods, Setter){
    foliumOfDescartes f;
    f.set_n(3);
    ASSERT_EQ(3, f.get_n());
}

TEST(Methods, SetterException){
    foliumOfDescartes f;
    ASSERT_ANY_THROW(f.set_n(-1));
}

TEST(Methods, Side){
    foliumOfDescartes f (sqrt(2));
    ASSERT_DOUBLE_EQ(1, f.getSide());
}

TEST(Methods, distanceToCenter){
    foliumOfDescartes f;
    double angle = M_PI;
    ASSERT_NEAR(0, f.distanceToCenter(angle), 0.000001);
}

TEST(Methods, distanceToCenterException1){
    foliumOfDescartes f;
    double angle = 7;
    ASSERT_ANY_THROW(f.distanceToCenter(angle));
}

TEST(Methods, distanceToCenterException2){
    foliumOfDescartes f;
    double angle = 7 * M_PI / 4;
    ASSERT_ANY_THROW(f.distanceToCenter(angle));
}

TEST(Methods, topRadius){
    foliumOfDescartes f;
    ASSERT_NEAR(0.0883883, f.topRadius(), 0.0000001);
}

TEST(Methods, nodeRadius){
    foliumOfDescartes f;
    ASSERT_DOUBLE_EQ(0.5, f.nodeRadius());
}

TEST(Methods, square){
    foliumOfDescartes f;
    ASSERT_NEAR(0.166666667, f.squareOfLoop(), 0.0000001);
}

TEST(Methods, diameter){
    foliumOfDescartes f;
    ASSERT_NEAR(0.321144348, f.diameterOfLoop(), 0.0000001);
}

TEST(Methods, distanceToDiameter){
    foliumOfDescartes f;
    ASSERT_NEAR(0.40824829, f.distanceToDiameter(), 0.0000001);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}