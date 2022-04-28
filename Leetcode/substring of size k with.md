amazon OA 

https://www.geeksforgeeks.org/count-of-substrings-of-length-k-with-exactly-k-distinct-characters/


naive
```

//O(n*k)
vector<string> findUniqueSubstrings(const string& s, int k){
    int n = int(s.length());
    

    //unordered_set<string> strs;
    set<string> strs;
    for (int i = 0; i + k <= n; i++){
        vector<bool> used(256);
        bool ok = true;
        for (int j = 0; j < k; j++){
            if(used[s[i+j]]){
                ok = false;
                break;
            }
            used[s[i+j]] = true;
        }
        if(ok) 
              strs.insert(s.substr(i, k));
    }
    
    
    return vector<string>(strs.begin(), strs.end());
}

bool check(vector<string> A, vector<string> B){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;

}

int main() {
    //테스트 셋
    cout << check(findUniqueSubstrings("abcabc", 3), vector<string>{"abc", "bca", "cab"}) << endl;
    cout << check(findUniqueSubstrings("abacab", 3), vector<string>{"bac", "cab"}) << endl;
  

    return 0;
}

```



for문 한번만 돌리게

/*LRVALUE?처럼 L을 업데이트 답을 업데이트 R반증가.
valid -> right를 계속 증가시킨다. r가 증가가능한 상태인가? stable state r 증가불가능 invalid일땐 left 업데이트
a
ab
aba 
  ba 
  bac distinct한조건에도맞고 길이도 3이다. bac를 집어넣음. 
  baca 이조건되니까 invalid가됬네 a도 2개, 길이가 3도아님. 그럼 b를ㄹ빼야지
   aca인데 이것도 invalid 그래서 ca 로
   ca
   cab distinct 길이도3 집어넣음 이걸 코딩으로 해보자
   
   
 
*/

```
vector<string> findUniqueSubstrings(const string& s, int k){
    int n = int(s.length());
    

    //unordered_set<string> strs;
    set<string> strs;
     
     vector<int> cnt(256);
     for(int L = 0, R = 0; R < n; R++) {
         //update right 
         cnt[s[R]]++;
         
         //update left
         while(R - L + 1 > k || cnt[s[R]] > 1){
                        cnt[s[L++]]--;
         }
          
         
         //update answer
         if (R - L + 1 == k)
               strs.insert(s.substr(L, k));         
     }
    
    return vector<string>(strs.begin(), strs.end());
}
```
