#include <stdio.h>
#include <string.h>

void baslayanKelimeleriBul(char metin[], char arananKelime[]) {
    printf("Aranan Kelimeye Baslayan Kelimeler: ");
    
    char* kelime = strtok(metin, " "); // Metni boşluklara göre parçalara ayır
    
    while (kelime != NULL) {
        if (strncmp(kelime, arananKelime, strlen(arananKelime)) == 0) {
            printf("%s ", kelime);
        }
        
        kelime = strtok(NULL, " "); // Bir sonraki kelimeye geç
    }
    
    printf("\n");
}

int main() {
    char metin[] = "Bu bir deneme metnidir ve bu metinde belirli bir metinden baslayan kelimeleri bulmamiz gerekiyor.";
    char arananKelime[] = "bu";
    
    baslayanKelimeleriBul(metin, arananKelime);
    
    return 0;
}