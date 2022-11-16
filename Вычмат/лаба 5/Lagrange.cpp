#include <iostream>
#include <cmath>
#define N 4

void Lagrange(double Xp, double x[], double y[]){
	double polinom =0;
	double temp;

	for (int i = 0; i < N; i++){
		temp = 1;
		for (int j = 0; j < N; j++){
			if (i != j)
			temp *= (Xp - x[j])/(x[i] - x[j]);
		}
		polinom += temp * y[i];
	}
  printf ("%f\n", polinom);
}

double function(double x){
	return 1/(x+1);
}

int main(){
  double h = 0;
  double x0=0;
  std::cout << "Enter x:" << std::endl;
  std::cin >> x0;
  std::cout << "Enter h" << std::endl;
  std::cin >> h;
	double x[N];
	double y[N];
  x0 = x0-h;
	for(int i = 0 ; i < N; i++){
    x0 = x0+h;
    x[i] = x0;
  }
	for (int i = 0; i < N; i++){
		y[i] = function(x[i]);
	}
	Lagrange(1, x, y);
}
