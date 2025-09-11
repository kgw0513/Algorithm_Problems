# [Gold II] Maze Connect - 17999 

[문제 링크](https://www.acmicpc.net/problem/17999) 

### 성능 요약

메모리: 11236 KB, 시간: 192 ms

### 분류

구현, 그래프 이론, 자료 구조, 그래프 탐색, 분리 집합, 플러드 필

### 제출 일자

2025년 9월 11일 16:31:54

### 문제 설명

<p>Given an orthogonal maze rotated 45 degrees and drawn with ASCII forward and backward slash characters (see below), determine the minimum number of walls that need to be removed to ensure it is possible to escape out of the (possibly disconnected) maze from every cell without going through a wall.</p>

<pre style="text-align: center;">/\
\/</pre>

<p>The above maze has only a single cell fully enclosed. Removing any wall will provide an escape route to the outside.</p>

<pre style="text-align: center;">/\..
\.\.
.\/\
..\/</pre>

<p>The above maze has two enclosed areas. Two walls need to be removed to connect all cells to the outside.</p>

<pre style="text-align: center;">/\/\/\/\/\/\/\/\/\/\
\../\.\/./././\/\/\/
/./\.././\/\.\/\/\/\
\/\/\.\/\/./\/..\../
/\/./\/\/./..\/\/..\
\.\.././\.\/\/./\.\/
/.../\../..\/./.../\
\/\/\/\/\/\/\/\/\/\/</pre>

<p>To make every cell in the above maze accessible from the outside, 26 walls need to be removed.</p>

### 입력 

 <p>The first line of input contains two numbers, <em>r</em> and <em>c</em> (1 ≤ <em>r</em>, <em>c</em> ≤ 1000), which are the number of rows (<em>r</em>) and columns (<em>c</em>) in the maze.</p>

<p>Each of the next <em>r</em> lines contains a string with exactly <em>c</em> characters, consisting of ‘.’, ‘/’, or ‘\’ only. Define an odd (even) square in the grid of characters as one where the sum of the <em>x</em> and <em>y</em> coordinates is odd (even). Either all forward slashes will be in the odd squares and all backwards slashes in the even squares, or vice versa.</p>

### 출력 

 <p>Output a single integer, which is the least number of walls that need to be removed so that escape is possible from every cell in the maze.</p>

