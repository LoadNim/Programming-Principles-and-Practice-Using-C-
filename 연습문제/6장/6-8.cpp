#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

void isright(const string& s){
    if(s.size() != 4) throw invalid_argument("네개의 소문자가 아닙니다.");
    for(char c : s){
        if(!(c >= 97 && c <= 122)) throw invalid_argument("입력 값이 소문자가 아닙니다.");
    }

    bool for_dup[26] = {0,};
    for(char c : s){
        if(for_dup[c-97]) throw invalid_argument("중복된 소문자가 있습니다.");
        else ++for_dup[c-97];
    }
}

int main(){
    try{
        const string answer = "spyr";
        cout<<"네개의 소문자를 입력하세요 (중복되는 소문자는 없습니다): ";
        string input;
        cin>>input;
        isright(input);
        while(answer != input){
            int strike = 0; int ball = 0;
            for(int i = 0; i < 4; ++i){
                if(answer[i] == input[i]) ++strike;
                else if(answer.find(input[i]) != string::npos) ++ball;
            }
            cout<<strike<<"스트라이크, "<<ball<<"볼\n";
            cout<<"네개의 소문자를 입력하세요 (중복되는 소문자는 없습니다): ";
            cin>>input;
            isright(input); 
        }
        cout<<"4스트라이크, 정답입니다.\n";
    }
    catch(exception& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}