https://www.youtube.com/watch?v=RxT7F6YA3TI&list=PL6YHvWRMtz7DS3hVaqMazHujPcKVfblQa&index=6&ab_channel=ezsw
```
//BFS
  #include <iostream>
  #include <cstring>
  #include <queue>
너비 우선 탐색.

시작 노드에서 인접 노드를 모두 방분하고, 방문한 노드에서 인접 노드를
모두 방문하는 것을 반복하게 된다.

 
//Queue 를 활용한 BFS

using namespace std;

#define MAX_N 10

int N, E;
int Graph[MAX_N][MAX_N]; //인접배열 for문끝나면 인접배열정보가들어감.


int main() {
    cin >> N >> E; //N은 정점, e는 간선의수 5,6

  memset(Visited, 0, sizeof(Visited));
  memset(Graph, 0, sizeof(Graph));
  for (int i = 0; i < E; ++i){
    int u, v;
    cin >> u >> v; //노드의 쌍을 읽어오기.
    Graph[u][v] = Graph[v][u] = 1; //무방향이다. 0에서1로도간다.
    
  }
  bfs(0);
  return0;
  
  
}


void bfs(int node) {
  bool visited[MAX_N] = { false };

  queue<int> myqueue;
  visited[node] = true; //push하기전에방문했다고 마킹. queue에 먼저들어간 노드가 항상 먼저 방문한다. 그래서 eneque할피룡가ㅓㅇㅄ음.
  myqueue.push(node);
  
  while(!mypush.empty()){
    int curr = myqueue.front();
    myqueue.pop();

    cout << curr << ' ';

    for (int next = 0; next < N; ++next){
      if (!visited[next] && Graph[curr][next]){
        visited[next] = true;
        myqueue.push(next);
      }
    }
  }


```
   
 ```                               
// BFS 활용. SHORTEST PATH
  //
int N, F;
int Graph[MAX_N][MAX_N];

                                

struct Point {
 int row, col, dist;
};

int D[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //상하좌우움직임
int N, Board[MAX_N][MAX_N];
  
int main() {
  cin >> N;
  for(int i =0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      cin >> Board[i][j];

  int srcRow, srcCol, dstRow, dstCol;
  cin >> srcRow >> srcCol  >> dstRow >> dstCol ; //색칠할위치 sr, sc color

  cout << bsf(srcRow, srcCol, dstRow, dstCol);
    return 0; 
}

void bfs(int srcRow, int srcCol, int dstRow, int dstCol) {
   bool visited[MAX_N][MAX_N] = {false};
   queue<Point> myqueue;
   visited[srcRow][srcCol] = true;
   myqueue.push({srcRow, srcCol, 0}); //c++ 문법 중괄호넣으면 struct안 변수에 assign된다.

   while(!myqueue.empty()) {
     Point curr = myqueue.front(); // 1
     myqueue.pop();
     if(curr.row == dstRow && curr.col == dstCol) 
       return curr.dist;

    
     for (int i = 0; i < 4; ++i){ //인접한노드를 push한다.
       int nr = curr.row + D[i][O], nc = curr.col + D[i][1];//지금행열값에 델타값 준다. 행과열의 좌표가 새로만들어짐.
       if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;//조건준다. 아래로벗어나면안되고. 열좌표도 벗어나면안되고. row값.
//예를들면 nr <0은. -1이되소 위로올라가서 벗어나면안되니까 row값이..
그래서 nr < 0 조건. 또 로우가 N보다 커지면.. 당연히 벗어나니까안되고. column도 옆으로가면안되고.. 
       if (visited[nr][nc]) continue; //방문했으면 스킵. 
       if (Board[nr][nc] == 1) continue;//벽만나도 스킵.
       myqueue.push({nr, nc, curr.dist+1});
       
       
     }
   }
  return -1;
}
  ```
  //빈공간방문 짧은경로로
