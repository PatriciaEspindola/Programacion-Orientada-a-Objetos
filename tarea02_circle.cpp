#include <iostream>
#define PI 3.1416
using namespace std;

class Circle {
    float radius;
public:
    Circle() {
        radius = 1.0;
    }

    Circle(float inData) { 
        radius = inData;
    }

    float getRadius() {
        return radius;
    }

    void setRadius(float value) {
        radius = value;
    }

    float area() {
        return PI * radius * radius;
    }
};

int main() {
    Circle c;
    cout << "radius: " << c.getRadius() << " area: " << c.area() << "\n";
    c.setRadius(5.0);
    cout << "new radius: " << c.getRadius() << " area: " << c.area() << "\n";
    Circle c2(10.0);
    cout << "c2 radius: " << c2.getRadius() << " area: " << c2.area() << "\n";

    return 0;
}
