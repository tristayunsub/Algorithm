세그먼트 트리의 재귀 구현

update 함수( 점갱신)

[S,E]
[S,MID] [MID+1,E]
.... 
X


```
#define SIZE (1 << 20) // 2^20 ( =1048576)
int tree [2 * SIZE]; 2의 20승사이즈

//A[X] = V로 갱신
//초기 호출 : update(X, V, 1, 1, SIZE)
void update(int X, int V, int node, int S, int E) {
    if(S == E) { 내가 배열에 X번쨰 위치에 기억위치하겠다. node,S,E 세값은 트리에서 NODE번호, 이노드는 수열에 S부터E까지 원소 관리
         tree[node] = V; 
         return;
      }
      
      int MID = (S + E) /2;
      if(X <= MID) update(X, V, 2 * node, S, MID);
      else update(X, V, 2 * node + 1, MID + 1, E);
  }
  
  ```
  
