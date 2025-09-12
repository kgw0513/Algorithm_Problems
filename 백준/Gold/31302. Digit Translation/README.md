# [Gold III] Digit Translation - 31302 

[문제 링크](https://www.acmicpc.net/problem/31302) 

### 성능 요약

메모리: 11960 KB, 시간: 192 ms

### 분류

다이나믹 프로그래밍, 문자열

### 제출 일자

2025년 9월 12일 12:04:03

### 문제 설명

<p>You are given a string of lowercase letters. In one operation, if you can find a substring that is one of the written-out forms of one of the digits from zero to nine ("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"), you can replace that substring with the numeric digit.</p>

<p>Your goal is to find the shortest possible string you can end up with after applying zero or more of these operations, as well as how many distinct strings of that length there are.</p>

### 입력 

 <p>The single line of input contains a string of lowercase letters with length at least one and at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>6</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^6$</span></mjx-container>.</p>

### 출력 

 <p>Output two separate lines.</p>

<p>On the first line output a single integer, which is the length of the shortest possible string.</p>

<p>On the second line output a single integer, which is the number of distinct strings of that length that can be obtained after applying zero or more of the specified operations, modulo 9302023.</p>

