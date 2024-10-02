# [Gold IV] Fair coin toss - 27697 

[문제 링크](https://www.acmicpc.net/problem/27697) 

### 성능 요약

메모리: 1112 KB, 시간: 4 ms

### 분류

수학, 확률론

### 제출 일자

2024년 10월 2일 19:03:50

### 문제 설명

<p>Lolek and Bolek are studying to become magicians. For the last hour they have been arguing whose turn it is to take out the trash. The fair solution would be to toss a coin… but one should never trust a magician when tossing a coin, right?</p>

<p>After looking through all pockets, they found n coins, each with one side labeled 1 and the other labeled 0. For each coin i they know the probability p<sub>i</sub> that it will show the side labeled 1 when tossed.</p>

<p>Of course, just knowing their coins did not really solve their problem. They still needed a fair way to decide their argument. After a while, Lolek came up with the following suggestion: they will toss all the coins they have, and xor the outcomes they get. In other words, they will just look at the parity of the number of 1s they see. If they get an even number of 1s, it’s Bolek’s turn to take out the trash, otherwise it’s Lolek’s turn.</p>

<p>Now they are arguing again – about the fairness of this method.</p>

<p>A set of coins is called fair if Lolek’s method is fair – that is, the probability that Bolek will take out the trash has to be exactly 50%.</p>

<p>You are given a description of all coins Lolek and Bolek have.</p>

<p>Find out how many subsets of the given set of coins are fair.</p>

### 입력 

 <p>The ﬁrst line of the input ﬁle contains an integer t specifying the number of test cases. Each test case is preceded by a blank line.</p>

<p>Each test case consists of two lines. The ﬁrst line contains the number n of coins (at most 10 in the easy data set, at most 60 in the hard data set). The second line contains n decimal numbers: the probabilities p<sub>1</sub>,…,p<sub>n</sub>. Each probability is given to exactly 6 decimal places.</p>

### 출력 

 <p>For each test case output a single line.</p>

<p>This line should contain the exact number of fair subsets.</p>

