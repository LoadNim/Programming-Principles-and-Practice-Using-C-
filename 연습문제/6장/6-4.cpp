#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Name_value{
    public:
        Name_value(const string& s, const int& n) : name(s), numbers(n){};
        bool Isdup(const string& s){return s == name;};
        void Show_data();
    private:
        string name;
        int numbers;
};

int main(){
    try{
        vector<Name_value> data;
        for(int i = 0; i < 10; ++i){
            string name_input;
            int numbers_input;
            cout<<"이름과 값을 공백으로 구분하여 입력하세요.\n";
            if(!(cin>>name_input>>numbers_input)) throw invalid_argument("유효하지 않은 입력값입니다.");
            for(Name_value v : data) if(v.Isdup(name_input)) throw invalid_argument("중복된 이름이 입력되었습니다.");
            data.push_back(Name_value(name_input, numbers_input));
        }
        for(int i = 0; i < 10; ++i) data[i].Show_data();
    }
    catch(invalid_argument& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}

void Name_value::Show_data(){
    cout<<"이름 : "<<name<<", 값 : "<<numbers<<endl;
}