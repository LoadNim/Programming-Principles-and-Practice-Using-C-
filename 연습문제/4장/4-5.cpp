#include <iostream>
using namespace std;

int main(){
    cout<<"두개의 double값과 연산자를 입력하세요.\n";
    double val1, val2;
    char oper;
    cin>>val1>>val2>>oper;

    if(oper == '+') cout<<val1<<"과 "<<val2<<"의 합은 "<<val1+val2<<"입니다.\n";
    else if(oper == '-') cout<<val1<<"과 "<<val2<<"의 차는 "<<val1-val2<<"입니다.\n";
    else if(oper == '*') cout<<val1<<"과 "<<val2<<"의 곱은 "<<val1*val2<<"입니다.\n";
    else if(oper == '/') cout<<val1<<"과 "<<val2<<"의 비는 "<<val1/val2<<"입니다.\n";
    else cout<<"잘못된 연산자 입력입니다.\n";
}