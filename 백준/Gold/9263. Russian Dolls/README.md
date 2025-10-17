# [Gold IV] Russian Dolls - 9263 

[문제 링크](https://www.acmicpc.net/problem/9263) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 10월 17일 15:01:33

### 문제 설명

<p>Maybe you know the famous russian souvenir Russian Dolls. It looks like a set of nested wooden  dolls. A doll with a smaller size is placed inside a bigger one. Let's consider all dolls taken apart.  Each doll has an outer volume out<sub>i</sub> which is the volume it occupies in space and an inner  volume in<sub>i</sub> - the volume of the empty space inside the doll. You may assume that you can put  one doll inside another if the outer volume of the first doll is strictly less than the inner volume of  the second one. If two or more dolls are inside another one they can't lie one near the other, they  must be nested.</p>

<p>For each doll the cost of unit of empty space - cost<sub>i</sub> is known. You must pay exactly cost<sub>i</sub> for  each unit of empty space which directly belongs to the i-th doll (but not to ones inside it). You  may arrange the dolls the way you want as long as you are not contradicting the rules. The  objective is to find an arrangement of nesting the dolls (not necessarily all of them) such that the overall cost you have to pay is minimized.</p>

### 입력 

 <p>First line contains an integer N (1 ≤ N ≤ 1000) which is the number of dolls you have. The i-th of the next N lines contains three integers out<sub>i</sub>, in<sub>i</sub>, cost<sub>i</sub> (1 ≤ in<sub>i</sub> < out<sub>i</sub> ≤ 1000, 1 ≤ cost<sub>i</sub> ≤ 1000), which are the outer volume, inner volume and the empty space cost of the i-th doll.</p>

### 출력 

 <p>Single integer P which is the minimum possible cost you should pay.</p>

