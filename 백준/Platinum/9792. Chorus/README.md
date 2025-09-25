# [Platinum V] Chorus - 9792 

[문제 링크](https://www.acmicpc.net/problem/9792) 

### 성능 요약

메모리: 2160 KB, 시간: 12 ms

### 분류

브루트포스 알고리즘, 해싱, 문자열

### 제출 일자

2025년 9월 25일 12:48:41

### 문제 설명

<p>You suddenly remember part of a chorus of a song. You wonder which song has it in your list of n song lyrics.</p>

### 입력 

 <p>There are two parts in the input.</p>

<p>The first line of the first part of the input is an integer n (1≤ n ≤15), the number of songs in your database. Then, you will be given n strings in n lines that only contain lowercase alphabets [a..z].</p>

<p>Each string is a full lyric of a song without spaces, commas, periods, and any other non lowercase alphabet characters. We have simplified this input format to avoid unnecessary errors. We are using real songs in the test data, so you can expect that the length of the longest song in the list is less than 1500 characters.</p>

<p>Then, you will be given the second part of the input which starts with another integer q (1 ≤ q ≤ 20) that denotes the number of queries. Then, you will be given q short strings in q lines that only contain lowercase alphabets. Each query string is part of the song lyric, but not necessarily from the chorus.</p>

<p>Here we define chorus of a song as "the longest substring in that song lyric that appears more than once".</p>

### 출력 

 <p>For each query string, output a list of song indices that have that query string in its chorus in one line. Here we define that a query string is found in a chorus if it is a substring of the chorus. If there are more than one song found, separate their indices by a single space.</p>

<p>Note: There is no space at the end of the output and song number starts from 0. If there is no song with such chorus, output "-1" instead (without the quote).</p>

<p>We guarantee that the output is unique.</p>

