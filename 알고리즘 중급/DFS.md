
```
//DFS 깊이 우선 탐색.
  #include <iostream>
  #include <cstring>
  #include <stack>
인접 노드가 없는 경우 이전 노드가 돌아가서, 다시 깊이 우선 탐색을 반복한다.

using namespace std;

#define MAX_N 10

int N, F;
int Graph[MAX_N][MAX_N]; //인접배열 for문끝나면 인접배열정보가들어감.
bool Visited[MAX_N]; //방문여부 마킹

int main() {
    cin >> N >> E; //N은 정점, e는 간선의수 5,6

  memset(Visited, 0, sizeof(Visited));
  memset(Graph, 0, sizeof(Graph));
  for (int i = 0; i < E; ++i){
    int u, v;
    cin >> u >> v; //노드의 쌍을 읽어오기.
    Graph[u][v] = Graph[v][u] = 1; //무방향이다. 0에서1로도간다.
    
  }
  dfs(0);
  return0;
  
  
}


void dfs(int node) {
  Visited[node] = true;
  cout << node << ' ';

  for (int next = 0; next < N; ++next) {
    if(!Visited[next] && Graph[node[next]])//0에ㅓ서부터 방문할때
방문한곳은없고 그래프노드는없으니까 dfs(1)만나러가고.. 이렇게 재귀적으로 계속for문이 1에서 2로가는 그래프는없으니까 false고 3으로가는건 있으니까 방문.)
      dfs(next);
  }
}

```

// DFS-STACK방법. 차이점bool visited가없고, memset도 그래프만존재.
//재귀호출 너무많이하면 스택오버플로.

```
int N, F;
int Graph[MAX_N][MAX_N];


void dfs(int node) {
  bool visited[MAX_N] = {false}; //로컬로 결정.

   stack<int> mystack;
   mystack.push(node);

   while (!mystack.empty()){
    int curr = mystack.top();
    mystack.pop();

    if(visited[curr]) continue;

    visited[curr] = true;
    cout << curr << ' ';

    for( int next = 0; next < N; ++ next){
      if(!visited[next] && Graph[curr][next])
        mystack.push(next);
    }
  }
}
입력하면 
5 6
0 1 0 2 1 3 1 4 2 4 3 4 

0 2 4 3 1 순으로 출력된다.

```


DFS 활용 Flood fill
2차원 공간에서도 활용가능.

5
0 0 0 0 0 
0 0 0 1 1
      1 0
      1 0
1 1 1 1 0
1이라는 벽 닿을떄까지 3채워넣기

```
struct Point {
 int row, col;
};

int D[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //상하좌우움직임
int N, Board{MAX_N}{MAX_N};
int main() {
  cin >> N;
  for(int i =0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      cin >> Board[i][j];

  int sr, sc, color;
  cin >> sr >> sc >> color; //색칠할위치 sr, sc color
  dfs(sr, sc color);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        cout << Board[i][j] << ' ';
        
      }
      cout << endl;
    }
    return 0;
}

void dfs(int r, int c, int color) {
   bool visited[MAX_N][MAX_N] = {false};
   stack<Point> mystack;
   mystack.push({r, c}); //row column 시작위치 push

   while(!mystack.empty()) {
     Point curr = mystack.top(); // 1
     mystack.pop();
     if(visited[curr.row][curr.col]) continue;

     visited[curr.row][curr.col] = true;
     Board[curr.row][curr.col] = color;

     for (int i = 0; i < 4; ++i){
       int nr = curr.row + D[i][O], nc = curr.col + D[i][1];
       if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
       if (visited[nr][nc]) continue;
       if (Board[nr][nc] == 1) continue;
       mystack.push({nr, nc});
       
       
     }
   }
}

```
