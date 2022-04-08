MaxHeap
===

```

#include <stdio.h>
#include <algorithm>
#include "Windows.h"
//내가 짠 모듈이 잘돌아가는지 그떄그떄확인
랜덤함수를 쓰기위해 windows.h 추가
using namespace std;

int heap_size;
int heap[100000];

int push(int data) {
   int target = heap_size + 1;
   while(target != 1 && heap[target /2] < data) { //부모노드가 자격이없다면 끌어내리기 부모를 자식으로 복사
     heap[target] = heap[target /2];
     target /= 2;
   } 
  //부모노드가 자격이 있다면 heapsize 증가
  heap[target] = data;
  ++heap_size;
  
}


void pop() {
   int parent = 1, child = 2;
   int temp = heap[heap_size];
   while(child < heap_size) {
      if(child + 1 < heap_size && heap[child] < heap[child + 1]) {
      ++child;
        
      }
        if(temp >= heap[child]){
          break;
   }

  heap[parent] = heap[child];
  parent = child;
  child *= 2;
  }
     heap[parent] = temp;
 --heap_size;
}

bool comp(int a, int b){
  return( a > b);
}


int main()
{  
   int a[1000], b[1000];
   for (int i = 0; i <9999; ++i){
     a[i] = rand() % 10000;
     b[i] = a[i];
   }
  sort(a, a + 99999, comp);

  for ( int i = 0; i <9999; ++i){
    push(b[i]);
  }

  for ( int i = 0; i < 9999; ++i){
    if (a[i] != heap[1]) {
      printf("not heap!!!\n");
      
    }
     pop();    
  }
   return 0;
}
```
