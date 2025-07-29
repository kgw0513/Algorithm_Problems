# [Gold III] Zmija - 14154 

[문제 링크](https://www.acmicpc.net/problem/14154) 

### 성능 요약

메모리: 8284 KB, 시간: 256 ms

### 분류

자료 구조, 덱, 구현, 시뮬레이션

### 제출 일자

2025년 7월 29일 16:58:07

### 문제 설명

<p>Po ploči sastavljenoj od N x N jediničnih kvadratića gmižu zmije. Svaka zmija zauzima niz od barem dva kvadratića, takav da svaka dva uzastopna kvadratića imaju zajedničku stranicu. Prvi kvadratić u nizu nazivamo glava. Na svakom kvadratiću ploče se može nalaziti maksimalno jedna zmija. Kvadratići koje na početku ne zauzimaju zmije mogu biti ili prazni ili se u njima može nalaziti prepreka.</p>

<p>Zmija gmiže tako da, u svakom koraku, najprije pomakne glavu na neko prazno susjedno polje, a zatim povuče rep ispraznivši tako jedno polje. Smjer kretanja je na početku odreñen položajem glave u odnosu na drugi po redu kvadratić koji čini zmiju. U svakom koraku zmija se ponaša prema sljedećim pravilima:</p>

<ul>
	<li>Ukoliko se može pomaknuti naprijed (bez da se pritom sudari sa preprekom, drugom zmijom, samom sobom ili da izañe izvan granica ploče), onda se pomakne naprijed;</li>
	<li>ako je to nemoguće onda pokuša skrenuti prema desno;</li>
	<li>ako je to nemoguće onda pokuša skrenuti prema lijevo;</li>
	<li>ako je to nemoguće onda ostane stajati na mjestu, te se u sljedećem koraku opet pokušava pomaknuti naprijed.</li>
</ul>

<p>Na ploči se nalazi nekoliko zmija označenih slovima engleske abecede. U svakom koraku sve se pokušavaju se pomaknuti prema gore opisanim pravilima i to abecednim redoslijedom. Svaki korak traje točno jednu sekundu. Napišite program koji će, za zadani početni položaj zmija na ploči, utvrditi njihov položaj nakon što protekne T sekundi. </p>

### 입력 

 <p>U prvom redu ulaza nalaze se cijeli brojevi N i T, 2 ≤ N ≤ 1 000, 1 ≤ T ≤ 1 000 000. Broj N opisuje dimenziju ploče, a T je broj sekundi nakon kojih treba utvrditi položaj zmija.</p>

<p>U svakom od idućih N redova nalazi se po N znakova; ti redovi opisuju početni položaj zmija, praznih kvadratića i prepreka na ploči.</p>

<p>Preciznije, svaki znak može biti:</p>

<ul>
	<li>'.' (točka) – pripadni kvadratić je prazan</li>
	<li>'#' – na pripadnom kvadratiću je prepreka</li>
	<li>veliko slovo engl. abecede – na pripadnom kvadratiću je glava zmije</li>
	<li>malo slovo engl. abecede – na pripadnom kvadratiću je dio zmije koji nije glava</li>
</ul>

<p>Svi kvadratići u kojima se nalazi isto slovo abecede (bilo veliko ili malo) čine jednu zmiju. Pri tome će ulazni podaci biti takvi da će svaki kvadratić koji čini neku zmiju biti susjedan točno sa dva druga njena kvadratića, osim glave i vrha repa koji će biti susjedni točno jednom njezinom kvadratiću. Naravno, neće postojati dvije različite zmije označene istim slovom. </p>

### 출력 

 <p>Potrebno je ispisati N redova, svaki sa po N znakova. Ti redovi trebaju opisivati položaj zmija po isteku T sekundi, u istom formatu kako je položaj bio opisan u ulaznim podacima. </p>

