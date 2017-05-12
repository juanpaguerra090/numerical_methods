#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;
void regresionPolinomial(double*x, double*y, int n){

 const int grado = 2;
 double matrix[grado+1][grado+1];
 double solutions[grado+1];

 double sumX = 0;
 double sumXY = 0;

    for (int i = 0; i < grado+1; ++i)
 {

  sumXY = 0;
  for (int k = 0; k < n; ++k)
  {
   sumXY += pow(x[k],i)*y[k];
  }
  solutions[i] = sumXY;

  for (int j = 0; j < grado+1; ++j)
  {
   if (i == 0 && j == 0)
   {
    matrix[i][j] = n;
   }else{
    sumX = 0;
    for (int k = 0; k < n; ++k)
    {
     sumX += pow(x[k],(j+i));
    }

    matrix[i][j] = sumX;
   }

   cout << matrix[i][j] << ", ";
  }
  cout << "= " << solutions[i] << endl;
 }

 int size = grado +1;
 double EPSILON = 0.0000001;

 double S[size];
 double OS[size];
 double E[size];
 for (int i = 0; i < size; ++i)
 {
  S[i] = 0;
  OS[i] = 0;
  E[i] = 0;
 }

 bool errorCheck = false;

 int counter=0;
 
 while(!errorCheck){
  for (int i = 0; i < size; ++i)
  {
   double sum = 0;
   for (int j = 0; j < size; ++j)
   {
    if (j != i)
    {
     sum += matrix[i][j]*S[j];
    }
   }
   OS[i] = S[i];
   S[i] = (solutions[i] - sum)/matrix[i][i];

   E[i] = (S[i]-OS[i]);
     }

  for (int i = 0; i < size; ++i)
  {
   if(abs(E[i]) > EPSILON){
    break;
   }
   errorCheck = true;
  }
  counter++;
 }

 for (int i = 0; i < size; ++i)
 {
  cout  << " a" << i << ": " << S[i] << endl;
 }
 cout << "it took " << counter << " times to terminate" << endl;

 for (int i = size-1; i >= 1; --i)
 {
  cout << S[i] << "X^"<< i << " + ";
 }
 cout << S[0] << endl;

 double e2[n];
 for (int i = 0; i < n; ++i)
 {
  double Ycalculada = 0;
  for (int j = size-1; j >= 1; --j)
  {
   Ycalculada += S[j]*(pow(x[i], j));
  }
  Ycalculada += S[0];
  e2[i] = pow(y[i]-Ycalculada,2);
 }

 double sr = 0;
 double sumY = solutions[0];
 double st = 0;
 for (int i = 0; i < n; ++i)
 {
  sr += e2[i];
  st += pow(y[i] - (sumY/n),2);
 }
 cout << "Sr: " << sr << endl;

 double sxy = sqrt(sr/(n-size));
 cout << "St: " << st << endl;

 double r2 = (st-sr)/st;
 double r = sqrt(r2);
 cout << "Error Estandar (Sx/y): " << sxy << endl;
 cout << "Coeficiente de determinacion (r2): " << r2 << endl;
 cout << "Coeficiente de correlacion (r): " << r << endl;
 cout << endl;
}
