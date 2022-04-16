https://www.youtube.com/watch?v=_2DOKWvGets&list=PL-OC--HdIAXMXZ3IXSeLaO9Rl6qJNGc6g&index=31&ab_channel=%EA%B0%9C%EB%B0%9C%EC%9E%90%EC%98%81%EB%A7%A8
삼전 b형드가자!

range sum이 자주 나온다고?
값을 변경하는것과 변경하지 않는경우
immutable, mutable

변경하지않는ㄴ건 prefix sum lookuptable로.
값을 변경하는경우 binart indexed tree (fenwick tree), segement tree) 요런것들.
min,max등 다양한 연산에 적용가능하다.

immutable 1d array

prefixs um 생성( 
그니까 0에서 4까지의 SUM S(5)를 0에서 9까지의 SUM S(10)에서 빼주면

5에서 9까지 구간합이나온다 A[5]


prefixs um 생성( 
그니까 0에서 4까지의 SUM S(5)를 0에서 9까지의 SUM S(10)에서 빼주면

5에서 9까지 구간합이나온다  A[5] + A[6] + A[7] + A[8] + A[9] =67

Prefix sum
S[i+1] = S[i] + A[i] , 0 =< i < n

Prefix sum 만들떄 s0에다가 0을채워넣으면 굳이

[0.. R] - [0... L-1] 할때 굳이 L-1 하지 않아도 됨
range sum

A[L] + A[L+1] + A[L+2] ...A[R-1] + A[R]
=S[R+1] - S[L]

Leetcode 303번 easy문제네..

이건 곱하기 xor에대해서도 유사한 방법으로 동작 가능


S[i+1] = S[i] * A[i] 0<=i < n 
range product

A[L] * A[L+1] * ~~~ =S[R+1] / S[L]

XOR 연산하면 0이된다. 
LEETCODE 303
```
class NumArray {
public:
    vector<int> sum;
    
    NumArray(vector<int>& nums) {
        int n = int(nums.size());
        sum.resize(n + 1);
        
        for( int i = 0; i < n; i++)
             sum[i+1] = sum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};

```


Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3문제 



Binary indexed tree

값이 변경과 구간의 합을 할 수있는 특별한 자료구조

성능은 O(logn)

bit의 연산은 prefix sum(배열의 index 0 부터의 합) 만을 구하며,이
prefix sum을가지고 구간합도 구할수있음.
실제론 배열로 저장이되어있고.

0~7
0~3              8~11
0~1   4~5         8~9  12~13
  0     2  4 6 8 10 

끝자리가 겹치지않는다.

    그래서 O(N)개의 size로 처리가된다.

  Sum(0,10) = BIT[8] + BIT[10] + BIT[11]

  0번부터 특정위치까지 무조건 sum을 구한다.

    11 = 01011
    10 = 01010
    8 = 01000
 
입력 배열에서의 prefix sum은 BIT에서 부분합들의 합으로 계산함
BIT에서의 index는 bit opeartion으로 계산



보면 레이어가

  
    11 = 01011
    10 = 01010
    8 = 01000
8 9 10 11
8 9
8   10

보면 11에서 끝자리수 1빼면 
10이되죠.
여기서 두번째 1빼면
  8이됨.

Update는 어떻게 일어나느냐?. update는 입력 배열의 특정위치에
  값을 add하는 동작.

struct BinaryIndexedTree {
  vector<int> tree; -> arraylist 만들고
  
  FenwickTree(int n ) : tree(n + 1){
    
  }

  void init(const int arr[], int n){
    for (int i =0; i < n; i++)
      add(i, arr[i]);
  }

  void init(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++)
      add(i, v[i]);
  }
}  

Prefix sum 계산 및 구간 계산 

int sum(int pos){
  pos++;//Bit 인덱스로 변환

  int res = 0;
  while(pos > 0){
    res += tree[pos];
    pos &=pos -1; //최하위 bit clear

    }

  return res
}

int sumRange(int left, int right){
  int res = sum(right);
  if (left > 0)
    res -= sum(left - 1);
  return res;
}
정수의 최하위 bit를 clear하는 방법.

x &= x -1 

  12 = 01100
  11 = 01011
  8 = 01000

update (정수 add) - O(log n)

void add(int pos, int delta){
  pos++;

  while(pos < (int)tree.size()){
    tree[pos] += delta;
    pos += pos & -pos; //최하위 bit를 더함. 그 마지막비트값을 더해주면. 그 다음에 업데이트하는 위치로 옮길수있다.
  }
}

2의 보수의 특성.
0 0 1 0 1 .... 5 
1 1 0 1 1    -5

  마지막 1의비트는 같다.

  0 0 0  1 0 1 0 -10
 1 1 1 1 0 1 1 0 -10

이런 특성 존재.

leetcode 307
```
    struct BinaryIndexedTree {
     vector<int> tree;
     
    
    void init(int n){
        tree.resize(n+1);
    }
    void add(int pos, int x){
        pos++;
        while(pos < int (tree.size())){
            tree[pos] += x;
            pos += pos & -pos;
        }
    }
    
    int sum(int pos) {
        int res = 0;
        
        pos++;
        while(pos > 0) {
             res += tree[pos];
            pos &= pos -1;
        }
        return res;
    }
    int sumRange(int left, int right){
        int res = sum(right);
        if(left > 0)
            res -= sum(left - 1);
        return res;
    }
};

class NumArray {
    BinaryIndexedTree bit;
    vector<int> value;
    
public:
    NumArray(vector<int>& nums) {
       int n = int(nums.size());
        
        bit.init(n);
        value.resize(n);
        for (int i = 0; i < n; i++ ){
            value[i] = nums[i];
            bit.add(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        bit.add(i, val - value[i]); 
        value[i] = val;
    }
    
    int sumRange(int i, int j) {
        return bit.sumRange(i, j);
    }
};
   ```

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
  
  
  
  Range Add, range sum 구간합.
  
  ```
  
Range add range sum
BIT는 값을 한번에 1개씩만 업데이트 하기 때문에, 특정 범위 내의 값들에 값을 ADD할 때는 O(klogn )의 시간이 소요됨.
   for( int i = left; i <= right; i++)
     fenwickTree.add(i, delta);


예를들면 x이후 모든 값들에 d를 더하는 경우.

y = a*x + b sum of [0, t]

범위 [L, R]에 d를 더하는 경우.
  a=0, b=(R-l+1) * d
  Sum(0,t) = a * t + b

struct FenwickTreeRange {
  FenwickTree mulFT; a x + b a를나타내고 기울기.
  FenwickTree addFT;이건 b y절편

  FenwickTreeRange(int n)
  :mulFT(n), addFT(n) {
    
  }

void add(int x, int delta){
  mulFT.add(x, delta);
  addFT.add(x, delta * (1 - x));
}
void addRange(int left, int right, int delta){
  add(left, delta)
  add(right + 1, -delta);
}
}

int sum(int x){
  return addFT.sum(x) + mulFT.sum(x) * x;

  
}

int sumRange(int left, int right){
  return sum(right) - sum(left-1);
  }
};
                                
   ```
