#include <iostream>
using namespace std;

class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

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

class Square : public FigGeo, public FigGeoPrinter {
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

    float getWidth() {
        return width;
    }

    void setWidth(float value) {
        width = value;
    }
};

class Triangle : public FigGeo, public FigGeoPrinter {
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

class Circle : public FigGeo, public FigGeoPrinter {
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

    float getRadius() {
        return radius;
    }

    void setRadius(float value) {
        radius = value;
    }
};

int main() {
    // AQUI SE USAN LOS PUNTEROS 
    Square* sqr = new Square();
    sqr->saveArea();
    sqr->saveArea();
    sqr->PrintDetails();

    Triangle* tri = new Triangle();
    tri->saveArea();
    tri->PrintDetails();

    Circle* cir = new Circle();
    cir->saveArea();
    cir->PrintDetails();

    // Para liberar espacio de memoria
    delete sqr;
    delete tri;
    delete cir;

    return 0;
}
