# [Gold IV] Zabawki - 26679 

[문제 링크](https://www.acmicpc.net/problem/26679) 

### 성능 요약

메모리: 3352 KB, 시간: 300 ms

### 분류

애드 혹, 문자열

### 제출 일자

2025년 9월 15일 13:15:30

### 문제 설명

<p>Być może o tym nie wiesz, ale bracia Bituś i Bajtuś posiadają całkiem imponujące kolekcje zabawek! Każdy z braci posiada n zabawek, a każda jest jednego z 26 typów. Dla ułatwienia bracia oznaczyli zabawki każdego typu kolejnymi literami alfabetu angielskiego – od <code>a</code> do <code>z</code>.</p>

<p>Podczas dzisiejszej zabawy Bituś wyjął swoje zabawki i ułożył je w ciągu od lewej do prawej. Tak więc Bituś może opisać ułożenie swoich zabawek za pomocą ciągu n znaków alfabetu angielskiego; i-ty znak tego ciągu wyznacza i-tą zabawkę od lewej w ciągu Bitusia. Również Bajtuś wyjął swoje zabawki i ułożył je w ciągu od lewej do prawej. Teraz Bituś chciałby upodobnić się do Bajtusia – sprawić, by jego zabawki były ułożone w tej samej kolejności, co zabawki Bajtusia.</p>

<p>W trakcie zabawy Bituś może zmieniać kolejność swoich zabawek za pomocą ruchów: każdy ruch polega na wzięciu pewnej nieparzystej liczby kolejnych zabawek i odwróceniu ich kolejności. Tak więc jeśli ciąg znaków <code>abcdea</code> opisuje kolejność zabawek Bitusia, to w jednym ruchu Bituś może uzyskać na przykład kolejność <code>adcbea</code> (poprzez odwrócenie kolejności zabawek od drugiej do czwartej) lub <code>edcbaa</code> (odwracając zabawki od pierwszej do piątej). Nie może on jednak wyprodukować w jednym ruchu kolejności bacdea.</p>

<p>Czy Bituś jest w stanie sprawić, by jego zabawki były ułożone w tej samej kolejności, co zabawki Bajtusia?</p>

### 입력 

 <p>Pierwszy wiersz wejścia zawiera jedną liczbę całkowitą n (1 ≤ n ≤ 300 000) oznaczającą liczbę zabawek posiadanych przez Bitusia (i zarazem liczbę zabawek Bajtusia). Drugi wiersz zawiera ciąg n znaków alfabetu angielskiego (od <code>a</code> do <code>z</code>) opisujący układ zabawek Bitusia na początku zabawy. Trzeci wiersz opisuje układ zabawek Bajtusia – w tym samym formacie co drugi wiersz.</p>

### 출력 

 <p>Jeśli Bituś może operacjami odwracania doprowadzić swój początkowy układ zabawek do układu zabawek Bajtusia, wypisz <code>TAK</code> w jedynym wierszu wyjścia. W przeciwnym razie wypisz <code>NIE</code>.</p>

