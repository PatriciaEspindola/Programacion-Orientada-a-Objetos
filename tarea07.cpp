#include <iostream>
#include <string>
using namespace std;

//interfase
class FigGeoPrinter {
public:
    virtual void PrintDetails() = 0;
};

//clase abstracta
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

class Circle : public FigGeo, public FigGeoPrinter {
private:
    float r;
    float PI = 3.1416;
public:
    float calcArea() override {
        return PI * r * r;
    }
    void PrintDetails() override {
        cout << "r= " << r << " area= " << area << "\n";
    }
    Circle() {
        r = 1;
    }
    float getR() {
        return r;
    }

    void setR(float value) {
        r = value;
    }
};

class Square : public FigGeo, public FigGeoPrinter {
private:
    float width;
public:
    float calcArea() override {
        return width * width;
    }
    void PrintDetails() override {
        cout << "width= " << width << " area= " << area << "\n";
    }
    Square() {
        width = 1.0;
        area = 0;
    }
    Square(float inData) {
        width = inData;
        area = 0;
    }
    float getWidth() {
        return width;
    }
    void setWidth(float value) {
        width = value;
    }
};


class Triangle : public FigGeo, public FigGeoPrinter {
private:
    float base;
    float height;
public:
    float calcArea() override {
        return (base * height) / 2;
    }
    void PrintDetails() override {
        cout << "base= " << base << " height= " << height << " area= " << area << "\n";
    }
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

class Creator {
public:
    virtual ~Creator() {};
    virtual FigGeo* FactoryMethod() const = 0;
    string SomeOperation() const {
        FigGeo* fig = this->FactoryMethod();
        string result = "Creator: the same creator's code has just worked area= " + to_string(fig->calcArea()) + "\n";
        fig->saveArea();
        return result;
    }
};

class CircleCreator : public Creator {
public:
    FigGeo* FactoryMethod() const override {
        return new Circle();
    }
};

class SquareCreator : public Creator {
public:
    FigGeo* FactoryMethod() const override {
        return new Square();
    }
};


class TriangleCreator : public Creator {
public:
    FigGeo* FactoryMethod() const override {
        return new Triangle();
    }
};

void Print(FigGeoPrinter& fig) {
    fig.PrintDetails();
}

int main() {
    cout << "App: Launched with the CircleCreator.\n";
    Creator* creator = new CircleCreator();
    cout << creator->SomeOperation();
    cout << std::endl;

    cout << "App: Launched with the SquareCreator.\n";
    Creator* creator2 = new SquareCreator();
    cout << creator2->SomeOperation();
    cout << std::endl;

    cout << "App: Launched with the TriangleCreator.\n";
    Creator* creator3 = new TriangleCreator();
    cout << creator3->SomeOperation();

    delete creator;
    delete creator2;
    delete creator3;
    return 0;
}
