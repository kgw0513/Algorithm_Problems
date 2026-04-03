# [Platinum V] Wowow - 6806 

[문제 링크](https://www.acmicpc.net/problem/6806) 

### 성능 요약

메모리: 103172 KB, 시간: 1992 ms

### 분류

자료 구조, 세그먼트 트리, 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2026년 4월 3일 16:47:06

### 문제 설명

<p>In the World of World of Warcraft, there is a very competitive ladder system. Sometimes players will change their rating. Also, new players (including more and more of your friends!) are constantly joining the game.</p>

<p>You and your group of friends would like to maintain a simple database with your scores, and you, as the computer scientist of the group, have been charged with the responsability of maintaning it. Don’t let your friends down!</p>

### 입력 

 <p>The input will consist of an integer N (1 ≤ N ≤ 1, 000, 000), followed by N lines. Each of these N lines will correspond to one of the following three formats:</p>

<ul>
	<li>N X R, where N is the character ’N’ to indicate a new friend has been added, X is a number (1 ≤ X ≤ 1, 000, 000) identifying this new friend, and R (1 ≤ R ≤ 10<sup>8</sup>) is the rating of this new friend.</li>
	<li>M X R, where M is the character ’M’ to indicate a modification of an existing friend, X is a number (1 ≤ X ≤ 1, 000, 000) identifying one of your friends, and R is the new rating assigned to this existing friend.</li>
	<li>Q K, where Q is the character ’Q’ to represent a query, K is a number (1 ≤ K ≤ 1, 000, 000), and K is at most the number of your friends that have a rating at this point.</li>
</ul>

<p>You may assume there will be no identical ratings in the input.</p>

### 출력 

 <p>For each line of input of the format Q K, you will output a line containing the identifier of the Kth highest rated person in the database at that point. Note that when K = 1, that is the top rated person, and K = 2 is the second best rated person, and so on.</p>

