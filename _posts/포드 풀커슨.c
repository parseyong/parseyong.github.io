#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define MAX_NODES 1000
#define O 1000000000

int n; //정점개수
int e; // 간선 개수
int capacity[MAX_NODES][MAX_NODES]; //용량
int flow[MAX_NODES][MAX_NODES];  // 유량
int as[MAX_NODES];
int pred[MAX_NODES];

int min(int x, int y) {
    return x < y ? x : y; // x와 y중 작은 값 리턴
}

int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x) {
    q[tail] = x;
    tail++;
    as[x] = B;
}

int dequeue() {
    int x = q[head];
    head++;
    as[x] = C;
    return x;
}

int bfs(int start, int target) {
    int u, v;
    for (u = 0; u < n; u++) {
        as[u] = A;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head != tail) {
        u = dequeue();
        for (v = 0; v < n; v++) {
            if (as[v] == A && capacity[u][v] - flow[u][v] > 0) {
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    return as[target] == C; //증가경로 찾는 함수
}

int fordFulkerson(int source, int sink) {
    int i, j, u;
    int max_flow = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            flow[i][j] = 0; //   유량값 초기화 
        }
    }

    while (bfs(source, sink)) {
        int increment = O;
        for (u = n - 1; pred[u] >= 0; u = pred[u]) {
            increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]); // 증가경로상에 있는 정점에 용량-유량값 대입
        }
        for (u = n - 1; pred[u] >= 0; u = pred[u]) {
            flow[pred[u]][u] += increment;  
            flow[u][pred[u]] -= increment;  //증가경로상에 있는 정점에 용량-유량값 대입, f(u,v)=-f(u,v)
        }
        max_flow += increment; 
    }
    return max_flow;
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            capacity[i][j] = 0; //용량값 초기화
        }
    }
    n = 6; //n은 정점의 개수 소스와 싱크 포함
    e = 7; // e는 간선의 개수

    capacity[0][1] = 10;
    capacity[0][3] = 10;
    capacity[1][2] = 15;
    capacity[2][3] = 6;
    capacity[2][5] = 10;
    capacity[3][4] = 25;
    capacity[4][5] = 10;  //용량값 지정
    

    int s = 0, t = 5; // s는 소스 t는 싱크
    printf("최대 유량은: %d\n", fordFulkerson(s, t));
}

