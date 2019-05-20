#include <iostream>
#include <math.h>

#define N 64

// A scaling fn to covert integers 0,1,...,N-1 to evently spaced floats ranging
// from 0 to 1.
float scale(int i, int n) {
  return ((float)i)/(n - 1);
}

// Distance between two points.
float distance(float x1, float x2) {
  return sqrt((x2- x1) * (x2 - x1));
}

int main() {
  float out[N] = {0.0f};
  float ref = 0.5f;
  for (int i = 0; i < N; ++i) {
    float x = scale(i, N);
    out[i] = distance(x, ref);
  }
  for (int i = 0; i < N; i++) {
    std::cout << out[i] << ", ";
  }
  std::cout << std::endl;
}
