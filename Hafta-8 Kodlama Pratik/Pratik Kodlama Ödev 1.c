#include <stdio.h>

int en_buyuk_sayi_bul(int dizi[], int uzunluk)
{
    int en_buyuk = dizi[0]; // Başlangıçta en büyük sayıyı dizinin ilk elemanı olarak varsayıyoruz

    for (int i = 1; i < uzunluk; i++) {
        if (dizi[i] > en_buyuk) {
            en_buyuk = dizi[i];
        }
    }

    return en_buyuk;
}

int main()
{
    int dizi[] = {1, 15, 5, 62, 75, 8, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);

    int en_buyuk_sayi = en_buyuk_sayi_bul(dizi, uzunluk);
    printf("En buyuk sayi: %d\n", en_buyuk_sayi);

    return 0;
}