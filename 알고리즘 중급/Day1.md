segement tree
===
https://www.youtube.com/watch?v=XaodfglnhVs&list=PLN3yisVKGPfhOAeqrYNun0Fu_O_gWy1mx&index=4&ab_channel=IOIKOREA

https://www.youtube.com/watch?v=075fcq7oCC8&ab_channel=%EA%B0%9C%EB%B0%9C%EC%9E%90%EC%98%81%EB%A7%A8 segment tree rangequery

길이 n의 수열 a1,a2,a3 an이 주어진다 다음쿼리르  출력하라

L,R이 주어지면 AL+ ... AR을 출력하라

위 문제는 누적합 배열 Si를 만드는것으로 간단하게 O(N) 전처리 쿼리당O(1)에 해결할 수 있다.
X,V가 주어지면 Ax를 V로바꿔라

누적합 배열을 사용하면 값 변경 쿼리를 O(N)에 할 수밖에없다.
세그먼트트리로 O(logN)으로.

각 노드는 특정구간을 대표


위상정렬
Topological sort,DAG(Directed acyclic graph 의 정점을 정렬
dag란 간선에 방향성이있으며 순환경로가 없는그래프
즉,a번 정점에서 b번 정점으로 가는 간선이있으면 a가 b보다 왼쪽에있어야함
시간복잡도: O(V+E)

Degree:차수. 무방향그래프에서 정점에 연결된 간선의 개수
In degree: 방향 그래프에서 정점에 들어가거나 나가는 간선의 개수

1.Indegree가 0인 정점 v선택
2.v를 정렬 결과에 추가 그래프에서 삭제
3.모든 정점이 사라질떄까지 반복
.
Queue Indegree가 0인 모든점을 담은 자료구조

1 -> 3 -> 5->라하면

1이 들어갔고 pop하고 3들어가고 pop 5 모든정점이 들어갈떄까지 반복


```
in[i] : 배열 in i번 정점의 indegree 값
con[i] : 간선들을 저장한 인접리스트 i 번 정점이 가리키는 정점들의 집합

std:vector <int> order;
std:;queue <int> que;
For (int i=1; i<=N;i++) if (!in[i]) //indegree가 0인 정점을 모두넣기
         que.push(i);
While (!que.empty()){ //que가 비어있을떄까지 반복
            int V = que.front(); que.pop();
            order.push_back(V);
            for ( int t : con[V]){
                if ( !--in[t]){ //정점 V를 지워서 indegree 가 새롭게 0이 된 정점 t
                             que.push(t);
                   }
             }        
        }
```        

예를들면 v가1이다 
근데 정점1을 지운다음에 그다음정점은? 3이된다. 
건설시간과 우선시간. 확정 순서가 곧 위상정렬 순서이면 계산이 용이ㅏ다.

정점마다 건설시간을 확정지어야 다음 정점에 대한 계산이 가능.


<절선 및 절점>

undirected graph G=(v,e)가 주어졌을떄 간선 e가 지워지면 connected component의 개수가
증가하는 겨우에, 간선e를 절선 bridge라고칭함

임의의 점1번점을 시작으로 DFS Spanning tree 구성
정점마다 자신의 subtree에서 가장 높이 올라갈수있는 depth
만약 자신보다 높이 못가는 자식이 하나라도있으면 자신은 절점이다.

root노드의 경우는 자식이2개이상이면 절점이고 아니면 절점이아님




3.Deuque를 이용한 구간쿼리 구하기.


최소값찾기
n개의 수 A1,A2,An과 L이 주어진다.
Di = A(i-L+1)~Ai 중의 최소값

이라고 정의할 때 D1,D2,... DN을 구하시오

예로 N=5, L=3일때

 A  2 3 5 4 1

D1 2                =2
D2 2 3               =2
D3 2 3 5             =2
D4      3 5 4          =3
D5      5 4 1         =1 

이됨
삭제하는 수가 최소였다면 최소값이 변한다. 이경우에 다음닶은?
최소값이었던 1보다 오른쪽에있으면서 가장작은 2
최소값의 위치 -> 다음 답 -> 다다음 답의 위치
의 CHAIN을 저장
1 3 2 4 =1
최소위치
1

3 2 4 
 최소위치
 3   >   4
  2     4
  
  수를 추가한 후에 CHAIN을 올바르게 갱신하면 답을 구함
  
  1 3 2 4
  
  풀이 앞에 수를 제거할때: CHAIN의 맨 앞 수를 빼거나 그냥 놔둔다
  뒤에 수를 추가할때: CHAIN의 맨 뒤 몇 개 의 수를 뺀 후 하나를 새로 넣는다
  
  위와 같은 일을 할 수 있으면 답을 구할수있다.
  각 구간의 답은 CHAIN의 맨 앞수로 구할수있다.
  
  Deque은 Double-ended queue
  양끝에서 삽입삭제를 모두할수있는 queue
  std:deque
  
  예시
  2 3 5 4 1
  
  chain은 비어있다. 
  2추가하면 chain에는 1  -> D1 = A1 =2
  처리한구간 뒤에 3추가. D2=A1=2
  5추가하면 체인위치추가 D3=A1=2
  첫번째위치 CHAIN에서 맨앞수빼줌
  2 3에 4추가 CHAIN에 4추가. CHAIN3의 숫자 5가 CHAIN4의숫자 4보다 크므로 체인3도삭제
  그럼 체인 2 4 D4=A2=3
  CHAIN2제거 CHAIN 4 5 에서 CHAIN4가 4고 CHAIN5가1이다 크니까 체인삭제
  CHAIN5만남음 D5=A5=1
  
  이런식으로풀면. O(N)번일어나고. 삽입삭제마다 O(1)의 시간이 걸림
  
  
  쿼리의 구간의 길이가 일정하지만. TWO POINTER가 가능할떄는 굳이 쿼리가 일정하지않아도 이방법사용가능
  
  다만. max,min등의 제한적인 쿼리에서만 이 방법을 사용할수있다.
  
  
  UNION & FIND
  DISJOINT SET?
  
  
