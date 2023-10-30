#include <iostream>
using namespace std;

int main(){
    cout<<"정수를 입력하세요.\n";
    int input;
    cin>>input;
    if(input%2) cout<<input<<"은(는) 홀수입니다.\n";
    else cout<<input<<"은(는) 짝수입니다.\n";
}