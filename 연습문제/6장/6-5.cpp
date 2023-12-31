#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

typedef pair<char, string> Token;

class Token_stream{
    public:
        void putback(Token T);
        Token get();
    private:
        bool full = false;
        Token buffer;
}ts;

void Sentence();
void Article();
void Noun();
void Verb();

int main(){
    cout<<"영어 문법 검사기입니다.\n";
    cout<<"string 값을 입력하세요.\n";
    cout<<"'.'으로 문장을 끝낼 수 있으며, x를 입력하면 프로그램이 종료됩니다.\n";
    try{
        while(cin){
            Token t = ts.get();
            if(t.first == 'x') break;
            else{
                ts.putback(t);
                Sentence();
            }
        }
    }
    catch(invalid_argument& e){
        cerr<<e.what()<<endl;
        return 1;
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 2;
    }
}

void Token_stream::putback(Token T){
    if(full) logic_error("가득 찬 버퍼에 putback() 시도");
    buffer = T;
    full = true;
}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;        
    }

    cin>>buffer.first;
    if(buffer.first == '.' || buffer.first == 'x') return buffer;
    else{
        cin.putback(buffer.first);
        cin>>buffer.second;
        transform(buffer.second.begin(), buffer.second.end(), buffer.second.begin(), ::tolower);

        if(buffer.second == "birds" || buffer.second == "fish" || buffer.second == "C++"){
            buffer.first = 'n';
            return buffer;
        }
        else if(buffer.second == "and" || buffer.second == "or" || buffer.second == "but"){
            buffer.first = 'c';
            return buffer;
        }
        else if(buffer.second == "the"){
            buffer.first = 'a';
            return buffer;
        }
        else if(buffer.second == "rules" || buffer.second == "fly" || buffer.second == "swim"){
            buffer.first = 'v';
            return buffer;
        }
        else{
            throw invalid_argument("잘못된 입력 값입니다.");
        }
    }
}

void Sentence(){
    Verb();
    if(cin.peek() == 10) throw invalid_argument("문장이 올바르게 종료되지 않았습니다.");
    Token t = ts.get();
    if(t.first == 'c') Sentence();
    else if(t.first == '.') cout<<"올바른 문장입니다.\n";
    else throw invalid_argument("접속사가 누락되었습니다.\n");
}

void Verb(){
    Noun();
    Token t = ts.get();
    if(t.first != 'v') throw invalid_argument("동사가 누락되었습니다.");
}

void Noun(){
    Article();
    Token t = ts.get();
    if(t.first != 'n') throw invalid_argument("명사가 누락되었습니다.");
}

void Article(){
    Token t = ts.get();
    if(t.first != 'a') ts.putback(t);
}