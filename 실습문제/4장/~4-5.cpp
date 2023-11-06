#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double val1, val2;
    cout<<"두 수를 입력하세요. (종료 : |)\n";
    while (cin>>val1>>val2){
        if(fabs(val1-val2)<0.01) cout<<"두 수가 거의 같음.\n";
        else if(val1==val2) cout<<"두 수가 같음.\n";
        else if(val1>val2) cout<<"더 작은 값 : "<<val2<<", 더 큰 값 : "<<val1<<endl;
        else cout<<"더 작은 값 : "<<val1<<",\t더 큰 값 : "<<val2<<endl;
        cout<<"두 수를 입력하세요. (종료 : |)\n";
    }
}