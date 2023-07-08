#include <stdio.h>

void tekrarEdenElemanlariBul(int dizi[], int uzunluk)
{
    printf("Tekrar Eden Elemanlar: ");

    for (int i = 0; i < uzunluk - 1; i++) {
        for (int j = i + 1; j < uzunluk; j++) {
            if (dizi[i] == dizi[j]) {
                printf("%d ", dizi[i]);
                break;
            }
        }
    }

    printf("\n");
}

int main()
{
    int dizi[] = {62, 1, 15, 4, 5, 62, 75, 8, 4, 62};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);

    tekrarEdenElemanlariBul(dizi, uzunluk);

    return 0;
}