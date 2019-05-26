#include <stdlib.h>  // dynamic memory management

#include "kernel.h"

#define N 200000000

float scale(int i, int n) {
  return ((float)i)/(n-1);
}

int main() {
  const float ref = 0.5f;

  float *in = (float*)calloc(N, sizeof(float));
  float *out = (float*)calloc(N, sizeof(float));

  for (int i = 0; i < N; i++) {
    in[i] = scale(i, N);
  }

  distanceArray(out, in, ref, N);

  free(in);
  free(out);
  return 0;
}
