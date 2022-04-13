//내부적으로는 max heap이거나 min heap임 
empty 일떄까지. pop하면 30 20 10 우선순위를 오름차순으로 하고싶다?

  pq.push할때 정렬방법주고시픈데 컨테이너정의할떄 vector값주고, greater라는 정렬방법을 준다. less라는함수? 30 20 10 내림차순 정렬

```
int main() {
  int n; cin >> n;
  priority_queue<int, vector<int>, greater<int> pq;
  for(int i = 0; i<n; i++){
    int x; cin >> x;
    pq.push(x);
  }

  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}
```

struct로 overloading을 통해 원하는 자료형 compare 가능
```
  greater<string>넣으면? 3 hello c++ nice, c++ hello nice 
  나만의 방식? mycompare bool=true false값
  operator 괄호연산자?

  c++ 3글자 nice 4글자 hello 5글자  
  
struct mycompare {
   bool operator() (string s1, string s2){
         return s1.length() > s2.length();
   }
 };
  
int main() {
  int n; cin >> n;
  // priority_queue<string, vector<string>, mycompare> pq;
  priority_queue<string, vector<string>, mycompare> pq;
  for(int i = 0; i<n; i++){
    string x; cin >> x;
    pq.push(x);
  }

  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

```
