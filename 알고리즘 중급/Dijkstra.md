다익스트라. 하나의 시작 정점에서 끝 정점까지 최단 경로를 구하는 알고리즘.

우선순위 큐사용. pair int 사용, Max heap과 min heap minheap이 필요.

queue 내부적으로 사용할 자료형.

//1.모든 정점까지 거리 구하기.

노드개수 6, 간선개수 9

6 9 

0 1 50

0 2 30
1 3 30
1 4 70


```
#include <iostream>
#include <queue>

#define INF 987654321
#define MAX_N 10

typedef pair<int, int> pii;

int N, E;
int Graph[MAX_N][MAX_N], Dist[MAX_N], Prev[Max_N]; -> 경로가 필요한 경우. 이전 경로 흔적 기록하는거 Prev로 추가.



int main() {
  cin >> N >> E;
  for( int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(i == j ) Graph[i][j] = 0;
      else        Graph[i][j] = INF; 
    }
  }

  for( int i =0; i < E; ++i){
    int u, v, cost;
    cin >> u >> v >> cost;
    Graph[u][v] = Graph[v][u] = cost;
  }

  dijkstra(0);

  int curr = 5;
  while(curr != -1){
    cout << curr << " < ";
    curr = Prev[curr];
  }

  

  for(int i = 0; i < N; ++i)
    cout << Dist[i] << ' ';
  cout << endl;
  return 0;
}



void dijkstra(int src) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  bool visited[MAX_N] = {false};
  for(int i=0; i<N; ++i) {
    
    Prev[i] = -1; Dist[i] = INF;
    
    }
  Dist[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    if(visited[u]) continue;

    visited[u] = true;
    for(int v = 0; v < N; ++v) {
      if( Dist[v] > Dist[u] + Graph[u][v]) {

        Prev[v] = u;
        Dist[v] = Dist[u] + Graph[u][v];
        pq.push(make_pair(Dist[v], v));
      }
    }
  }
}

```
보면 

DIST 배열과

0    1    2    3  4   5
INF INF INF INF INF INF

이값을 이제 0이 True로 바뀌면서 방문하면서~ dist값과~
  
  거기다가 0에서 1이나 2로갈때 들어가는 간선의 비용 50이나 30

이런것들을 더해가면서 
```
for(int v = 0; v < N; ++v) {
      if( Dist[v] > Dist[u] + Graph[u][v]) {
        Dist[v] = Dist[u] + Graph[u][v];
        기존의 비용보다 적은지 비교하면서~ 많약에 거리가 이전 경로보다 작다면~ push 진행. 그리고 visited 5까지 T가 되도록 연산진행

        마지막엔 90이라는 정답.
        
visited가보인다.

0 1 2 3 4 5
F F F F F F
```
  
  ```
//다익스트라 특징 Greedy algorithm이다. 매 선택에서 가까운 노드부터 탐색., 음의 가중치는 허용되지 않음.

//Dynamic programming 새로운 노드까지 최단 경로를 구하기 위해서 이전에 계산한 결과를 사용.

//수학적 증명
최단 경로를 구성하는 부분 경로도 최단 경로이다.
        정점 s에서 정점 d까지가는 최단경로.
        안에 부분 경로도 최단경로이다.

        P: 최단 경로가 결정된 정점의 집합( 방문된 정점.)
          Dist[s] = 0
          s a x가있을때

           dist[a] < dist[x] 우선순위큐에서 작은거먼저 꺼냈겠지
         모순됬고 가정자체가 잘못됨.   b,y있을때 y를 먼저 방문했을리가없다 방문하지않은 정점중에서 y가나왔다는건 비용이 가장 적은방법.
```
           
           
//다잉ㄱ스트라 특정 도착점까지 거리 구하기.

특정 도착점 구하는데.

    for( int i =0; i < N; ++i){
      cout << dijkstra(0, i) << endl;
    }
    return 0;
  }

  요렇게 나온다.

//특정도착점 거리구하기 2. 다른점 . void 대신 int 

  ```
  int dijkstra(int src, int dst) {//dst가 추가
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  bool visited[MAX_N] = {false};
  for(int i=0; i<N; ++i) {
    
   Dist[i] = INF;
    
    }
  Dist[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()){
    int u = pq.top().second;
    if ( u == dst) return pq.top().fisrt;//추가 비용을 반환 pop된 정점이 도착점과 같다고하면 그 비용을 바로 반환. 함수 실행 종료. dst u로해도되고. first로 반환해도됨.
    pq.pop();
    if(visited[u]) continue;

    visited[u] = true;
    for(int v = 0; v < N; ++v) {
      if( Dist[v] > Dist[u] + Graph[u][v]) {

        Dist[v] = Dist[u] + Graph[u][v];
        pq.push(make_pair(Dist[v], v));
      }
    }
  }
  return INF;  
}
  ```
    
   dijkstra(0, 3)들어가면.
     
     0 1 2 3 4 5 에서 4까지 값나오고
       
       visited 0 1 2 3 까지 방문하고 3 pop
