#pragma once
#ifndef LINEAR_REG_H
#define LINEAR_REG_H
#include "mat.h"
#include "vectr.h"
class linear_reg{
    public:
        linear_reg(const mat& X, const vectr& y);
        void fit(double alpha = 0.1, int iters = 1000);
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