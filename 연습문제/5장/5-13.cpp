#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

string make_answer(){
    int seed;
    cout<<"임의의 int형 정수값을 입력해주세요.\n";
    if(!(cin>>seed)) throw invalid_argument("입력 값이 int형 정수 값이 아닙니다.");
    srand(seed);

    string answer;
    bool for_answer[10] = {0,};
    int num = rand() % 9 + 49;
    answer.push_back(num);
    ++for_answer[num-48];

    while (answer.size() != 4){
        num = rand() % 10 + 48;
        if(for_answer[num-48]) continue;
        answer.push_back(num);
        ++for_answer[num-48];
    }
    return answer;
}

void isright(string& s){
    if(s[0] == '0') throw invalid_argument("첫 자리엔 0이 올 수 없습니다.");
    if(s.size() != 4) throw invalid_argument("네자리 정수가 아닙니다.");
    for(char c : s){
        if(!(c >= 48 && c <= 57)) throw invalid_argument("입력값이 정수가 아닙니다.");
    }

    bool for_dup[10] = {0,};
    for(char c : s){
        if(for_dup[c-48]) throw invalid_argument("자리에 중복된 값이 있습니다.");
        else ++for_dup[c-48];
    }
}

int main(){
    try{
        string answer = make_answer();
        cout<<"네 자리 정수를 입력하세요 (각 자리별 중복되는 숫자는 없습니다): ";
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
            cout<<"네 자리 정수를 입력하세요 (각 자리별 중복되는 숫자는 없습니다): ";
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