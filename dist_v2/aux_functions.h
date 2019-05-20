#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

// A scaling fn to covert integers 0,1,...,N-1 to evently spaced floats ranging
// from 0 to 1.
float scale(int i, int n);

// Distance between two points.
float distance(float x1, float x2);

void distanceArray(float* out, float* in, float ref, int n);

#endif  // AUX_FUNCTIONS_H
