#include <iostream>
# include <cmath>

using namespace std;
int iteracion = 0;

float funcion (float x){ return (4*x-7)/(x-2); }

float metodo(float x1, float x2){
    float num1 = funcion(x1);
    float num2 = funcion(x2);
    float raiz = (x1+x2)/2;
    float raizE = funcion(raiz);

    if (raizE == 0){
        return raiz;
    }

    else if(num1*num2 < 0){
        if(num1 <= 0.00001 && num1 >= -0.00001 && num2>= -0.00001 && num2<= 0.00001){   //ERROR
            return raiz;
        }
        else{
            if (raizE*num1 < 0){
                iteracion++;
                return metodo(x1,raiz);
            }
            else if (raizE*num1 > 0){
                iteracion++;
                return metodo(raiz,x2);
            }
        }
    }
    else{
        cout << "No se encontró la raiz" << endl;
        return -999;
    }
}
