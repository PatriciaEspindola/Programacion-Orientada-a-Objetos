#include <iostream>
using namespace std;

// Clase abstracta
class FigGeo {
protected:
    float area;
public:
    virtual float calcularArea() = 0;
    float getArea() {
        return area;
    }

    void saveArea() {
        if (area == -1) {
            cout << "Calculando área:\n";
            area = calcularArea();
        }
    }
};

class Square : public FigGeo {
    float width;
public:
    float calcularArea() override {
        return width * width;
    }

    Square() {
        width = 1.0;
        area = -1;
    }

    Square(float inData) {
        width = inData;
        area = -1;
    }

    float getWidth() {
        return width;
    }

    void setWidth(float value) {
        width = value;
    }
};

class Triangle : public FigGeo {
    float base;
    float height;
public:
    float calcularArea() override {
        return (base * height) / 2;
    }

    Triangle() {
        base = 1.0;
        height = 1.0;
        area = -1;
    }

    Triangle(float b, float h) {
        base = b;
        height = h;
        area = -1;
    }

    float getBase() {
        return base;
    }

    float getHeight() {
        return height;
    }

    void setBase(float b) {
        base = b;
    }

    void setHeight(float h) {
        height = h;
    }
};

class Circle : public FigGeo {
    float radius;
public:
    float calcularArea() override {
        return 3.1416 * radius * radius;
    }

    Circle() {
        radius = 1.0;
        area = -1;
    }

    Circle(float inData) {
        radius = inData;
        area = -1;
    }

    float getRadius() {
        return radius;
    }

    void setRadius(float value) {
        radius = value;
    }
};

int main() {
    Square sqr;
    sqr.saveArea();
    cout << "Área del cuadrado: " << sqr.getArea() << endl;

    Triangle tri;
    tri.saveArea();
    cout << "Área del triángulo: " << tri.getArea() << endl;

    Circle circ;
    circ.saveArea();
    cout << "Área del círculo: " << circ.getArea() << endl;

    return 0;
}
