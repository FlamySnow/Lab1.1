#include "../lib/folium_of_Descartes.hpp"
using namespace fancyCurve;

int main() {
    foliumOfDescartes f;
    double n, angle;
    int t = 1;
    while (t) {
        cout << "Equation of the folium of Descartes:" << endl;
        f.print();
        cout << "Parameter of the folium of Descartes: --> " << f.get_n() << endl;
        cout << "Side of square: --> " << f.getSide() << endl;
        cout << "Enter value of angle: --> ";
        do {
            n = getNum(angle);
            if (n != 1)
                cout << "Enter numbers only!" << endl;
        } while (n != 1);
        try{
            cout << "Distance to the center in dependence of angle: --> " << f.distanceToCenter(angle) << endl;
        }
        catch (std::invalid_argument& error) {
            cout << error.what() << endl;
        }
        cout << "Radius of curvature in the top: --> " << f.topRadius() << endl;
        cout << "Radius of curvature in the node: --> " << f.nodeRadius() << endl;
        cout << "Square of the loop: --> " << f.squareOfLoop() << endl;
        cout << "Length of the largest diameter of the loop: --> " << f.diameterOfLoop() << endl;
        cout << "Distance from the node to the largest diameter: --> " << f.distanceToDiameter() << endl;
        cout << "Enter new parameter or some letter to exit: --> ";
        cin >> n;
        if (cin.good()) {
            try {
                f.set_n(n);
            }
            catch (std::invalid_argument& error) {
                cout << error.what() <<  endl;
            }
        }
        else
            t = 0;
    }
    return 0;
}
