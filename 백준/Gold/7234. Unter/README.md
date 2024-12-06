# [Gold I] Unter - 7234 

[문제 링크](https://www.acmicpc.net/problem/7234) 

### 성능 요약

메모리: 29556 KB, 시간: 432 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 12월 6일 19:13:22

### 문제 설명

<p>Justas planuoja sukurti programėlę, leidžiančią žmonėms dalintis kelionėmis automobiliu. Pirmiausia jam reikia parašyti programą, kuri leistų rasti trumpiausią atstumą tarp dviejų namų.</p>

<p>Mieste, kuriame veiks programėlė, yra N namų, sunumeruotų nuo 1 iki N. Namus tiesiogiai jungia N dvikrypčių gatvių. Viena gatvė jungia lygiai du namus ir du namus jungia ne daugiau kaip viena gatvė.</p>

<p>Justas jau parašė algoritmą, kuris leidžia rasti trumpiausią kelią tarp dviejų namų, kai yra tik vienas būdas nuvažiuoti iš vieno namo į kitą, nevažiuojant pro tą patį namą daugiau nei kartą. Tačiau jam reikia jūsų pagalbos rasti trumpiausią kelią tarp tokių namų porų, tarp kurių nuvažiuoti yra daugiau nei vienas toks būdas.</p>

<p>Raskite trumpiausią atstumą tarp Q namų porų.</p>

### 입력 

 <p>Pirmoje eilutėje pateikiami du sveikieji skaičiai: namų skaičius N ir užklausų skaičius Q.</p>

<p>Tolimesnėse N eilučių pateikiama po du tarpu atskirtus sveikuosius skaičius a<sub>i</sub> ir b<sub>i</sub>. Šie skaičiai nurodo, kad mieste egzistuoja gatvė tarp namų a<sub>i</sub> ir b<sub>i</sub>.</p>

<p>Likusiose Q eilučių pateikiama po du tarpu atskirtus sveikuosius skaičius c<sub>j</sub> ir d<sub>j</sub>.</p>

### 출력 

 <p>Išveskite Q eilučių. k-toje eilutėje pateikite vieną skaičių – trumpiausio kelio tarp namų c<sub>k</sub> ir d<sub>k</sub> ilgį. Atstumą tarp dviejų namų Justas skaičiuoja kaip gatvių, kuriomis reikia važiuoti, skaičių.</p>

