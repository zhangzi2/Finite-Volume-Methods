//
//  lax_wendroff.cpp
//  lax wendroff
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "lax_wendroff.hpp"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double q_0(double x){
    double q_0;
    if (x<=1){q_0=1.0;}
    else{q_0=0.0;}
    return q_0;
}


vector<double> lax_wendroff(int a, int b, double dx, double dt, int max_t){
    double nu = dt/dx;
    
    vector<double> space;
    for (int j=0; j<=(b-a)/dx; ++j){
        space.push_back(j*dx);
    }
    
    vector<double> time;
    for (int j=0; j<=max_t/dt; ++j){
        time.push_back(j*dt);
    }
       
    vector<double> Q;
    for (int j=0; j<space.size(); ++j){
        Q.push_back(q_0(space[j]));
    }
    
    vector<double> F;
    F.push_back(1);
    for (int j=1; j<Q.size(); ++j){
        F.push_back(Q[j-1]+0.5*(1-nu)*(Q[j]-Q[j-1]));
    }
    F.push_back(*(Q.end()-1));
    
    for (int j=1; j < time.size(); ++j){
        Q[0] = 1;
        for (int i = 1; i < Q.size(); ++i){
            Q[i] = Q[i] + (dt/dx)*(F[i]-F[i+1]);
        }
        for (int k = 1; k < Q.size(); ++k){
            F[k] = Q[k-1]+0.5*(1-nu)*(Q[k]-Q[k-1]);
        }
        *(F.end()-1) = *(Q.end()-1);
    }
    return Q;
}
