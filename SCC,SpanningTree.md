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
    
    ![components](https://user-images.githubusercontent.com/75001605/162580536-cad9e987-4d78-4649-b959-bbe01bd56546.png)

    
    [경로 압축] $$$ 필수
  ```
    
    
    
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
    
    
    

  
방향 그래프
사이클을 찾는거니까 반대로 역방향으로 갈때 갈 수 있다면 사이클이 아닐 수 없음을 증명하면 쉬움
그거 이해하려면 일단 DFS 스패닝 트리에 대해서 제대로 이해해야 함. DFS 스패닝 트리가 무향일 때랑 유향일 때랑 좀 다른데 그 부분도 이해해야하고



