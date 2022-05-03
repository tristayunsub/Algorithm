https://omnis.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B0%95%EC%A2%8C-5%ED%9A%8C?category=321653

그리디 문제~
몇번의 선택하면서 답을 찾아냄.

그 선택은 전에 결정했거나 앞으로 결정할 선택 고려 X 그 당시의 상황에서만 가장 최적인 해를 취하는 것

각 선택들은 부분적으로는 최적일지 모르나. 전체적으로 보면 최적이 아닐수도 있다.

전체적으로도 최적이되는가??.. 는 고려해봄

거스름돈 문제. 돈의개수 최소한 적게. 거스름돈 2250원. 천원짜리 두장. 백원2개 오십원1개

가장 단위가 큰 화폐부터 고름.

PROGRAM __charge__;

const

money array[ ]of integer = (1000,500,100..);

var 

result: array

charge : integer;

i:intger;

begin

charge:=2250;


repeat
for i = 1 to 5 do begin
if charge >= money[i] then break

end;



inc(result[i]);

dec(charge,money[i])

until charge = 0;


for i=1 to 5 do begin

writeln(money[i]:4,'원짜리',result[i],'개')
end;

만약에  한국은행에서 1100원짜리 새로운 화폐를 만들엇다 하자.

그리고 주어야할 거스름돈을 2600원. 거스름돈을 준다면? 1100원짜리 2장 + 100원 짜리 4개 = 총 화폐 6개.

하지만 이것 알다시피 최적해가 아님.


최소 신장 비용 트리. minimum spanning tree 

mst는 그래프 상의 모든 정점을 연결하는 가장 짧은 이음선들의 집합.

prim 알고리즘.

무방향 그래프 G(V,E)인 경우. 이진힙 이용시 평균 (E*LOGV) 의 시간 복잡도. 최악O(V^2)
