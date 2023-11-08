#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <climits>
using namespace std;

int main(){
    vector<string>str = {"Umamusume", "Genshin", "Arknights", "Umamusume", "Umamusume", "Genshin", "Umamusume"};
    cout<<"최댓값 : "<<*max_element(str.begin(), str.end())<<endl;
    cout<<"최솟값 : "<<*min_element(str.begin(), str.end())<<endl;
    
    int mode_val = INT_MIN;
    string mode_key;
    map<string, int>formode;
    for(string v : str){
        map<string, int>::iterator it = formode.find(v);
        if(it == formode.end()) formode.insert(pair<string, int>(v, 1));
        else ++formode[v];
        if(mode_val < formode[v]){
            mode_val = formode[v];
            mode_key = v;
        }
    }
    cout<<"최빈값 : "<<mode_key<<endl;
} 