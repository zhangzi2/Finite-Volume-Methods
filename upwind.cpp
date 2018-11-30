
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

double q_0(double x){
    double q_0;
    if (x<=1){q_0=1.0;}
    else{q_0=0.0;}
    return q_0;
}

double q_true(double x, double t){
    double q_true;
    if (x-1<=1){q_true=1.0;}
    else {q_true=0.0;}
    return q_true;
}

vector<double> upwind(int a, int b, double dx, double dt, int max_t, int t){
    vector<double> space;
    for (int j=0; j<=(b-a)/dx; ++j){
        space.push_back(j*dx);
    }
    
    vector<double> time;
    for (int j=0; j<=max_t/dx; ++j){
        time.push_back(j*dt);
    }
    
    vector<double> true_solution;

    vector<double> Q;
    for (int j=0; j<space.size(); ++j){
        Q.push_back(q_0(space[j]));
    }
    
    vector<double> F;
    F.push_back(1);
    for (int j=1; j<Q.size()+1; ++j){
        F.push_back(Q[j-1]);
    }
    
    for (int j = 1; j < time.size(); ++j){
        Q[0] = 1;
        for (int i = 1; i < Q.size(); ++i){
            Q[i] = Q[i] + (dt/dx)*(F[i]-F[i+1]);
        }
        for (int k = 1; k < Q.size()+1; ++k){
            F[k] = Q[k-1];
        }
        if (time[j] == t){
            return Q;
        }
    }
    return vector<double>();
}