# [Unrated] Queen’s Case - 22631 

[문제 링크](https://www.acmicpc.net/problem/22631) 

### 성능 요약

메모리: 10348 KB, 시간: 4 ms

### 분류

분류 없음

### 제출 일자

2025년 11월 8일 04:05:54

### 문제 설명

<p>A small country called Maltius was governed by a queen. The queen was known as an oppressive ruler. People in the country suffered from heavy taxes and forced labor. So some young people decided to form a revolutionary army and fight against the queen. Now, they besieged the palace and have just rushed into the entrance.</p>

<p>Your task is to write a program to determine whether the queen can escape or will be caught by the army.</p>

<p>Here is detailed description.</p>

<ul>
	<li>The palace can be considered as grid squares.</li>
	<li>The queen and the army move alternately. The queen moves first.</li>
	<li>At each of their turns, they either move to an adjacent cell or stay at the same cell.</li>
	<li>Each of them must follow the optimal strategy.</li>
	<li>If the queen and the army are at the same cell, the queen will be caught by the army immediately.</li>
	<li>If the queen is at any of exit cells alone after the army’s turn, the queen can escape from the army.</li>
	<li>There may be cases in which the queen cannot escape but won’t be caught by the army forever, under their optimal strategies.</li>
</ul>

### 입력 

 <p>The input describes a map of the palace. The first line of the input contains two integers <i>W</i> (1 ≤ <i>W</i> ≤ 30) and <i>H</i> (1 ≤ <i>H</i> ≤ 30), which indicate the width and height of the palace. The following <i>H</i> lines, each of which contains <i>W</i> characters, denote the map of the palace. "Q" indicates the queen, "A" the army,"E" an exit,"#" a wall and "." a floor.</p>

<p>The map contains exactly one "Q", exactly one "A" and at least one "E". You can assume both the queen and the army can reach all the exits.</p>

### 출력 

 <p>Output "Queen can escape.", "Army can catch Queen." or "Queen can not escape and Army can not catch Queen." in a line.</p>

