BigO notation Examples
===


https://www.youtube.com/watch?v=Mo4vesaut8g&t=555s&ab_channel=freeCodeCamp.org

Advanced: Worst case

```
#Typical
s = set()
for i in range(50000):
        s. add(i = 47)       #O(1)
        
```
O(N), wall time : 10.3ms

Worst
s = set()
for i in range(50000):
      s.add(i = (2**61-1))

O(N^2) , wall time: 34.2s

3300x slower!

Big-O doenst have to be complicated
```
function linearFunc(Arr){
   for( let i = 0; i <arr.length; i++) { <O(n)
   console.log(1000 * 100000) <- constant time
   }
  }
  
 const arr = [1,2,3,4,5,6,7]
 linearFunc(arr)
 ```
 dont be fooled by big numbers its just constant time
 
 
O(N) + O(1) + O(1) = O(n)


```
function sqaure(n){
 for (let i = 0 ; i < n; i++) {
       for (let j = 0 ; j < n; j++) { nested loop
     console.log(i, j);
     }
   }
  }
O(n^2)
```

O(n^2) matrix
rows, columns.
 j       i
 
O(n cubed O^3)


```
function cube(n){
 for (let i = 0 ; i < n; i++) {
       for (let j = 0 ; j < n; j++) { nested loop
           for (let k = 0 ; k < n; k++)
     console.log(i, j, k );
     }
   }
  }
O(n^3)
```

I        J      K
height  row cloum
three dimensional


Loalgorithm nuber^number?

?^? = 8

Log28=3

2^3= 2x2x2= 8

O(logN)

n=8

```
function logFunc(n) {
  if(n == 0) return "Done";
  n= Math.floor(n / 2);
  return logFunc(n);
 }

```

```
 function logn(n) {
   while( n > 1 ) {
     n = Math.floor(n/2)
     }
   }
```   
   
   iteration 1 : n = 8/2 =4
   floors the result of our division
   
   Math.floor(s/2_ we get 2 instead of 2.5
   
   iteration 2: n = 4/2 = 2
   
   iteration 3: n = 2/2 = 1
   o(log8)
   
  o of log base two, eight) = 2^n=8
  
  2 two to the third power
  divide value by 2
  long n times to get 1
  iteration 1 4 
  2 2 
  3 1
  so we exit the function
  
  
  Binary search and logn
  
  unordered array
  
  ordered array visualization
  
 
 
  1 2 7 12  43 44 54 100 124
  
  iterate: 반복하다
  
  start by finding the mid point
  
  values increasing
  
  value decreasing
  
  100?? 
  is this number 
  greater than or less than our midpoint?
  
 2<  43 < 100 
  
 binary search only work on ordered array
 
 44 54 100 124
 

1000,000/ = 500,000

4/2 = 2

we are still searching 100

44 54 100 124

get rid of left side 44 54

124 if is our mid

100 < 124
mid point can only be this element



coding binary search
with recursive function

```
let arr = []
let start = 0
let target = 100000;

for( let i = 1; i <= 1024; i++) {
 arr push(i)
}
console.log(arr)

let end = arr length - 1;

function binarySearch(arr, start, end, target) {
    console.log(arr slice(start, end));
    
    if( start > end) return false;
    let midIndex = Math.floor((start + end) /2);
    console.log(arr[midIndex])
    
    if(arr[midIndex] === target) return true;
     
    if(arr[midIndex] > target) return binarySearch(arr, target, start, midIndex  -1, target)
    else return binarySearch(arr, midIndex + 1, end, target)
     // if the value at mid is greater than our target, then thats going to mean that our target is
      // actually in the leftside of the array
      so both of the line count only mid+1 =6 and to 8
      so if we use binary search we dont need to search whole array
}

binarySearch(arr, start, end, target)
```
maximum call stack size exceeded?

if we target negative -10

we can se tha array is continuing to get smaller and smaller




To understand o over nlogn O(nlogn)


```
function nLogFunc(n) {
  let y = n; 
  while (n > 1) {
  n = Math.floor(n / 2);
  for( let i = 1; i <= y; i++) {
  console.log(i);
  }
 }
}

```   

for loop up until the
size of n we will log or print te value for i

n =4 
4/2=2 for loop

log(1)
log(2)
log(3)
log(4)
once this finished we move on to the next iteration of the while loop
and repeat the process

n = 2
2/2 =1
for loop

log(1)
log(2)
log(3)
log(4)

Merge sort (nlogn)





fibonacci and exponential complexity
O(2^n)

```
function fib(n) {
  if( n === 0 ) {
  return 0;
  }
  if( n === 1 ) {
  return 1;
  }
  return fib(n - 1) + fib(n - 2);
 }
```
f(4)
2 = 2^1 (f4-1)     f(4-2)

4 = 2^2  f(3-1) f(3-2) f(2-1) f(2-2)
our exponents correlate with our levels

level3   f(1) f(0) .....
8 = 2^3

two to the n minus one




O(n!) n factorial



```
function f(n) {
 if( n === 0 ) {
  console.log("")
  return
  }
  
  for( let i = 0; i < n ; i++) {
  f(n =1);
  }
 }
 
 ```
 
 space compleixty?
 
 총 공간 요구 = 고정 공간 요구 + 가변 공간 요구로 나타낼 수 있으며 


여기서 고정 공간은 입력과 출력의 횟수나 크기와 관계없는 공간의 요구(코드 저장 공간, 단순 변수, 고정 크기의 구조 변수, 상수)를 말합니다.

가변 공간은 해결하려는 문제의 특정 인스턴스에 의존하는 크기를 가진 구조화 변수들을 위해서 필요로 하는 공간, 함수가 순환 호출을 할 경우 요구되는 추가 공간, 그러니까 동적으로 필요한 공간을 말합니다



```
int factorial(int n)
{
    int i = 0;
    int fac = 1;
    for(i = 1; i <= n; i++)
    {
        fac = fac * i;
    }
    return fac;
}
```

C
n의 값에 상관없이 스택에는 n과 i 그리고 fac 변수만 저장됩니다. 여기서의 공간 복잡도는 
O(1) 입니다.



```
int factorial(int n)
{
    if(n > 1) return n * factorial(n - 1);
    else return 1;
}
```


O(n)



 


     
 
 
 
 
 
 
 
