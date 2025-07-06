#include <stdio.h>
#define QUEUE_MAX 100010

typedef struct {
    int num;
    int cnt;
} element;

typedef struct {

    int front;
    int back;
    element arr[QUEUE_MAX];
    int size;

}Queue;

void q_init(Queue* q){
    q->front = 0;
    q->back=0;
    q->size=0;
}

void q_push(Queue* q, element n){
    q->arr[q->back] = n;
    q->back = (q->back+1)%QUEUE_MAX;
    q->size++;
}

element q_pop(Queue* q){
    element res = q->arr[q->front];
    q->front = (q->front+1)%QUEUE_MAX;
    q->size--;
    return res;
}

int q_size(Queue* q){
    return q->size;
}

int main() {

    int n;
    scanf("%d ",&n);

    Queue q;
    Queue* qp = &q;
    q_init(qp);
    q_push(qp, (element){2,1});
    q_push(qp, (element){3,1});
    q_push(qp, (element){5,1});
    q_push(qp, (element){7,1});


    while(!(q_size(qp)==0)){
        element q_front = q_pop(qp);
        if(q_front.cnt==n){
            printf("%d\n",q_front.num);
            continue;
        }

        int nextnum;
        for(int i=0;i<=9;i++){
            nextnum = q_front.num*10+i;
            int cnt = 0;
            for(int j=1;j*j<=nextnum;j++){
                if(nextnum%j==0) cnt++;
            }
            if(cnt==1){ // 소수일때
                q_push(qp, (element){nextnum, q_front.cnt+1});
            }
        }
    }
    return 0;
}