//
//  REA_algorithm.hpp
//  REA algorithm
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef REA_algorithm_hpp
#define REA_algorithm_hpp

#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

double q_0(double x);
double u(double r, double x);
double minmod(double a, double b, double c);
vector<double> REA(int a, int b, double dx, double dt, int max_t);



#endif /* REA_algorithm_hpp */
