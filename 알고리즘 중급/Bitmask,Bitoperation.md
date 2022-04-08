https://mygumi.tistory.com/361
외판원 순회문제?
Traveling salesman problem

모든 도시를 한번만 방문하면서 다시 시작점으로 돌아오는 최소 거리 비용을 구하는 문제이다.

이 문제는 완전탐색 문제로써, 단순하게 풀면 경우의 수가 N! 로 시간초과를 경험하게 된다.

시간을 줄이기 위해 동적계획법으로 접근하고, 점화식은 다음과 같다.

https://www.youtube.com/watch?v=6sEFap7hIl4&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&ab_channel=KartikArora
dp with bitmasking
https://www.youtube.com/watch?v=jqJ5s077OKo&ab_channel=Errichto
 

dp[current][visited] = min(dp[current][visited], tsp(next, visited + next) + w[current][next])


https://www.youtube.com/watch?v=yHBYeguDR0A&ab_channel=%EC%97%94%EC%A7%80%EB%8B%88%EC%96%B4%EB%8C%80%ED%95%9C%EB%AF%BC%EA%B5%AD

모든 도시를 한번만 방문하면서 다시 시작점으로 돌아오는 최소 거리 비용을 구하는 문제이다.

이 문제는 완전탐색 문제로써, 단순하게 풀면 경우의 수가 N! 로 시간초과를 경험하게 된다.

시간을 줄이기 위해 동적계획법으로 접근하고, 점화식은 다음과 같다.

 

dp[current][visited] = min(dp[current][visited], tsp(next, visited + next) + w[current][next])


