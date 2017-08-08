# OpenACC Parallel Directive

## Objectives

- [x] You will learn to identify some cases where the automatic parallelization (**kernels** directive) is not usefull.
- [x] You will learn to use the **parallel** directive
- [x] You will learn to use the **loop** directive and the **independent** clause 

## Introdution

As mentioned in the [1.kernels](https://github.com/DonAurelio/openacc-workshop/tree/master/1.kernels). OpenACC give us two possibilities to express parallelism in our applications. the **kernels** and the **parallel** directives. **This section is dedicated to the parallel directive**.

* Send the data to be processed to the GPU memory.
* When the calculation is finished in GPU, bring the data back to the CPU memory.
* Check the GPU does what we expect.

OpenACC give us two possibilities to express parallelism in our applications. the **kernels** and the **parallel** directives. The former relies on the compiler capabilities to parallelize a given región of code (Automatic Paralelization).  The latter relies on the programer capabilities to bring the compiler with the correct directives to parallellize a given región of code (Non-Automatic Parallelization). **This section is dedicated to the kernels directive**.

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