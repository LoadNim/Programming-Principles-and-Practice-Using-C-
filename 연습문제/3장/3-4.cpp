#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int val1, int val2){
    if(val1 < val2) swap(val1, val2);
    while(val2 != 0){
        int temp = val2;
        val2 = val1 % val2;
        val1 = temp;
    }
    return val1;
}

int main(){
    cout<<"두개의 정수를 입력하세요\n";
    int val1, val2;
    cin>>val1>>val2;

    cout<<"작은 값 : "<<min(val1, val2)<<endl;
    cout<<"큰 값 : "<<max(val1, val2)<<endl;
    cout<<"둘의 합 : "<<val1+val2<<endl;
    cout<<"둘의 차 : "<<abs(val1 - val2)<<endl;
    cout<<"둘의 곱 : "<<val1*val2<<endl;
    int result = gcd(val1, val2);
    cout<<"둘의 비 : "<<val1/result<<':'<<val2/result<<endl;
}