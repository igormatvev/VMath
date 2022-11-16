#include <iostream>
#include <iomanip>
#include <cmath>

const double ratio = (sqrt(5) + 1) / 2;

double f(double x){
	return pow(x, 2) - 4 * x;
}

int main(){
	int count = 1;
	double a = 0, b = 6;
	double eps = 1e-4;
	double x1 = b - (b - a) / ratio, x2 = a + (b - a) / ratio;

	double f1 = f(x1), f2 = f(x2);

	std::cout.precision(6);
	while (fabs(b - a) / 2 > eps){
		std::cout << "Iteration: " << count << "\n";
		std::cout << "a  = " << a << "\tb  = " << b << "\n";
		std::cout << "x1 = " << x1 << "\t" << "x2 = " << x2 << "\n";

		if (f1 <= f2){
			f2 = f1;
			b = x2;
			x2 = x1;
			x1 = a + (b - x2);
			f1 = f(x1);
		}
		else{
			f1 = f2;
			a = x1;
			x1 = x2;
			x2 = b - (x1 - a);
			f2 = f(x2);
		}

		std::cout << "F(x) = " << f((a + b) / 2) << "\n";
		std::cout << "x    = " << (a + b) / 2 << "\n\n";

		count++;
	}

	system("pause");
	return 0;
}
