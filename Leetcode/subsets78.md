https://leetcode.com/problems/subsets/
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
subset문제.


예를들면
1 2 3 4 가있는데 이 부분집합만드는 경우의수 2^n인데 만약에 뒤에 5가 추가된다면?

bit를 이용한방볍
-쉽게 구현가능, 속도매우빠름
-정수의 bit크기에 의존적, bit로 표현하기 어려운경우도많음

1 2 3 4 5
0 0 0 0 0

2진수 subset 10진수로..

0에서 2^n -1까지 확인하면된다.
각 숫자의 비트를 확인 1이면 그에해당하는 값을 추가.

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = int(nums.size());
        
        vector<vector<int>> res;
        for(int i = 0; i < (1 << n); i++){ 
            vector<int> v;
            for( int j = 0; j < n; j++) {
                if(i & (1 << j))
                    v.push_back(nums[j]); 
            }
            res.push_back(v);
        }
        
        return res;
    }
};
```


```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = int(nums.size());
        
        vector<vector<int>> res;
        for(int i = 0; i < (1 << n); i++){ 
            vector<int> v;
            for( int j = 0, t = i; t; j++, t >>= 1) {
                if(t & 1)
                    v.push_back(nums[j]); 
            }
            res.push_back(v);
        }
        
        return res;
    }
};
// (1 << n) 뜻은 2의 n승이라는뜻이랑 동의어.
//9줄 맘에안든다.
//t는 i 복사본이고 i가 0일떄까지돈다. t가 맨 밑에비트가 1인지만본다. , j만큼 민거랑 똑같은 효과본다.
```

class Solution {
public:

    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = int(nums.size());
        
        vector<vector<int>> res;
        for(int i = 0; i < (1 << n); i++){ 
            vector<int> v;
            for( int j = 0, t = i; t; j++, t >>= 1) {
                if(t & 1)
                    v.push_back(nums[j]); 
            }
            res.push_back(v);
        }
        
        return res;
    }
};
*/
    
    
// (1 << n) 뜻은 2의 n승이라는뜻이랑 동의어.
//9줄 맘에안든다.
//t는 i 복사본이고 i가 0일떄까지돈다. t가 맨 밑에비트가 1인지만본다. , j만큼 민거랑 똑같은 효과본다.
    
    
 //recursive call(backtracking)을 이용한 방법.   
    
        void rec(const vector<vector<int>>& res, const vector<int>& nums, vector<int>& v, int depth ){
            if(depth >= nums.size()) { //A
                res.push_back(v);
                return;
            }
            // exclude nums[depth]
            rec(res, nums, v, depth + 1);
            
            // include nums[depth]
            v.push_back(nums[depth]);
            rec(res, nums, v, depth + 1);
            v.pop_back();
        }
        vector<vector<int>> subsets(vector<int>& nums) {
        int n = int(nums.size());
        vector<vector<int>> res;
        vector<int> v;
        rec(res, nums, v, 0 );
        return res;
    }
};

A.마지막 depth에 도달하면 결과에 추가
B.해당 DEPTH의 값을 추가하지 않는 경우
C. 해당 DEPTH의 값을 추가하는 경우.

```
뭐 RECURSIVE하게도 가능하다~
