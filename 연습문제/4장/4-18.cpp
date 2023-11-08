#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout<<"이차 방정식의 이차식의 계수, 일차식의 계수, 상수를 입력하세요.\n";
    int a, b, c;
    cin>>a>>b>>c;

    double x1, x2;
    if((b*b) - (4*a*c) < 0) cout<<"해가 허수입니다.\n";
    else{
        x1 = (-b + sqrt((b*b) - (4*a*c))) / (2*a);
        x2 = (-b - sqrt((b*b) - (4*a*c))) / (2*a);
        cout<<"x1 : "<<x1<<", "<<"x2 : "<<x2<<endl;
    }
}