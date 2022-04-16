Segement tree란

주어지는 연속된 데이터에 대한 구간 연산을 O(log n) 시간에 할 수 있는 자료구조.
Update: 특정 위치에 대한 업데이트를 O(logn)에 가능
Query: 구간에 대한 연산을 O(logn)에 계산

complete tree 의 특성.
segment tree의 부모-자식 간의 index 번호 규칙.

  부모에서 자식으로 내려가는경우, 자식에서 부모로 올라가는경우.
  맨위에서부터 차곡차곡 채워온다. 맨 마지막 레이어만. 다안차도된다.
  자식 왼쪽 i*2, 오른쪽 i*2 +1.
  올라갈때 i/2, j/2
각 segement에 부여된 번호는 segement 저장을 위한 배열의 index로 사용함.  
