# OpenACC Kernels Directive

## Objectives

- [x] You will learn how to create kernels regions and what is its purpose.
- [x] You will learn how to use the **loop** and the **independent** clause 

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

OpenACC give us two possibilities to express parallelism in our applications. the **kernels** and the **parallel** directives. The former relies on the compiler capabilities to parallelize a given región of code (Automatic Paralelization).  The latter relies on the programer capabilities to bring the compiler with the correct directives to parallellize a given región of code (Non-Automatic Parallelization). **This section is dedicated to the kernels directive**.

As follows is described the format to create a *kernels region* using the **kernels** directive.

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

* Comment the following line of your *Makefile*

```make
CFLAGS = -std=c++11 -O3
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

### Feedback

If the code answer is correct we can assume the data was copied to the GPU, processed and get it back to the CPU memory as we expect.

## Exercise 2

The process of parallelization is an incremental process, ie, while you are performing small changes to the code, at the same time you have to test whether or not that change improves the execution time of the code. Experts recommend starting this process with the **kernels** directive. As in some cases this directive may be the definitive solution, in other cases it may not. **The kernels directive parallelize our code, but not in the way we expect, because the execution time does not improve and we got a compiler feedback that suggest what is the real problem.**.

Let's give the compiler more information about our code. 

* Place the **loop** directive with the **independent** clause just above the vector sum loop.

```c
/* Vector sum  */
#pragma acc loop independent
for(...) .....;
```

* Run the code **vector.c**

```bash
make run
```

### Questions

* Is the answer correct?
* Does the execution time improve?
* Why?
* What does the **loop** directive do?
* What does the **independent** clause do?

**Discuss these questions with the speaker**

## Exercise 3

* Place the **loop** directive with the **independent** clause just above the vector multiplication for loop.

```c
/* Vector multiplication  */
#pragma acc loop independent
for(...) .....;
```

* Run the code **vector.c**

```bash
make run
```

### Questions

* Is the answer correct?
* Does the execution time improve?
* Why?

**Discuss these questions with the speaker**