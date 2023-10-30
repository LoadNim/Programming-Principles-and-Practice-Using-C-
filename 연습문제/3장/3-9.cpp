#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<<"숫자로 바꿀 영어 스펠링을 소문자로 입력하세요.\n";
    string input;
    cin>>input;

    if(input == "one") cout<<"1\n";
    else if(input == "two") cout<<"2\n";
    else if(input == "three") cout<<"3\n";
    else if(input == "four") cout<<"4\n";
    else if(input == "five") cout<<"5\n";
    else if(input == "six") cout<<"6\n";
    else if(input == "seven") cout<<"7\n";
    else if(input == "eight") cout<<"8\n";
    else if(input == "nine") cout<<"9\n";
    else if(input == "zero") cout<<"0\n";
    else cout<<"숫자가 아닙니다.\n";
}