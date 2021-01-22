#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int KnapsackRec(int n, int c, int weight[], int value[], int *values)
{
    int result;
    // Jezeli mamy obliczony wynik dla danej kombinacji, po prostu go zwracamy
    if (*((values + n * n) + c) != -1)
    {
        result = *((values + n * n) + c);
    }
    // Jezeli skonczyly nam sie elementy lub pojemnosc, zwracamy zero
    if (n == 0 || c == 0)
    {
        result = 0;
    }
    // waga przedmiotu jest wieksza od dostepnego miejsca, wiec przechodzimy do kolejnego elementu
    else if (weight[n - 1] > c)
    {
        result = KnapsackRec(n - 1, c, weight, value, values);
    }
    else
    {
        // porownujemy wybranie elementu i jego niewybranie, wybieramy co nam daje lepszy rezultat
        int tmp1 = KnapsackRec(n - 1, c, weight, value, values);
        int tmp2 = value[n - 1] + KnapsackRec(n - 1, c - weight[n - 1], weight, value, values);
        result = max(tmp1, tmp2);
    }
    // zapisujemy wynik operacji w odpowiedniej komorce w tablicy dwuwymiarowej
    *((values + n * n) + c) = result;
    return result;
}

void printItemsInKnapsack(int *values, int weight[], int value[], int c, int n)
{
    cout << "Wybrane przedmioty:" << endl;
    int totalProfit = *((values + n * n) + c);
    for (int i = n - 1; i > 0; i--)
    {
        if (totalProfit != *((values + i * i) + c))
        {
            cout << "Przedmiot o wadze " << weight[i] << " i wartosci " << value[i] << endl;
            c -= weight[i];
            totalProfit -= value[i];
        }
    }

    if (totalProfit != 0)
    {
        cout << "Przedmiot o wadze " << weight[0] << " i wartosci " << value[0] << endl;
    }
}

int main()
{
    // ilosc przedmiotow, ktore bierzemy pod uwage
    int n = 3;
    // pojemnosc plecaka
    int c = 4;
    // wagi przedmiotow
    int weight[] = {1, 2, 3};
    // wartosc przedmiotwo
    int value[] = {2, 3, 4};

    // tablica przechowujaca wartosci dotychczas obliczone
    int values[n][c];

    // Wypelnienie tablicy pustymi wartosciami
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            values[i][j] = -1;
        }
    }

    cout << KnapsackRec(n, c, weight, value, (int *)values) << endl;

    // na podstawie tablicy wartosci jestesmy w stanie uzyskac poszczegolne elementy, ktore wyladowaly w plecaku
    printItemsInKnapsack((int *)values, weight, value, c, n);

    return 0;
}
