# include "vectr.h"
# include <vector>
# include <iostream>
using namespace std;

vectr::vectr(int s){
    if (s<1){
        throw "Cannot create a vector of size less than 1";
    }
    size = s;
    data = vector<double>(s);
}
vectr::vectr(vector<double> v){
    size = v.size();
    data = v;
}

double vectr::operator*(const vectr& v){
    if(size != v.size){
        throw "Khaled doesn't approve";
    }
    double result = 0;
    for (int i=0;i<size;i++){
        result += data[i]*v.data[i];
    }
    return result;
}
double& vectr::operator[](int i){
    if (i<0 || i>=size){
        throw "Index out of bounds";
    }
    return data[i];
}
vectr vectr::operator+(const vectr& v){
    if(size != v.size){
        throw "Saidi doesn't approve";
    }
    vectr A5u7osam(v.size);
    for(int i=0;i<size;i++){
        A5u7osam[i]=data[i]+v.data[i];
    }
    return A5u7osam;
}
vectr vectr::operator-(const vectr& v){
    if (size != v.size){
        throw "Cannot subtract vectors of different sizes";
    }
    vector<double> result(size);
    for (int i=0; i<size; i++){
        result[i] = data[i] - v.data[i];
    }
    vectr res(result);
    return res;
}
vectr vectr::operator*(double c){
    vector<double> result(size);
    for (int i=0; i<size; i++){
        result[i] = data[i]*c;
    }
    vectr res(result);
    return res;
}
vectr vectr::operator/(double c){
    if (c == 0){
        throw "Cannot divide by zero";
    }
    vector<double> result(size);
    for (int i=0; i<size; i++){
        result[i] = data[i]/c;
    }
    vectr res(result);
    return res;
}
void vectr::operator=(const vectr& v){
    size = v.size;
    data = v.data;
}
void vectr::set(int i, double val){
    if (i<0 || i>=size){
        throw "Index out of bounds";
    }
    data[i] = val;
}
int vectr::get_size(){
    return size;
}
void vectr::print(){
    for (int i=0; i<size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

vectr::~vectr(){
    data.clear();
}

// int main(){
//     vectr v1(0);
//     vectr v2(3);
//     v1.set(0, 1);
//     v1.set(1, 2);
//     v1.set(2, 3);
//     v2.set(0, 4);
//     v2.set(1, 5);
//     v2.set(2, 6);
//     vectr v3 = v1 + v2;
//     v3.print();
//     vectr v4 = v1 - v2;
//     v4.print();
//     vectr v5 = v1*2;
//     v5.print();
//     vectr v6 = v1/2;
//     v6.print();
//     cout << v1*v2 << endl;
//     cout<<v1.get_size()<<v2.get_size()<<endl;
//     return 0;
// }
