#include <stdio.h>
#define MAX_ARR 200010



typedef struct _Element{
    int start;
    int end;

} Element;

int cmp(const void* a, const void* b){
    
    Element* at = (Element*)a;
    Element* bt = (Element*)b;
    
    if(at->end == bt->end){
        return at->start - bt->start;
    }
    return at->end - bt->end;
}

typedef struct _PriorityQueue {

    Element arr[MAX_ARR+1];
    int back;

} PriorityQueue;

void pq_init(PriorityQueue* pq){
    pq->back = 1;
}

int pq_is_empty(PriorityQueue* pq){
    return pq->back==1;
}

int pq_size(PriorityQueue* pq){
    return pq->back-1;
}

void pq_insert(PriorityQueue* pq, Element element){

    int cursor = pq->back++;
    pq->arr[cursor] = element;

    int next = cursor;
    Element temp;
    while(cursor>1){
        next = (cursor)/2;

        if(cmp(&pq->arr[cursor], &pq->arr[next])>=0) break;
        
        temp = pq->arr[cursor];
        pq->arr[cursor] = pq->arr[next];
        pq->arr[next] = temp;

        cursor = next;
    }
}

Element pq_pop(PriorityQueue* pq){

    Element result = pq->arr[1];
        pq->arr[1] = pq->arr[--pq->back];

    int cursor = 1;

    Element temp;
    int left, right, next;
    while(1) {
        
        next = cursor;
        left = cursor*2;
        right = cursor*2+1;
        if(left < pq->back && cmp(&pq->arr[left],&pq->arr[next])<0) {
            next = left;
        }
        if(right < pq->back && cmp(&pq->arr[right],&pq->arr[next])<0){
            next = right;
        }
        
        if(next==cursor) break;

        temp = pq->arr[cursor];
        pq->arr[cursor] = pq->arr[next];
        pq->arr[next] = temp;

        cursor = next;
    }
    
    return result;
}


int main(){

    int n;
    scanf("%d ", &n);

    PriorityQueue pq;
    PriorityQueue* pqp = &pq;
    pq_init(pqp);
    
    int s,e;
    for(int i=0;i<n;i++){
        scanf("%d %d",&s, &e);
        pq_insert(pqp, (Element){s,e});
    }

    int cur_time = 0;
    int ans = 0;
    while(!pq_is_empty(pqp)){
        
        Element qfront = pq_pop(pqp);
        if(qfront.start < cur_time) continue;

        cur_time = qfront.end;
        ans++;
        
    }
    printf("%d\n",ans);

    return 0;
}