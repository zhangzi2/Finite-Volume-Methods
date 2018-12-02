//
//  Header.h
//  upwind
//
//  Created by Kevin Zhang on 11/30/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef upwind_h
#define upwind_h

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

double q_0(double x);
double q_true(double x, double t);
vector<double> upwind(int a, int b, double dx, double dt, int max_t);

#endif /* Header_h */
