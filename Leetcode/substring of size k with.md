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



