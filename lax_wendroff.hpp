//
//  lax_wendroff.hpp
//  lax wendroff
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef lax_wendroff_hpp
#define lax_wendroff_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
vector<double> lax_wendroff(int a, int b, double dx, double dt, int max_t);
double q_true(double x, double t);
double q_0(double x);

#endif /* lax_wendroff_hpp */
