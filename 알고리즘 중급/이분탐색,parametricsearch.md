https://www.youtube.com/watch?v=3TkaOKHxHnI&t=10s&ab_channel=BaaarkingDog

BOJ 1920 수찾기

0  1 2 3 4 5 6 7 8 9
2 4 6 13 16 19 22 23 30 32

입력받은후에 STL sort함수써서 정렬
st와 en변수

st = 0
en = 9 
로둔다. 범위안에 우리가찾고싶어하는 값이 없을수도있따
mid = (st+en)/2
(st+en)이 홀수면 나머지는 버려
mid= 4 , A[mid] 와 19의 값을 비교 st, en값 적절히바꿈
A[mid]=16, 찾고시픈값 19 mid이하의 인데스에는 19가없고
st= mid + 1로 절반으로 범위줄이기가능

또 mid = (st+en)/2 반복

A[mid]와 target 을 비교해보면 A[mid] = 23은 19보다 크기 때문에

mid인덱스에는 19가없고 en = mid-1로 변경
이걸 계속반복해나감

A[mid]=19가 우리의 target

만약 배열아네 내가 찾고싶어하는 수가없으면?
배열에서 10찾아보자. 
mid는 16
A[mid] > target => en = mid - 1
A[mid] = target -> st= en = mid 


```
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binarysearch(int target) {
       int st = 0;
       int en = n-1;
       while(st <= en) {
        int mid = (st+en)/2;
        if(a[mid] < target)
         st = mid + 1;
         else if(a[mid] > target)
          en = mid-1;
          else
          return 1;
        }
          return 0;
     }
     
int main(void) {
  ios::sync_With_stdio(0);
  cin.tie(0);
  cin >> n;
  for( int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int m;
  cin >> m;
  while(m--) {
       int L;
       cin >> t;
       cout << binarysearch(t) << '\n';
     }
 }

 ```
 
 BOJ 10816번 숫자카드2
 
