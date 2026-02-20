# [Silver II] Geometric Inflation - 9307 

[문제 링크](https://www.acmicpc.net/problem/9307) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

사칙연산, 다이나믹 프로그래밍, 수학, 문자열

### 제출 일자

2026년 2월 20일 17:38:01

### 문제 설명

<p>A very unusual model of inflation can be simulated by multiplying the cost of a given item 3 months ago with the cost of the item 2 months ago and dividing that quantity by the cost of the item 1 month ago. The costs will be given in dollars, with no more than 2 decimal places representing cents. No cost can include partial cents, so always round to the nearest whole cent for every month.</p>

<p>For example, suppose dumplings from the corner cost <span>$</span>5.23 in month 1, <span>$</span>5.50 in month 2, and <span>$</span>5.52 in month 3. It is now month 4 and we need to find out how much to charge considering inflation. We would multiply 5.23 by 5.50 to get 28.765. Note: no rounding takes place at this step. Then take that quantity and divide it by 5.52 to get 5.21.</p>

### 입력 

 <p>Each line will start with 3 decimal numbers, with 1 or 2 decimal places, representing the costs at month 1, 2, and 3. The next input on the line will be an integer, N, between 1 and 100 inclusively indicating for which month the cost is to be calculated. A line starting with -1 will mark the end of the test cases.</p>

### 출력 

 <p>For each test case (line of input) you should calculate the cost for that month and output your result as “Month N cost: <span>$</span>c”, where c is the cost in dollars. Each output should have exactly 2 decimal digits and be comma grouped. The cost for every month that you are requested to find will fit in a Java double.</p>

