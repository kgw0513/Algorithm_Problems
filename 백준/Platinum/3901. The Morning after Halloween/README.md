# [Platinum V] The Morning after Halloween - 3901 

[문제 링크](https://www.acmicpc.net/problem/3901) 

### 성능 요약

메모리: 76172 KB, 시간: 4080 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프

### 제출 일자

2025년 12월 13일 17:08:44

### 문제 설명

<p>You are working for an amusement park as an operator of an obakeyashiki, or a haunted house, in which guests walk through narrow and dark corridors. The house is proud of their lively ghosts, which are actually robots remotely controlled by the operator, hiding here and there in the corridors. One morning, you found that the ghosts are not in the positions where they are supposed to be. Ah, yesterday was Halloween. Believe or not, paranormal spirits have moved them around the corridors in the night. You have to move them into their right positions before guests come. Your manager is eager to know how long it takes to restore the ghosts.</p>

<p>In this problem, you are asked to write a program that, given a floor map of a house, finds the smallest number of steps to move all ghosts to the positions where they are supposed to be.</p>

<p>A floor consists of a matrix of square cells. A cell is either a wall cell where ghosts cannot move into or a corridor cell where they can.</p>

<p>At each step, you can move any number of ghosts simultaneously. Every ghost can either stay in the current cell, or move to one of the corridor cells in its 4-neighborhood (i.e. immediately left, right, up or down), if the ghosts satisfy the following conditions:</p>

<ol>
	<li>No more than one ghost occupies one position at the end of the step.</li>
	<li>No pair of ghosts exchange their positions one another in the step.</li>
</ol>

<p>For example, suppose ghosts are located as shown in the following (partial) map, where a sharp sign (‘#’) represents a wall cell and ‘a’, ‘b’, and ‘c’ ghosts.</p>

<pre>####
 ab#
#c##
####
</pre>

<p>The following four maps show the only possible positions of the ghosts after one step.</p>

<pre>####   ####   ####   ####
 ab#   a b#   acb#   ab #
#c##   #c##   # ##   #c##
####   ####   ####   ####
</pre>

### 입력 

 <p>The input consists of at most 10 datasets, each of which represents a floor map of a house. The format of a dataset is as follows.</p>

<pre>w h n
c11 c12 ··· c1w
c21 c22 ··· c2w
...
ch1 ch2 ··· chw
</pre>

<p> </p>

<p>w, h and n in the first line are integers, separated by a space. w and h are the floor width and height of the house, respectively. n is the number of ghosts. They satisfy the following constraints.</p>

<p>4 ≤ w ≤ 16, 4 ≤ h ≤ 16, 1 ≤ n ≤ 3</p>

<p>Subsequent h lines of w characters are the floor map. Each of cij is either:</p>

<ul>
	<li>a ‘#’ representing a wall cell,</li>
	<li>a lowercase letter representing a corridor cell which is the initial position of a ghost,</li>
	<li>an uppercase letter representing a corridor cell which is the position where the ghost corresponding to its lowercase letter is supposed to be, or</li>
	<li>a space representing a corridor cell that is none of the above.</li>
</ul>

<p>In each map, each of the first n letters from a and the first n letters from A appears once and only once. Outermost cells of a map are walls; i.e. all characters of the first and last lines are sharps; and the first and last characters on each line are also sharps. All corridor cells in a map are connected; i.e. given a corridor cell, you can reach any other corridor cell by following corridor cells in the 4-neighborhoods. Similarly, all wall cells are connected. Any 2 × 2 area on any map has at least one sharp. You can assume that every map has a sequence of moves of ghosts that restores all ghosts to the positions where they are supposed to be.</p>

<p>The last dataset is followed by a line containing three zeros separated by a space.</p>

### 출력 

 <p>For each dataset in the input, one line containing the smallest number of steps to restore ghosts into the positions where they are supposed to be should be output. An output line should not contain extra characters such as spaces.</p>

