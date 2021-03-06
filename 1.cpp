#include <iostream>

using namespace std;

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

int main() {
    int n = 5;
    int c = 10;
    int weight[] = {1, 2, 3, 2, 5};
    int value[] = {5, 3, 5, 3, 2};

    int values[n][c];
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < c;j++) {
            values[i][j] = -1;
        }
    }
    cout << KnapsackRec(5, 10, weight, value) << endl;

    return 0;
} 