#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<string>name;
    vector<int>numbers;

    for(int i = 0; i < 10; ++i){
        string name_input;
        int numbers_input;
        cout<<"이름과 값을 공백으로 구분하여 입력하세요.\n";
        cin>>name_input>>numbers_input;
        
        vector<string>::iterator it = find(name.begin(), name.end(), name_input);
        if(it == name.end()){
            name.push_back(name_input);
            numbers.push_back(numbers_input);
        }
        else{
            cout<<"유일하지 않은 이름입니다.\n프로그램을 종료합니다.\n";
            exit(1);
        }
    }

    for(int i = 0; i < 10; ++i){
        cout<<"이름 : "<<name[i]<<", 값 : "<<numbers[i]<<endl;
    }
}