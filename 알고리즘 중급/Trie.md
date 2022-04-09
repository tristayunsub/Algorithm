https://jason9319.tistory.com/129?category=670441
트라이란 문자열에서 검색을 빠르게 해주는 자료구조~

정수형 자료형에 대해서 이진검색트리를 이용하면 O(logN)의 시간만에 원하는 데이터를 검색할 수 있습니다.

하지만 문자열에서 이진검색트리를 사용한다면 문자열의 최대길이가 M이라면 O(MlongN)의 시간 복잡도를
가지게 될 것입니다.

우리는 문자열에서 검색을 개선하기 위하여 트라이를 이용하여 O(M)의 시간만에 원하는 문자열을 검색할 수 있습니다.

트라이라는 명칭을 Retrieval(탐색)에서 유래

트라이는 어떻게 문자열 검색을 O(M)만에 처리해줄수있나?

최대 트리의 높이까지 탐색.
시간복잡도는 O(H) 

```
struct Trie {
bool finish: // 끝나는 지점 표시
Trie* next[26]; //26가지 알파벳애 대한 트라이
Trie() : finish(false) {
   memset(next, 0, sizeof(next));
           }
           ~Trie() {
           for ( int i = 0; i < 26; i++)
                    if(next[i])
                    delete next[i];
                    }
       void insert(const char* key) {
               if(*key == 'o')
       finish = true; //문자열이 끝나는 지점일 경우 표시
                   else {
                    int curr = *key - 'A';
                    if (next[curr] == NULL)
        next[curr] = new Trie(); //탐색이 처음되는 지점일 경우  동적할당
             next[curr] -> insert(key + 1); //다음 문자 삽입
                          }
                        }
                        
                  Trie* find(const char* key) {
           if(*key == '\0') return this; // 문자열이 끝나는 위치를 반환
                  int curr = *key - 'A';
           if(next[curr] == NULL) return NULL; //찾는 값이 존재하지않음
                  return next[curr]->find(key + 1); //다음 문자를 탐색
                             }
                           };
 ```
 트라이는 자료구조
 
 우리는 문제에서 원하는 조건에 따라 find함수를 여러 방식으로 변형하여 사용하게 될 것입니다.
 그러면 우리는 트라이를 통하여 
 BOJ 5052 전화번호 목록 문제를 보겠습니다.
 
 모든 문자열을 트라이에 삽입해준후 다시 모든 문자열을 트라이로 검색하면서 아직 검색중인데 finish인 부분이 한번이라도 존재한다면 일관성이 없다고 처리가 됩니다.
 
 총 시간복잡도는 O(T*(N*10))이된다. 10은 전화번호의 최대길이
 
 
```
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 10000
using namespace std;

struct Trie{
 Trie* next[10];
  bool term;
 Trie() : term(false){
 memset(next,0,sizeof(next));
         }
         ~Trie(){
         for(int i=0;i<10;i++){
             if(next[i])
             delete next[i];
              }
             }
  void insert(const char* key) {
          if(*key=='\0')
            term=true;
            else{
         int curr = *key-'0';
         if(next[curr]==NULL)
         next[curr]=new Trie();
       next[curr]->insert(key+1);
               }
             }
   bool find(const char* key){
          if(*key='\0')
             return 0;
             if(term)
              return 1;
         int curr = *key-'0';
       return next[curr] -> find(key+1);
                  }
                };
        int t,n,r;
        char a[MAX_N][11];
         int main(){
          scanf("%d",&t);
          while(t--){
          scanf("&d", &n);
           getchar();
          for(int i=0; i<n;i++)
           scanf("&d", &a[i]);
          Trie *root=new Trie;
            r=0;
            for(int i=0; i<n;i++)
            root ->insert(a[i]);
            for(int i=0; i<n;i++)
            if(root->find(a[i])){
                 r=1;
                 }
                }
         printf("%s\n",r?"NO":"YES");
             }
            return 0;
           }
           
```           
 
                
                   
       
       
              
           
           
           
