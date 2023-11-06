#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<double> temps;
    for(double temp; cin>>temp;) temps.push_back(temp);

    double sum = 0;
    for(int x : temps) sum += x;
    cout<<"온도 평균 : "<<sum/temps.size()<<'\n';

    sort(temps.begin(), temps.end());
    cout<<"온도 중앙값 : ";
    if(temps.size()%2 == 0) cout<<(temps[temps.size()/2] + temps[temps.size()/2 - 1]) / 2<<endl;
    else cout<<temps[temps.size()/2]<<endl;
}