#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int change_string_to_int(string s){
    vector<string>numbers(10);
    numbers[0] = "zero"; numbers[1] = "one"; numbers[2] = "two";
    numbers[3] = "three"; numbers[4] = "four"; numbers[5] = "five";
    numbers[6] = "six"; numbers[7] = "seven"; numbers[8] = "eight"; numbers[9] = "nine";
    vector<string>::iterator it = find(numbers.begin(), numbers.end(), s);

    if(s.size() == 1 && isdigit(s[0])) return stoi(s);
    else if(it != numbers.end()) return it-numbers.begin();
    else{
        cout<<s<<"는 잘못된 입력입니다!\n";
        exit(1);
    }
}

int main(){
    cout<<"한자리 숫자, 혹은 해당하는 영어와 연산자를 입력하세요.\n";
    char oper;
    string input_1, input_2;
    cin>>input_1>>input_2>>oper;
    int val1, val2;
    val1 = change_string_to_int(input_1);
    val2 = change_string_to_int(input_2);

    if(oper == '+') cout<<input_1<<"과 "<<input_2<<"의 합은 "<<val1+val2<<"입니다.\n";
    else if(oper == '-') cout<<input_1<<"과 "<<input_2<<"의 차는 "<<val1-val2<<"입니다.\n";
    else if(oper == '*') cout<<input_1<<"과 "<<input_2<<"의 곱은 "<<val1*val2<<"입니다.\n";
    else if(oper == '/') cout<<input_1<<"과 "<<input_2<<"의 비는 "<<val1/val2<<"입니다.\n";
    else cout<<"잘못된 연산자 입력입니다.\n";
}