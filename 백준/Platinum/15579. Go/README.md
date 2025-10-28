# [Platinum IV] Go - 15579 

[문제 링크](https://www.acmicpc.net/problem/15579) 

### 성능 요약

메모리: 217900 KB, 시간: 80 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 10월 28일 14:23:13

### 문제 설명

<p>Branimirko is still a passionate player of the world-renowned game Pokémon Go. Recently, he decided to organize a competition in catching Pokémon. It will be held in Ilica street in Zagreb, and the main sponsor is his friend Slavko. The reward is, of course, candy!</p>

<p>Ilica is, as we all know, the longest street in Zagreb. There are N houses on the same side of the street, and each house has a house number between 1 and N. The competition begins at house number K.</p>

<p>Before the competition, Branimirko looked at the map and saw M Pokémon. Each Pokémon is located at its (distinct) house number A<sub>i</sub>, is valued at B<sub>i</sub> candy, and can be caught only in the next T<sub>i</sub> seconds, after which it disappears from the map and is impossible to catch.</p>

<p>Branimirko can visit one house number per second. Also, when he catches a Pokémon, that Pokémon disappears from the map.</p>

<p>Since Branimirko really likes candy, he asked for your help.</p>

<p>Help him and determine the maximal amount of candy he can get!</p>

### 입력 

 <p>The first line of input contains integers N, K (1 ≤ K ≤ N ≤ 1 000) and M (1 ≤ M ≤ 100), the number of houses, the starting house number and the number of Pokémon.</p>

<p>Each of the following M lines contains integers A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ N), B<sub>i</sub> (1 ≤ B<sub>i</sub> ≤ 100) and T<sub>i</sub> (1 ≤ T<sub>i</sub> ≤ 2 000) from the task.</p>

<p>In the input data, the Pokémon will always be in a strictly ascending order by house number A<sup>i</sup>.</p>

### 출력 

 <p>You must output the required maximal amount of candy from the task.</p>

