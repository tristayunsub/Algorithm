LEETCODE 852
```

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int N = int(arr.size());
        int lo = 1, hi = N - 2;
        while (lo<=hi){
            int mid = (lo + hi) / 2; // int mid = lo + (hi - lo) / 2;
            if ( arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) // 미드값이 그 앞값보다 크고, 미드값이 그 뒷값보다 크면 mid값 출력.
                return mid;
            else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) // 그게아니라 미드값이 앞값보다는 큰데, 그 뒷값보단 작으면 ,lo값+1,->증가추세일때.
                                                                            
                lo = mid + 1;
            else
                hi = mid - 1;                    //감소추세일때는.. 미드값이 앞값보다는 작고 뒷값보다는 클때.. 그떄는 hi를 -1해준다. 생각해보면 감소추세면 당연히 뒤로가야지 최곳값이나오고.
        }        
        return 0;
    }
};
```
근데 lower bound로도 풀어보자.

```
class Solution {
public:
    bool decide(const vector<int>& arr, int x){
        return arr[x] > arr[x+1];
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int N = int(arr.size());
        int lo = 1, hi = N - 2;
        while (lo<=hi){
            int mid = (lo + hi) / 2; // int mid = lo + (hi - lo) / 2;
            if (decide(arr, mid))
                 hi = mid - 1;
              else
                  lo = mid + 1;
         
                       }        
        return lo;
    }
};
```

leetcode 287번.

```
class Solution {
    
public:
    //O(n)
    bool decide(const vector<int>& nums, int x) {
        int cnt = 0;
        for(auto it : nums){
            if(it <= x)
                cnt++;
        }
        return cnt >= x + 1;
    }
        
    //O(n*logn)
    int findDuplicate(vector<int>& nums) {
         int N = int(nums.size()); // int N = static_cast<int>(nums.size());
         int lo = 1, hi = N - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if ( decide(nums,mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
```

leetcode 378번.
kth smallest element in a sorted matrix

```
class Solution {
public:
    
    //O(N^2)
    bool decide(vector<vector<int>>& mat, int k, int x){
        int N = int(mat.size());
        
        int cnt = 0;
        for ( int i =0; i < N; i++){
            for (int j = 0 ; j < N; j++){
                if(mat[i][j] <= x )
                    cnt++;
            }
        }
        return cnt >= k;
    }
    
    // O(N^2*logX)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = int (matrix.size());
        
        int lo = matrix[0][0], hi = matrix[N-1][N-1];
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if ( decide(matrix, k, mid))
                 hi = mid - 1;
            else 
                lo = mid + 1;
        }
        return lo;
    }
};
```

leetcode 240번 문제를 풂으로써 저 bool 연산을 O(n)으로 만들기 가능.

```
class Solution {
public:
    
    //O(N)
    bool decide(vector<vector<int>>& mat, int k, int x){
        int N = int(mat.size());
        
        int cnt = 0;
        int r = N - 1, c = 0;
        while(r >= 0 && c < N){
            if(mat[r][c] <= x)
                c++;
            else{
                cnt += c;
                r--;
                
            }
         }
                cnt += (r + 1) * c;
        
        return cnt >= k;
    }
    
    // O(N^2*logX)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = int (matrix.size());
        
        int lo = matrix[0][0], hi = matrix[N-1][N-1];
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if ( decide(matrix, k, mid))
                 hi = mid - 1;
            else 
                lo = mid + 1;
        }
        return lo;
    }
};
```

//내값이 타겟보다크면 왼쪽 아니면 위쪽 , 작으면? 아래쪽 오른쪽

//양방향 펼쳐지면 어렵지. 맨처음시작점을 18부터 시작한다고 치면.

//이값이 타겟보다 크니까 위로만가면된다. 왼쪽가는걸 인위적으로 없애버리자.

//타겟보다작으면 오른쪽 크면 윗쪽으로만 가면된다. 

//O(N)으로 타겟보다 작은 숫자를 셀수있따.
