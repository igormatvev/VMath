#include <iostream>
#include <iomanip>
#include <math.h>

int n=0;

double function(double x){
	return (x*x)-6;
}

double derivative(double x){
	return 2*x;
}



int main(){
  double  x0 = 3;
	double exp = 0.000000001;
  double a=2,b=3,c=0;
  double x = x0 - function(x0) / derivative(x0);
  double C=0;
  std::cout <<"["<< a<<" ; "<<b<< "]"<< std::endl;

  std::cout << "Newton's method" << std::endl;

  while (abs(x - x0) > exp) {
    x0 = x;
    x = x0 - function(x) / derivative(x);
    n+=1;
    std::cout << "Step numb. " <<n << ": x = " << x  << std::endl;
  }


  n=0;
  std::cout << "MPD" << std::endl;
  while (abs(a - b) > exp) {
    c=(a+b)/2;
    if( function(a)* function(c)>0)
      a=c;
    else
      b=c;
    n+=1;
    std::cout << "Step numb. " <<n << ": x = " << c<<"["<< a<<" ; "<<b<< "]"  << std::endl;
  }

  n=0; a=2,b=3,c=b;
  std::cout << "Chord method:" << std::endl;
  while (abs(c -C) > exp) {
    C=c;
    c=(a*function(b)-b*function(a))/(function(b)-function(a));

    if( function(a)* function(c)>0)
      a=c;
    else
      b=c;
    n+=1;
    std::cout << "Step numb. " <<n << ": x = " << c<<"["<< a<<" ; "<<b<< "]"  << std::endl;
  }
}
