#include <iostream>
#include <vector>
using namespace std;

int main(){
    try{
        int N;
        cout<<"합계를 구할 정수의 개수를 입력하세요 : ";
        if(!(cin>>N)) throw logic_error("N에 int형 값이 아닌 값이 입력되었습니다.");
        
        double input;
        vector<double>numbers;
        cout<<"정수를 입력하세요 ('|'로 입력 종료)\n";
        while(cin>>input) numbers.push_back(input);
        if(N > numbers.size()) throw logic_error("vector 요소보다 많은 개수의 합은 구할 수 없습니다.");

        double sum = 0;
        cout<<"앞 숫자 "<<N<<"개 ( ";
        for(int i = 0; i < N; ++i){
            cout<<numbers[i]<<' ';
            sum += numbers[i];
        }
        cout<<")의 합은 "<<sum<<"입니다.\n";
        
        vector<double>diff;
        diff.push_back(0);
        for(int i = 1; i < numbers.size(); ++i){
            diff.push_back(numbers[i] - numbers[i-1]);
        }

        for(int i = 1; i < numbers.size(); ++i){
            if(diff[i] == 0) cout<<"numbers["<<i<<"]와 numbers["<<i-1<<"]의 값은 같습니다.\n";
            else cout<<"numbers["<<i<<"]와 numbers["<<i-1<<"]의 차이 : "<<diff[i]<<endl;
        }
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}