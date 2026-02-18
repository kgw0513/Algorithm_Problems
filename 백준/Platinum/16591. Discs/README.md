# [Platinum IV] Discs - 16591 

[문제 링크](https://www.acmicpc.net/problem/16591) 

### 성능 요약

메모리: 11248 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2026년 2월 19일 02:03:33

### 문제 설명

<p>There are N discs on a two dimensional field, and all of them are centered on different lattice points. These discs have an interesting arrangement, i.e. for every two different discs A and B, then either A is inside B or B is inside A (they may touch each other). Note that the shape of each disc is a circle.</p>

<p>Now, forget the discs, and you will see the truth! As you step forward into a new dimension, an astonishing and utterly new world arises as only the N center points remain. The time has come for you to reconstruct the discs in a better way: Each disc mush be centered at one of those center points, and each center point must be the center of exactly one disc. Every two different discs must satisfy the previous arrangement (i.e. either A is inside B or B is inside A). Finally, the sum of all discs’ radii is minimum. Note that a disc’s radius can be 0, which is essentially a dot.</p>

<p>Given N different lattice points, find the minimum possible sum for such discs’ radii. Your answer will be considered as correct if it has an absolute or relative error less than 10<sup>−6</sup>.</p>

### 입력 

 <p>Input begins with an integer: N (2 ≤ N ≤ 16) representing the number of center points. The next N lines, each contains two integers: x<sub>i</sub> y<sub>i</sub> (0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>) representing a center point at coordinate (x<sub>i</sub>, y<sub>i</sub>). You may safely assume that all the given center points are unique.</p>

### 출력 

 <p>Output in a line the minimum possible sum of the discs’ radii which satisfies the requirement given in the problem statement.</p>

