#include <iostream>
using namespace std;

int main(){
    int penny;
    cout<<"몇 페니를 가지고 계세요?\n";
    cin>>penny;
    int nickel;
    cout<<"몇 니켈을 가지고 계세요?\n";
    cin>>nickel;
    int dime;
    cout<<"몇 다임을 가지고 계세요?\n";
    cin>>dime;
    int quarter;
    cout<<"몇 쿼터를 가지고 계세요?\n";
    cin>>quarter;
    int half_dolar;
    cout<<"몇 하프 달러를 가지고 계세요?\n";
    cin>>half_dolar;
    int dolar;
    cout<<"몇 달러를 가지고 계세요?\n";
    cin>>dolar;

    if(penny){
        if(penny!=1) cout<<"You have "<<penny<<" pennies.\n";
        else cout<<"You have 1 penny.\n";
    }
    else cout<<"You have not any penny.\n";
    if(nickel){
        if(nickel!=1) cout<<"You have "<<nickel<<" nickels.\n";
        else cout<<"You have 1 nickel.\n";
    }
    else cout<<"You have not any nickel.\n";
    if(dime){
        if(dime!=1) cout<<"You have "<<dime<<" dimes.\n";
        else cout<<"You have 1 dime.\n";
    }
    else cout<<"You have not any dime.\n";
    if(quarter){
        if(quarter!=1) cout<<"You have "<<quarter<<" quarters.\n";
        else cout<<"You have 1 quarter.\n";
    }
    else cout<<"You have not any quarter.\n";
    if(half_dolar){
        if(half_dolar!=1) cout<<"You have "<<half_dolar<<" half dolars.\n";
        else cout<<"You have 1 half dolar.\n";
    }
    else cout<<"You have not any half dolar.\n";
    if(dolar){
        if(dolar!=1) cout<<"You have "<<dolar<<" dolars.\n";
        else cout<<"You have 1 dolor.\n";
    }
    else cout<<"You have not any dolar.\n";
    int cent = penny+(nickel*5)+(dime*10)+(quarter*25)+(half_dolar*50)+(dolar*100);
    cout<<"The value of all of your coins is $"<<cent*0.01<<endl;
}