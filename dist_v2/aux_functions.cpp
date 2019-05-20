#include <math.h>

// A scaling fn to covert integers 0,1,...,N-1 to evently spaced floats ranging
// from 0 to 1.
float scale(int i, int n) {
  return ((float)i)/(n - 1);
}

// Distance between two points.
float distance(float x1, float x2) {
  return sqrt((x2- x1) * (x2 - x1));
}

void distanceArray(float* out, float* in, float ref, int n) {
  for (int i = 0; i < n; ++i) {
    out[i] = distance(in[i], ref);
  }
}
