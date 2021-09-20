#include "../lib/folium_of_Descartes.hpp"
using namespace fancyCurve;

int main() {
    foliumOfDescartes f;
    int a = 0;
    std::cout << "Hello, your folium of Descartes now is: ";
    f.print();
    std::cout << "And you can:" << std::endl;
    do {
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Set new parameter of the folium;" << std::endl;
        std::cout << "2. Get current parameter of the folium;" << std::endl;
        std::cout << "3. Get the side of a square that is equal to the largest chord of the folium;" << std::endl;
        std::cout << "4. Get the distance to center in polar coordinate system based on angle;" << std::endl;
        std::cout << "5. Get the radius of curvature at the top of the folium;" << std::endl;
        std::cout << "6. Get the radius of curvature at the node point;" << std::endl;
        std::cout << "7. Get the square of the loop of the folium;" << std::endl;
        std::cout << "8. Get the length of the largest diameter of the loop;" << std::endl;
        std::cout << "9. Get the distance from the node to the largest diameter;" << std::endl;
        std::cout << "10. Print equation of the folium." << std::endl;
        std::cout << "Please, make your choice: --> ";
        errorType  e;
        e = getNum(a);
        if (e != ok) {
            if (e == incorrect_input)
                std::cout << "Enter numbers only!" << std::endl;
            if (e == eof)
                std::cout << "Seems like it is the end of file." << std::endl;
            a = -1;
            continue;
        }
        double n;
        switch (a) {
            case 1: {
                std::cout << "Enter new parameter of the folium: --> ";
                do {
                    e = getNum(n);
                    if (e == incorrect_input)
                        std::cout << "Enter numbers only!" << std::endl;
                    if (e == eof)
                        std::cout << "Seems like it is the end of file." << std::endl;
                } while (e != ok);
                f.set_n(n);
            }
                break;
            case 2:
                std::cout << "Current parameter of the folium is: --> " << f.get_n();
                break;
            case 3:
                std::cout << "Side of a square is: --> " << f.getSide();
                break;
            case 4: {
                std::cout << "Enter value of angle: --> ";
                do {
                    e = getNum(n);
                    if (e == incorrect_input)
                        std::cout << "Enter numbers only!";
                    if (e == eof)
                        std::cout << "Seems like it is the end of file.";
                } while (e != ok);
                try {
                    std::cout << "Distance to center: --> " << f.distanceToCenter(n);
                }
                catch (std::exception& ex) {
                    std::cout << ex.what();
                }
            }
                break;
            case 5:
                std::cout << "Radius of curvature at the top of the folium: --> " << f.topRadius();
                break;
            case 6:
                std::cout << "Radius of curvature at the node point: --> " << f.nodeRadius();
                break;
            case 7:
                std::cout << "Square of the loop of the folium: --> " << f.squareOfLoop();
                break;
            case 8:
                std::cout << "Length of the largest diameter of the loop: --> " << f.diameterOfLoop();
                break;
            case 9:
                std::cout << "Distance from the node to the largest diameter: --> " << f.distanceToDiameter();
                break;
            case 10:
                f.print();
                break;
            default:;
        }
        std::cout << std::endl;
    } while (a != 0);
    return 0;
}
