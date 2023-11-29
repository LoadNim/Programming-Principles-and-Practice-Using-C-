#include <iostream>
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
double Bit_and();
double Bit_xor();
double Bit_or();

int main(){
    cout<<"간단한 계산기입니다.\n";
    cout<<"부동소수점 숫자를 이용한 표현식을 입력하세요.\n";\
    cout<<"사칙연산을 지원하며, 소괄호를 지원하며, 비트 논리 연산을 지원합니다.\n";
    cout<<"표현식 뒤에 '='를 입력하면, 계산결과를 출력하며, 종료를 원할 시, x를 입력하세요.\n";
    try{
        double val = 0;
        while(cin){
            Token t = ts.get();
            if(t.first == 'x') break;
            else if(t.first == '=') cout<<val<<endl;
            else{
                ts.putback(t);
                val = Bit_or();
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
        case '{': case '}':
        case '=': case 'x': case '(': case ')':
        case '+': case '-': case '*': case '/':
        case '~': case '&': case '|': case '^':
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
        
        case '!':{
            char next = cin.peek();
            if(next =='{' || next == '(' || next == '.' || (next >= '0' && next <= '9')) buffer.first = '1';
            else buffer.first = '2';
            return buffer;
        }

        default:
            throw invalid_argument("잘못된 입력 값입니다.");
    }
}

double Bit_or(){
    double left = Bit_xor();
    Token t = ts.get();
    while (true){
        switch (t.first){
            case '|':{
                double right = Bit_xor();
                if(left != floor(left)) throw invalid_argument("double형의 or연산은 정의되지 않습니다.");
                if(right != floor(right)) throw invalid_argument("double형의 or연산은 정의되지 않습니다.");
                left = (int)left | (int)right;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double Bit_xor(){
    double left = Bit_and();
    Token t = ts.get();
    while (true){
        switch (t.first){
            case '^':{
                double right = Bit_and();
                if(left != floor(left)) throw invalid_argument("double형의 xor연산은 정의되지 않습니다.");
                if(right != floor(right)) throw invalid_argument("double형의 xor연산은 정의되지 않습니다.");
                left = (int)left ^ (int)right;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double Bit_and(){
    double left = expression();
    Token t = ts.get();
    while (true){
        switch (t.first){
            case '&':{
                double right = expression();
                if(left != floor(left)) throw invalid_argument("double형의 and연산은 정의되지 않습니다.");
                if(right != floor(right)) throw invalid_argument("double형의 and연산은 정의되지 않습니다.");
                left = (int)left & (int)right;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
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
        if(t.first == '2'){
            if(left != floor(left)) throw invalid_argument("double형의 계승은 정의되지 않습니다.");
            else if(left == 0){
                left = 1;
                t= ts.get();
            }
            else if(left >= 1){
                double d = 1;
                for(int i = 1; i <= left; ++i) d *= i;
                left = d;
                t = ts.get();
            }
            else throw invalid_argument("음수의 계승은 정의되지 않습니다.");
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
            double d = Bit_or();
            t = ts.get();
            if(t.first != '}') throw invalid_argument("'}'가 나와야 함");
            return d;
        }
        case '(':{
            double d = Bit_or();
            t = ts.get();
            if(t.first != ')') throw invalid_argument("')'가 나와야 함");
            return d;
        }
        case '1':{
            double d = primary();
            return !d;
        }
        case '~':{
            double d = primary();
            if(d != floor(d)) throw invalid_argument("double형의 보수 연산은 정의되지 않습니다.");
            return ~(int)d;
        }
        case '8': return t.second;
        default:
            throw logic_error("primary가 나와야 함");
    }
}