#pragma once
#ifndef MAT_H
#define MAT_H
#include <vector>
#include "vectr.h"
using namespace std;

class mat{
    public:
        mat(int r, int c);
        mat(vector<vectr> m);
        mat(const mat& m);        
        ~mat();
        
        vectr operator*(vectr& v);
        mat operator*(mat& m);
        mat operator+(const mat& m);
        mat operator-(const mat& m);
        mat operator*(double c);
        mat operator/(double c);
        vectr operator[](int i);
        void operator=(const mat& m);
        void set(int r, int c, double val);
        void set(int r, vectr v);
        void set(vectr v, int c);
        int get_rows();
        int get_cols();
        void print();
        mat t();
    private:
        vector<vectr> data;
        int rows;
        int cols;
};
#endif