
https://www.youtube.com/watch?v=fFsjQSNPK0U&list=PLHqxB9kMLLaP2OFW2u63xTnJDjLKsD1IF&index=2&ab_channel=%EC%A3%BC%EB%8B%88%EC%98%A8TV%EC%95%84%EB%AC%B4%EA%B1%B0%EB%82%98%EC%97%B0%EA%B5%AC%EC%86%8C


```
int main() {
   int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  v.push_back(5);//깜빡한거 추가해줌. pushback은 v.end가 가리키는곳에다 값을 집어넣음. 그럼 20 30 10있을때 뒤에 5넣는다. v.end,


  //iterator? vector<int>::iteratr를 auto로 문법대체가능
  // vector<int>::iterator it = v.begin();
  auto it = v.begin();
  for(auto& it: v)
  cout << it << " ";

  //이렇게써도 결과가 같다
  for (int i: v)
    cout << i << " "; 


  
//정렬 함수 구현해보자
sort(v.begin(), v.end()); //만약 v.end대신에 v.begin() + 3하면 첫번째부터 3번째까지 값만 정렬
for (int i: v)
    cout << i << " "; 

  //find 10
  int x; cin >> x;
  auto it = find(v.begin(), v.end(), x);//find함수는 vector 10 20 30 주면 v.begin v.end x값하고 같은게있는지 확인 iterator 타입은. vector<int>::iterator *it가 가리키는 주소의 값
  if (it != v.end())
     cout << "I found " << *it << "!" <<endl;
  else
    cout<< "I cant found "<< x << "!" << endl;
}

```
