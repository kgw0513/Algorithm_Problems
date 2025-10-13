# [Gold III] Paper Route - 4138 

[문제 링크](https://www.acmicpc.net/problem/4138) 

### 성능 요약

메모리: 12896 KB, 시간: 60 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 10월 13일 21:32:34

### 문제 설명

<p>As a poor, tuition-ridden student, you've decided to take up a part time job as a paperboy/papergirl. You've just been handed your paper route: a set of addresses (conveniently labelled 1 to <em>N</em>).</p>

<p>Every morning, you start at the newspaper office (which happens to be address number 0). You have to plan a route to deliver a newspaper to every address - and you also want to get to class right after you're done. Conveniently, there are only <em>N</em> roads in your area connecting the addresses, and each of them takes a known time to traverse. Also, you've precalculated the time it takes to get to Waterloo campus from each address, including the newspaper office (through some combination of biking, busing, or hitching a ride). How soon can you be done delivering papers and be in your seat at school?</p>

### 입력 

 <p>First, there will be a single integer <em>N</em> (the number of addresses, 1 ≤ <em>N</em> ≤ 100,000).</p>

<p>Next, there will be <em>N</em>+1 lines, each with an integer <em>c<sub>i</sub></em> (starting with <em>i</em> = 0, 0 ≤ <em>c<sub>i</sub></em> ≤ 1,000,000,000), the time it takes to get from location <em>i</em> to campus.</p>

<p>Finally, the input will contain <em>N</em> lines, each with three integers <em>a</em>, <em>b</em>, <em>c</em> (0 ≤ <em>a</em>, <em>b</em> ≤ <em>N</em>, <em>a</em> != <em>b</em>, 0 ≤ <em>c</em> ≤ 1,000). Each of these lines describes a road between locations <em>a</em> and <em>b</em> taking <em>c</em> minutes to traverse.</p>

<p>It is guaranteed that you will be able to reach all the addresses. (Remember that location 0 is the newspaper office.)</p>

### 출력 

 <p>Output the minimum time it will take to deliver all the papers and get to class.</p>

