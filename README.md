# Finite-Volume-Methods
Numerical solvers for 1-dimensional advection equations implemented in Matlab and C++. The uwpind, Lax-Wendorff, and MC limiter methods are used to solve
the following problem:


<a href="https://www.codecogs.com/eqnedit.php?latex=q_t&plus;q_x=0&space;\:\:\:\:\:\:&space;\text{for}&space;0<x<50,&space;t>0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?q_t&plus;q_x=0&space;\:\:\:\:\:\:&space;\text{for}&space;0<x<50,&space;t>0" title="q_t+q_x=0 \:\:\:\:\:\: \text{for} 0<x<50, t>0" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=q(x,0)&space;=&space;q_0(x)&space;\:\:\:\:\:\;&space;\text{for}&space;\:\:0\leq&space;x&space;\leq&space;50" target="_blank"><img src="https://latex.codecogs.com/gif.latex?q(x,0)&space;=&space;q_0(x)&space;\:\:\:\:\:\;&space;\text{for}&space;\:\:0\leq&space;x&space;\leq&space;50" title="q(x,0) = q_0(x) \:\:\:\:\:\; \text{for} \:\:0\leq x \leq 50" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=q(0,t)&space;=&space;1&space;\:\:\:\:\:\:&space;\text{for}\:\;&space;t>0," target="_blank"><img src="https://latex.codecogs.com/gif.latex?q(0,t)&space;=&space;1&space;\:\:\:\:\:\:&space;\text{for}\:\;&space;t>0," title="q(0,t) = 1 \:\:\:\:\:\: \text{for}\:\; t>0," /></a>

where

<a href="https://www.codecogs.com/eqnedit.php?latex=q_0(x)&space;=&space;\begin{cases}&space;1,&&space;\text{if}\:\:\:x\leq&space;1\\&space;0,&\text{otherwise}\end{cases}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?q_0(x)&space;=&space;\begin{cases}&space;1,&&space;\text{if}\:\:\:x\leq&space;1\\&space;0,&\text{otherwise}\end{cases}" title="q_0(x) = \begin{cases} 1,& \text{if}\:\:\:x\leq 1\\ 0,&\text{otherwise}\end{cases}" /></a>

Finite volume methods compute the "density" ,Q, using the fluxes at the cell edge:

<a href="https://www.codecogs.com/eqnedit.php?latex=Q_i^{n&plus;1}&space;=&space;Q_i^n&plus;\frac{\Delta&space;t}{\Delta&space;x}(F_{i&plus;1/2}-F_{i-1/2})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Q_i^{n&plus;1}&space;=&space;Q_i^n&plus;\frac{\Delta&space;t}{\Delta&space;x}(F_{i&plus;1/2}-F_{i-1/2})" title="Q_i^{n+1} = Q_i^n+\frac{\Delta t}{\Delta x}(F_{i+1/2}-F_{i-1/2})" /></a>

The term density is used to describe the amount of whatever substance we are trying to model. Below are the results:


Upwind:

![hw2fig1](https://user-images.githubusercontent.com/40212726/49548173-bd097b00-f899-11e8-97c5-590d9a103315.png)

Lax Wendroff:

![mth654hw3fig1](https://user-images.githubusercontent.com/40212726/49548222-df02fd80-f899-11e8-87f0-cc938ae21288.png)

MC limiter:

![mth654hw3fig2](https://user-images.githubusercontent.com/40212726/49548244-f0e4a080-f899-11e8-8471-6eb1c7da7f9f.png)
