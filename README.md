# Maszyna Turinga C++
**Michał Bartula, Maciej Grygierzec**

Prosty symulator **Maszyny Turinga**, oparty na języku C++. Maszyna wykonuje polecenia użytkownika na wzór **Maszyny Turinga**, na podstawie otrzymanych danych.
## Instrukcja instalacji ##
Pobranie pliku source.cpp. Odpalenie go w kompilatorze, najlepiej w Code::Blocks. Skompilowanie i odpalenie programu przyciskiem **f9**. Program korzysta z biblioteki <Windows.h>, która działa tylko na systemie windows.

## Opis działania symulatora ##

**DO KORZYSTANIA Z MASZYNY WYMAGANA JEST PODSTAWOWA WIEDZA ODNOŚNIE MASZYNY TURINGA, NIE JEST ONA ZAWARTA W 100% W INSTRUKCJI**

**1.** Użytkownik zostaje poproszony o podanie wszystkich stanów, które będzie chciał wykorzystać w maszynie (włącznie ze stanem zerowym).
Stany muszą być oddzielone przecinkiem, lub spacją. Program będzie ignorował wszystkie przecinki i spacje także nie należy ich używać w nazwach stanów. Wszystkie zduplikowane nazwy zostaną automatycznie usunięte.

![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/4c6ca1a8-25ca-4a45-b866-039f2a158eae)


**2.** Użytkownik zostanie poproszony o podanie wszystkich znaków, które będzie chciał wykorzystać w maszynie (włącznie ze znakiem pustym). Znaki składają się z pojedynczego znaku.
Znaki nie muszą być oddzielone przecinkiem, lub spacją, mogą być pisane jeden koło drugiego. Program będzie ignorował wszystkie przecinki i spacje także nie należy ich używać jako znaków. Wszystkie zduplikowane znaki zostaną automatycznie usunięte.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/3ead02cc-d852-4ea7-b4ab-a65a6bc93f4b)

**3.** Użytkownik zostanie poproszony o wpisanie stanu, który wybrał jako początkowy. W razie wpisania nieistniejącego stanu, użytkownik zostanie poproszony o ponowne wpisanie stanu.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/0febcca2-da73-408b-abd8-9c4cf2d448d1)


**4.** Użytkownik zostanie poproszony o wpisanie znaku pustego. W razie wpisania nieistniejącego znaku, użytkownik zostanie poproszony o ponowne wpisanie znaku.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/ceda1ebd-7e92-4283-96d2-c8a3328c9d6c)

**5.** Użytkownik zostanie poproszony o wpisanie taśmy. Taśma musi składać się ze znaków zadeklarowanych w kroku 2. W razie wpisania niepoprawnego znaku, użytkownik zostanie poproszony o wpisanie taśmy jeszcze raz. Program automatycznie dodaje znaki puste w miarę potrzeby na początku i końcu taśmy, także jeśli nie są potrzebne nie należy ich w niej uwzględniać. Program w późniejszych etapach daje możliwość wybrania miejsca rozpoczęcia programu na taśmie, oraz wprowadzenia następnych taśm i poleceń dla wybranych znaków i stanów.

![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/c8c77f30-92a4-4238-9262-77657710ec71)

**6.** Użytkownik zostanie poproszony o wpisanie numeru znaku rozpoczęcia programu, zaczynając od numeru 1. W wypadku wprowadzenia numeru znaku wychodzącego poza krawędź taśmy należy wpisać numer jeszcze raz.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/e37e5291-73ab-4f09-9e44-8bf0575da5c5)


**7.** W celu wygody użytkownika zostaną wyświetlone wszystkie stany, znaki oraz taśma. Następnie przychodzi kolej na wpisywanie poleceń. Polecenia mają strukturę:

|stan1|wartość1|-(lub dowolny ciąg znaków np ->)|stan2|wartość2|znak przesunięcia (L,P,R,N,S - małe litery również działają)|

W wypadku wpisania jakiejkolwiek błędnego parametru, program poinformuje który parametr jest błędny i poprosi o ponowne wprowadzenie linijki. 

**Uwaga!** Poleceń nie da się zmienić po ich wpisaniu, ponadto maksymalną ilością poleceń do wprowadzenia jest ilość znaków * ilość stanów.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/fd90cc6f-74b6-4285-98a6-770400aee5b4)


**8.** W celach instruktażowych, włączę maszynę aby wykonała powyższy kod. Kod ten ma za zadanie zmienić wszystkie 0 na 1 i odwrotnie dopóki nie napotka znaku pustego, następnie zmienić kierunek i wykonać się ponownie dopóki nie dotrze do znaku pustego. Program ten pokazuje przykład dodawania znaków pustych w razie konieczności do taśmy. Wynikiem odpalenia kodu będzie wypisanie zmian które zaszły (stany i znaki), wypisanie taśmy po zamianie wartości, oraz wskazanie strzałką aktualnego miejsca na taśmie.


![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/77a38a90-1ade-40e8-95da-c08e5885c098)
![image](https://github.com/Omen1719/symulator-maszyny-turinga/assets/123622068/96875e7e-ad30-412c-bb52-170083839e62)



**9.** Użytkownik zostanie zapytany czy chce wpisać następną taśmę. Cofnie go to do kroku 5. Jedyną różnicą jest to, że nie musi wpisywać poleceń ponownie, zostaną one automatycznie zastosowane do taśmy.

