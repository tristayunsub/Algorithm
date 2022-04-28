set 은 tree 구조 가지고있음. o(logn)이다 set은

unordered set은 o(1) 시간복잡도 가진다.

```
unordered_set 보면

template<
    class key,
    class HASH = std::hash<key>,
    class KeyEqual = std:equal_to<Key>,
    class Allocator = std::allocator<Key>,
> class unordered_Set;

순서없이 bucket 안에 들어가있따. hash값에 따라 결졍된다.

int main
{
     std::unordered_set<std::string> uordSet;
     
     urodSet.emplace("abc");
     urodSet.emplace("def");
     urodSet.emplace("ghi");
     urodSet.emplace("jkl");
     
     for (const std::string & str : uordSet)
     {
       std;:cout << str << std::endl;
       
      
     }
     
     uordSet.find('abc'); // O(1)
          uordSet.erase('abc'); // O(1)
          
          return 0; 

}

해쉬는 필연적으로 value가 너무크다. 그래서 bucket에 넣음.

    여러개의 버켓에 해쉬값을 나누어 담음.
    
    
    td::cout << "bucket count: "  << uordSet.bucket_count() << 하면 
    
    뭐 4개가있을수도있고 7개, 8 개 되게 다름.
    
    만약 rehashing이 안되면 o(n) 시간이돼서 시간 허비하게됨 뭐 이런걸 잘 구슬려야~
    삼성 b형 통과한다는 거군아
    
    의문점 버킷의 갯수가 13개인데. 새로운데이터가 차면서 element가 계속들어오면
    
    linked list를 타야되는데 그럼 거기서 걸리는 시간. bucket count가 늘어나서~
    
    버켓이 13개에서 29로 늘어남.
    
    
```
