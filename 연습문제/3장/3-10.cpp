#include <iostream>
using namespace std;

int main(){
    cout<<"연산자와 두 피연산자를 입력하세요";
    char operation;
    double val1, val2;
    cin>>operation>>val1>>val2;

    if(operation == '+') cout<<val1+val2<<endl;
    else if(operation == '-') cout<<val1-val2<<endl;
    else if(operation == '/') cout<<val1/val2<<endl;
    else if(operation == '*') cout<<val1*val2<<endl;
    else cout<<"연산자를 잘 못 입력하였습니다.\n";
}