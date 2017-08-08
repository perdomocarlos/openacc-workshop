# OpenACC Parallel Directive

## Objectives

- [x] You will learn to identify some cases where the automatic parallelization (**kernels** directive) is not usefull.
- [x] You will learn to use the **parallel** directive
- [x] You will learn to use the **loop** directive and the **independent** clause 

## Introdution

As mentioned in the [1.kernels](https://github.com/DonAurelio/openacc-workshop/tree/master/1.kernels). OpenACC give us two possibilities to express parallelism in our applications. the **kernels** and the **parallel** directives. **This section is dedicated to the parallel directive**.

When we use the **parallel** directive, the compiler relies on our capabilities to parallelize the code (this is called non aotomatic parallelization). In this way we have to carry out:

1. Send the data to be processed to the GPU memory.
2. When the calculation is finished in GPU, bring the data back to the CPU memory.
3 Check the GPU does what we expect.

## Exercise 1

Veryfy your code runs correctly in a sequential approach.

* Uncomment this line of your make file

```make
CFLAGS = -std=c++11 -O3
```

* Comment these lines

```make
# CFLAGS = -std=c++11 -O3 -acc -ta=tesla:cc30 -Minfo=accel
```

```make
# CFLAGS = -std=c++11 -O3 -acc -ta=tesla:cc30,time -Minfo=accel
```
* Run the *matrixmult.c* code

```bash
make run
```

### Questions

* Take notes of the execution time.
* Take notes of the validation.

## Exercise 2

The purpose of this exercise is to parallelize the matrix multiplication problem. To do this, it is recommended to follow this steps:

1. Identify in the code that región that is intensive computationally.
2. Try to parallelize that section(s) of code with a **kernels región**. 
3. If the code works correctly with **kernels** try to improve its execution time, giving the compiler more information about your code.
4. If the code does not work with **kernels**, try with the parallel directive. adding directives and clauses incrementally until you get the desired result.


Edit the file *matrixmult.c*

* Enclose the following code in a **kernels región** 

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
The part of the code that performs the matrix multiplication is considered to be more expensive computationally.

* Uncomment this line of your make file

```make
# CFLAGS = -std=c++11 -O3 -acc -ta=tesla:cc30 -Minfo=accel
```

* Comment these lines

```make
# CFLAGS = -std=c++11 -O3
```

```make
# CFLAGS = -std=c++11 -O3 -acc -ta=tesla:cc30,time -Minfo=accel
```
* Run the *matrixmult.c* code

```bash
make run
```