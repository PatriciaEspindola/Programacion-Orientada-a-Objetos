#include <iostream> 
using namespace std;

class Triangle {
    float base;
    float height;
public:
    Triangle() {
        base = 1.0;
        height = 1.0;
    }

    Triangle(float inBase, float inHeight) {
        base = inBase;
        height = inHeight;
    }

    float getBase() {
        return base;
    }

    float getHeight() {
        return height;
    }

    void setBase(float value) {
        base = value;
    }

    void setHeight(float value) {
        height = value;
    }

    float area() {
        return (base * height) / 2;
    }
}; 

int main() {
    Triangle tri;
    cout << "base: " << tri.getBase() << " height: " << tri.getHeight() << " area: " << tri.area() << "\n";

    tri.setBase(6.0);
    tri.setHeight(10.0);
    cout << "new base: " << tri.getBase() << " new height: " << tri.getHeight() << " area: " << tri.area() << "\n";

    Triangle tri2(12.0, 9.0);
    cout << "tri2 base: " << tri2.getBase() << " height: " << tri2.getHeight() << " area: " << tri2.area() << "\n";

    return 0;
}
