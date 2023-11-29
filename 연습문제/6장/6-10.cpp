#include <iostream>
#include <cmath>
using namespace std;

long long permutation(const int a, const int b);
long long combination(const int a, const int b);

int main(){
    try{
        int a, b;
        cout<<"전체의 수와 선택할 수를 입력하세요 : ";
        if(!(cin>>a>>b)) throw invalid_argument("int형 정수를 입력하세요.");
        if(a < b) throw invalid_argument("전체의 수가 더 커야만 합니다.");
        char choice;
        cout<<"순열과 조합 중 하나를 선택하세요 (순열 : p, 조합 : c) : ";
        if(!(cin>>choice)) throw invalid_argument("비정상적인 입력입니다.");
        switch (choice){
            case 'p':
                cout<<"순열 P("<<a<<", "<<b<<") = "<<permutation(a, b)<<endl;
                break;
            case 'c':
                cout<<"조합 C("<<a<<", "<<b<<") = "<<combination(a, b)<<endl;
        }
    }
    catch(invalid_argument& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}

long long permutation(const int a, const int b){
    long long result = 1;
    for(long long i = a; i > a-b; --i) result *= i;
    return result;
}

long long combination(const int a, const int b){
    long long molecule = permutation(a, b);
    long long denomiator = 1;
    for(long long i = 1; i <= b; ++i) denomiator *= i;
    return molecule / denomiator;
}