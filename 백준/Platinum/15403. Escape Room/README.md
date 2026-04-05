# [Platinum V] Escape Room - 15403 

[문제 링크](https://www.acmicpc.net/problem/15403) 

### 성능 요약

메모리: 4076 KB, 시간: 24 ms

### 분류

그리디 알고리즘, 애드 혹

### 제출 일자

2026년 4월 5일 13:47:06

### 문제 설명

<p>As you know, escape rooms became very popular since they allow you to play the role of a video game hero. One such room has the following quiz. You know that the locker password is a permutation of N numbers. A permutation of length N is a sequence of distinct positive integers, whose values are at most N. You got the following hint regarding the password - the length of the longest increasing subsequence starting at position i equals A<sub>i</sub>. Therefore you want to find the password using these values. As there can be several possible permutations you want to find the lexicographically smallest one. Permutation P is lexicographically smaller than permutation Q if there is an index i such that P<sub>i</sub> < Q<sub>i</sub> and P<sub>j</sub> = Q<sub>j</sub> for all j < i. It is guaranteed that there is at least one possible permutation satisfying the above constraints. Can you open the door?</p>

### 입력 

 <p>The first line of the input contains one integer N (1 ≤ N ≤ 10<sup>5</sup>).</p>

<p>The next line contains N space-separated integer A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ N).</p>

<p>It’s guaranteed that at least one possible permutation exists. </p>

### 출력 

 <p>Print in one line the lexicographically smallest permutation that satisfies all the conditions.</p>

