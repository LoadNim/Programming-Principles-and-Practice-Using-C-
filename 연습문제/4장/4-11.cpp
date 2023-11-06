#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>prime;
    prime.push_back(2);

    for(int i = 3; i <= 100; ++i){
        bool isprime = true;
        for(int v : prime){
            if(i%v==0){isprime = false; break;}
        }
        if(isprime) prime.push_back(i);
    }

    cout<<"100 이하의 모든 소수\n";
    for(int v : prime) cout<<v<<endl;
}