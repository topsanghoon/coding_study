#include <stdio.h>
#include <stdlib.h> // qsort 이용

#define MAX_ARR_SIZE 200010

typedef struct _PriorityQueue {

    int arr[MAX_ARR_SIZE];
    int back;

} PriorityQueue;

void pq_init(PriorityQueue* pq){
    pq -> back = 0;
}

void pq_push(PriorityQueue* pq, int value){

    int cursor = pq->back++;
    pq->arr[cursor] = value;
    

    int parent,temp;
    while(cursor){

        parent = (cursor-1)/2;
        if(pq->arr[parent] <= pq->arr[cursor]) break;
        
        temp = pq->arr[parent];
        pq->arr[parent] = pq->arr[cursor];
        pq->arr[cursor] = temp;
        
        cursor = parent;    
    }
}

int pq_is_empty(PriorityQueue* pq){
    return pq->back == 0;
}

int pq_size(PriorityQueue* pq){
    return pq->back;
}


int pq_pop(PriorityQueue* pq){

    if(pq_is_empty(pq)) return -1;
    
    int result = pq->arr[0];
    pq -> back--;
    pq->arr[0] = pq->arr[pq->back];

    int cursor = 0;
    int left, right, temp, next;
    while(1){

        next = cursor;
        left = cursor*2 + 1; // 1부터 시작했을 시 cursor*2
        right = cursor*2 + 2; // 1부터 시작했을 시 cursor*2+1
        
        if(left < pq->back && pq->arr[left] < pq->arr[next]) next = left;
        if(right < pq->back && pq->arr[right] < pq->arr[next])next = right;

        if(next==cursor) break;
        
        temp = pq->arr[next];
        pq->arr[next] = pq->arr[cursor];
        pq->arr[cursor] = temp;
        
        cursor = next;
    }

    return result;
}


int main() {

    PriorityQueue q;
    PriorityQueue* qp = &q;
    pq_init(qp);

    int n;
    scanf("%d ",&n);
    int k;
    for(int i=0;i<n;i++){
        scanf("%d ",&k);
        pq_push(qp,k);
    }

    int ans = 0;
    
    while(pq_size(qp) >= 2){

        int a = pq_pop(qp);
        int b = pq_pop(qp);
        ans += a+b;
        pq_push(qp,a+b);
    }
    
    printf("%d\n",ans);
    return 0;
}