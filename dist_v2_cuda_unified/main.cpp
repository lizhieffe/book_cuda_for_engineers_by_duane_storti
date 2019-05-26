#include <cuda_runtime_api.h>
#include <cuda.h>
#include <stdlib.h>  // dynamic memory management

#include "kernel.h"

#define N 200000000

int main() {
  const float ref = 0.5f;

  distanceArray(ref, N);
  return 0;
}
