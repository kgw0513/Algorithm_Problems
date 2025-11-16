# [Gold III] Macbeth - 13501 

[문제 링크](https://www.acmicpc.net/problem/13501) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 11월 16일 20:41:02

### 문제 설명

<p>Macbeth starts out as a faithful follower of the king, having just played a pivotal role in a battle. Unfortunately, he meets three witches who predict an impending promotion, and his subsequent becoming king. When the promotion indeed happens, he starts to believe in his destiny to be king; he and his wife become blinded and crazed by naked ambition, and murder the king and pretty much everyone they perceive to be a threat or competition.</p>

<p>What gave the witches so much power over Macbeth is their ability to make a correct prediction of the future.4 Perhaps, Macbeth should have made their task a little harder by asking for more than one prediction. As you all know, making predictions using a crystal ball is hard work: crystal balls tend to be fussy about when they will let you predict particular events, and some take longer than others. So it becomes a difficult task for the witches to figure out how to make the most predictions together.</p>

<p>For each event, you will be given an interval of time. If the witches want to predict the event, one of them has to be looking at her crystal ball for the entirety of that time interval while thinking about the event. (So even if two events have the same interval, that one witch can only predict one of them.) Of course, the witches will coordinate to predict as many events total as possible.</p>

### 입력 

 <p>The first line contains a number K ≥ 1, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of each data set contains two integers n, w. 0 ≤ n ≤ 1000 is the number of events, and 1 ≤ w ≤ 10 is the number of witches.</p>

<p>This is followed by n lines, each describing one event i with two integers 0 ≤ s<sub>i</sub> < t<sub>i</sub> ≤ 10<sup>7</sup>. In order to predict event i, one witch has to watch her crystal ball for the entirety of the interval [s<sub>i</sub>, t<sub>i</sub>] while only thinking about event i.</p>

### 출력 

 <p>For each data set, first output “Data Set x:” on a line by itself, where x is its number. Then, output the maximum total number of events the witches can predict.</p>

<p>Each data set should be followed by a blank line.</p>

