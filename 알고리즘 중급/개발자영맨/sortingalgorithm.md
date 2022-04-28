왜 알아야되는가 기본이 된다.

어떻게 구현하느냐에 따라 속도와 메모리 사용량이 크게달라짐

sorting algorithm에도 주요한 개념들이있다.
top-down, bottoup, divide and conquer, 


상황에따라 최선의 알고리즘이 달라짐.

내장 알고리즘이 항상 최선은 아니다~ STL말하는거

필요하면 구현해서 사용할 수 있는 정도는 되어야한다

스피드가 대부분 NLOGN
쉘소트, 
퀵소트 PARTITIONING 알고리즘이 매우 중요, 인터넷에 돌아다니는 코드에 버그가 많다.
QUICKSELECT, 3-WAY

힙소트 HEAP특성을 이용해서 품

머지소트 STABLE SORT의 대표. LINKED LIST에 탁월


는 알고있어야됌. 깊이봐야됌 앞에 쉬운 버블 선택, 삽입은 의미없다.

INTROSORT. STL에서 사용하는 알고리즘
TIMESORT

점근적 표기법으로. asymptotic notation 점근적 표기법. 빅오메가나 빅세타는 

점근적 표기법 사용법 개중요

점근적 표기법


O(!) A++;
    b++
     c= a + b; 

o(N) FOR(int i = 0; i < n; i++){
     ~
}

o(3n) for(int i = 0; n*3; i++)
   
o(n/2)  for(int i = 0; i<n; i += 2)
    

O(N^2 + n) for(int i ... i<n)
    
    for(int i = 0; i < n; i++){
        for(int j n)
    }

O((n^2+n)/2) for(int i =0, i<n)
    for(int i =0; i < n;){
        for(j....)
    }

logn은 logarithmic time

linear time

n^2 quadratic time

2^n exponentioal time ->안쓸꺼임

factorial time 도 안쓸꺼임

여기서도 주어진 공간에 어딘가에 복사해 두는 작업이 필요하지 않는 알고리즘

in place algorithm.
    
    buble sort
    shell sort
    heap sort
    quick sort
    
    not -in place 
    merge sot
    couting sort 이런것들
