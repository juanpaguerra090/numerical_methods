using std::cout;
using std::endl;
#include <string>
#include <iostream>
#include <cmath>


float function(float x){
    return (2*pow(x,3))-(5*pow(x,2))+(3*x);
}

float raiz(float x1, float x2){
    
    float left=function(x1);
    float right=function(x2);
    float middle=(x1+x2)/2;

    if(function(middle)==0){
        return middle;
    }
    else if(x1==x2){
        return x1;
    }
    else if(left*right<0){
        if(left>=-0.0000000000000001 && left<=0.0000000000000001 && right>=-0.0000000000000001 && right<=0.0000000000000001){
            return middle;
        }
        else{
            if((left*function(middle))<0){
                return raiz(x1,middle);
            }
            else if((function(middle)*right)<0){
                return raiz(middle,x2);
            }
        }
        std::cout « " yup. ";
    }
    else{
        std::cout « std::endl « " Intersection not found. There might be more than 1.";
        return -999;
    }
}

int main() {
    std::cout « " Hello World!" « std::endl
    std::cout  « std::endl « "raiz = " « raiz(0,2);
}