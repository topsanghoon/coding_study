 #include <iostream>
 #include <vector>
 #include <queue>

 using namespace std;

 int main(){

    int N;
    cin >> N;
    
    priority_queue <long long, vector<long long>, greater<long long>> q; 
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }

    long long answer = 0;
    while(q.size() != 1){
        long long num1, num2;
        num1 = q.top(); q.pop();
        num2 = q.top(); q.pop();

        long long sum = num1 + num2;
        answer += sum;
        q.push(sum);
    }

    cout << answer;

    return 0;
 }