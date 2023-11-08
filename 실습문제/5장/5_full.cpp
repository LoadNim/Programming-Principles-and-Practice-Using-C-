#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    try{
        cout<<"Success!\n";
        cout<<"Success!\n";
        cout<<"Success"<<"!\n";
        cout<<"success"<<'\n';
        int res = 7; vector<int>v(10); v[5] = res; cout<<"Success!\n";
        vector<int> v1(10); v1[5] = 7; if(v1[5] == 7) cout<<"Suceess!\n";
        if(v[5] == 7) cout<<"Success!\n"; else cout<<"Fail!\n";
        bool c = true; if(c) cout<<"Success!\n"; else cout<<"Fail!\n";
        string s = "ape"; bool c1 = false; if(!c1) cout<<"Success!\n";
        string s1 = "ape"; if(s1 != "fool") cout<<"Success!\n";
        string s2 = "ape"; if(s2 != "fool") cout<<"Success!\n";
        string s3 = "ape"; if(s3 == "ape") cout<<"Success!\n";
        vector<char> v2(5); for(int i = 0; v2.size() > i; ++i); cout<<"Success!\n";
        vector<char> v3(5); for(int i = 0; v3.size() >= i; ++i); cout<<"Success!\n";
        string s4 = "Success!\n"; for(int i = 0; i < 9; ++i) cout<<s4[i];
        if(true) cout<<"Success!\n"; else cout<<"Fail!\n";
        int x = 20; char c2 = x; if(c2 == 20) cout<<"Success!\n";
        string s5 = "Success!\n"; for(int i = 0; i < 9; ++i) cout<<s5[i];
        vector<int> v4(5); for(int i = 0; i <= v4.size(); ++i); cout<<"Success!\n";
        int i = 0; int j = 9; while(i < 10) ++i; if(j <= i) cout<<"Success!\n";
        int x2 = 2; double d = 4.5/(x2-1); if(d == 2*x2+0.5) cout<<"Success!\n";
        string s6 = "Success!\n"; for(int i = 0; i < 9; ++i) cout<<s6[i];
        int i1 = 0; while(i1 < 10) ++i1; if(j <= i1) cout<<"Success!\n";
        cout<<"Success!\n";
        cin.get();
        return 0;
    }
    catch(exception& e){
        cerr<<"오류: "<<e.what()<<'\n';
        cin.get();
        return 1;
    }
    catch(...){
        cerr<<"이런: 알려지지 않은 예외!\n";
        cin.get();
        return 2;
    }
}