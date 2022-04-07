using pint = pair<int, int>;  // pint라는 단어로 짧게 사용가능 두 정수가 들어있는 구조체 직접 한게아니라 pair라는 구조체로 int두개묶음
#define x first 
#define y second

const int inf = 1e9;

priority_queue<pint, vector<pint>, greater<pint> > q;



https://gall.dcinside.com/mgallery/board/view/?id=ps&no=16915&s_type=search_subject_memo&s_keyword=stl&page=2

https://www.youtube.com/watch?v=BKBXM7ypQG0&list=PL1w8k37X_6L9NXrP1D31hDTKcdAPIL0cG&ab_channel=KnowledgeCenter STL playlist
list 웬만하면 쓰지마셈
불편한 (그리고 느린) list를 써야만 풀수 있는 문제는 별로 없으니깐
duque를 많이쓴다.

2.STL 구성요소
1.컨테이너(container) 2.반복자(iterator) 3.알고리즘(algorithm) 4.함수자(functor)
  1.컨테이너: 객체를 저장하는 객체로 컬렉션 혹은 자료구조
  2.반복자: 포인터와 비슷한 개념으로 컨테이너의 원소를 가리키고,가리키는 원소에 접근하여 다른 원소를 가리킨다.
  3.알고리즘:정렬, 삭제, 검색, 연산등을 해결하는 일반화된 방법을 제공하는 함수템플릿
  4.함수객체: 함수처럼 동작하는 객체로 operator()연산자를 오버로딩한 객체
  어댑터: 구성 요소의 인터페이스를 변경해 새로운 인터페이스 갖는다
  5.할당기: 컨테이너 메모리 할당 정책을 캡슐화한 클래스 객체.
    
   Container
   표준 시퀀스 컨테이너: standard sequence container: 컨테이너 원소가 자신만의 삽입 위치 를 가지는 컨테이너
   _vector,deque 등
   -표준 연관 컨테이너(Standard associative. container) 저장 원소가 삽입 순서와 다르게특정 정렬기준에
   의해 자동 정렬되는 컨테이너, _set, map등
 
 # string 컨테이너 : 시퀀스 컨테이너의 일종이지만, 문자열만을 저장

- 배열 기반 컨테이너(array-based container) : 데이터 여러 개가 하나의 메모리 단위에 저장 _ vector, deque 등

- 노드 기반 컨테이너(node-based container) : 데이터 하나를 하나의 메모리 단위에 저장 _ map, set 등
   
  
  iterator:
컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할
컨테이너 내부의 원소를 가리키고 접근
컨테이너의 모든 원소를 순회할 수 있어야함.
순방향 반복자 forward iterator: 입력, 출력. 반복자 기능에 순방향으로 이동
양방향 반복자: 순방향 반복자 기능에 역방향으로 ㅣ이동

set,mpa, 등은 양방향 반복자
vector, deque등은 임의 접근 반복자

sequence container: 순서 있게 자료를 보관
associative container: key 값과 짝지어 자료를 보관

sequence container: 많지 않은 자료를 보관
검색속도가 중요한 경우 사용

sequence container 
-vector
-list
-deque

associative container 종류
map, set hash_map, hash_set, multi_map, multi_set, hash_multimap, hash multiset
multi는 중복되는 key 값을 사용할때, map과 set은 자료를 정렬하여 저장하고 정렬순으로 순회
hash는 정렬필요없고 빠른검사

예를 들면 순열알고리즘

permutation 알고 서로 다른 n개의 원소에서 r개를 뽑아 한줄로 세우는 경우의 수
nPr이라고 나타낸다. 순서가 부여된 임의의 집합을 다른 순서로 뒤섞는 연산.
  
 만약[1,2,3]이라는 리스트의 모든 순열값은
 [
    [1, 2, 3],
    [1, 3, 2],
    [2, 1, 3],
    [2, 3, 1],
    [3, 1, 2],
    [3, 2, 1]
]

3! 은 6이나온다.
  
  여기서 잠깐 DFS와 BFS배워보자
  
  
