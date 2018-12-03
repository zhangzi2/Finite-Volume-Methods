//
//  REA_algorithm.cpp
//  REA algorithm
//
//  Created by Kevin Zhang on 12/2/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "REA_algorithm.hpp"
#include <math.h>
#include <vector>

using namespace std;

//initial conditions
double q_0(double x){
    if (x < 5 && x > -5){
        return 1.0;
    }
    else{
        return 0.0;
    }
}

//velocity of wave
double u(double r, double x){
    return r*x;
}

//minmod function
double minmod(double a, double b, double c){
    vector<double> A = {a,b,c};
    if (signbit(a) + signbit(b) + signbit(c) == 0){
        return *min_element(A.begin(),A.end());
    }
    else{
        return *max_element(A.begin(), A.end());
    }
}

vector<double> REA(int a, int b, double dx, double dt, int max_t){
    double r = 0.03;
    vector<double> space;
    for (int j=0; j<=(b-a)/dx; ++j){
        space.push_back(a+j*dx);
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
    F.push_back(u(r, space[0])*Q[0]);
    F.push_back(u(r, space[1])*Q[1]);
    for (int i = 2; i < Q.size()-1; ++i){
        if(u(r, space[i] > 0)){
            double sigma = minmod((Q[i]-Q[i-2])/(2*dx), 2*(Q[i-1]-Q[i-2])/dx, 2*(Q[i]-Q[i-1])/dx);
            F.push_back(u(r, space[i])*Q[i-1] + 0.5*u(r, space[i])*(dx-u(r, space[i])*dt)*sigma);
        }
        else{
            double sigma = minmod((Q[i+1]-Q[i-1])/(2*dx), 2*(Q[i]-Q[i-1])/dx, 2*(Q[i+1]-Q[i])/dx);
            F.push_back(u(r, space[i])*Q[i] + 0.5*abs(u(r, space[i]))*(dx - abs(u(r, space[i])*dt))*sigma);
        }
    }
    F.push_back(u(r,*(space.end()-2))* *(Q.end()-2));
    F.push_back(u(r,*(space.end()-1))* *(Q.end()-1));
    
    for (int j = 1; j < time.size(); ++j){
        for (int i = 0; i < Q.size(); ++i){
            Q[i] = Q[i] + (dt/dx)*(F[i]-F[i+1]);
        }
        F[0] = u(r, space[0])*Q[0];
        F[1] = u(r, space[1])*Q[1];
        for (int i = 2; i < Q.size()-1; ++i){
            if(u(r, space[i] > 0)){
                double sigma = minmod((Q[i]-Q[i-2])/(2*dx), 2*(Q[i-1]-Q[i-2])/dx, 2*(Q[i]-Q[i-1])/dx);
                F[i] = u(r, space[i])*Q[i-1] + 0.5*u(r, space[i])*(dx-u(r, space[i])*dt)*sigma;
            }
            else{
                double sigma = minmod((Q[i+1]-Q[i-1])/(2*dx), 2*(Q[i]-Q[i-1])/dx, 2*(Q[i+1]-Q[i])/dx);
                F[i] = u(r, space[i])*Q[i] + 0.5*abs(u(r, space[i]))*(dx - abs(u(r, space[i])*dt))*sigma;
            }
        }
        *(F.end()-2) = u(r,*(space.end()-2))* *(Q.end()-2);
        *(F.end()-1) = u(r,*(space.end()-1))* *(Q.end()-1);
    }
    return Q;
}
