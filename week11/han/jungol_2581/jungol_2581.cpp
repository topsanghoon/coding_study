    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    // https://jungol.co.kr/problem/2581
    // 예산

    int N, M;
    vector<int> arr;

    int answer = 0;
    int sum = 0;

    void searchMax(int left, int right){
        int mid = (left + right) / 2;
        int tempSum = 0;
        for(int i = 0; i < (int)arr.size(); i++){
            if(arr[i] <= mid) tempSum += arr[i];
            else tempSum += mid;
        }

        if(left > right) {
            answer = mid;
            return;
        }
        if(tempSum > M) searchMax(left, mid - 1);
        else searchMax(mid + 1, right);
    }

    int main(void){
        cin >> N;
        for(int i = 0; i < N; i++){
            int temp;
            cin >> temp;
            sum += temp;
            arr.push_back(temp);
        }
        cin >> M;
        sort(arr.begin(), arr.end());
        int maxOne = *max_element(arr.begin(), arr.end());
        if(sum <= M){
            cout << maxOne;
            return 0;
        }
        else{
            searchMax(1, arr[arr.size()-1]);
        }
        cout << answer;
    }