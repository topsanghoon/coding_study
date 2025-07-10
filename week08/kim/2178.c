#include <stdio.h>
#define QUEUE_MAX 10010
#define MAX_ARR 100
typedef struct  {

    int y;
    int x;
    int depth;

} Node;

typedef struct {

    int front,back;
    int size;
    Node arr[QUEUE_MAX];

} Queue;

void q_init(Queue* q){
    q->front = 0;
    q->back = 0;
    q->size = 0;
}

void q_push(Queue* q, Node node){
    q->arr[q->back] = node;
    q->back = (q->back+1)%QUEUE_MAX;
    q->size++;
}
Node q_pop(Queue* q){
    Node fr = q->arr[q->front];
    q->front = (q->front+1)%QUEUE_MAX;
    q->size--;
    return fr;
}

int q_size(Queue* q){
    return q->size;
}


int ny[4] = {1,-1,0,0};
int nx[4] = {0,0,1,-1};
char arr[MAX_ARR][MAX_ARR] = {};
int n,m;
int ans = -1;
int main() {

    scanf("%d %d ",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }

    Queue q;
    Queue* qp = &q;
    q_init(qp);

    arr[0][0] = '0';
    q_push(qp,(Node){0,0,1});
    
    while(!q_size(qp)==0){
        
        Node qfront = q_pop(qp);
        if(qfront.y == n-1 && qfront.x == m-1){
            ans = qfront.depth;
            break;
        }

        int nextx,nexty;
        for(int i=0;i<4;i++){

            nexty = qfront.y + ny[i];
            nextx = qfront.x + nx[i];

            if(!(0<=nexty && nexty<n)) continue; // 범위에 맞는지 확인
            if(!(0<=nextx && nextx<m)) continue;
            if(arr[nexty][nextx]=='0') continue;
            arr[nexty][nextx] = '0';
            q_push(qp,(Node){nexty,nextx,qfront.depth+1});
        }
    }

    printf("%d\n",ans);
    
    return 0;
}