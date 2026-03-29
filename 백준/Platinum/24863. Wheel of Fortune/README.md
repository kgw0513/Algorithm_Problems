# [Platinum V] Wheel of Fortune - 24863 

[문제 링크](https://www.acmicpc.net/problem/24863) 

### 성능 요약

메모리: 79956 KB, 시간: 148 ms

### 분류

문자열, 브루트포스 알고리즘, 해 구성하기

### 제출 일자

2026년 3월 29일 12:13:24

### 문제 설명

<p>Katya's old dream to be in the "Wheel of Fortune" game has come true.</p>

<p>Let's remind the rules of the "Wheel of Fortune" game: </p>

<ul>
	<li>The goal of the game is to guess a word hidden by the game host. The contestants make turns by naming a letter. </li>
	<li>If the named letter occurs in the hidden word, then the host opens all its occurrences in the word, and the contestant can name a new letter. </li>
	<li>If the contestant names a letter that doesn't occur in the hidden word, the turn of the next contestant starts.</li>
</ul>

<p>The host of the game hides the word of length $L$. Katya really wanted to win the game, so she hacked the game editor's computer. She found out that the hidden word will be one of $N$ words.</p>

<p>Katya has the first turn in the game. Help Katya to understand if she can guarantee to win the game. Is it true that Katya will be able to guess any word from the stolen list  without loosing the turn?</p>

### 입력 

 <p>In the first line there are two integers $L$ and $N$ --- the length of the hidden word and the number of stolen words ($1 \le L \le 10^6$, $1 \le N \le 10^5$).</p>

<p>In the next $N$ lines there are different words of length $L$. They consist of lowercase English letters.</p>

<p>It is guaranteed that the total length of all words does not exceed $10^6$.</p>

### 출력 

 <p>Output "<code>YES</code>", if Katya is able guarantee herself a win, otherwise output "<code>NO</code>".</p>

