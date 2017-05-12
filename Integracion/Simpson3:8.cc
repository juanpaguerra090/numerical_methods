#include <iostream>
#include <cmath>

double funcion(double x){ 
    return x+2;    //Aqui va la funcion 
}


double Simpson3_8(){
    
    double x[] = {0,0.2,0.4,0.6,0.8};
    int tamano = sizeof(x)/sizeof(double);
    double b = x[tamano-1];
    double a = x[0];
    
    double area = (b-a)*((funcion(a)+3*funcion(x[1])+3*funcion(x[2])+funcion(b))/8);
    
    return area;
}
