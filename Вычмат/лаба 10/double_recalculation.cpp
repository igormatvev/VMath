#include <iostream>
#include <math.h>
#include <vector>

#define eps 0.0000000001

double f(double x) {
  return 1 / x;
}

double Trapezia(double a, double b, int N, double shag) {
  double S = 0;
  double h = a;
  double array_X;
  for (int i = 0; i <= N; ++i) {
    h += shag;
    S += (f(h) + f(h + shag)) / 2 * shag;
  }
  return S;
}

double Simpson(double a, double b, int N, double shag) {
  double result = 0;
  std::vector<double> array_Y(N);
  double h = a;
  for (int i = 0; i < N + 1; ++i) {
    array_Y[i] = h;
    h += shag;
  }
  for (int i = 2; i <= N; i += 2) {
    result += (array_Y[i] - array_Y[i - 2]) * (f(array_Y[i - 2]) / 6 + 2 * f(array_Y[i - 1]) / 3 + f(array_Y[i]) / 6);
  }
  return result;
}

int main() {
  double a = 1, b = 2;
  int x = 0, N = 10;
  double shag = (b - a) / N;
  double S = Simpson(a, b, N, shag);
  double S1 = 0;

  while (fabs(S - S1) > 15 * eps) {
    S1 = S;
    x++;
    printf("Step = %f\n", shag);
    N *= 2;
    shag = (b - a) / N;
    S = Simpson(a, b, N, shag);
  }
  printf("Simpson's method: %.15f\n", S);
  x = 0;
  std::cout << std::endl;
  N = 10;
  shag = (b - a) / N;
  S = Trapezia(a, b, N, shag);
  S1 = 0;
  while (fabs(S - S1) > 3* eps) {
    S1 = S;
    x++;
    printf("Step = %d\n", x);
    printf("Step = %.10f\n", shag);
    N *= 2;
    shag = (b - a) / N;
    S = Trapezia(a, b, N, shag);
  }
  printf("Trapeze method: %.15f\n", S);
}
