#include <iostream>
using namespace std;

int main(){
    cout<<"세 개의 정수를 입력하세요.\n";
    int val1, val2, val3;
    cin>>val1>>val2>>val3;
    if(val1 >= val2) swap(val1, val2);
    if(val1 >= val3) swap(val1, val3);
    if(val2 >= val3) swap(val2, val3);
    cout<<val1<<", "<<val2<<", "<<val3<<endl;
}