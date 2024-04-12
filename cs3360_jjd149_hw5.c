#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

#define NUM_INTEGERS 1000000
int NUM_MODULUS= 1000;

int main() {
  struct timeval start, end;
  int i, j, k,p,m, threads_count;
  int *arr = (int *) malloc(NUM_INTEGERS * sizeof(int));
  double elapsed_time,speedUp;
  double speed[4][4];
  double temp[4];

  // Seed the random number generator
  srand(12345);

  for (j = 0; j < NUM_INTEGERS; j++) {
        arr[j] = rand();
  }

  for (p = 0; p<=4;p++){
      m=0;
      for (threads_count = 1; threads_count <= 16; threads_count *= 2) {
          // Compute modulus
          gettimeofday (&start, NULL);
          #pragma omp parallel for num_threads(threads_count)
          for (j = 0; j < NUM_INTEGERS; j++) {
              for (k = 1; k <= NUM_MODULUS; k++) {
                  arr[j] % k;
              }
          }
          gettimeofday (&end, NULL);
          elapsed_time = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0);
          speed[p][m]= elapsed_time;
          m++;
      }

  }
  free(arr);
  for (p = 0; p<=4;p++){
      for (m = 0; m<=4;m++){
          temp[m] += speed[p][0]/speed[p][m];
      }

  }
  for (p = 0; p<=4;p++){
      temp[p] = temp[p]/5;
  }
  p=0;

  for (threads_count = 1; threads_count <= 16; threads_count *= 2){
      printf("SpeedUp for %d threads: %f percent\n", threads_count,temp[p]);
      p++;
  }
  return 0;
}
