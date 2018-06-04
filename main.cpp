#include <iostream>
#include "myclasses.h"
using namespace std;


int main() {

    CColoredLine cl1;
    CPoint dot;
    cl1.set(13,131,42,12);
    cl1.setColor(132,135,23);
    cout << "Color:("<< cl1.get_red() << "," << cl1.get_green() << "," << cl1.get_blue() << ")\n";
    cout << "Line: (" << cl1.get_first_x() << ";" << cl1.get_first_y() << "),(" << cl1.get_last_x() << ";" << cl1.get_last_y() << ")\n\n";
    CPolyLine p1(5);
    p1.show(p1.getHead(),p1.getHead());
    return 0;
}