# Parallel Programming Approach

## Objectives

- [x] You will see how a parallel program actually runs on a computer.
- [x] And how many cores does it use.

## Introdution

Parallel programming allow to divide a big task in subtasks that in consequense can be performed in parallel by a parallel computer (PCs, Cluster, Supercomputer).

## Example

This code is the matrix multiplication code, given in a sequential approach. The objective of this example is to parallelize it with OpenMP. After that answer the questions.

Edit the file *matrixmult.c*

* Import the OpenMP funtions header 

```c
#include <omp.h>        /* OpenMP funtions header */
```

* Replace this code

```c
/* C = A x B */
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

* for that one

```c
/* C = A x B */
#pragma omp parallel shared(A,B,C)
{
    #pragma omp for 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
} 
```

* Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```

* Run the following command in one **Terminal**

```bash
htop 
```

Then, run the *matrixmult.c* code in another *Terminal* as follows, and quickly check the **htop command Terminal**

```bash
make run 
```

## Questions

* How many cores this *matrixmult.c* takes to perform its calculation? 
* Is there paralelism?.
* How long does the program take to finish?