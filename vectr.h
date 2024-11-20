#pragma once
#ifndef VECTR_H
#define VECTR_H
#include <vector>
using namespace std;

class vectr{
    public:
        vectr(int s);
        vectr(vector<double> v);
        ~vectr();
        
        double operator*(const vectr& v);
        double& operator[](int i);
        void operator=(const vectr& v);
        int get_size() const;
        void print();
        vectr operator+(const vectr& v);
        vectr operator-(const vectr& v);
        vectr operator*(double c);
        vectr operator/(double c);
    private:
        vector<double> data;
        int size;

        
};
#endif