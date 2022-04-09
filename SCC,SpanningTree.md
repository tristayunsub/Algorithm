Strongly Connected Component
===
https://goo-gy.github.io/2021-05-23-kruskal
크루스칼(Kruskal) 알고리즘을 이용하여 최소 스패닝 트리 (Minimum Spanning Tree) 찾기
https://velog.io/@kasterra/%ED%95%B5%EC%8B%AC-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%9E%98%ED%94%84-%EA%B9%8A%EC%9D%B4-%EC%9A%B0%EC%84%A0-%ED%83%90%EC%83%89-u0coubay

스패닝 트리란? 어떤 그래프의 부분 그래프 중에 모든 노드를 포함하고 모든 노드들이 서로
간에 경로가 존재하는 그래프를 말한다. 이 그래프는( 모든 간선의 Weigh가 양수라는 가정)당연히
트리 형태를 가짐. 최소 스패닝 트리는 간선의 weight 합이 최소가 되는 스패닝트리

그래프의 간선을 weight가 작은것부터 순회, 해당 간선을 추가할때 cycle 생성하지 않는다면 트리에 추가한다.
dfs와 union find

루스칼 알고리즘을 적용하여 트리를 만들어 나갈 때 Cycle이 생기는지 확인할 필요가 있었다. 어떤 그래프에서 Cycle이 있는지 확인하기 위해서는 쉽게 생각해서 DFS로 순회하면서 방문한 곳을 또 방문한다면 Cycle이 있다는 것을 알 수 있다. 하지만 이보다 더 효율적인 Union-Find 알고리즘을 알아보자.

< Union-Find >
Union-Find는 서로소 집합 (Disjoint Set) 을 표현하기 위해 사용하는 알고리즘이라고 한다. 
크루스칼 알고리즘에서 집합은 연결된 컴포넌트로 볼 수 있다.
간선을 확정하여 두 컴포넌트를 합칠 때 Union-Find 알고리즘을 사용할 것이다.

구현 a,b,c,d,e,f,g
Link b,d,c,d,d,f,g
size 1,2,1,4,1,1,1

![components](https://user-images.githubusercontent.com/75001605/162580138-50db03ae-46db-4f2a-b6c1-af9f15b9b168.png)
![balance](https://user-images.githubusercontent.com/75001605/162580146-9e953262-acc9-4011-90b7-b39d65e81590.png)


<parent link>
  Union find에서 연결된 컴포넌트 표현하기위해 트리구조로 표현. 각 노드가 속한 트리의 루트 노드를
  찾아낼 수 있으면 ㅗ딘다. 따라서 트리의 루트를 찾기위해서 각 노드마다 부모를 가리키는 Parent Link저장한다.
  
<size>
  두 트리를 합칠때union, 한 트리는 다른트리의 하위로. 임의로 합치면 트리의 불균형이 생길수있다.
  왼쪽size가 작은 트리를 size가 큰트리의 하위로 들어가면 트리의 불균형이 줄어들어 
  루트 노드를 찾는시간을 줄인다.


union-find 알고리즘에서는 확정된 컴포넌트를 트리구조로 표현하여 트리의 루트가 대표 노드가 된다.
union-find 단계 
  
  
1.연결시킬 두 노드가 속한 컴포넌트에서 루트 노드 찾는다
해당 노드가 속한 트리에서 부모를 계속따라가면 루트 찾을수있음
  
  
2.루트 노드가 같다면 두 노드가 같은 컴포넌트에 존재하는 것이기에, 루트 노드가 다를때만
두 컴포넌트 결합

 <kruskal with union-find>
 각 노드마다 parent link와 size 저장
 초깃값으로 parent link는 자신의 index를, size는 1을 가진다.
   
    
그래프 내의 간선을 weight가 작은 순으로 순회하면서 다음 작업 수행
  간선마다 연결된 두 노드의 루트 노드를 찾고
    루트 노드가 다르면 두 집합을 합치고 간선을 스패닝트리에 추가
 
    
```
  if(sizez[root1] < sizes[root2])
  {
    parent_links[root1] = root2;
    sizes[root2] += sizes[root1];
    
  }else
  {
    parent_links[root2] = root1;
    sizes[root1] += sizes[root2];
  }
}



int solution()
{
  sort(edges.begin(), edges.end());
  for (int i = 0; i < E; i++)
  {
    int root1 = find_root(edges[i].src);
    int root2 = find_root(edges[i].src);
    if (root1 != root2)
    { 
      union_graph(root1, root2);
    }
  }
    
}
```
    
   
![components](https://user-images.githubusercontent.com/75001605/162580536-cad9e987-4d78-4649-b959-bbe01bd56546.png)

    
 [경로 압축] $$$ 필수
  
     
 parent link는 컴포넌트에서 루트를 찾기위한 용도이다. 노드a가 노드 b보다 하위에 있다는 사실은

   
  union이 일어나더라도 변하지 않기 때문에, 루트를 한번 찾으면 중간에 거치는 노드를 생략하고
  
   
   찾은 루트를 parent link로 바로 연결할 수 있다.

```
    int find_root(int node_number)
    {
      if(node_number == parent_links[node_number])
         return node_number;
      parent_links[node_number] = find_root(parent_links[node_number]);
      return parent_links[node_number];
    
    }
    
 ```
    
    

  
방향 그래프. 
   
   사이클을 찾는거니까 반대로 역방향으로 갈때 갈 수 있다면 사이클이 아닐 수 없음을 증명하면 쉬움
  
   
   그거 이해하려면 일단 DFS 스패닝 트리에 대해서 제대로 이해해야 함. DFS 스패닝 트리가 무향일 때랑 유향일 때랑 좀 다른데 그 부분도 이해해야하고


   https://nsgg.tistory.com/126 무향 유향?
    
   DFS 스패닝트리 의 모든 ㄱ간선 4가지로 분류
   
   트리 간선(TREE EDGE):스패닝 트리에 포함된 간선
   
   
   순방향 간선(forward edge):스패닝 트리의 선조에서 자손으로 연결
   
   역방향 간선(back edge): 스패닝 트리의 자손에서 선조로 연결된 간선
   
   교차 간선(cross edge): 교차 간선은 트리에서 선조와 자손 관계가 아닌 정점들간에 연결된 간선들

2.간선의 분류 무향:
   무향 그래프의 간선은 양방향으로 통행 가능
   
   교차 간선이 없다.
   교차간선이 생기려면 선조-자손관계가 아니어야한다.
   
   하지만 무향 그래프에서는 방향과 상관없ㅂ이 연결되면
   항상 이어지기 때문에 교차 간선이 있을 수 없다.

   (u-v 가 교차 간선이기 위해서는 v가 먼저 방문된후 u를 방문하지 않고 종료해야하는데 u-v로 v가 종료되기전에 u에 방문함)

 

  순 방향 간선과 역방향 간선의 구분이 없다.
   
   3.간선 분류의 이용
   
   간선의 분류는 그래프 알고리즘을 이해하고 증명하기 위한 도구로 유용하다.
   
   위상 정렬의 정당성 증명
   
   위상 정렬 알고리즘(topology set)은 dfs의 종료 역순으로 정점을 재배열하므로
   
   dfs(u)가 dfs(v)보다 일찍 종료된 경우.(재배열 된 후 u가 뒤쪽에 있을 때)
   
   u에서 v로 가는 간선이 존재할 수 없다는 것만 증명하면 그 정당성을 보일 수 있다.
   
   -(u,v)가 트리 간선이면 dfs(u)에서 dfs(v)를 호출했다는 말이다. 그러면 dfs(u)가 먼저 종료 x
   
   -(u,v)가 역방향 간선이라면 v가 u의 선조이므로, v에서 u로 가는 경로가 있다는 뜻. 여기에(u,v)가 있으면 위상정렬은 DAG여야 한다는 가정에 모순
   
   
   -(U,V)가 순방향 간선이라면 U가 V의 선조이므로 DFS(U)가 먼저 종료 불가능
   
   -(u,v)가 교차 간선이라면 v를 방문했다는 뜻이고, dfs(v)가 먼저 종료
      (dfs(u)가 먼저 종료되었다는 가정에 모순)
   
   따라서 간선(u,v)는 존재할 수 없고, 위상 정렬의 정당성은 증명된다.
   
   사이클 존재 여부 확인
   
   사이클의 존재 여부는 역방향 간선의 존재여부와 동치이다.
   
   사이클이 있는 그래프를 깊이 우선 탐색할 경우
   
   사이클에 포함된 정점 중 깊이 우선 탐색 과정에서 처음 만나는 정점을 u라고 하자
   
   dfs(u)는 u에서 갈 수 있는 정점들을 모두 방문한 후에야 종료
   
   사이클에 포함된 u 이전에 있는 정점을 dfs(u)가 종료하기전에 방문하게 되는데,
   
   이 정점에서 u로가는 정점은 항상 역방향 간선이 된다.
   
   4. 간선을 구분하는 방법 구현: 유향
   
   가장 구분하기 쉬운 간선은 트리간선.
   
   만약 dfs 실행중 정점v를 이미 방문했다고 하면 이것이 자손인지 부모인지 알길이없다.
   
   따라서 탐색 과정에서 또 다른 정보들을 dfs중에 업데이트 시켜야한다.
   
   그 정보는 몇번째로 발견 되었는지를 기록하는 것이다.
   
   (u,v)를 검사하는데 v가 이미 방문된 상태라고 해보자.
   
   이때 방문 순서를 이용해 (u,v)를 분류할 수 있는지 확인하면 된다.
   
   
   -(u,v)가 순방향 간선이라면 v는 u의 자손이어야한다. 따라서 v는 u보다더 늦게 발견되어야한다.
   
   
   -(u,v)가 역방향 간선이라면 v는 u의 선조여야 한다. 따라서 v는 u보다 일찍 발견되었어야한다.
   
   
   -(u,v)가 교차간선이라면 dfs(v) 종료 이후 dfs(u)가  호출되어야한다. 따라서 v는 u보다 일찍 발견
   
   
이처럼 발견 순서 정보를 이용하면 해당 간선이 순방향 간선인지를 알아낼 수 있다.

 

역방향 간선과 교차 간선을 구분 짓기위해 선조인지 아닌지를 알아야하는데

 

이는 dfs(v)가 종료되었는지 확인함으로써 구분 지을 수 있다.

(종료하지 않았으면 선조라는 것이므로 역방향 간선, 아니면 교차 간선)

 
*무향에서는 discovered[]만 있으면 모든 간선을 구분할 수 있다 (교차 간선이 없음)
   
```
   vector<vector<int> > adj;
vector<int> discovered, finished;
int counter;

void dfs2(int here)
{
  discovered[here] = counter++;
  for (int i = 0; i < adj[here].size(); i++)
    {
      int there = adj[here][i];

      cout<<"("<<here<<"," <<there<<")is a";

      if(discovered[there] == -1)
      {
        cout<<"tree edge"<<endl; 
        dfs2(there);
      }
      else if (discovered[here] < discovered[there])
        cout<<"forward edge"<<endl;
      else if (finished[there] == 0)
        cout<<"back edge"<<endl;
      else
        cout<<"cross edge"<<endl;
    }
  finished[here] = 1;
  
}
```
   

5.절단점 찾기
===
   
