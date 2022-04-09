LCA
===


https://blog.naver.com/dudals5018/221373700337 binary lifting
https://www.youtube.com/watch?v=dOAxrhAUIhA&ab_channel=Errichto lca

https://www.youtube.com/watch?v=oib-XsjFa-M binary lifting

1.binary lifting은 up이라는 2차원 배열을 사용한다. 
트리에서 각 노드의 조상들을 기록하는 배열
ㄱ러나 전부 기록하는게아니라 2의 지수승만큼 위에있는 조상만 기록한다.

예를들어, 노드가 총 N개 있는 트리에서 노드 u가 있다면
up[u][0]은 노드 u 보다 2^0 = 1 칸 위에 있는 노드의 인덱스를 저장한다.(즉,부모)
up[u][1]은 노드 u보다 2^1 = 2 칸위에 있는 노드의 인덱스를 저장한다.
up[u][1]은 노드 u보다 2^2 = 4 칸위에 있는 노드의 인덱스를 저장한다.

up[u][ceil(logN)은 노드u보다 한마디로 root

up배열은 dfs로 0(Nlogn)만에 구해진다.

up[u][0]은 부모이고 0이 아닌 i에 대해 up[up[u][i-1]][i-1]


2. isAncestor라는 함수를 사용한다..
트리를 dfs 했을 때, discover time과 finish time을 이용해 상수시간 만에
두 노드가 조상관계인지 확인하는 함수

3.준비된 up배열과 isAncestor를 이용해 binary searh하듯 LCA찾으면된다.

물론 서로가 조상관계인지 체크

lca(u,v)를 찾으려면 v는 가만히두고. u에대해서 수행
i를 처음에 ceil로둔다.
i가 음수가될떄까지 아래과정 반복
up배열이 v의조상이라면 i만 -1
up가 v의 조상이 아니라면 u = up가 되고 i도 -1하낟.

i가 음수가 되면 자연스레 다음이 성립한다.
u는 v의 조상이 아니고, up[u][0] v의 조상이다.
up[u[0] LCA(u,v)

전체시간 복잡도는 O(nlogn) 쿼리당O(lgn)

tree of size N, rooted at 0

given v and k, find k-th ancestor of v

repeat k times:
 v = parent[v]
 
 if you just brute force it O(Q*N) -> O(... + Q*log(N))
 
 divide by two 
 bs
 Divide and conquer
 
 powers of two
segement trees
binary lifting
sparse table

n=100
1 ,2,4,8... 64 available powers

int up[N][LOG]
up[v][j] -- 2^j-th ancestor of v

for v = 0 N-1;
up[v][0] = parent[v]
FOR J = 1... LOG-1;
 up[v][j] = up[up [v][j-1]][j-1]
up[u][1] = up[up[v][0][0]
up[u][2] = up[up[v][1][1]
up[u][3] = up[up[v][2][2]

how do we know fourth ancestor
if we know second it
we can combine them
eigth ancestour 

every node each of any nodes 

log of logarithm of depth of tree






