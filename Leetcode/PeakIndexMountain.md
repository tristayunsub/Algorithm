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
