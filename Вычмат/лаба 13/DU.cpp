#include <array>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1e-4;
const double H   = 0.1;
const double E   = 2.71828;
const int    N   = 2;

double f(double x, double y0, double y1){
	return (pow(E, x) + y1 + y0) / 3;
}

double RK_time_averaging(double x[N], double y[N], bool isFinal){
	int ind = 1, k;
	double Yh[N], Yh2[N], Y_avg[N];
	double step = H, X, Xh2, a;

	do{
		a = 0;

		if (isFinal){
			cout << "\nStep " << ind++ << "\n" << "h = " << step << "\n\n";
			cout << left << setw(6) << "X"
				 << left << setw(6) << "Y"
				 << left << setw(6) << "Y'\n";
		}

		for (int i = 0; i < N; i++){
			Yh[i] = y[i];
			Yh2[i] = y[i];
		}

		if (isFinal){
			cout << setw(9) << left << x[0]
				 << setw(9) << left << Yh[0]
				 << setw(9) << left << Yh[1] << "\n";
		}

		for (X = x[0]; X < x[1] - step + 1e-7; X += step){
			for (int i = 0; i < N; i++){
				i != N - 1 ? Y_avg[i] = Yh[i] + step / 2 * Yh[i + 1]
					       : Y_avg[i] = Yh[i] + step / 2 * f(X, Yh[0], Yh[1]);
			}

			for (int i = 0; i < N; i++){
				i != N - 1 ? Yh[i] += step * Y_avg[i + 1]
					: Yh[i] += step * f(X + step / 2, Y_avg[0], Y_avg[1]);
			}

			for (Xh2 = X, k = 0; k < 2; k++, Xh2 += step / 2){
				for (int i = 0; i < N; i++){
					i != N - 1 ? Y_avg[i] = Yh2[i] + step / 4 * Yh2[i + 1]
						: Y_avg[i] = Yh2[i] + step / 4 * f(Xh2, Yh2[0], Yh2[1]);
		    }

				for (int i = 0; i < N; i++){
					i != N - 1 ? Yh2[i] += step / 2 * Y_avg[i + 1]
						: Yh2[i] += step / 2 * f(Xh2 + step / 4, Y_avg[0], Y_avg[1]);
				}
			}

			if (fabs(Yh[N - 1] - Yh2[N - 1]) < 3 * EPS)
				a++;

			if (isFinal){
				cout << setw(9) << left << X + step
					 << setw(9) << left << Yh2[0]
					 << setw(9) << left << Yh2[1] << "\n";
			}
		}

		step /= 2;

	} while (a != (x[1] - x[0]) / (2 * step));

	return Yh[0];
}

void shooting(double x[N], double y[N], double y2){
	int i = 1;
	double a = -10, b = 10;


	do{
		cout << "Step " << i++ << ":\t";

		y[N - 1] = (b + a) / 2;

		cout << "[ " << left << setw(9) << a << "; "
			 << left << setw(9) << b << " ] y' = " << y[N - 1] << "\n";

		RK_time_averaging(x, y, 0) > y2 ? b = y[N - 1] : a = y[N - 1];

	} while (!(abs(RK_time_averaging(x, y, false) - y2) < EPS));

	cout << "\n\nCalculation of the differential equation:\n";

	RK_time_averaging(x, y, true);
}

int main(){
	setlocale(LC_ALL, "rus");

	double x[N] = { 0, 1 };
	double y[N] = { 1 };
	double y2 = E;

	shooting(x, y, y2);

	system("pause");
	return 0;
}
