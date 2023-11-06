#include <iostream>
#include <cmath>
using namespace std;

int chess_board(int limit){
    int i = 0;
    int sum = 0;
    while (sum <= limit) sum += pow(2, i++);
    return i;
}

int main(){
    cout<<"쌀 1,000톨까지 필요한 체스보드 칸의 갯수 : "<<chess_board(1000)<<endl;
    cout<<"쌀 1,000,000톨까지 필요한 체스보드 칸의 갯수 : "<<chess_board(1000000)<<endl;
    cout<<"쌀 1,000,000,000톨까지 필요한 체스보드 칸의 갯수 : "<<chess_board(1000000000)<<endl;
}