#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <omp.h>
int main()
{
    float *m1,*m2,*r;
    int n=1024;
    m1=(float *)malloc(sizeof(float)*n*n);
    m2=(float *)malloc(sizeof(float)*n*n);
    r=(float *)malloc(sizeof(float)*n*n);
    for (int i = 0 ; i<(n*n);i++){
        m1[i]=i;
        m2[i]=i*2;
        r[i]=0;
    }
    printf("Multiplying 1024x1024 matrices (1 Billion operations)...\n");
    double start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0 ; i<n ; i++){
        for (int k = 0 ; k<n ; k++){
            float m1_v=m1[(i*n)+k];
            for (int j = 0 ; j<n ; j++){
                r[(i*n)+j] = r[(i*n)+j] + (m1_v*m2[(k*n)+j]);
            }
        }
    }
    double end = omp_get_wtime();
    printf("Done! Time taken: %f seconds\n", end-start);
    printf("Sanity Check: %f\n", r[n]);
    free(m1);
    free(m2);
    free(r);
    
    return 0;
}