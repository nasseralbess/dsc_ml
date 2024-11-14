#include <vector>
#include <iostream>
#include "mat.h"
#include "vectr.h"
#include "vectr.cpp"
using namespace std;

mat::mat(int r, int c){
    if (r<1 || c<1){
        throw "Cannot create a matrix with less than 1 row or column";
    }
    rows = r;
    cols = c;
    data = vector<vectr>(r, vectr(c));
}
mat::mat(vector<vectr> m){
    if (m.size()<1){
        throw "Cannot create a matrix with less than 1 row";
    }
    rows = m.size();
    cols = m[0].get_size();
    for (int i=1; i<rows; i++){
        if (m[i].get_size() != cols){
            throw "Cannot create a matrix with rows of different sizes";
        }
    }
    data = m;
}
mat::mat(const mat& m){
    rows = m.rows;
    cols = m.cols;
    data = m.data;
}
mat::~mat(){
    data.clear();
}
vectr mat::operator[](int i){
    if (i<0 || i>=rows){
        throw "Index out of bounds";
    }
    return data[i];
}
vectr mat::operator*(vectr& v){
    if(cols != v.get_size()){
        throw "Cannot multiply a matrix of size "+to_string(rows)+"x"+to_string(cols)+" by a vector of size "+to_string(v.get_size());
    }
    vectr res(rows);
    for(int i=0; i<rows;i++){
        res.set(i,data[i]*v);
    }
    return res;
}
mat mat::operator*(mat& m){
    if (cols != m.rows){
        throw "Cannot multiply a matrix of size "+to_string(rows)+"x"+to_string(cols)+" by a matrix of size "+to_string(m.rows)+"x"+to_string(m.cols);
    }
    mat result(rows, m.cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<m.cols;j++){
            vectr res2(cols);
            for(int k=0;k<cols;k++ ){
                res2.set(k,m[k][j]);
            }
            result.set(i,j,data[i]*res2);
        }
    }
    return result;
}
mat mat::operator+(const mat& m){
    if (rows != m.rows || cols != m.cols){
        throw "Cannot add matrices of different sizes";
    }
    mat result(rows, cols);
    for (int i=0; i<rows; i++){
        result.data[i] = data[i] + m.data[i];
    }
    return result;
}
mat mat::operator-(const mat& m){
    if (rows != m.rows || cols != m.cols){
        throw "Cannot subtract matrices of different sizes";
    }
    mat result(rows, cols);
    for (int i=0; i<rows; i++){
        result.data[i] = data[i] - m.data[i];
    }
    return result;
}
mat mat::operator*(double c){
    mat result(rows, cols);
    for (int i=0; i<rows; i++){
        result.data[i] = data[i]*c;
    }
    return result;
}
mat mat::operator/(double c){
    if (c == 0){
        throw "Cannot divide by zero";
    }
    mat result(rows, cols);
    for (int i=0; i<rows; i++){
        result.data[i] = data[i]/c;
    }
    return result;
}
void mat::operator=(const mat& m){
    rows = m.rows;
    cols = m.cols;
    data = m.data;
}
void mat::set(int r, int c, double val){
    if (r<0 || r>=rows || c<0 || c>=cols){
        throw "Index out of bounds";
    }
    data[r].set(c, val);
}
void mat::set(int r, vectr v){
    if (r<0 || r>=rows || v.get_size() != cols){
        throw "Index out of bounds";
    }
    data[r] = v;
}
void mat::set(vectr v, int c){
    if (c<0 || c>=cols || v.get_size() != rows){
        throw "Index out of bounds";
    }
    for (int i=0; i<rows; i++){
        data[i].set(c, v[i]);
    }
}
int mat::get_rows(){
    return rows;
}
int mat::get_cols(){
    return cols;
}
void mat::print(){
    for (int i=0; i<rows; i++){
        data[i].print();
    }
}
mat mat::t(){
    mat result(cols, rows);
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            result.data[j].set(i, data[i][j]);
        }
    }
    return result;
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


    return 0;
}