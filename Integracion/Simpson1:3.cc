#include <iostream>
#include <cmath>

double funcion(double x){ 
    return x+2;    //Aqui va la funcion 
}

double Simpson1_3Simple(){
    
    double b = 0.8;
    double a = 0;
    double xMedia = 0.4;
    
    //Normal
    double area = (b-a)*((funcion(a)+4*funcion(xMedia)+funcion(b))/6);
    
    return area;
}

double reglaSimpson1_3Mult(){
    
    double x[] = {0,0.2,0.4,0.6,0.8};
    int tamano = sizeof(x)/sizeof(double);
    
    double b = x[tamano-1];
    double a = x[0];
    
    double sumatoriaI =0.0;
    double sumatoriaP =0.0;
    
    for(int i=1;i<tamano-1;i+=2){
        sumatoriaI += funcion(x[i]);
    }
    for(int j=2;j<tamano-2;j+=2){      //pares
        sumatoriaP += funcion(x[j]);
    }
    
    
    return area;
}
