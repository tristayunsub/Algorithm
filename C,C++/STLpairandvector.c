// pair 정의 first, second인 두개의 변수를 저장할수 있는 struct
// 용도. 이차원배열 인덱스, 이차원 좌표평면에서의 자표, 정점 번호와 해당 정점 번호까지의 최단거리 저장

예제
```
//pair 선언
pair<int, int> p;
pair<char, dobule> p;

//pair 생성

int a = 1, b = 2;
pair<int, int> p = make_pair(a, b);
pair<int, int> p = make_pair(1, 2);

//pair 멤버 변수에 접근
int valA = p.first;
int valB =  p.second;
```
first가 1이고 second가 2인 pair를 만들기위해 pair<int,int> 선언후에 각 멤버변수를 
초기화해주는 것이 아니라 make_pair를 이용해 바로 만들어낼 수 있다는 것을 알아두면 좋을 것 같습니다



2. vector
1)정의
사이즈가 유동적인 배열

<vector>는 많이사용되는 컨테이너

편의상 함수의 적용 대상이 되는 벡터는 v

v.size() v의 사이즈를 리턴. 원소의 개수

v.resize(new_size) v를 new_size사이즈로 바꿔줌

v.empty() v의 사이즈가 0인지 아닌지

v.begin() v의 0번쨰 원ㅅ를 가리키는 iterator 리턴
v.end() v의 마지막 원소를 가리키는 iterator 리턴
v.front() v의 0번쨰 원소를 리턴
v.back() v의 마지막 원소를 리턴
v.push_back(val) v의 끝에 val를 추가
v.pop_back() v의 마지막 원소를 삭제
v.clear() v의 모든 원소를 삭제

예로 reverse()사용하면 vector에 속한 원소들의 순서가 뒤집어진다.
  
  vector 1 5 2 3 이라면. reverse()한 결과는 3 2 5 1 이된다.
  reverse(v.begin(), v.end());

sort()이용하면 vector에 속한 원소를 오름차순정렬
sort(v.begin(), v.end());

4.vector 예제

```
vector<int> iv;
vector<pair<int, int>> pv;

사이즈가 3인 vector 생성
vector<int>  myv(3);

//사이즈가 n(5)이고 각 원소가 2로 초기화된 vector 생성
int N = 5;
vector<int> myv(N, 2);

//vector에 원소 추가
iv.push_back(1); // iv: 1
iv.push_back(2); //iv : 12
iv.push_back(3); //iv: 1 2 3

pv.push_back(make_pair(2, 4));

///vector 사이즈 조정
iv.resize(4);
cout << iv.size(); //4

cout << iv.front(); //1
cout << iv.back(); //0 (resize를 4로했기떄문에 마지막원소는 자동적으로 0이된다).

iv.pop_back(); // iv: 1 2
iv.clear(); //iv: 

Queue
FIFO 자료구조

용도
BFS
2다리에 올라갈 수 있는 최대 하중과 각 트럭의 무게가 주어질때 모든 트럭이 다리를 지나가는데 걸리는 최소시간 문제
```
q.size() q의사이즈리턴
q.empty() q의사이즈가 0인지 아닌지 확인
q.front() q에 가장 먼저 들어간 원소를 리턴
q.back() q에 가장 나중에 들어간 원소를 리턴
q.push(val) q의 위(뒤에 val 추가)
q.pop() q에 가장 먼저 들어간 원소를 삭제
```
4.예제
````
queue<pair<int, int>> q;

q.push(make_pair(1,2));

int a = 2, b = 3;
pair<int, int> p = make_pair(a,b);
q.push(p);

cout << q.front().first << ' ' << q.front.second; // 1 2
cout << q.back().first << ' ' << q.back().second; // 2 3

//q가 비어잇찌 않는동ㅇ안
while(!q.empty())
{
   pair<int, int> n = q.front();
   q.pop();
  
  cout << n.first << ' ' << n.second << '\n'; // 1 2
                                              // 2 3
}
 
cout << q.size(); //0

q.push(make_pair(4,5));
q.push(make_pair(5,6));

q.push(make_pair(4,5));
q.push(make_pair(5,6));

queue<pair<int, int>> emt;
swap(q, emt);

cout << q.size(); // 0

29번째 줄을 보면 swap이라는 함수를 사용한 것을 볼 수 있습니다. 자주 쓰이지는 않지만, vector와는 달리 queue는 clear() 멤버 함수가 없으므로 swap이라는 함수를 이용해 clear() 하고자 하는 queue를 빈 queue와 swap해줌으로써 clear()와 같은 효과를 낼 수 있습니다. 이렇게 swap을 이용하는 것이 queue가 빌 때까지 원소를 pop()하는 것보다 빠르기 때문에 알아두는 것이 좋겠습니다.

2. stack

LIFO 후입선출 자료구조

DFS깊이우선탐색

만약 어떤 일의 실행순서를 기록해두었다가 나중에 일의 순서를 반대로 출력하고 싶은 경우, 일을 실행할 때마다 stack에 차례대로 push 해두었다가 모든 일을 실행하고 나서 stack이 빌 때까지 pop하면 된다)

  <STACK> include해야합ㄴ디ㅏ.
  
   s.size()

 s의 사이즈(물리적인 저장 용량이 아닌 원소의 개수)를 리턴

 s.empty() 

 s의 사이즈가 0인지 아닌지를 확인

 s.top()

 s에 가장 나중에 들어간 원소를 리턴

 s.push(val)

 s의 뒤에 val 추가 

 s.pop()

 s에 가장 나중에 들어간 원소를 삭제

4.예제
```
stack<int> s;

for(int i=1; i<=5; i+=)
      s.push(i);

cout << s.size();      //5

//s가 비어있지 않는 동안
while(!s.empty())
{
   int n = s.top(); // 정수 n은 stack의 top이다.
   s.pop();
  
   cout<< n << '\n';         // 5 4 3 2 1
}

cout << s.size();   //0

```
5.map
인덱스로 int가 아닌다른 자료형을 사용하는 배열

후에 사용법을 이해하기 편하도록 '배열'이라고 했지만, map의 내부적인 구조는 각 노드가 key와 value의 쌍으로 이루어진 '트리'입니다. 특히 검색, 삽입, 삭제 등의 속도를 빠르게 하기 위해 균형 이진 트리 중의 하나인 '레드 블랙 트리'로 구현되어 있습니다. 검색 속도가 특히 빠른데 이는 key를 기준으로 정렬된 상태이기 때문입니다

2)용도
연관 있는 두 값을 함께 묶어서 관리하되 검색을 빠르게 하고 싶은 경우
만약 SNS상 사람들의 친구 관계를 그래프를 이용해 나타내고, 
이 그래프에 여러가지 알고리즘들을 적용해 멋진 일들을 하고 싶다고 합시다.
  일반적인 경우라면, 사람을 정점으로, 사람들 간의 친구 관계를 간선으로 나타내게 되겠죠??
  문제는! 그래프의 연결관계를 배열에 저장하려면, 각 정점을 사람 이름으로 나타내는 것이 아니라 번호로 나타내야 한다는 점입니다. 그러려면, 어떤 과정이 필요할까요?? 사람의 이름을 정점의 번호로 변환해주는 과정이 필요하겠죠?? 이 때, map을 이용해 문제를 해결할 수 있습니다. key를 사람의 이름으로, value를 정점 번호로 묶어서 저장해놓는다면 나중에 몇 번 정점에 해당하는지 알고 싶은 사람의 이름이 있을 때, 이름을 검색해 해당 정점 번호를 빠르게 알아낼 수 있습니다.


  3)사용법
  map을 위해선 <map> 인클루드
  
 map은 unique 중복 불가한 key와 value 쌍으로 이루어진 노드의 트리
 key값을 갖는 노드를 추가하면? 해당 key값을 갖고있던 원래 노드의 value 값에 더퍼씌워진다.
  (2,3)인 노드a가 이미 존재하는 map에 2,4인 노드 b를 추가하려는 경우, 노드 a의 value가 4로 덮어 씌워지고
  map에는 key가 2인 노드는 하나만 존재하게된다.
  map요소에 접근할떄 ,iterator, 인덱스key를 이용하는 방식두가지
  
  m.size() 사이즈리턴
  m.empty
  m.begin
  m.end
  m[k] = v
  m.insert(make_pair(k,v)) m에 key가 k이고, value가 v인 노드 추가
  m.erase(k) m에서 key가 k인 노드삭제
  m.find(k) m에서 key가 k인 노드를 찾아, 해당 노드를 가리키는 iterator 리턴
  m.count- m에서 key가 k인 노드의 개수를 리턴.
  
  map의 첫번째 원소 삭제 m.erase(m.begin())
  vector v에 있는 모든값 추가 -> m.insert(v.begin(), v.end())
  
  map은 iterator를 자주 사용하기에 잘 사용법을 익혀야함.
  
```
  map<char, int> m;
  map<char,int>::iterator it;
 
  m['B'] = 2;         //m: (B,2)
  m.insert(make_pair('A', 1));  //m : (A,1) (B,2)
  m.['C'] = 3;       // m : (A,1) (B,2) (C,3)

  m.erase('A');       // m: (B,2) (C,3)

//m 전체를 순회하며 key와 value 출력
for(it = m.begin(); it != m.end(); it++)
  cout << it -> first << ' ' << it->second << '\n';

if(m.find('B') != m.end())
   cout << "key값이 B인 노드가 존재합니다." << '\n';
else
   cout << "key 값이 B인 노드가 존재하지 않습니다." << '\n';

```
 find가 key가 k인 노드를찾아~ 해당 노드 가리키는 이터레이터~
 
 
 6.set
 key만 있는 map 혹은 정렬된 집합
 
 (set은 map과 구조가 매우 유사. key만있고 value가 없는 map이라고 생각 할 수 있습니다.
  따라서 방법도 map과 크게 다르지 않습니다. 정렬된 집합이라고 정의한 이유는 set이 갖는 값들이 중복을
  허락하지 않고 정렬되어있기 때문입니다. (위의 map에서 설명한 key값의 특성)
  
  ```
  set<int> s;
set<int>::iterator it;
 
s.insert(4);               //s : 4
s.insert(1):               //s : 1 4
s.insert(2);               //s : 1 2 4
 
vector<int> v;
v.push_back(3);            //v : 3
v.push_back(5);            //v : 3 5
v.push_back(6);            //v : 3 5 6
 
s.insert(v.begin(), v.end());        //s : 1 2 3 4 5 6
 
s.erase(4);                //s : 1 2 3 5 6
s.erase(s.begin());        //s : 2 3 5 6 
 
//지울 원소를 입력받음
int toErase;
scanf("%d", &toErase);
 
it = s.find(toErase);
 
//지울 원소가 존재하는 원소일 때만 지움
if(it != s.end())
    s.erase(it); //예를들면~ toErase에 2,3,5, 다들어간다치면 6만나믄ㄴ다.
 
```


출처: https://sarah950716.tistory.com/6?category=598483 [주니어 개발자의 대나무숲]

  
