# OpeACC Kernels Directive

## Objectives

- [x] You will learn how to use the Kernels directive and what is its purpose.

## Introdution

OpenACC works with the same format as OpenMP does

```c
#pragma omp directive-name clauses..
```

in OpenACC

```c
#pragma acc directive-name clauses..
```

However, OpenMP creates code to be executed in CPU and OpenACC to both CPU and GPU. When we program in GPU platforms we must to care about:

* Send the data to be processed to the GPU memory.
* When the calculation is finished in GPU, bring the data back to the CPU memory.
* Check the GPU does what we expect.

OpenACC give us two possibilities to express parallelism in our applications. the **kernels** and the **parallel** directives. The former relies on the compiler capabilities to parallelize a given región of code (Automatic Paralelization).  The latter relies on the programer capabilities to bring the compiler with the correct directives to parallellize a given región of code. **This section is dedicated to the kernels directive**. The kernels región has the follwing format:


```c
#pragma acc kernels
{
	// Code to be parallelized here ..
}
```

## Exercise 1

* Run the code *vector.c*, take notes of the execution time and valiation.

```bash
make run
```

* Enclose the following section of code in a **kernels region**.

```c
/* Vector sum  */
for(int j=0; j<N; ++j) C[j] = A[j] + B[j];

/* Vector multiplicaion */
for(int j=0; j<N; ++j) D[j] = A[j] * B[j];
```

* Uncomment the following line of your *Makefile*

```make
CFLAGS = -std=c++11 -O3 -acc -ta=tesla:cc30,time -Minfo=accel
```

* Run the code **vector.c**

```bash
make run
```

### Questions

* Is the answer correct?
* Does the execution time improve?
* Why not?
* Was the code parallelized?

**Discuss these questions with the speaker**