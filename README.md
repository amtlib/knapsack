# Problem plecakowy

## Na czym polega?
Mamy zadaną ilość przedmiotów, wraz z ich wartościami i wagą/rozmiarem. Mamy również pojemnik (plecak), który ma określoną pojemność. Problem polega na tym, że należy podjąć decyzję, które przedmioty wybrać, by ich wartość była jak największa.
Idąc dalej, nie każdy przedmiot musi się znaleźć w pojemniku. Próbując rozwiązać ten problem licząc każdą kombinację jest ich 2^n, co już przy niewielu przedmiotach generuje bardzo dużo możliwości. Istnieje wiele podejść, które mają na celu zoptymalizowanie procesu doboru przedmiotów.
## Podejście dynamiczne
Stosując programowanie dynamiczne, mamy do wykonania następujące kroki:
1. Rekurencja
2. Zapamiętywanie wewnątrzprocesowych wyników
## Pierwszy krok - rekurencja
Liczba elementów pozostałych do rozważenia: n
Ile jeszcze zmieści się w plecaku: c
Aktualna wartośc plecaka: v

Zaczynamy sprawdzać elementy od ostatniego. Dany przedmiot może zostać umieszczony w plecaku, lub nie.
Tak:
- n = n - 1
- c = c - <waga przedmiotu>
- v = v + <wartość przedmiotu>
Nie:
- n = n -1
- c = c
- v = v
Postępujemy ze sprawdzaniem dopóki nie skończą nam się elementy do rozważenia, lub skończy się nam pojemość plecaka.
```cpp
 int max(int a, int b) { return (a > b) ? a : b; } 

 int KnapsackRec(int n, int c, int weight[], int value[]) {
    // Jezeli skonczyly nam sie elementy lub pojemnosc, zwracamy zero
    if(n == 0 || c == 0) {
        return 0;
    // waga przedmiotu jest wieksza od dostepnego miejsca, wiec przechodzimy do kolejnego elementu
    }else if(weight[n - 1] > c) {
        return KnapsackRec(n - 1, c, weight, value);
    }else {
        // porownujemy wybranie elementu i jego niewybranie, wybieramy co nam daje lepszy rezultat
        int tmp1 = KnapsackRec(n - 1, c, weight, value);
        int tmp2 = value[n - 1] + KnapsackRec(n - 1, c - weight[n - 1], weight, value);
        return max(tmp1, tmp2);
    }
}
```
