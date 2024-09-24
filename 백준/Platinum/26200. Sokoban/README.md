# [Platinum IV] Sokoban - 26200 

[문제 링크](https://www.acmicpc.net/problem/26200) 

### 성능 요약

메모리: 77996 KB, 시간: 2160 ms

### 분류

0-1 너비 우선 탐색, 너비 우선 탐색, 데이크스트라, 그래프 이론, 그래프 탐색, 최단 경로

### 제출 일자

2024년 9월 15일 01:55:22

### 문제 설명

<p>If you are familiar with the Sokoban video game, the description of the task is quite short. You have to find the minimum number of box pushes to solve a given puzzle. The number of moves the player makes is not important.</p>

<p>The game Sokoban takes place on a grid, where in every step the player can move to one of the four adjacent squares in either the horizontal or vertical direction. Some squares are blocked by walls and some other squares are occupied by boxes. Certain squares are designated as storage locations. The player has to push boxes onto those storage locations. The player pushes a box by moving into its square, which pushes it into the square beyond. There must be a free square beyond the box, otherwise it cannot be moved. The player also cannot push boxes into other boxes or walls, and boxes cannot be pulled or transferred in any other way. The only allowed method of moving boxes is by pushing them. Even if the box is already on the storage location, it can still be moved. The only important thing is that all boxes end up on the storage locations in the end.</p>

<p>Even very small configurations can be extremely complex, so we need to use an efficient algorithm for solving Sokoban puzzles.</p>

### 입력 

 <p>A grid of dimensions <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times M$</span></mjx-container> is described in <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines with at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> characters. Some lines may contain less than <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> characters as they do not contain trailing spaces. It is guaranteed that the player is in a region that is enclosed with the walls. The number of boxes <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container> equals the number of storage locations. The following list describes the meaning of each character that can be used to describe a puzzle:</p>

<pre><code>'#' - a wall
' ' - free square
'.' - free storage location
'@' - the player standing on a square that is not a storage location
'+' - the player standing on a storage location
'$' - a box placed on a square that is not a storage location
'*' - a box placed on a storage location
</code></pre>

### 출력 

 <p>Output a single line that contains the minimum number of box pushes that are needed to solve the given puzzle. It is guaranteed that a puzzle is solvable.</p>

