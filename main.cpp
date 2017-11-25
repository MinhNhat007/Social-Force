#include <iostream>
#include "pedestrian.h"

using namespace std;

int main()
{
    Pedestrian p1(0,0,1.4,-2.3);
    cout << "Hello world!" << endl;
    cout << "Im new pedestian..." << endl;
    cout << "My position is (" << p1.getPositionX() << "," << p1.getPositionY() << ")" << endl;
    cout << "My velocity is (" << p1.getVelocityX() << "," << p1.getVelocityY() << ")";

    return 0;
}
