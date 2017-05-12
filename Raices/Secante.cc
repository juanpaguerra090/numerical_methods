#include <iostream>
#include <cmath>


int iteracion = 1;
double funcion(double x){
    return sin(x) -0.25*x +2;
}

float metodo(float x1, float x2){
  std::cout << "Iteraciones: " << iteracion << std::endl;

    float fun1 = funcion(x1);
    float fun2 = funcion(x2);
    float raiz = x1 - (fun1*(x2-x1)/(fun2-fun1));
    float funRaiz = funcion(raiz);

    std::cout << "X" << iteracion << ": " << raiz << std::endl;

    if(funRaiz == 0 || fun1 == 0){
        return raiz;
    }
    else if(funRaiz < 0.0001 && funRaiz > -0.0001){ //ERROR
        return raiz;
        std::cout << "Iteraciones: " << iteracion << std::endl;
    }
    else if(iteracion >= 50){
        std::cout << "No hay raiz, es divergente" <<  std::endl;
        return -1;
    }
    else{
        iteracion++;
        return metodo(raiz,x2);
    }
}
