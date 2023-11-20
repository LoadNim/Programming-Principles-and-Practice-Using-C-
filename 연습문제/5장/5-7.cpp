#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

pair<double, double> cal_x(double a, double b, double c){
    if(((b * b) - (4* a * c)) < 0) throw logic_error("해가 허수입니다.");
    pair<double, double>x;
    x.first = (-b + sqrt((b*b) - (4*a*c))) / (2*a);
    x.second = (-b - sqrt((b*b) - (4*a*c))) / (2*a);
    return x;
}

int main(){
    try{
        double a, b, c;
        cout<<"이차식의 계수, 일차식의 계수, 상수항을 입력하세요 : ";
        if(!(cin>>a>>b>>c)) throw logic_error("double값이 아닌 값이 입력되었습니다.");
        pair<double, double>x = cal_x(a, b, c);
        cout<<"x1 : "<<x.first<<", x2 : "<<x.second<<endl;
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}