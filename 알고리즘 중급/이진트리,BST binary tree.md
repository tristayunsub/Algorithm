이진 트리란

1.공집합도 이진트리
2. 서브트리도 이진트리
3. 왼쪽 서브트리와 오른쪽 서브트리는 서로소 이다.

서브트리가 null일 경우에도 서브트리가 이진트리이려면 공집합도 이진트리여야함
만약에 

left right가 교집합있을때 사이클을 형성해버림 겹침. 그러니까 서로소여야함 겹치지않게

            1
        2         3
   4      5      6      7
   
 이진트리 순회 traversal 모든 노드를 방문하는 방법
 
 전위 preorder
 중위 inorder
 후위 postorder
 
 
 전위순회와 중위순회 결과를 받고
그걸로 이진트리 재구성한다라고하면

```
class TreeNode:
 def __init__ (self, item = 0, left = none, right =none):
     self.item = item
     self.left = left
     self.right = right

 class Solution:
def BuildTree(self, preorder: List[int, inorder: List[int]])
-> TreeNode:
 if len(preorder) == 0: // 길이가 0이면 none
     return none
 else: root, pos = preorder[0], inorder.index(preorder[0]) preorder의 첫번째가 root고, 루트노드의 인덱스번호를 pos(position)로 찾으면
 left = self.buildTree(prorder[1:pos + 1], inorder[:pos]) 
 right = self.buildTree(preorder[pos + 1:], inorder[pos + 1:])
 return TreeNode(root, left, right)
```

right에선

[     ]pos[pos+1 부터 끝까지]

left에선 
O [     ] [POS+1   ]
과정
1.preorder의 첫번째 노드는 루트 노드이고, Inorder에서 루트 노드의 위치를 찾는다.
2.인오더 에서 루트노드의 왼쪾 오른쪽의 노드들은 각각 왼쪽 오른쪽 서브트리이다.
3. 왼쪽 오른쪽 서브트리의 크기를 안다면, preorder의 왼쪽/오른쪽 preorder를 결정할 수 있다.
4. 루트노드의 왼쪽/오른쪽 서브트리의 pre/inorde를 재귀호출을 통해 연결하면. 이진트리를 구성

BST각 노드는 유일한 키. distinct 키
왼쪽 서브트리에 있는 키들은 모두 루트노드의 키보다 작다
오른쪽서브트링있는ㄴ키들은 모두 루트 노드의 키보다 크다.
왼쪽 서브트리와 오른쪽 서브트리도 이진탐색 트리이다.

unbalanced뭐 삽 삭 탐색 가능해야됨.

Search는? 

```
if this == null 
    return null
else if this key == search value
     return this 
else if this key < serach value
   serach right
else search left

7탐색해보면~ 15보다작죠~ else serach left로가죠
7이 6보다 크니까 serach right
7이 같으니까~ return this

insert

if insertion point is found
   create new vertex
else if value to be inserted < this key
  go left
else 
  go right
9넣는다.
9가 15보다 작으니까? go left
6이 9보다 크니까 go right 
leaf node찾음. 9가 7보다더크면? 오른쪽에삽입~ 만약에 6이었다면?
왼쪽에 삽입~


remove가 까다롭다.

search for v

if v is a leaf
  delete leaf v
else if v has 1 child
  bypass v
else 
  replace v with successor 
  
  만약에 자식노드가 1개면 그냥 삭제하고 그 아래꺼를 위로땡김
 
 
 
 이진탐색트리의 재구성: 1편(배열)
 
Leetcode 108
converted sorted array to binary search tree

오름차순으로 정렬된 배열을 줄게

높이가 균형잡힌 이진탐색트리를 만들어봐  

height balanced bst
모든 노드에서 왼쪾오른쪽 섭트리의 높이의 차이가 1보다 작은 BST

nums = [1,3]이잇을경우에
height balanced 

만약 -10 -3 0 5 9일때


```
def sortedarraybst(self, nums: List[int]) -> TreeNode:
if len(nums) == 0:
 return None
else:
 mid = len(nums) // 2
 root = TreeNode(nums[mid])
 root.left = self.sortedarrayToBST(nums[:mid]) // (nums[:mid] 리스트 슬라이싱  ()mid() 
 root.right = self.sortedArrayToBST(nums[mid + 1:])
 return root 
```

https://min-ingful.tistory.com/44 

파이썬에서는 문자뽑기우해 [시작인덱스, 끝 인덱스+1]하면 쉽게해결가능.

a[1:4] 하면
bcd출력

그러나 c++ sting.substr()함수는 좀다름
시작인덱스, 원하는 문자열 길이. 해당 인덱스부터 문자열 끝까지 문자열 자르고싶을때는
substr()에 인자를 시작 인덱스만 넣는다

string s = "abcdef"

string::sbustr(시작인덱스,문자열길이)
s1= s.substr(2,3) //2번인덱스부터 문자열 3개
 s1 == "cde"
 s2=s.substr(1) //1번인덱스부터 문자열끝까지
 s2 == "bcdef"이다.
 
 stl없이하려면
 
 substring구현
 
 strncpy로 구현 가능https://codingdog.tistory.com/entry/c%EC%96%B8%EC%96%B4-substring-%EA%B5%AC%ED%98%84-strncpy%EB%A1%9C-%EC%86%90%EC%89%BD%EA%B2%8C-%EB%A7%8C%EB%93%A4%EC%96%B4-%EB%B4%85%EC%8B%9C%EB%8B%A4
 
 char* strncpy(char *est,const char

서브스트링사용ㅂㅂ


리스트를 이진탐색트리로 재구ㅅ성
루트 노드를 알려면 연결리스트의 길이를 알아야 
연결 리스트의 길이를 효율적으로 알려면?
부분 리스트로 재귀호출 해야함

루트노드.
토끼와 거북이의 재림
토끼와 거북이 알고리즘?
tortoise and hare

linked list에서 순환 루프 여부를 확인하고 순환 루프의 시작 노드를 알아내는데 사용되는 알고리즘

https://velog.io/@lacomaco/%ED%86%A0%EB%81%BC%EC%99%80-%EA%B1%B0%EB%B6%81%EC%9D%B4-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-LeetCode-142

시작지점에 토끼, 거북이로 불리는 노드 포인터를 둔다.
거북이는 한 번에 한칸씩 움직인다.
토끼는 한번에 두칸씩

토끼와 거북이가 같은 노드를 가리킬때 까지 알고리즘 수행.
만약 토끼가 null을 가리키게 되면 순환 루프가 없다는 뜻이다.
둘이 같은 노드를 가리키게 되면 순환 루프가 있다는 소리가 된다.

느리게 움직이는 거부기와 빠르게 움직이는 토끼 포인터가 순환 루프에선 결국 같은 노드를 가리키게된다

알고리즘 원리. 
1.토끼와 거북이가 서로 만나면 토끼는 움직이지 않고 거북이를 linkedlist의 head로 옮긴다.
2.토끼와 거북이를 1칸씩 움직인다.
3.토끼와 거북이가 서로 만나게 되면. 그 부분이 순환 루프의 시작 노드이다.

D: head에서 순환루프 시작 노드까지의 거리
M: 순환루프 시작노드 부터 토끼와 거북이가  만난 지점 까지의 거리
R:토끼와 거북이가 만난 지점부터 순환 루프 시작 노드까지의 거리

거북이 =D +M
토끼 = 2(D+M)
토끼는 거북이 보다 2배 움직엿으므로 2*거북이가 움직인 거리 2D+2M이다.

토끼의 경우 시작노드 -> 순환 루프 시작 노드 -> 거북이와 만난 지점 
-> 루프 시작 노드 -> 거북이와 만난 지점 이런 경로로 움직였다. 


토끼 = D + M + R + M -> D + 2M + R

D + 2M + R = 2D + 2M

R = D

