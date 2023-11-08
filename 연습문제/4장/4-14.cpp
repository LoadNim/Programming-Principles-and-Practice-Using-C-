#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int max;
    cout<<"몇 이하의 소수를 구할지 입력하세요.\n";
    cin>>max;

    vector<int>numbers;
    numbers.reserve(max);
    for(int i = 1; i <=max; ++i) numbers.push_back(i);
    vector<int>::iterator it = numbers.begin();
    numbers.erase(it);

    vector<int>prime;
    for(int i = 2; i <= sqrt(max); ++i){
        if(*it == i) prime.push_back(*it);
        while(it != numbers.end()){
            if(*it % i == 0) numbers.erase(it);
            else ++it;
        }
        it = numbers.begin();
    }
    prime.insert(prime.end(), numbers.begin(), numbers.end());
    cout<<max<<"이하의 모든 소수"<<endl;
    for(int v : prime) cout<<v<<endl;
}