//
//  MC_limiter.hpp
//  MC limiter
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef MC_limiter_hpp
#define MC_limiter_hpp

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

double q_0(double x);
vector<double> MC_limiter(int a, int b, double dx, double dt, int max_t);

#endif
