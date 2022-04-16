decisiom problem
최적의 해 optimization problem 이라고한다.

예 f(x)=0을 만족하는 x를 찾아라

yes-no 답이 있는 질문을 decision problem이라고 한다.

decision_procedure = true f(x) >=0 
                     false f(x) <0
 특정값 이상에서는 항상 yes, 그 이하에서는 no라면 binary search로 최적의 해를 찾을 수있다.
 
 특정 값 이상에서는 항상  yes, 그이하에서는 no라면 최적의 해는 yes 영역의 lower bound이다!
 
 ```
  
 int lowerBound(int A[], int size, int key) {
   int lo = 0;
   int hi = size - 1;

   while (lo <= hi) {
     int mid = (lo + hi) / 2;
     if( A[mid] < key)
       lo = mid + 1;
     else
       hi = mid - 1;
   }

   return lo;
 }


bool decide(int x) {

  //return true or false

  
}

int solve(int lo, int hi){
  while(lo <= hi){
    int mid = (lo + hi) /2;
    if(decide(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
    
  }
  return lo;
}
 ```
 
 high는 true인 구간에서만 하고 , low는 false일때 한칸더 앞으로 갈수도있다.
 
 bst이야기ㅣ?
 
 
 
