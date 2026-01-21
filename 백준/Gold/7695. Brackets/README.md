# [Gold III] Brackets - 7695 

[문제 링크](https://www.acmicpc.net/problem/7695) 

### 성능 요약

메모리: 2036 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 1월 21일 18:14:07

### 문제 설명

<p>We give the following inductive definition of a “regular brackets” sequence:</p>

<ul>
	<li>the empty sequence is a regular brackets sequence,</li>
	<li>if s is a regular brackets sequence, then (s) and [s] are regular brackets sequences, and</li>
	<li>if a and b are regular brackets sequences, then ab is a regular brackets sequence.</li>
	<li>no other sequence is a regular brackets sequence</li>
</ul>

<p>For instance, all of the following character sequences are regular brackets sequences:</p>

<pre>(), [], (()), ()[], ()[()]</pre>

<p>while the following character sequences are not:</p>

<pre>(, ], )(, ([)], ([(]</pre>

<p>Given a brackets sequence of characters a<sub>1</sub>a<sub>2</sub>...a<sub>n</sub>, your goal is to find the length of the longest regular brackets sequence that is a subsequence of s. That is, you wish to find the largest m such that for indices i<sub>1</sub>, i<sub>2</sub>, . . . , i<sub>m</sub> where 1 ≤ i<sub>1</sub> < i<sub>2</sub> < . . . < i<sub>m</sub> ≤ n, a<sub>i<sub>1</sub></sub> a<sub>i<sub>2</sub></sub> . . . a<sub>i<sub>m</sub></sub> is a regular brackets sequence.</p>

### 입력 

 <p>The input test file will contain multiple test cases. Each input test case consists of a single line containing only the characters (, ), [, and ]; each input test will have length between 1 and 100, inclusive. The end-of-file is marked by a line containing the word “end” and should not be processed.</p>

### 출력 

 <p>For each input case, the program should print the length of the longest possible regular brackets subsequence on a single line.</p>

