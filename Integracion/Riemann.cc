#include <iostream>
#include <cmath>

using namespace std;

float functionX(float x){
    return x + 2;
}

float riemmanIzquierda(float x1, float x2, int division){
    
    float altura;
    float area = 0;
    float diferencial = (x2 - x1)/division;
    float base = diferencial;
    float left = x1;
    float right = left + diferencial;
    
    
    for(int i = 0; i < division ; i++){
        altura = functionX(left);
        area += abs(base*altura);
        left += diferencial;
        right += diferencial;
    }
    
    return area;
}

float riemmanDerecha(float x1, float x2, int division){
    
    float altura;
    float area = 0;
    float diferencial = (x2 - x1)/division;
    float base = diferencial;
    float left = x1;
    float right = left + diferencial;
    
    for(int i = 0; i < division; i++){
        altura = functionX(right);
        area += abs(base*altura);
        left += diferencial;
        right += diferencial;
    }
    
    return area;
}
