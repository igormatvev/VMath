#include <iostream>
#include <iostream>
#include <fstream>
#include <math.h>
const unsigned int X = 3;
const unsigned int Y = 4;
using namespace std;

void print(double arr[X][Y], int h, int w){
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%7.3f",arr[i][j]);
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  double A[X][Y] = {{10 ,-3, 1,-1},{2 ,-10, 3, -4},{4 ,1, 10, 21}};

  double C[X][X]={0,0};
  double B[X]={0};
  double Radical[X]={0};
  double TEMP_in_mass[X]={0};
  double exp = 0.001;
  double N;

  print(A, X, Y);
  for (int i = 0; i < X; i++) {
    double tmp = A[i][i];
    for (int j = 0; j < Y; j++) {
      A[i][j] = A[i][j] / tmp;
    }
  }

  print(A, X, Y);
  for(int i = 0; i < X; i++) {
    for (int j = 0; j < X; j++) {
      if (i != j) {
        C[i][j] = A[i][j];
      }
    }
    B[i] = A[i][Y-1];
  }

  for (int i = 0; i < X; i++) {
    for (int j = 0; j < X; j++) {
      printf("%7.3f",C[i][j]);
    }
    cout << endl;
  }
  cout << "\n\n\n" << endl;


  double maxC = C[0][0];
  double maxB = B[0];

  for(int i = 0;i < X;i++){
    double temp=0;
    for (int j = 0;j < X;j++) {
      temp += abs(C[i][j]);
      if (temp > maxC) {
        maxC = temp;
      }
    }
    if(abs(B[i]) >= maxB) {
      maxB = abs(B[i]);
    }
  }
  cout << maxC << endl;
  N = round(log((exp*(1-maxC))/maxB)/log(maxC)) + 1;

  for(int d = 0; d < N;d++) {

    for (int i = X-1; i > -1; i--){

      for (int j = 0; j < X; j++) {
        TEMP_in_mass[i] += C[i][j] * Radical[j];
      }

    }


    for (int i = 0; i< X; i++) {
      Radical[i] = B[i] - TEMP_in_mass[i];
      TEMP_in_mass[i] = 0;
    }

    cout<< "N = "<< d+1<<endl;
    for(int i = 0;i< X;i++) {
      cout << "x"<<i+1<<"="<< printf("%7.5f",Radical[i])<<endl;
    }
  }
}
