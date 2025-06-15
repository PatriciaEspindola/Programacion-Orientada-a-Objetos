#include <iostream>
#include <string>
#include <vector>
using namespace std;

//interface
class FigGeoPrinter {
    public: 
        virtual void PrintDetails()=0;
};

//clase repo
class Repo {
    public:
        virtual int Save(float area)=0;
        virtual float GetArea (int index)=0;
};

//clase VectorRepo -REPOSITORIO-
class VectorRepo: public Repo {
    vector<float> dataBase;      //vector flotante
    public:
        int Save(float area) override {
        dataBase.push_back(area);
        return dataBase.size()-1;
        } 
        float GetArea(int index) override {
        return dataBase.at(index);
        }
};

//clase abstracta
class FigGeo {
    protected:
        float area;
        Repo * repo;
        int id;
    public:
       virtual float calcArea()=0;
       float getArea(){
           return area;
       }
       void saveArea(){
            if(area==0){
               cout<<"calculando area...\n";
               area=calcArea();
               repo->Save(area);
            }
       }
};
class Circle: public FigGeo, public FigGeoPrinter {
    private:
        float r;
        float PI = 3.1416;
    public:
        float calcArea() override {
            return PI * r * r;
        }
        void PrintDetails() override {
            cout << "Circle: r= "<< r << "area= "<< area<< "\n"; 
        }
        Circle (Repo* repoPtr) {
            r=1;
            area=0;
            repo=repoPtr;
        }
};

//Clase Square
class Square: public FigGeo, public FigGeoPrinter {
    private:
        float width;
    public:
        float calcArea() override {
            return width * width;
        }
        void PrintDetails() override {
            cout << "Square: width= "<< width << "area= "<< area<< "\n"; 
        }
        Square (Repo* repoPtr) {
            width=1;
            area=0;
            repo=repoPtr;
        }
};

//Clase Triangle
class Triangle: public FigGeo, public FigGeoPrinter {
    private:
        float base;
        float height;
    public:
        float calcArea() override {
            return (base * height) / 2;
        }
        void PrintDetails() override {
            cout << "base = " << base << ", height = " << height << ", area = " << area << "\n";
        }
        Triangle (Repo* repoPtr) {
            base=1;
            height=1;
            area=0;
            repo=repoPtr;
        }
};

void Print(FigGeoPrinter& fig) {
    fig.PrintDetails();
}
int main() {
    VectorRepo repoV = VectorRepo();
    Circle crl2=Circle(&repoV);
    Circle crl1=Circle(&repoV);
    crl1.saveArea();
    crl2.saveArea();
    cout<<repoV.GetArea(0)<<"\n";
    cout<<repoV.GetArea(1)<<"\n";
    
    Square sqr2=Square(&repoV);
    Square sqr1=Square(&repoV);
    sqr1.saveArea();
    sqr2.saveArea();
    cout<<repoV.GetArea(2)<<"\n";
    cout<<repoV.GetArea(3)<<"\n";
    
    Triangle tri2=Triangle(&repoV);
    Triangle tri1=Triangle(&repoV);
    tri1.saveArea();
    tri2.saveArea();
    cout<<repoV.GetArea(4)<<"\n";
    cout<<repoV.GetArea(5)<<"\n";
    return 0;
}
