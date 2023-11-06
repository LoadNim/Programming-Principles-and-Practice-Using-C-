#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int>numbers;
    numbers.reserve(100);
    for(int i = 1; i <=100; ++i) numbers.push_back(i);
    vector<int>::iterator it = numbers.begin();
    numbers.erase(it);

    vector<int>prime;
    for(int i = 2; i <= sqrt(100); ++i){
        if(*it == i) prime.push_back(*it);
        while(it != numbers.end()){
            if(*it % i == 0) numbers.erase(it);
            else ++it;
        }
        it = numbers.begin();
    }
    prime.insert(prime.end(), numbers.begin(), numbers.end());
    cout<<"100이하의 모든 소수"<<endl;
    for(int v : prime) cout<<v<<endl;
}