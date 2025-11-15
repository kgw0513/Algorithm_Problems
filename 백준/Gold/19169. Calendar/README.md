# [Gold II] Calendar - 19169 

[문제 링크](https://www.acmicpc.net/problem/19169) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 많은 조건 분기

### 제출 일자

2025년 11월 15일 12:21:32

### 문제 설명

<p>Handy Smurf created his newest invention: nanobot calendar.  It obviously consists of nanobots showing current date. Every day in order to switch current date they have to perform a cyclic rotation by $k$ places (so that nanobot that was initially at position $i$ is now at position $(i+k) \bmod n$, nanobots are indexed from $0$).  However, nanobots can only understand one command: <code>reverse</code> $l r$ which reverses positions of all nanobots at positions between $l$ and $r$ (so that nanobot that was initially at position $l$ is now at $r$, the one that was at $l+1$ is now at $r-1$ and so on).  Help Handy write an algorithm for updating the date with minimum number of commands issued.</p>

### 입력 

 <p>First and only line of input contains two integers $n$ and $k$ ($1 \leq n \leq 10^9$, $0 \leq k < n$), specifying the number of nanobots and number of places to rotate.</p>

### 출력 

 <p>First line of output should contain integer $m$ -- the number of <code>reverse</code> commands used. On each of the next $m$ lines output two integers $a$ and $b$ ($0 \leq a \leq b < n$) which means that the next command is <code>reverse</code> $a b$.</p>

