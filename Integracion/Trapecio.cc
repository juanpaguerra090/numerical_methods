#include <iostream>
#include <cmath>

double funcion(double x){ 
    return x+2;
}

double reglaTrapecio(int noX,double a, double b){
    double base = b-a;
    double baseDiv = base/noX;
    
    double sumaX = a;
    double sumatoria = 0;
    for(int i=1;i<noX;i++){
        sumaX += baseDiv;
        sumatoria += funcion(sumaX);
    }
    
    double area = (b-a)*((funcion(a) + 2*sumatoria + funcion(b))/(2*noX));
    
    return area;
}
