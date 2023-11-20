#include <iostream>
#include <stdexcept>
using namespace std;

double ctof(double c){
    return c * 1.8 + 32;
}

double ftoc(double f){
    return (f - 32) / 1.8;
}

int main(){
    try{
        double c;
        cout<<"화씨 값으로 변환할 섭씨 값을 입력하세요 : ";
        if(!(cin>>c)) throw logic_error("섭씨에 double값이 아닌 다른 값이 들어왔습니다.\n");
        cout<<"섭씨 값 "<<c<<"를 화씨 값으로 변환하면 : "<<ctof(c)<<endl;

        double f;
        cout<<"섭씨 값으로 변환할 화씨 값을 입력하세요 : ";
        if(!(cin>>f)) throw logic_error("화씨에 double값이 아닌 다른 값이 들어왔습니다.\n");
        cout<<"화씨 값 "<<f<<"를 섭씨 값으로 변환하면 : "<<ftoc(f)<<endl;
    }
    catch(logic_error& e){
        cerr<<e.what()<<endl;
        return 1;
    }
}