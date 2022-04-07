```
for (int i =0; i<maxv; i++) d[i] = inf;
q.emplace(0, start); 우선순위 큐
d[start] = 0;  스타트로 향하는 거리 는 0부터시작, 정점 now와 now로 향하는거리 nowd

while (!q.empty()) {
       int nowd = q.top().x, now = q.top().y; q.pop();
       if (d[now] != nowd) continue;
     
       for( pint k : g[now] ) {
             int nxt = k.x, nxtd = nowd + k.y;
             if (nxtd < d[nxt]) {
                d[nxt] = nxtd;
                q.emplace(nxtd, nxt);
             }
    
     }
}

```
classic한 구현

1. dist[start] = 0
2. 방문한적이없는 정점들중 dist[x]가 가장 작은 정점x를 찾아서,
3. 정점 x와 연결된 각 정점 i 에 대해,
   dist[x] +(간선의 길이)가 dist[i]보다 작으면, dist[i] = dist[x] + (간선의 길이)로 갱신한다.
4. 방문한 적이 없는 정점이 남아있으면 2번으로 돌아간다.
     
     더빠르게할수있었던 이유 dist를 우선순위 큐를 이용해서  직접 방문하지 않는 정점들을 모두 보지않고도
     우선순위 큐에서 찾을 수 있었다. 우선순위큐를 사용할때 visited 변수를 쓰지않았다.
      최단경로를 찾았을때 딱 한번만 전파시켜 각 정점을 한번만 방문하게했다.
     
     이걸 확인하는게 if (d[now] != nowd) continue;이다.
       
     구현할때 매우 어렵다.
       
      
      
     Dijkstar 알고리즘 가중치가 음수인 간선이 존재할때에는 시간 복잡도가 보장되지 않는다!
       
     그래프에 음의 사이클이 존재할 경우 무한루프 돌게된다.
       간선의 가중치가 모두 양성일떄만해야됨
       
       
       Bellman-Ford 알고리즘이다.
       1. dist[start] = 0. 나머지 i에 대해 dist[i] = inf.
       2. 각 간선(u,v) 길이 = l 에대해 dist[v] = min(dist[v], dist[u] + l)
       3.2번 과정을ㄹ V-1번 반복해준다.
       4.최단 경로는 단순 경로이므로, 최단 경로의 길이는 많아야 V-1이다.
       
       
       예를들면 dist[u] = 10, dist[v] = 30 이라하자. 그때 간선의 길이가
       4면, dist[v]=14로 갱신되게됌 - 간선을 완화해준다.
       
       증명
       임의의 점v에 대해ㅓ서, 시작점 start 에서 v까지의 최단경로가 존재한다.
       간선완화를 경로의 길이만큼 반복해주면 start에서 v까찌 최단경로구해진다.
       
       완화 과정이 안끝날떄가있따. 그래프에 음의사이클.
       이를 이용해 그래프에 음의 사이클이 존재하는지 체크
       ```
       int a[maxe], b[maxe], d[maxe];
       
       for ( int _=0; _<v _++) for ( int=0; i<e; i++){
          if (d[a[i]] + w[i] < d[b[i]])
               d[b[i]] = d[a[i]] + w[i];
              }
        ``` 
              
       다익스트라 (ElogV), 이론적으로는 O(E+VlogV)
       SPFA 알고리즘은 벨만포드 알고리즘 성능향상. 음수 간선이 있는 그래프
       O(VE)이지만 O(V+E)로정도로 동작
       
       
      플로이드 알고리즘?
          간선에 가중치가있는 그래프
          모든 시작 정점 u와 끝 정점 v에 대하여
          
          
          u에서 v로가는 최단 경로의 길이
          
          다이나믹 프로그래밍
     dp[x][y]: 정점x에서 정점 y로 가는 최단거리
     
     초기조건 dp[0][x][y]는 x와 y사이 간선이 있을 때만 (간선의 길이), 아니면 무한대
     
     dp[k][x][y]
     1.dp[k][x][y] = dp[k-1][x][y]
     2.dp[k][x][y] = dp[k-1][x][y] + dp[k-1][k][y]
     두 dp식의 합
     3.dp점화식
      dp[k][x][y] = min(dp[k-1][x][y], dp[k-1][x][k] + dp[k-1][k][y])
      dp[x][y] = min(dp[x][y], dp[x][k] + dp[k][y])
         
          for(int k=0; k<n; k++) 
              for (int i=0; i<n; i++)
                 for( int j=0; j<n; j++)
                   dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      다익스트라보단 오래걸린다.
        
     
                1번부터 k-1번까지 정점갈떄
                1번부터 k-1번까지 이용해서 만든 최단경로 어딘가에 k번정점을 끼워넣는다.
          binarysearch랑 비슷한거같은데?
          섞은건가?
          
         
          
       https://security-nanglam.tistory.com/413
bfs문제풀기 나중에
       
       
       
       
