#include <iostream>
#include <stdexcept>
using namespace std;

double ctok(double c){
    double k = c + 273.15;
    return k;
}

int main(){
    try{
        double c = 0;
        cin>>c; if(c < -273.15) throw logic_error("비정상적으로 낮은 값입니다.");
        double k = ctok(c);
        cout<<k<<'\n';
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}