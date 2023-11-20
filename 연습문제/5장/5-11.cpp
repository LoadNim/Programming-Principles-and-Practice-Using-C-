#include <iostream>
#include <climits>
#include <vector>
using namespace std;

bool isoverflow(int a, int b){
    if(INT_MAX - a < b) return false;
    else return true;
}

int main(){
    vector<int>pibo;
    pibo.push_back(1); pibo.push_back(1);
    for(int i = 2; isoverflow(pibo[i-2], pibo[i-1]); ++i) pibo.push_back(pibo[i-2] + pibo[i-1]);
    for(int v : pibo) cout<<v<<endl;
}