#include <iostream>
#include <cmath>

double f(double x); // funcion a derivar
// funcion que calcule la derivada forward
double derivada_forward(double x, double h);
// funcion que calcule la derivada central
double derivada_central(double x, double h);

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  double H = 0.01;
  const double X = M_PI;
  const double EXACT = std::cos(X);
  for (H= 0.1; H>= 1.0e-6; H/=10)
    {
  double error_f = std::fabs((derivada_forward(X, H) - EXACT)/EXACT);
  double error_c = std::fabs((derivada_central(X, H) - EXACT)/EXACT);
  std::cout << H << "\t" << error_f << "\t" << error_c << "\n";
    // cambiar H en valores 0.1, 0.01, 0.001, 1.0e-6, e ir imprimiendo el error 
    }
  // double error_f = std::fabs((derivada_forward(X, H) - EXACT)/EXACT);
  //double error_c = std::fabs((derivada_central(X, H) - EXACT)/EXACT);
  
  // std::cout << H << "\t" << error_f << "\t" << error_c << "\n";
  
  return 0;
}

double derivada_forward(double x, double h)
{
  return (f(x + h) - f(x))/h;
}

double derivada_central(double x, double h)
{
  return (f(x + h/2) - f(x - h/2))/h;
}

double f(double x)
{
  return std::sin(x);
}
