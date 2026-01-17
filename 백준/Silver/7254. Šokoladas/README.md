# [Silver IV] Šokoladas - 7254 

[문제 링크](https://www.acmicpc.net/problem/7254) 

### 성능 요약

메모리: 5960 KB, 시간: 8 ms

### 분류

구현, 브루트포스 알고리즘

### 제출 일자

2026년 1월 17일 19:51:21

### 문제 설명

<p>Vytautas darbo metu mėgsta valgyti šokoladą bei vaišinti juo savo kolegas. Jis perka šokolado plyteles, padalintas į M × N kvadratėlių, ant kurių užrašyti skaičiai nuo 1 iki G .</p>

<p>Visi kvadratėliai, ant kurių viršaus yra tas pats skaičius, sudaro sritį, kurios gali būti įvairių formų ir nebūtinai vientisos.</p>

<p>Vytautas planuoja pavaišinti kolegas ir nori nusipirkti tokią šokolado plytelę, kuriose visos minėtos sritys yra vientisi stačiakampiai.</p>

<p>Pavyzdys 1. Tarkime, yra tokia 2 × 6 plytelė:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/096bc1b0-d7f5-4b96-ae51-24fe075560c8/-/preview/" style="width: 300px; height: 115px;"></p>

<p>Kvadratėliai su skaičiumi 1 sudaro stačiakampę sritį 2 × 3, su skaičiais 2 ir 3 – sritis 1 × 2. Pagaliau, kvadratėliai su skaičiais 4 ir 5 sudaro stačiakampes sritis 1 × 1. Taigi, ši plytelė Vytautui yra tinkama.</p>

<p>Pavyzdys 2. Dabar panagrinėkime kitą, 3 × 6 dydžio, plytelę:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ad7d5887-f5fd-44db-87e2-99170b4f0348/-/preview/" style="width: 309px; height: 173px;"></p>

<p>Ši plytelė nėra tinkama dėl dviejų priežasčių. Kvadratėliai su skaičiumi 1 sudaro dvi atskiras stačiakampio sritis ir nėra vientisas stačiakampis. Kvadratėliai su skaičiumi 2 sudaro vientisą sritį, bet tai nėra stačiakampis.</p>

<p>Duota šokolado plytelė. Nustatykite, ar ją galima padalinti į vientisas stačiakampes sritis.</p>

### 입력 

 <p>Pirmoje eilutėje pateikti trys sveikieji skaičiai M, N, G, kurių pirmieji du apibrėžia plytelės dydį, o trečias reiškia didžiausią skaičių, užrašytą ant kurio nors kvadratėlio.</p>

<p>Tolimesnėse M eilutėse pateikiami skaičiai ant kavadratėlių – po N kiekvienoje eilutėje.</p>

### 출력 

 <p>Išveskite žodį TAIP, jeigu plytelę galima padalinti į vientisas stačiakampes sritis, arba NE – jeigu to negalima padaryti.</p>

