#include <iostream>
#include <stdlib.h>  // dynamic memory management

#include "aux_functions.h"

#define N 20000000

int main() {
  float *in = (float*)calloc(N, sizeof(float));
  float *out = (float*)calloc(N, sizeof(float));
  float ref = 0.5f;

  for (int i = 0; i < N; ++i) {
    in[i] = scale(i, N);
  }

  distanceArray(out, in, ref, N);

  free(in);
  free(out);
  return 0;
}

