#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main(){
    cout<<"거리와 거리단위를 입력하세요. (종료 : |)\n";
    double max = numeric_limits<double>::min();
    double min = numeric_limits<double>::max();
    double sum = 0;
    vector<double>input_record;

    double val;
    string dist_unit;
    while(cin>>val>>dist_unit){
        double temp;
        if(dist_unit == "m") temp = val;
        else if(dist_unit == "cm") temp = val / 100;
        else if(dist_unit == "in") temp = val / 39.37;
        else if(dist_unit == "ft") temp = val / 3.281;
        else{
            cout<<"잘못된 단위입니다.\n";
            cout<<"거리와 거리단위를 입력하세요. (종료 : |)\n";
            continue;
        }
        
        if(temp > max){
             cout<<"지금 까지 가장 큰 값 : "<<temp<<"m\n";
             max = temp;
        }
        if(temp < min){
            cout<<"지금 까지 가장 작은 값 : "<<temp<<"m\n";
            min = temp;
        }
        sum+=temp;
        input_record.push_back(temp);
        cout<<"거리와 거리단위를 입력하세요. (종료 : |)\n";
    }

    cout<<"최솟값 : "<<min<<"m\n";
    cout<<"최댓값 : "<<max<<"m\n";
    cout<<"값의 갯수 : "<<input_record.size()<<"개\n";
    cout<<"값의 합 : "<<sum<<"m\n";

    sort(input_record.begin(), input_record.end());
    for(double r : input_record) cout<<r<<"m ";
}