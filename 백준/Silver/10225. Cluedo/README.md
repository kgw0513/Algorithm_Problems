# [Silver V] Cluedo - 10225 

[문제 링크](https://www.acmicpc.net/problem/10225) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2025년 3월 25일 19:45:44

### 문제 설명

<p>Dr. Black has been murdered. Detective Jill must determine the murderer, the location, and the weapon. There are six possible murderers, numbered 1 to 6. There are ten possible locations, numbered 1 to 10. There are six possible weapons, numbered 1 to 6.</p>

<p>For illustration only, we show the names of the possible murderers, locations and weapons. The names are not required to solve the task.</p>

<table class="table table-bordered">
	<thead>
		<tr>
			<th>Murderer</th>
			<th>Location</th>
			<th>Weapon</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>
			<ol>
				<li>Professor Plum</li>
				<li>Miss Scarlet</li>
				<li>Colonel Mustard</li>
				<li>Mrs. White</li>
				<li>Reverend Green</li>
				<li>Mrs. Peacock</li>
			</ol>
			</td>
			<td>
			<ol>
				<li>Ballroom</li>
				<li>Kitchen</li>
				<li>Conservatory</li>
				<li>Dining Room</li>
				<li>Billiard Room</li>
				<li>Library</li>
				<li>Lounge</li>
				<li>Hall</li>
				<li>Study</li>
				<li>Cellar</li>
			</ol>
			</td>
			<td>
			<ol>
				<li>Lead pipe</li>
				<li>Dagger</li>
				<li>Candlestick</li>
				<li>Revolver</li>
				<li>Rope</li>
				<li>Spanner</li>
			</ol>
			</td>
		</tr>
	</tbody>
</table>

<p>Jill repeatedly tries to guess the correct combination of murderer, location and weapon. Each guess is called a <i>theory</i>. She asks her assistant Jack to confirm or to refute each theory in turn. When Jack confirms a theory, Jill is done. When Jack refutes a theory, he reports to Jill that one of the murderer, location or weapon is wrong.</p>

<p>You are to implement the procedure <b>Solve</b> that plays Jill's role. The grader will call <b>Solve</b> many times, each time with a new case to be solved. <b>Solve</b> must repeatedly call <b>Theory(M,L,W)</b>, which is implemented by the grader. M, L and W are numbers denoting a particular combination of murderer, location and weapon. <b>Theory(M,L,W)</b> returns 0 if the theory is correct. If the theory is wrong, a value of 1, 2 or 3 is returned. 1 indicates that the murderer is wrong; 2 indicates that the location is wrong; 3 indicates that the weapon is wrong. If more than one is wrong, Jack picks one arbitrarily between the wrong ones (not necessarily in a deterministic way). When <b>Theory(M,L,W)</b> returns 0, <b>Solve</b> should return.</p>

### 입력 

 Empty

### 출력 

 Empty

