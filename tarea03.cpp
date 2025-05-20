#include <iostream>
using namespace std;

class Square {
    float width;
    float areaValue;

public:
    Square() {
        width = 1.0;
        areaValue = -1;
    }

    Square(float inData) {
        width = inData;
        areaValue = -1;
    }

    float getWidth() {
        return width;
    }

    void setWidth(float value) {
        width = value;
        areaValue = -1; // Reiniciar área cuando se cambia el ancho
    }

    void calcularArea() {
        if (areaValue == -1)
            areaValue = width * width;
    }

    float area() {
        return areaValue;
    }
};

class Triangle {
    float base;
    float height;
    float areaValue;

public:
    Triangle() {
        base = 1.0;
        height = 1.0;
        areaValue = -1;
    }

    Triangle(float b, float h) {
        base = b;
        height = h;
        areaValue = -1;
    }

    float getBase() {
        return base;
    }

    float getHeight() {
        return height;
    }

    void setBase(float b) {
        base = b;
        areaValue = -1;
    }

    void setHeight(float h) {
        height = h;
        areaValue = -1;
    }

    void calcularArea() {
        if (areaValue == -1)
            areaValue = (base * height) / 2;
    }

    float area() {
        return areaValue;
    }
};

class Circle {
    float radius;
    float areaValue;

public:
    Circle() {
        radius = 1.0;
        areaValue = -1;
    }

    Circle(float r) {
        radius = r;
        areaValue = -1;
    }

    float getRadius() {
        return radius;
    }

    void setRadius(float r) {
        radius = r;
        areaValue = -1;
    }

    void calcularArea() {
        if (areaValue == -1)
            areaValue = 3.1416 * radius * radius;
    }

    float area() {
        return areaValue;
    }
};

int main() {
    Square sqr;
    sqr.calcularArea();
    cout << "Square width: " << sqr.getWidth() << " area: " << sqr.area() << "\n";

    sqr.setWidth(5.0);
    sqr.calcularArea();
    cout << "New square width: " << sqr.getWidth() << " area: " << sqr.area() << "\n";

    Square sqr2(10.0);
    sqr2.calcularArea();
    cout << "sqr2 width: " << sqr2.getWidth() << " area: " << sqr2.area() << "\n";

    Triangle tri;
    tri.calcularArea();
    cout << "Triangle base: " << tri.getBase() << ", height: " << tri.getHeight()
         << ", area: " << tri.area() << "\n";

    tri.setBase(6.0);
    tri.setHeight(9.0);
    tri.calcularArea();
    cout << "New triangle base: " << tri.getBase() << ", height: " << tri.getHeight()
         << ", area: " << tri.area() << "\n";

    Triangle tri2(3.0, 2.0);
    tri2.calcularArea();
    cout << "tri2 base: " << tri2.getBase() << ", height: " << tri2.getHeight()
         << ", area: " << tri2.area() << "\n";

    Circle circ;
    circ.calcularArea();
    cout << "Circle radius: " << circ.getRadius() << ", area: " << circ.area() << "\n";

    circ.setRadius(5.0);
    circ.calcularArea();
    cout << "New circle radius: " << circ.getRadius() << ", area: " << circ.area() << "\n";

    Circle circ2(3.0);
    circ2.calcularArea();
    cout << "circ2 radius: " << circ2.getRadius() << ", area: " << circ2.area() << "\n";

    return 0;
}

