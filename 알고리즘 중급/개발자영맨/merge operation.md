
merge operation

개선 방법 어떤 idea 들이 존재할까?



실제 쓰이는곳 merge sort tree 쉬발


merge는 두개의 정렬된 배열을 하나으 ㅣ큰 정렬로 합친다.

```

void merge(int out[], const int in1[], int n1, const int in2[], int n2) {
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(in1[i] <= n2){
            if(in1[i] <= in2[j])
                out[k++] = in1[i++];
            else
                out[k++] = in2[j++];
        }
        
    }
    
    while(i < n1)
        out[k++] = in1[i++];
    while(j < n2)
        out[k++] = in2[j++];
    
}


```
만일 하나의 배열안에서 in-place merge를 진행한다라면? -> 여분의 메모리가 꼭필요하다.


복사를 줄이는 양도 존재함

작은값들로 앞부분부터 채우지말고

뒤에서부터 앞으로 채우는 방법. 
    
    ```
    in-placem erge 코드
    
void merge(int data[], int lo, int mid, int hi, int aux[]) {
      for(int i = lo, j = 0; i <= mid; i++; j++)
       aux[j] = data[i];
       
       int i = mid + 1; j = 0, k = lo;
    while(i <= hi &&  j <= mid - lo){
    if(aux[j] <= data[i])
        data[k++] = aux[j++];
    else
        data[k++] = data[i++];
        }
        
        while(j <= mid - lo)
        data[k++] = aux[j++];
}
        
    }
      
      
      
      
      }


```
