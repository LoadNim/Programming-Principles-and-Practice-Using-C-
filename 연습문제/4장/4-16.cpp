#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    vector<int>nums = {1, 10, 10, 5, 2, 10, 1, 2, 3, 3, 10, 10};
    int min = INT_MAX;
    int max = INT_MIN;

    for(int v : nums){
        if(v < min) min = v;
        if(v > max) max = v;
    }

    int formode[max+1] = {0,};
    for(int v : nums) ++formode[v];
    int mode = 0;
    int mode_index;
    for(int i = 0; i < max+1; ++i){
        if(mode < formode[i]){
            mode = formode[i];
            mode_index = i;
        }
    }

    cout<<"최댓값 : "<<max<<endl;
    cout<<"최솟값 : "<<min<<endl;
    cout<<"최빈값 : "<<mode_index<<endl;
}