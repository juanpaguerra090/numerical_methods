#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double LaGrange( int i, double x_incognita, double *x, int n ) {
    int j = 0;
    double val = 1;
    while ( j < n ) {
        if ( i != j ) {
            val *= ( x_incognita - x[j] ) / ( x[i] - x[j] );
        }
        j++;
    }
    return val;
}
double f( double *y, double *x, double x_incognita, int n ) {
    int i = 0;
    double val = 0;
    while ( i < n ) {
        val += LaGrange( i, x_incognita, x, n ) * y[i];
        i++;
    }
    return val;
}
void interpolacionLagrange() {
    double y[] = {14.621, 11.843, 9.870, 8.418, 7.305, 6.413};
    double x[] = {0,8,16,24,32,40};
    int n = sizeof( y ) / sizeof(double);
    double x_incognita = 27;
    cout << "O(27)= " << f( y, x, x_incognita, n ) << endl;;
}
