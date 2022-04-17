https://leetcode.com/problems/subsets-ii/


중복값이 있을경우.

[1,2,2]

1, 2, 2

{1,2}, {1,2}, {2,2}
{1,2,2}

```
class Solution {
public:
    
    void rec(vector<vector<int>>& res, const vector<int>& nums, vector<int>& v, int depth){
        res.push_back(v);
        for(int i = depth; i < int(nums.size()); i++){
            v.push_back(nums[i]);
            rec(res, nums, v, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        
        int n = int(nums.size());
        vector<vector<int>> res;
        vector<int> v;
        rec(res, nums, v, 0);
        
        
        sort(res.begin(), res.end());
        
        /*
        int j = 0;
        for( int i = 1; i < int(res.size()); i++) {
            if (res[j] != res[i])
                res[++j] = res[i];
        }
        res.resize(j+1);
        더간단하게
        */
        res.erase(unique(res.begin(), res.end()), res.end());
        
        
        
        return res;
    }
};

```

/*여기서 중복제거하는 코드너허야됌

예를들면 1 3 2 1 2 3 1 있따치자
1 1 1 2 2 3 3

1이 j라고치자 첫버쨰.
같으면 i만증가하고 다르면 j를 그 다음으로
1.j++
2.res[j] = res[i]
3.
   vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        int n = int(nums.size());
        vector<vector<int>> res;
        vector<int> v;
        rec(res, nums, v, 0);
        
        
        sort(res.begin(), res.end());
        int j = 0;
        for( int i = 1; i < int(res.size()); i++) {
            if (res[j] != res[i])
                res[++j] = res[i];
        }
        res.resize(j+1);
        
        
        return res;
    }
    머지? 이거 accepted는 됬는데 wrong answer네
중간에 4 414 가된다.
14하고 41도 중복제거가안됌.
입력값이 정렬이안되있음.

*/
                                            
                                            
```
                                            class Solution {
public:
    
    void rec(vector<vector<int>>& res, const vector<int>& nums, vector<int>& v, int depth){
        res.push_back(v);
        for(int i = depth; i < int(nums.size()); i++){
            if(i != depth && nums[i - 1] == nums[i]) //중요함.
                continue;
            
            v.push_back(nums[i]);
            rec(res, nums, v, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        
        int n = int(nums.size());
        vector<vector<int>> res;
        vector<int> v;
        rec(res, nums, v, 0);
        
        
        //sort(res.begin(), res.end());
        
        
        //res.erase(unique(res.begin(), res.end()), res.end());
        
        
        
        return res;
    }
};
  ```
  
  앞에거하고 같지않으면 처리한다는... 
