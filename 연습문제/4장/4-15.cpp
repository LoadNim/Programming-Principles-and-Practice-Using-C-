#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>prime;
    prime.push_back(2);

    int n;
    cout<<"첫 몇개의 소수를 찾을까요?\n";
    cin>>n;

    int num = 3;
    while (prime.size() != n){
        bool isprime = true;
        for(int v : prime){
            if(num % v == 0){isprime = false; break;}
            if(v * v >= num) break;
        }
        if(isprime) prime.push_back(num);
        ++num;
    }
    cout<<"첫 "<<n<<"개의 소수는 다음과 같습니다.\n";
    for(int v : prime) cout<<v<<endl;
}