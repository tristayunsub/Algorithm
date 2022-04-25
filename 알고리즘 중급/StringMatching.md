https://www.youtube.com/watch?v=_hsHF9_C_GQ&list=PL-OC--HdIAXMXZ3IXSeLaO9Rl6qJNGc6g&index=29&ab_channel=%EA%B0%9C%EB%B0%9C%EC%9E%90%EC%98%81%EB%A7%A8

KMP 알고리즘까지 학습~

실제로는 그렇게 빠르지않아도. 유용하게 쓰인다.

aaba 패턴 빠르게. s


Search 자체도 중요하지만 원리는 훨씬더 활용도가 높다.

KMP알고리즘에 사용되는 PREFIX FUNCTION은 그 자체로도 매우매우 유용하게 사용된다.

원리를 이해하고 다양한 활용 예를 찾아보고자한다.

TEXT "AABAAACAADAA"

PATTERN "AABA"

INDEX 0에서 "AABA"문자열 같은지 비교

INDEX 1에서 비교

INDEX 2에서 같은지 비교

NAIVE한 방법들은 텍스트의 처음부터 차례대로 key가 있는지 찾는다.

```

vector<int> searchNaive(const string& text, const string& pattern){
  vector<int> res;

  int textLength = (int)text.length();
  int patternLength = (int)pattern.length();

  for(int i = 0; i <= textLength - patternLength; i++){ //A
    bool matched = true;                      //B
    for(int j = 0; j < patternLength; j++){ 
      if(text[i+j]!= pattern[j]){
        matched = false;
        break;
      }
    }
      if (matched)          //C
        res.push_back(i);
    
  }

  
    return res;
}



```



/*
A.텍스트의 처음부터 끝까지 LOOP를 돌면서
B.해당 위치에 PATTERN이 있는지 확인
C패턴이 있으면 그 위치를 저장.
TIME COMPLEXITY가 O(N*M)
텍스트의 길이가 N, PATTERN이 M이라고하면 NAIVE 한 방법은 

이것보다 빠른 방법들이 많이 연구되었고, 그 방법들은 O(N+M)이하다

어떻게 가능한지?

아래 NAIVE 방법에서 바깥 LOOP(a)를 빠르게 건너뛰거나
loopb를 빠르게 건너뛰는 경우.

결국 안쪽 loop(B) 실행이 최소화 되도록 하는것이 핵심.



*/


