# [Gold V] Wi-fi Towers (Small) - 12615 

[문제 링크](https://www.acmicpc.net/problem/12615) 

### 성능 요약

메모리: 2020 KB, 시간: 360 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2025년 1월 10일 17:03:57

### 문제 설명

<p>You are given a network of wireless towers. Each tower has a range and can send data to neighboring towers as long as the distance is less than or equal to the sending tower's range.</p>

<p>The towers are using an old communication protocol A, but there is a new, better protocol B available. We are thinking about upgrading some towers to send data using protocol B to achieve better bandwidth.</p>

<p>There is one important restriction: if a tower T is using the new protocol B, every tower within T's range must also be running protocol B, so that they can understand the data sent from T. The reverse is not necessary — towers running the new protocol B can be sent data from towers using the old protocol A.</p>

<p>Your task is to select the best set of towers to upgrade from protocol A to protocol B. There is some benefit to upgrading a tower, but there are also installation costs. So each tower will have a score, which can be positive or negative, which is the value of upgrading the tower. Choose the set of towers to upgrade in such a way that the total score of the upgraded towers is maximized.</p>

### 입력 

 <p>The first line contains the number of test cases, <strong>T</strong>. Each test case starts with the number of towers, <strong>n</strong>. The following <strong>n</strong> lines each contain 4 integers: <strong>x</strong>, <strong>y</strong>, <strong>r</strong>, <strong>s</strong>. They describe a tower at coordinates <strong>x</strong>, <strong>y</strong> having a range of <strong>r</strong> and a score (value of updating to the new protocol) of <strong>s</strong></p>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 55</li>
	<li>-10 000 ≤ <strong>x</strong>, <strong>y</strong> ≤ 10 000</li>
	<li>1 ≤ <strong>r</strong> ≤ 20 000</li>
	<li>-1000 ≤ <strong>s</strong> ≤ 1000</li>
	<li>No two towers will have the same coordinates.</li>
	<li>1 ≤ <strong>n</strong> ≤ 15</li>
</ul>

### 출력 

 <p>For each test case, output:</p>

<pre>Case #X: score</pre>

<p>where <strong>X</strong> is the test case number, starting from 1, and <strong>score</strong> is the total score for the best choice of towers.</p>

<div> </div>

