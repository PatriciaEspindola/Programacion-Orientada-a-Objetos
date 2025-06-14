#include <iostream>
using namespace std;

// Interfaz para imprimir detalles
class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

// Interfaz para guardar el área
class Storable {
public:
    virtual void storeArea() = 0;
};

// Clase abstracta
class FigGeo {
protected:
    float area;
public:
    virtual float calcArea() = 0;
    float getArea() {
        return area;
    }
    void saveArea() {
        if (area == 0) {
            cout << "calculando area...\n";
            area = calcArea();
        }
    }
};

class Square : public FigGeo, public FigGeoPrinter, public Storable {
    float width;
public:
    Square() {
        width = 1.0;
        area = 0;
    }

    Square(float inData) {
        width = inData;
        area = 0;
    }

    float calcArea() override {
        return width * width;
    }

    void PrintDetails() override {
        cout << "width = " << width << ", area = " << area << "\n";
    }

    void storeArea() override {
        cout << "Área del cuadrado (" << area << ") guardada correctamente.\n";
    }

    float getWidth() {
        return width;
    }

    void setWidth(float value) {
        width = value;
    }
};

class Triangle : public FigGeo, public FigGeoPrinter, public Storable {
    float base;
    float height;
public:
    Triangle() {
        base = 1.0;
        height = 1.0;
        area = 0;
    }

    Triangle(float b, float h) {
        base = b;
        height = h;
        area = 0;
    }

    float calcArea() override {
        return (base * height) / 2;
    }

    void PrintDetails() override {
        cout << "base = " << base << ", height = " << height << ", area = " << area << "\n";
    }

    void storeArea() override {
        cout << "Área del triángulo (" << area << ") guardada correctamente.\n";
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
};

class Circle : public FigGeo, public FigGeoPrinter, public Storable {
    float radius;
public:
    Circle() {
        radius = 1.0;
        area = 0;
    }

    Circle(float r) {
        radius = r;
        area = 0;
    }

    float calcArea() override {
        return 3.1416 * radius * radius;
    }

    void PrintDetails() override {
        cout << "radius = " << radius << ", area = " << area << "\n";
    }

    void storeArea() override {
        cout << "Área del círculo (" << area << ") guardada correctamente.\n";
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
    sqr.PrintDetails();
    sqr.storeArea();

    Triangle tri;
    tri.saveArea();
    tri.PrintDetails();
    tri.storeArea();

    Circle cir;
    cir.saveArea();
    cir.PrintDetails();
    cir.storeArea();

    return 0;
}
