//
//  MC_limiter.cpp
//  MC limiter
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "MC_limiter.hpp"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include "MC_limiter.hpp"

using namespace std;

double q_0(double x){
    double q_0;
    if (x<=1){q_0=1.0;}
    else{q_0=0.0;}
    return q_0;
}

vector<double> MC_limiter(int a, int b, double dx, double dt, int max_t){
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
    if (Q[1]-Q[0] == 0){
        F.push_back(Q[0]);
    }
    else {
        double theta_0 = (Q[0]-1)/(Q[1]-Q[0]);
        double phi_0 = fmax(0,fmin(0.5+theta_0/2, fmin(2,2*theta_0)));
        F.push_back(Q[0]+phi_0*0.5*(1-nu)*(Q[1]-Q[0]));
    }
    for (int i = 2; i < Q.size(); ++i){
        if (Q[i] - Q[i-1] == 0) {
            F.push_back(Q[i-1]);
        }
        else {
            double theta = (Q[i-1]-Q[i-2])/(Q[i]-Q[i-1]);
            double phi = fmax(0,fmin(0.5+theta/2, fmin(2,2*theta)));
            F.push_back(Q[i-1] + phi*0.5*(1-nu)*(Q[i]-Q[i-1]));
        }
    }
    F.push_back(*(Q.end()-1));
    
    for (int j = 1; j<time.size(); ++j) {
        Q[0] = 1;
        for (int i = 1; i < Q.size(); ++i){
            Q[i] = Q[i] + (dt/dx)*(F[i]-F[i+1]);
        }
        
        if (Q[1]-Q[0]==0){
            F[1] = Q[0];
        }
        else {
            double theta_0 = (Q[0]-1)/(Q[1]-Q[0]);
            double phi_0 = fmax(0,fmin(0.5+theta_0/2, fmin(2,2*theta_0)));
            F[1] = Q[0] + phi_0*0.5*(1-nu)*(Q[1]-Q[0]);
        }
        
        for (int i = 2; i < Q.size(); ++i){
            double theta = (Q[i-1]-Q[i-2])/(Q[i]-Q[i-1]);
            double phi = fmax(0,fmin(0.5+theta/2, fmin(2,2*theta)));
            F[i] = Q[i-1] + phi*0.5*(1-nu)*(Q[i]-Q[i-1]);
        }
        *(F.end()-1) = *(Q.end()-1);
    }
    return Q;
}
