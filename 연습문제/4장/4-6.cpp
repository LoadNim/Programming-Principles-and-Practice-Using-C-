#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string>numbers(10);
    numbers[0] = "zero"; numbers[1] = "one"; numbers[2] = "two";
    numbers[3] = "three"; numbers[4] = "four"; numbers[5] = "five";
    numbers[6] = "six"; numbers[7] = "seven"; numbers[8] = "eight"; numbers[9] = "nine";

    for(int i = 0; i < 5; ++i){
        int input_int;
        string input_string;
        cout<<"영어로 변환할 한자리 숫자를 입력하세요.\n";
        cin>>input_int;
        cout<<numbers[input_int]<<endl;

        cout<<"숫자로 변환할 한자리 숫자를 영어로 입력하세요.\n";
        cin>>input_string;
        vector<string>::iterator it = find(numbers.begin(), numbers.end(), input_string);
        cout<<it-numbers.begin()<<endl;
    }
}