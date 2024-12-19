#pragma once
#ifndef LINEAR_REG_H
#define LINEAR_REG_H
#include "mat.h"
#include "vectr.h"
class linear_reg{
    public:
        linear_reg(mat X, vectr y);
        void fit(double alpha_input= 0.001, int iters_input = 1000000);
        vectr predict(mat& X);
        double accuracy(mat& X, const vectr& y);
        double mse(mat& X, const vectr& y);
        void get_params();
    private:
        mat X;
        vectr y;
        vectr theta;    
        double alpha;
        int iters;
        void gradient_descent();
};
#endif 