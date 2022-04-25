
```
vector<int> prefixFunction(const string& s) {
     int n = int(s.length());
    vector<int> pi(n);
    
    int j = 0;
    for (int i = 1; i < n; i++){
         //...
         while( j > 0 && s[j] != s[i])
             j = pi[j - 1];
        
        if(s[j] == s[i])
            j++; //길이
            
        pi[i] = j;
            
    }
    
    return pi;
}

class Solution {
public:
    string longestPrefix(string s) {
            int n = int(s.length());
            vector<int> pi = prefixFunction(s);
            return s.substr(0, pi[n-1]);
    }
};

```
