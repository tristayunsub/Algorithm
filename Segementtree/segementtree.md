segement tree
===
https://www.youtube.com/watch?v=XaodfglnhVs&list=PLN3yisVKGPfhOAeqrYNun0Fu_O_gWy1mx&index=4&ab_channel=IOIKOREA

길이 n의 수열 a1,a2,a3 an이 주어진다 다음쿼리르  출력하라

L,R이 주어지면 AL+ ... AR을 출력하라

위 문제는 누적합 배열 Si를 만드는것으로 간단하게 O(N) 전처리 쿼리당O(1)에 해결할 수 있다.
X,V가 주어지면 Ax를 V로바꿔라

누적합 배열을 사용하면 값 변경 쿼리를 O(N)에 할 수밖에없다.
세그먼트트리로 O(logN)으로.

각 노드는 특정구간을 대표
