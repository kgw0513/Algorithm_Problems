# [Platinum V] Experimental Charges - 19687 

[문제 링크](https://www.acmicpc.net/problem/19687) 

### 성능 요약

메모리: 2908 KB, 시간: 24 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2026년 1월 4일 11:23:38

### 문제 설명

<p>There are N charged particles, each with either a positive or a negative charge. The charge on each particle is unknown, but it is known that if two particles with the same charge are brought close together, they will repel each other and if two particles with a different charge are brought together, they will attract each other.</p>

<p>In an experiment, Q events happen in chronological order. Each event is of one of the following 2 types:</p>

<ol>
	<li>Two particles are brought close together and you are told whether they repel or attract,</li>
	<li>You are asked when two particles are brought together, whether they will repel, attract or either is possible, based on the experimental observations so far.</li>
</ol>

<p>It is guaranteed that there is at least one configuration of particles that match all the experimental observations given.</p>

### 입력 

 <p>Your program must read from standard input.</p>

<p>The input starts with a line with 2 integers, N and Q. N denotes the number of charged particles, Q denotes the number of events.</p>

<p>Q lines will then follow with 1 character and 2 integers each, the i<sup>th</sup> line will contain T<sub>i</sub>, A<sub>i</sub> and B<sub>i</sub>. If T<sub>i</sub> = ‘A’, it denotes type 1 event where particles A<sub>i</sub> and B<sub>i</sub> attract. If T<sub>i</sub> = ‘R’, it denotes type 1 event where particles A<sub>i</sub> and B<sub>i</sub> repel. If T<sub>i</sub> = ‘Q’, it denotes type 2 event asking whether particles A<sub>i</sub> and B<sub>i</sub> attract or repel (or either is possible).</p>

### 출력 

 <p>Your program must print to standard output.</p>

<p>For every type 2 event, your program must output one line with one character. Output ‘A’ if the charges will attract, ‘R’ if the charges will repel, or ‘?’ if either is possible.</p>

