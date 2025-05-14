#include <iostream>
using namespace std;

// Funcion para area del circulo
float areaCirculo(float radio) {
    float pi = 3.1416;
    return pi * radio * radio;
}

// Funcion area de cuadrado
float areaCuadrado(float lado) {
    return lado * lado;
}

// Funcion area del triángulo
float areaTriangulo(float base, float altura) {
    return (base * altura) / 2;
}

int main() {
    // valores
    float radio = 7.0;
    float lado = 10.0;
    float base = 6.0;
    float altura = 3.0;

    // Resultados
    cout << "Área del círculo: " << areaCirculo(radio) << endl;
    cout << "Área del cuadrado: " << areaCuadrado(lado) << endl;
    cout << "Área del triángulo: " << areaTriangulo(base, altura) << endl;

    return 0;
}
