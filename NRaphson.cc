using namespace std;
#include <iostream>
#include <cmath>

double function(double x){ //Funcion a evaluar
    return (pow(x,3) + 5*x - 10);
}

double dFunction(double x){ // Derivada de la funcion
    return (3*pow(x,2) + 5);
}

double raphson(double x0){
    
}

int main (){
    double x0 = 2.00;
    double x1 = x0 - function(x0)/dFunction(x0); // Formula de Newton-Raphson
    cout << x1;

}


/* 
Finding the f'(x) i.e. the first derivative of f(x) can be difficult if f(x) is complicated.
When f'(xn) tends to zero i.e. the first derivative of f(xn) tends to zero, Newton-Raphson method gives no solution.
Near local maxima or local minima, there is infinite oscillation resulting in slow convergence.
In Newton’s method C program, if the initial guess is far from the desired root, then the method may converge to some other roots.
If root jumping occurs, the intended solution is not obtained.
*/