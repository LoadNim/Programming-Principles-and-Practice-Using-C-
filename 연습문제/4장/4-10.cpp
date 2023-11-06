#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int>com = {1, 2, 1, 3, 3};
    cout<<"가위 바위 보 게임\n";
    for(int i = 0; i < 5; ++i){
        int rsp;
        string user;
        cout<<"무엇을 내시겠습니까? : ";
        cin>>user;

        if(user == "가위") rsp = 1;
        else if(user =="바위") rsp = 2;
        else if(user == "보") rsp = 3;
        else{cout<<user<<"는 잘못된 입력입니다.\n"; exit(1);}

        switch(rsp){
            case 1:
                if(com[i] == 1) cout<<"비겼습니다.\n";
                else if(com[i] == 2) cout<<"졌습니다.\n";
                else cout<<"이겼습니다.\n";
                break;
            case 2:
                if(com[i] == 1) cout<<"이겼습니다.\n";
                else if(com[i] == 2) cout<<"비겼습니다.\n";
                else cout<<"졌습니다.\n";
                break;
            case 3:
                if(com[i] == 1) cout<<"졌습니다.\n";
                else if(com[i] == 2) cout<<"이겼습니다.\n";
                else cout<<"비겼습니다.\n";
                break;
        }
    }
}