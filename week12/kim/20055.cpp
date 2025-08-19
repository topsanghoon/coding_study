#include <iostream>
#include <vector>

using namespace std;

struct Section {
    int n;
    bool rb;
    
    Section(int n, int rb) : n(n), rb(rb){}
    
};

vector<Section> belt;
int n,k;

int getNext(int a){
    return (a-1+(2*n))%(2*n);
}

bool canMove(Section src, Section dst){
    return (src.rb && !dst.rb && dst.n>0);
}

int main()
{
    cin >> n >> k;
    belt = vector<Section>(2*n,Section(0,false));

    for(int i = 0; i<2*n;i++){
        int a;
        cin >> a;
        belt[i].n = a;
    }
    
    int cur_start = 0;
    int cur_end = n-1;

    int status = 0;
    int cnt = 0;

    while(1){
        status++;
        //회전
        cur_start = getNext(cur_start);
        cur_end = getNext(cur_end);

        belt[cur_end].rb = false;

        // 로봇 이동
        for(int i=getNext(cur_end), h=0; h<n-1 ; h++){
           
            int next = (i+1)%(2*n);

            if(canMove(belt[i], belt[next])){
                
                belt[i].rb = false;

                belt[next].n--;
                if(belt[next].n==0) cnt++;
                if(next!=cur_end) belt[next].rb = true;
                
            }

            i=getNext(i);
        }

        belt[cur_end].rb = false;
        
        //로봇 추가
        if(belt[cur_start].n > 0){
            belt[cur_start].rb=true;
            belt[cur_start].n--;
            if(belt[cur_start].n==0) cnt++;
        }

        if(cnt>=k) break;
    }

    cout << status;

    return 0;
}