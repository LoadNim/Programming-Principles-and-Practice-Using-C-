#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void is_not_int(int sum, int num){
    if(num > 0 && sum > INT_MAX - num) throw overflow_error("\nint로 표현하기엔 너무 큰 값입니다.");
    if(num < 0 && sum < INT_MIN - num) throw underflow_error("\nint로 표현하기엔 너무 작은 값입니다.");
}

int main(){
    try{
        int N;
        cout<<"합계를 구할 정수의 개수를 입력하세요 : ";
        if(!(cin>>N)) throw logic_error("N에 int형 값이 아닌 값이 입력되었습니다.");
        
        int input;
        vector<int>numbers;
        cout<<"정수를 입력하세요 ('|'로 입력 종료)\n";
        while(cin>>input) numbers.push_back(input);
        if(N > numbers.size()) throw logic_error("vector 요소보다 많은 개수의 합은 구할 수 없습니다.");

        int sum = 0;
        cout<<"앞 숫자 "<<N<<"개 ( ";
        for(int i = 0; i < N; ++i){
            cout<<numbers[i]<<' ';
            is_not_int(sum, numbers[i]);
            sum += numbers[i];
        }
        cout<<")의 합은 "<<sum<<"입니다.\n";
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
    catch(overflow_error& e){
        cerr<<e.what()<<endl;
        return 2;
    }
    catch(underflow_error& e){
        cerr<<e.what()<<endl;
        return 3;
    }
}