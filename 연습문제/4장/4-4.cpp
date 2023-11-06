#include <iostream>
using namespace std;

int main(){
    int target, guess;
    int min = 1;
    int max = 100;

    cout<<"당신이 생각하는 숫자를 입력하십시오.(1-100)\n";
    cin>>target;
    for(int i = 0; i < 7; ++i){
        char temp;
        guess = (min + max - 1) / 2;
        cout<<"당신이 생각하는 숫자가 "<<guess<<"입니까? (위 : u, 아래 : d, 일치 : c)\n";
        cin>>temp;
        if(temp == 'c') break;
        else if(temp == 'u') min = guess + 1;
        else max = guess;
    }
    if(min == max) guess = min;
    cout<<"당신이 생각하는 숫자는 "<<guess<<"입니다.\n";
}