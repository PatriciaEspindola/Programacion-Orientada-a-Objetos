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
    Triangle(float b, float h) { 
        base = b; 
        height = h; 
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

    float area() { 
        return (base * height) / 2; 
    } 

};  

class Circle { 
    float radius; 
    
public: 
    Circle() { 
        radius = 1.0; 
    } 

    Circle(float r) { 
        radius = r; 
    } 

    float getRadius() { 
        return radius; 
    } 

    void setRadius(float r) { 
        radius = r; 
    } 

    float area() { 
        return 3.1416 * radius * radius; 
    } 

}; 

int main() { 
    Triangle tri; 
    cout << "Triangle base: " << tri.getBase() << ", height: " << tri.getHeight() 
         << ", area: " << tri.area() << "\n"; 
    tri.setBase(6.0); 
    tri.setHeight(9.0); 
    cout << "New triangle base: " << tri.getBase() << ", height: " << tri.getHeight() 
         << ", area: " << tri.area() << "\n"; 
    Triangle tri2(3.0, 2.0); 
    cout << "tri2 base: " << tri2.getBase() << ", height: " << tri2.getHeight() 

         << ", area: " << tri2.area() << "\n"; 

    Circle circ; 
    cout << "Circle radius: " << circ.getRadius() << ", area: " << circ.area() << "\n"; 
    circ.setRadius(5.0); 
    cout << "New circle radius: " << circ.getRadius() << ", area: " << circ.area() << "\n"; 
    Circle circ2(3.0); 
    cout << "circ2 radius: " << circ2.getRadius() << ", area: " << circ2.area() << "\n"; 

    return 0; 

} 
