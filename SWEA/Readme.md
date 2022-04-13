https://zoosso.tistory.com/335
- C++(.cpp) / C 언어 권장

    : 참고할 자료가 C/C++ 코드가 많기도 하지만

      문제 요구사항 제한이 있지만 문법이나 기능면에서 C++ 효과적.

- 특정 알고리즘(다익스트라, Flood Fill, KMP 등)을 아는 것 보다는 설계 및 시뮬레이션이 중요

    : 4시간 동안 한 문제를 푸는 것이기에 특정 알고리즘 보다는 전체적인 설계 능력이 중요

     주어진 메모리에서 시간 최적화를 많이 요구하는 편

     흔히, 1 (설계) + 2 (구현) + 1 (디버깅 및 최적화) = 4 hour

자주 사용되는 자료구조

Linked List, Hash, Queue, Stack, Graph, Merge Sort, Insertion Sort

+ DFS/BFS, Trie, KMP, Segment Tree, Indexed Tree, Heap Sort, 비트연산, 자료 압축

※ 초창기에는 DP 유형은 주로 나왔지만 현재는 설계와 최적화 중시

- STL 등 라이브러리를 잘 사용하고 이해하는 것도 중요하지만

  <stdio.h> <iostream> <malloc.h>만 사용가능

- C++의 경우 ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);를 통해

  입출력 속도를 높일 수 있지만 안정적이지 않기에 scanf, printf 권장

- 구조체 및 포인터 이해 (ex. 포인터 배열로 대상 접근)

- 정적 배열 사용시 Runtime Error 방지를 위해서 여유롭게 크기 설정

- 배열 시작 Index는 상황에 따라 『 0 』 /  『 1 』 선택

- 매크로 함수보다는 inline 키워드 권장

  ex)  inline int max(int A, int B) { return A > B ? A : B; }

- 기출 유형 많이 풀어보기 (main.cpp + user.cpp 구조로 된 API형 문제)

  : 문제 설명과 함께 main.cpp에서 함수 호출 횟수, 변수 조건 파악

- SWEA Reference Code 활용 (실제 시험에서도 주어짐)

    ex) Heap, djb2, Quick Sort

- 첫번째 Test Case는 통과 후 2번째 Test Case부터 틀리는 경우는 초기화 init() 부분 의심

    ex) 두번째 TC만 실행해보면서 확인
