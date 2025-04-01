# [Gold V] Turnir - 12111 

[문제 링크](https://www.acmicpc.net/problem/12111) 

### 성능 요약

메모리: 51456 KB, 시간: 1360 ms

### 분류

애드 혹, 이분 탐색, 수학, 정렬

### 제출 일자

2025년 4월 1일 18:22:08

### 문제 설명

<p>Young Jozef was given a set consisting of 2<sup>N</sup> positive integers as a gift. Considering the fact that Jozef often takes part in football tournaments, he decided to organize a tournament for his 2<sup>N</sup> positive integers.</p>

<p>The numbers tournament is depicted below; the tournament takes place in pairs, where the higher of two numbers advances to the upper level. The levels are denoted with numbers from 1 to N, where the highest level is given the number 0.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12111/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-03-09%20%EC%98%A4%ED%9B%84%208.43.48.png" style="height:513px; width:500px"></p>

<p>Since Jozef doesn’t have time to organize all tournaments, he wants to know, for each number from the initial set, the highest level (the smallest level number) at which the number can end up in, for any permutation of the input array.</p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 20).</p>

<p>The following line contains 2<sup>N</sup> positive integers from the interval [1, 10<sup>9</sup>], the elements of the set.</p>

### 출력 

 <p>The first and only line of output must contain 2<sup>N</sup> numbers, the labels of the highest level (the smallest level labels) at which a number can end up in, in the order the numbers were given in the input.</p>

