#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{

    int n, m, i, j, s, c, d;
    printf("m = ");
    scanf_s("%d", &m);
    printf("n = ");
    scanf_s("%d", &n);
    int** b = new int* [m];
    for (int z = 0; z < m; ++z)
        b[z] = new int[n];
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            b[i][j] = abs(i - j) + 1;
            printf("%4d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int** a = new int* [m];
    for (int z = 0; z < m; ++z)
        a[z] = new int[n];
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }

    s = 1;
    for (i = 0; i < n; i++){
        a[0][i] = s;
        s++;
    }
    for (i = 1; i < m; i++){
        a[i][n - 1] = s;
        s++;
    }
    for (i = n - 2; i >= 0; i--){
        a[m - 1][i] = s;
        s++;
    }
    for (i = m - 2; i > 0; i--){
        a[i][0] = s;
        s++;
    }


    c = 1;
    d = 1;

    while (s < m * n){
        while (a[c][d + 1] == 0){            
            a[c][d] = s;
            s++;
            d++;
        }

        while (a[c + 1][d] == 0){
            a[c][d] = s;
            s++;
            c++;
        }

        while (a[c][d - 1] == 0){
            a[c][d] = s;
            s++;
            d--;
        }

        while (a[c - 1][d] == 0){
            a[c][d] = s;
            s++;
            c--;
        }
    }

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (a[i][j] == 0){
                a[i][j] = s;
            }
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }



    return 0;
}