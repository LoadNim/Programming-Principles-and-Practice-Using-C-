#include <iostream>
#include <string>
using namespace std;

void simple_error(){
    cout<<"simple_error(\"장난치지 마세요!\")\n";
    exit(1);
}

int main(){
    string first_name;
    cout<<"편지 받을 사람의 이름을 입력하세요\n";
    cin>>first_name;

    string friend_name;
    cout<<"친구의 이름을 입력하세요\n";
    cin>>friend_name;

    char friend_sex;
    cout<<"친구의 성별을 입력하세요 (남자 : m, 여자 : f)\n";
    cin>>friend_sex;

    int age;
    cout<<"편지 받을 사람의 나이를 입력하세요\n";
    cin>>age;
    if(age <= 0 || age >= 100) simple_error();

    cout<<"친애하는 "<<first_name<<",\n";
    cout<<" 잘 지내시죠? 저는 잘 지냅니다. 보고싶네요.\n";
    cout<<"요즘 "<<friend_name<<" 만난 적 있으신가요?\n";
    if(friend_sex == 'm') cout<<friend_name<<"을 보시거든 그에게 저한테 전화해달라고 전해주세요.\n";
    else cout<<friend_name<<"을 보시거든 그녀에게 저한테 전화해달라고 전해주세요.\n";

    if(age < 12) cout<<"내년에 "<<age+1<<"살이 되겠군요.\n";
    else if(age == 17) cout<<"내년에는 투표를 할 수 있겠네요.\n";
    else if(age > 70) cout<<"은퇴 후를 잘 즐기고 계시지요?\n";
    cout<<"당신의 친구, \n\n";
}