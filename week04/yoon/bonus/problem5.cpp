#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <direct.h>

using namespace std;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    FILE* f = freopen("problem5.txt", "r", stdin);
    if (f == NULL) {
        printf("failed!\n");
        return 1;
    } else {
        printf("success\n");
    }
    #endif

    int N, goal_y, goal_x;
    cin >> N >> goal_y >> goal_x;
    goal_y--, goal_x--; // 0-indexed

    cout << N << goal_x << goal_y << "\n";

    vector<vector<int>> height(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> height[i][j];

    vector<vector<int>> cost(N, vector<int>(N, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // 바깥(높이 0)에서 테두리 셀로 들어오는 경우: 높이^2 만큼 초기 비용으로 설정
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (y == 0 || y == N - 1 || x == 0 || x == N - 1) {
                int initial_cost = height[y][x] * height[y][x];
                cost[y][x] = initial_cost;
                pq.push({initial_cost, y, x});
            }
        }
    }

    while (!pq.empty()) {
        int cur_cost, y, x;
        tie(cur_cost, y, x) = pq.top(); pq.pop();

        if (cur_cost > cost[y][x]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            int diff = height[ny][nx] - height[y][x];
            int move_cost = 0;
            if (diff > 0) move_cost = diff * diff;  // 오르막
            else if (diff < 0) move_cost = -diff;   // 내리막
            // 평지면 0

            int new_cost = cur_cost + move_cost;
            if (cost[ny][nx] > new_cost) {
                cost[ny][nx] = new_cost;
                pq.push({new_cost, ny, nx});
            }
        }
    }

    cout << cost[goal_y][goal_x] << "\n";

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF 1e9

typedef struct {
    int y, x;
} Coord;

typedef struct {
    Coord data[MAX * MAX * 8];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int y, int x) {
    q->data[q->rear++] = (Coord){y, x};
}

Coord dequeue(Queue* q) {
    return q->data[q->front++];
}

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
    int N, dest_y, dest_x;
    scanf("%d", &N);
    scanf("%d %d", &dest_y, &dest_x);
    dest_y--, dest_x--; // 0-indexed

    int height[MAX][MAX];
    int cost[MAX][MAX];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &height[i][j]);

    // initialize cost
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cost[i][j] = INF;

    Queue q;
    init_queue(&q);

    // 테두리 셀 초기화 (외부에서 진입하는 높이^2 비용으로 시작)
    for (int i = 0; i < N; ++i) {
        int edge[] = {0, N - 1};

        for (int j = 0; j < 2; ++j) {
            int y = i, x = edge[j];
            int c = height[y][x] * height[y][x];
            if (cost[y][x] > c) {
                cost[y][x] = c;
                enqueue(&q, y, x);
            }

            y = edge[j], x = i;
            c = height[y][x] * height[y][x];
            if (cost[y][x] > c) {
                cost[y][x] = c;
                enqueue(&q, y, x);
            }
        }
    }

    while (!is_empty(&q)) {
        Coord cur = dequeue(&q);
        int y = cur.y, x = cur.x;

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            int diff = height[ny][nx] - height[y][x];
            int move_cost = 0;

            if (diff > 0) move_cost = diff * diff;
            else if (diff < 0) move_cost = -diff;

            int new_cost = cost[y][x] + move_cost;
            if (new_cost < cost[ny][nx]) {
                cost[ny][nx] = new_cost;
                enqueue(&q, ny, nx);
            }
        }
    }

    printf("%d\n", cost[dest_y][dest_x]);
    return 0;
}

*/

/*  c코드 우선순위 큐 기반
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF 100000000
#define HEAP_SIZE (MAX * MAX * 4)

typedef struct {
    int cost, y, x;
} Node;

typedef struct {
    Node arr[HEAP_SIZE];
    int size;
} MinHeap;

void swap(Node* a, Node* b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(MinHeap* h, int cost, int y, int x) {
    int i = ++(h->size);
    h->arr[i] = (Node){cost, y, x};

    while (i > 1 && h->arr[i].cost < h->arr[i / 2].cost) {
        swap(&h->arr[i], &h->arr[i / 2]);
        i /= 2;
    }
}

Node pop(MinHeap* h) {
    Node ret = h->arr[1];
    h->arr[1] = h->arr[h->size--];

    int parent = 1;
    while (1) {
        int left = parent * 2;
        int right = parent * 2 + 1;
        int smallest = parent;

        if (left <= h->size && h->arr[left].cost < h->arr[smallest].cost)
            smallest = left;
        if (right <= h->size && h->arr[right].cost < h->arr[smallest].cost)
            smallest = right;

        if (smallest == parent) break;

        swap(&h->arr[parent], &h->arr[smallest]);
        parent = smallest;
    }

    return ret;
}

int empty(MinHeap* h) {
    return h->size == 0;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int N, dest_y, dest_x;
    scanf("%d", &N);
    scanf("%d %d", &dest_y, &dest_x);
    dest_y--, dest_x--; // 0-indexed

    int height[MAX][MAX];
    int cost[MAX][MAX];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &height[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cost[i][j] = INF;

    MinHeap heap = { .size = 0 };

    // 테두리 셀을 외부 진입 지점으로 초기화
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (y == 0 || y == N - 1 || x == 0 || x == N - 1) {
                int init_cost = height[y][x] * height[y][x];
                if (cost[y][x] > init_cost) {
                    cost[y][x] = init_cost;
                    push(&heap, init_cost, y, x);
                }
            }
        }
    }

    while (!empty(&heap)) {
        Node cur = pop(&heap);
        int y = cur.y, x = cur.x;
        int cur_cost = cur.cost;

        if (cur_cost > cost[y][x]) continue;

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            int diff = height[ny][nx] - height[y][x];
            int move_cost = 0;
            if (diff > 0) move_cost = diff * diff;
            else if (diff < 0) move_cost = -diff;

            int new_cost = cur_cost + move_cost;
            if (new_cost < cost[ny][nx]) {
                cost[ny][nx] = new_cost;
                push(&heap, new_cost, ny, nx);
            }
        }
    }

    if (cost[dest_y][dest_x] == INF)
        printf("-1\n");  // 도달 불가
    else
        printf("%d\n", cost[dest_y][dest_x]);

    return 0;
}


*/
