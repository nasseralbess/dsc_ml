#pragma once
#ifndef LINEAR_REG_H
#define LINEAR_REG_H
#include "mat.h"
#include "vectr.h"
class linear_reg{
    public:
        linear_reg(mat X, vectr y);
        void fit(double alpha_input= 0.005, int iters_input = 500000);
        vectr predict(mat& X);
        double accuracy(const mat& X, const vectr& y);
        double mse(const mat& X, const vectr& y);
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