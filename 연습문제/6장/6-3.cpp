#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

typedef pair<char, double> Token;

class Token_stream{
    public:
        void putback(Token T);
        Token get();
    private:
        bool full = false;
        Token buffer;
}ts;

double primary();
double term();
double fac();
double expression();

int main(){
    cout<<"간단한 계산기입니다.\n";
    cout<<"부동소수점 숫자를 이용한 표현식을 입력하세요.\n";\
    cout<<"사칙연산을 지원하며, 소괄호를 지원합니다.\n";
    cout<<"표현식 뒤에 '='를 입력하면, 계산결과를 출력하며, 종료를 원할 시, x를 입력하세요.\n";
    try{
        int i = 1;
        double val = 0;
        while(cin){
            Token t = ts.get();
            if(t.first == 'x') break;
            else if(t.first == '=') cout<<val<<endl;
            else{
                ts.putback(t);
                val = expression();
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
    switch (buffer.first){
        case '{': case '}': case '!':
        case '=': case 'x': case '(': case ')':
        case '+': case '-': case '*': case '/':
            return buffer;

        case '.':
        case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': case '0':{
            cin.putback(buffer.first);
            double val;
            cin>>val;
            buffer.first = '8';
            buffer.second = val;
            return buffer;
        }
        default:
            throw invalid_argument("잘못된 입력 값입니다.");
    }
}

double expression(){
    double left = term();
    Token t = ts.get();
    while (true){
        switch (t.first){
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term(){
    double left = fac();
    Token t = ts.get();
    while(true){
        switch(t.first){
            case '*':
                left *= fac();
                t = ts.get();
                break;
            case '/':{
                double d = fac();
                if (d == 0) throw logic_error("0으로 나눌 수 없습니다.");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double fac(){
    double left = primary();
    Token t = ts.get();
    while(true){
        if(t.first == '!'){
            if(left != floor(left)) throw invalid_argument("double형의 계승은 정의되지 않습니다.");
            else if(left == 0){
                left = 1;
                t= ts.get();
            }
            else{
                double d = 1;
                for(int i = 1; i <= left; ++i) d *= i;
                left = d;
                t = ts.get();
            }
        }
        else{
            ts.putback(t);
            return left;
        }
    }
}

double primary(){
    Token t = ts.get();
    switch(t.first){
        case '{':{
            double d = expression();
            t = ts.get();
            if(t.first != '}') throw invalid_argument("'}'가 나와야 함");
            return d;
        }
        case '(':{
            double d = expression();
            t = ts.get();
            if(t.first != ')') throw invalid_argument("')'가 나와야 함");
            return d;
        }
        case '8': return t.second;
        default:
            throw logic_error("primary가 나와야 함");
    }
}