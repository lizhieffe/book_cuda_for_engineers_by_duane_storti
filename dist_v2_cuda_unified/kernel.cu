#include <iostream>
#include <stdio.h>

#include "kernel.h"

#define TPB 64

__device__
float distance(float x1, float x2) {
  return sqrt((x2-x1)*(x2-x1));
}

__global__
void distanceKernel(float *d_out, float *d_in, float ref) {
  const int i = blockIdx.x*blockDim.x + threadIdx.x;
  const float x = d_in[i];
  d_out[i] = distance(x, ref);
  // printf("i = %2d: dist from %f to %f is %f.\n", i, ref, x, d_out[i]);
}

float scale(int i, int n) {
  return ((float)i)/(n-1);
}

void distanceArray(float ref, int len) {
    int dev = 0;
        cudaDeviceProp devProp;
            cudaGetDeviceProperties(&devProp, dev);
                std::cout << "使用GPU device " << dev << ": " << devProp.name << std::endl;
                    std::cout << "SM的数量：" << devProp.multiProcessorCount << std::endl;
                        std::cout << "每个线程块的共享内存大小：" << devProp.sharedMemPerBlock / 1024.0 << " KB" << std::endl;
                            std::cout << "每个线程块的最大线程数：" << devProp.maxThreadsPerBlock << std::endl;
                                std::cout << "每个EM的最大线程数：" << devProp.maxThreadsPerMultiProcessor << std::endl;
                                    std::cout << "每个EM的最大线程束数：" << devProp.maxThreadsPerMultiProcessor / 32 << std::endl;


  float *in = NULL;
  float *out = NULL;

  cudaMallocManaged(&in, len * sizeof(float));
  cudaMallocManaged(&out, len * sizeof(float));

  for (int i = 0; i < len; i++) {
    in[i] = scale(i, len);
  }

  distanceKernel<<<len/TPB, TPB>>> (out, in, ref);
  cudaDeviceSynchronize();

  cudaFree(in);
  cudaFree(out);
}
