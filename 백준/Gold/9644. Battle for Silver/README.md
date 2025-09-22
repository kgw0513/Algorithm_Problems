# [Gold III] Battle for Silver - 9644 

[문제 링크](https://www.acmicpc.net/problem/9644) 

### 성능 요약

메모리: 2820 KB, 시간: 72 ms

### 분류

그래프 이론, 평면 그래프

### 제출 일자

2025년 9월 22일 16:32:57

### 문제 설명

<p>Piet Hein was a Dutch naval officer during the Eighty Years’ War between the United Provinces of The Netherlands and Spain. His most famous victory was the capture of the Zilvervloot (‘Silver Fleet’) near Cuba in 1628, where he intercepted a number of Spanish vessels that were carrying silver from the Spanish colonies in the Americas to Spain. Details about this famous naval battle are sketchy, so the description below may contain some historical inaccuracies.</p>

<p>The Silver Fleet consisted of vessels containing silver coins. Piet Hein’s basic strategy was simple: tow away a number of vessels from the fleet, in order to capture their contents.</p>

<p>In an attempt to prevent the Dutch from carrying out this plan, the Spanish tied all the ships in their fleet together using huge iron chains. Each vessel in their fleet was fixed to at least one other vessel; any two vessels were connected by at most one chain; and the Spanish made sure that the chains did not cross each other, otherwise they could get tied up into a knot. As an end result, the vessels and the chains connecting them formed a connected, planar graph.</p>

<p>However, the Spanish preventive measures only made their situation worse. As an experienced naval officer, Piet Hein knew that towing away a group of ships was easiest if, for every two ships in the group, the ships were connected by a chain. He called such groups chaingroups.</p>

<p>Piet Hein ordered his men to tow away all the ships in the chaingroup that contained the largest amount of booty, after severing the links with the remaining ships in the Spanish fleet with a few highly accurate canon shots. The total booty in a chaingroup is the total number of silver coins in the vessels that make up the chaingroup.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/bfs.png" style="height:235px; width:246px"></p>

<p>Figure 1 – The Silver Fleet represented as a graph: each dot denotes a vessel in the fleet, while each line denotes a chain that connects two vessels. The vessels that are connected in the figure by the dashed lines correspond to the chaingroup that provides the highest total value of silver coins. In this case, Piet Hein loots 4500 silver coins from the fleet.</p>

<p>Given a description of the Silver Fleet, find the value of the chaingroup with the highest amount of booty (i.e., total number of silver coins in the ships that make up the chaingroup).</p>

### 입력 

 <p>For each test-case:</p>

<ul>
	<li>A line containing two integers v (2 ≤ v ≤ 450) and e (1 ≤ e ≤ 900), the number of vessels in the fleet and the number of chains, respectively.</li>
	<li>Then, v lines specifying S<sub>1</sub>, S<sub>2</sub>, ... , S<sub>v</sub>, the amount of silver coins carried by vessel i (1 ≤ i ≤ v). The S<sub>i</sub> will be positive integers, where 100 ≤ S<sub>i</sub> ≤ 6000.</li>
	<li>Then, for each chain, a line containing two integers c<sub>start</sub> and c<sub>end</sub> , the two vessels connected by the chain, where (1 ≤ c<sub>start</sub> < c<sub>end</sub> ≤ v).</li>
</ul>

<p>Each fleet forms a connected, planar graph.</p>

### 출력 

 <p>For each test case, one line containing a single positive integer: the number of silver coins that is captured by Piet Hein’s fleet.</p>

