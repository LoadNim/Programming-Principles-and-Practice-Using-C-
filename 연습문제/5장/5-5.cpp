#include <iostream>
#include <stdexcept>
using namespace std;

double ctok(double c){
    if(c < -273.15) throw logic_error("비정상적으로 낮은 섭씨 값입니다.");
    double k = c + 273.15;
    return k;
}

double ktoc(double k){
    if(k < 0) throw logic_error("비정상적으로 낮은 켈빈 값입니다.");
    double c = k - 273.15;
    return c;
}

int main(){
    try{
        double c = 0;
        cout<<"켈빈 값으로 변환할 섭씨 값을 입력하세요 : ";
        cin>>c;
        double k = ctok(c);
        cout<<"섭씨 값 "<<c<<"를 켈빈 값으로 변환하면 : "<<k<<endl;

        cout<<"섭씨 값으로 변환할 켈빈 값을 입력하세요 : ";
        cin>>k;
        c = ktoc(k);
        cout<<"켈빈 값 "<<k<<"를 섭씨 값으로 변환하면 : "<<c<<endl;
        
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}