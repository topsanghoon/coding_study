#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N,K,P,X;
int number[10][7] = {
{1,1,0,1,1,1,1}, //0
{0,1,0,1,0,0,0}, //1
{1,1,1,0,1,1,0}, //2
{1,1,1,1,1,0,0}, //3
{0,1,1,1,0,0,1}, //4
{1,0,1,1,1,0,1}, //5
{1,0,1,1,1,1,1}, //6
{1,1,0,1,0,0,0}, //7
{1,1,1,1,1,1,1}, //8
{1,1,1,1,1,0,1}  //9
};
//숫자를 바꿀때 토글해야하는 갯수를 반환
int convert_num(int num1,int num2){
    int count =0;
    for(int i=0;i<7;i++){
        int tmp1=number[num1][i];
        int tmp2=number[num2][i];
        //cout<<"i: "<<i<<" tmp1:"<<tmp1<<" tmp2:"<<tmp2<<'\n';
        if(tmp1 != tmp2) count++;
    }
    return count;
}

int toggles_between(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int len = max(sa.size(), sb.size());

    while (sa.size() < len) sa = "0" + sa;
    while (sb.size() < len) sb = "0" + sb;

    int total = 0;
    for (int i = 0; i < len; i++) {
        total += convert_num(sa[i]-'0', sb[i]-'0');
    }
    return total;
}

int main() {
    cin>>N>>K>>P>>X;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if(i == X) continue;
        if (toggles_between(X, i) <= P){
            //cout<<"X:"<<X<<" i:"<<i<<" answer:"<<answer<<'\n';
            answer++;
        } 
        
    }
    cout << answer;

    return 0;
}