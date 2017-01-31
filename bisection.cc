using namespace std;
#include <iostream>
#include <cmath>

float function (float x){
    return (2*pow(x,4) + pow(x,3) - 8*pow(x,2) - x + 6)/(x+2);
}

float root(float x1, float x2){
    float l = function(x1);
    float r = function(x2);
    float mid = (x1+x2)/2;
    
    if (function(mid)==0){
        return mid;
    }
    
    else if(x1==x2){
        return x1;
    }
    
    else if (l*r<0){
        if (l >= -.0000000000001 && l <= .0000000000001 && r >= -.0000000000001 && r <= .0000000000001){
            return mid;
        } 
        else{
            if(l*function(mid)<0){
                return root(x1, mid);
            }
            else if((function(mid)*r)<0){
                return root(mid, x2);
            }
        }
        std::cout<< ": yup";
    }
    else{
        std::cout << std::endl <<"intersection not found, there must be more than 1";
        return -1;
    }
}

int main (){
    std::cout << std::endl << "root: "<< root(-4,0);
}