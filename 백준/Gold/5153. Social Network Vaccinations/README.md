# [Gold V] Social Network Vaccinations - 5153 

[문제 링크](https://www.acmicpc.net/problem/5153) 

### 성능 요약

메모리: 2024 KB, 시간: 1536 ms

### 분류

백트래킹, 브루트포스 알고리즘, 플러드 필, 그래프 이론, 그래프 탐색, 파싱, 문자열

### 제출 일자

2025년 8월 2일 16:52:03

### 문제 설명

<p>Health Care policy decisions lead to or rely on many interesting computational questions. One involves vaccinations. The current approach here is to leave the decision to individuals, or, in some cases, try to vaccinate everyone. The ideal time for that is in school, as it may provide the most comprehensive access to a population. If a vaccination of everyone is overkill, it is not clear that leaving the decision to individuals is a very good policy. This approach basically assumes that the vaccinated person is the main or only one benefiting from it. But that’s far from the truth: by being vaccinated, a person also contributes significantly to protecting others, for the vaccinated person cannot catch or transmit the disease. Thus, from a societal viewpoint, it would be ideal to choose vaccinated individuals carefully to protect the whole of society well.</p>

<p>One simple way to model this is as follows: we are given a social network (graph) with individuals and their connections. We assume the following for simplicity: whenever someone gets sick, he will infect all his unvaccinated friends, who will then also get sick. Anyone who is vaccinated never gets sick. As the public health operator, we know the number D of doses of the vaccine we have. We can use it to vaccinate D individuals. Being pessimistic, we assume that afterwards, the disease will break out at one individual so that it maximizes the number of people who eventually get sick. Our goal is thus to choose the D individuals to vaccinate to minimize the number of people who will eventually get sick, under the pessimistic assumption.</p>

### 입력 

 <p>The first line is the number K of input data sets, followed by the K data sets, each of the following form:</p>

<p>The first line contains two integers n,D. 1 ≤ n ≤ 30 is the number of people in the network, and 0 ≤ D ≤ 6 is the number of doses of the vaccine we have.</p>

<p>This is followed by n lines, each describing the friends of one individual. The ith line will contain all the friends of person i, separated by spaces. Friendships are reflexive and symmetric, i.e., everyone has at least himself as a friend, and if i is friends with j, then j is also friends with i.</p>

### 출력 

 <p>For each data set, output “Data Set x:” on a line by itself, where x is its number. On the next line, output the number of people who will get sick in the worst case, assuming you choose an optimal set of people to vaccinate. Each data set should be followed by a blank line.</p>

