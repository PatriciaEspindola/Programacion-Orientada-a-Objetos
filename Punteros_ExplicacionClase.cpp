#include <iostream>
using namespace std;

int main()
{
    int *v1=nullptr;
    int value=4;
    v1=&value;
    cout<< v1 << "\n";
    cout << *v1 << endl;
    
    //v1++;
    //cout<< v1 << "\n";
    //cout << *v1 << endl;
    
    //apunta y manda el valor de value incrementado
    (*v1)++;
    cout << *v1 << endl;
    cout << value << "\n";
    
    //declarar puntero con valor asignado
    int *v2 = new int(2);
    cout<< v2 << endl;
    cout << *v2 << endl;
    return 0;
}
