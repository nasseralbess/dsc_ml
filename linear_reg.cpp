#include "linear_reg.h"
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

linear_reg::linear_reg(const mat& X_input, const vectr& y_input): X(X_input), y(y_input) {
    if (X_input.get_rows() != y_input.get_size()) {
        throw "Number of training examples must match number of labels";
    }
    theta = vectr(X.get_cols());
    for (int i = 0; i < X.get_cols(); i++) {
        theta[i] = ((double)rand()) / RAND_MAX;
    }
}

void linear_reg::fit(double alpha_input, int iters_input) {   
    alpha = alpha_input;
    iters = iters_input;
    gradient_descent();
}

void linear_reg::gradient_descent() {
    for(int k=0;k<iters;k++){    
        for(int i=0;i<X.get_rows();i++){
            vector<double>grads(theta.get_size(),0);
            int f = 0;
            for(int j=0;j<X.get_cols();j++){
                f+= theta[j]*X[i][j];
            }
            for(int j=0;j<theta.get_size();j++){
                grads[j] += X[i][j]*(f-y[i])/X.get_rows();
            }
            for(int j=0;j<theta.get_size();j++){
                theta[j]-= alpha*grads[j];
            }
        }
    }
}

vectr linear_reg::predict(mat& X_input) {
    vectr res(X_input.get_rows());
    res = X_input*theta;
    return res;
}

double linear_reg::accuracy(const mat& X_test, const vectr& y_test) {
    return 0;
}

double linear_reg::mse(const mat& X_test, const vectr& y_test) {
    return 0;
}

void linear_reg::get_params() {
    cout << "Model Parameters (theta):" << endl;
    for(int i = 0; i < theta.get_size(); i++) {
        cout << "θ" << i << ": " << theta[i] << endl;
    }
    cout << "Learning rate (alpha): " << alpha << endl;
    cout << "Number of iterations: " << iters << endl;
}

int main(){
    vectr v1 ({1,2,3});
    vectr v2({9,5,6});
    vectr v3({5,7,9});
    mat mat1({v1,v2,v3});
    vectr v4({1,4});
    vectr v5({2,5});
    vectr v6({3,6});
    mat mat2({v4,v5,v6});
    mat mat3 = mat1*mat2;
    mat3.print();
    vectr mat4 = mat1*v3;
    mat4.print();
    mat mat5 = mat3.t();
    mat5.print();


    return 0;
}