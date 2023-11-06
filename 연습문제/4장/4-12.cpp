#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>prime;
    prime.push_back(2);

    int max;
    cout<<"몇 이하의 소수를 구할지 입력하시오 : ";
    cin>>max;

    for(int i = 3; i <= max; ++i){
        bool isprime = true;
        for(int v : prime){
            if(i%v==0){isprime = false; break;}
        }
        if(isprime) prime.push_back(i);
    }

    cout<<max<<"이하의 모든 소수\n";
    for(int v : prime) cout<<v<<endl;
}