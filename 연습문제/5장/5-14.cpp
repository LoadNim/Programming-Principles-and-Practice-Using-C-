#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int>nums(7);
    vector<string>days;
    days.push_back("monday"); days.push_back("mon");
    days.push_back("tuesday"); days.push_back("tue");
    days.push_back("wednesday"); days.push_back("wed");
    days.push_back("thursday"); days.push_back("thu");
    days.push_back("friday"); days.push_back("fri");
    days.push_back("saturday"); days.push_back("sat");
    days.push_back("sunday"); days.push_back("sun");

    int deny = 0;
    int input_nums;
    string input_days;
    cout<<"요일과 값을 공백을 두어 입력하세요.\n";
    for(;;){
        cin>>input_days>>input_nums;
        transform(input_days.begin(), input_days.end(), input_days.begin(), ::tolower);
        vector<string>::iterator it;
        it = find(days.begin(), days.end(), input_days);
        if(it == days.end()){
            cout<<"잘못된 요일을 입력하였습니다.\n";
            ++deny;
        }
        else{
            int index = (it - days.begin()) / 2;
            nums[index] += input_nums;
        }
        try{
            char continue_input;
            cout<<"입력을 계속 하시겠습니까? (y/n) ";
            cin>>continue_input;
            if (continue_input == 'y' || continue_input == 'Y') continue;
            else if(continue_input == 'n' || continue_input == 'N') break;
            else throw invalid_argument("입력값은 y 또는 n 만 허용됩니다.\n");
        }
        catch(invalid_argument& e){
            cerr<<e.what()<<endl;
            return 1;
        }
    }
    for(int i = 0; i < days.size(); i += 2){
        cout<<days[i]<<": "<<nums[i/2]<<endl;
    }
    cout<<"입력 거부된 횟수 : "<<deny<<endl;
}