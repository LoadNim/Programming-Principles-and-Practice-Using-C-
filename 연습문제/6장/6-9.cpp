#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main(){
    try{
        cout<<"최대 네자리의 숫자를 입력하세요.\n";
        char input_ch; string input_st;
        while(cin.get(input_ch) && input_ch != '\n'){
            input_st.push_back(input_ch);
        }
        int input_i = stoi(input_st);
        if(input_i >= 10000) throw invalid_argument("최대 네자리까지 지원합니다.");
        cout<<input_i<<"은 ";
        if(input_i >= 1000){
            cout<<input_i/1000<<"천";
            input_i %= 1000;
        }
        if(input_i >= 100){
            cout<<input_i/100<<"백";
            input_i %= 100;
        }
        if(input_i >= 10){
            cout<<input_i/10<<"십";
            input_i %= 10;
        }
        if(input_i >= 1){
            cout<<input_i<<endl;
        }
        
    }
    catch(invalid_argument& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}