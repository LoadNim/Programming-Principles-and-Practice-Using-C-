#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cout<<"인접 도시간의 거리를 double형으로 입력하세요.\n";
    vector<double>input;
    for(int i = 0; i < 5; ++i){
        double temp;
        cin>>temp;
        input.push_back(temp);
    }

    cout<<"최단거리 : "<<*min_element(input.begin(), input.end())<<endl;
    cout<<"최장거리 : "<<*max_element(input.begin(), input.end())<<endl;
    cout<<"평균거리 : "<<accumulate(input.begin(), input.end(), double(0)) / input.size()<<endl;
}