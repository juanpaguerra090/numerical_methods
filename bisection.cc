using namespace std;
#include <iostream>
#include <cmath>

 int iteration; // Variable para contar el numero de iteraciones realizadas

double function (double x){ //
    return (2*pow(x,2)+3*x);
}

double bisection(double x1, double x2){
    double l = function(x1);
    double mid = (x1+x2) * .5;
    double r = function(x2);

// condition ? value_if_true : value_if_false 


    if (function(mid)==0){
        return mid;
    }
    
    else if(x1==x2){
        return x1;
    }
    
    else if (l*r<0){
        if (l >= -.0000000000001 && l <= .0000000000001 && r >= -.0000000000001 && r <= .0000000000001){
            //std::cout<< "Iteration Number: "+ iteration;
            return mid;
        } 
        else{
            if(l*function(mid)<0){
                //iteration++;
                //std::cout<< "Iteration Number: ";
                //std::cout<< iteration;
                return bisection(x1, mid);
            }
            else if((r*function(mid))<0){
                //iteration++;
                //std::cout<< "Iteration Number: ";
                //std::cout<< iteration;
                return bisection(mid, x2);
            }
        }
        std::cout<< "";
    }
    else{
        std::cout << std::endl <<"No root found. Function might not be continous. \n";
        return -1.00;
    }
}

int main (){
    std::cout << "Results: \n ";
    std::cout << "X1: "<< bisection(-3,0);
}