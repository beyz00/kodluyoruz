#include <stdio.h>
#include <stdlib.h>

// Bağlı listeyi temsil etmek için düğüm yapısı
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

// Bağlı listeye öğe ekleme işlemi
void listeEkle(struct Dugum** baslangic, int veri)
{
    // Yeni bir düğüm oluştur
    struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni_dugum->veri = veri;
    yeni_dugum->sonraki = NULL;

    // Eğer liste boş ise, yeni düğümü başlangıç olarak ayarla
    if (*baslangic == NULL) {
        *baslangic = yeni_dugum;
    }
    // Liste boş değilse, son düğümü bul ve yeni düğümü sona ekle
    else {
        struct Dugum* temp = *baslangic;
        while (temp->sonraki != NULL) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeni_dugum;
    }
}

// Bağlı listeden öğe kaldırma işlemi
void listeOgeKaldir(struct Dugum** baslangic, int veri)
{
    // Başlangıç düğümü ve önceki düğümü tutacak geçici değişkenler
    struct Dugum* temp = *baslangic;
    struct Dugum* onceki = NULL;

    // Başlangıç düğümünü kontrol et
    if (temp != NULL && temp->veri == veri) {
        *baslangic = temp->sonraki; // İlk düğümü kaldır
        free(temp); // Bellekten serbest bırak
        return;
    }

    // Kaldırılacak öğeyi bulana kadar liste üzerinde dolaş
    while (temp != NULL && temp->veri != veri) {
        onceki = temp;
        temp = temp->sonraki;
    }

    // Öğe bulunduysa, önceki düğümü bağlantıyı atla ve kaldır
    if (temp != NULL) {
        onceki->sonraki = temp->sonraki;
        free(temp); // Bellekten serbest bırak
    }
}

// Bağlı listeyi yazdırma işlemi
void listeYazdir(struct Dugum* baslangic)
{
    struct Dugum* temp = baslangic;
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("\n");
}

int main()
{
    struct Dugum* baslangic = NULL; // Başlangıçta boş bir bağlı liste

    // Elemanları bağlı listeye ekle
    listeEkle(&baslangic, 1);
    listeEkle(&baslangic, 15);
    listeEkle(&baslangic, 5);
    listeEkle(&baslangic, 62);
    listeEkle(&baslangic, 75);
    listeEkle(&baslangic, 8);
    listeEkle(&baslangic, 4);

    printf("Bağlı liste: ");
    listeYazdir(baslangic);

    // Öğe kaldırma işlemi
    int kalkan_oge = 62; // Kaldırılacak öğe
    listeOgeKaldir(&baslangic, kalkan_oge);

    printf("Öğe kaldırıldıktan sonra bağlı liste: ");
    listeYazdir(baslangic);

    return 0;
}