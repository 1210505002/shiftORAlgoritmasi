#include <stdio.h>
#include <string.h>
#include <limits.h>
// t gonderilen metin dosyasi (text), p aranan kelime (pattern)
int shift_or(char *t, char *p)
{
    int m = strlen(p); //p stringinin uzunlugunu m degiskenine atar.
    long pattern_mask[256]; //her bir karakter icin bir pattern maskesi tutar.
    long R = ~1; //R degiskeni bit islemleri yapmak icin kullanilir.
    int i;
    if (m == 0) //eger aranan pattern bossa -1 dondurur.
        return -1;
    if (m > 63) //eger aranan pattern 63 karakterden uzunsa hata mesaji verir ve -1 dondurur.
    {
        printf("Pattern is too long!");
        return -1;
    }
    for (i = 0; i <= 255; ++i) //her bir karakter icin pattern maskelemesi yapar.
    {
        pattern_mask[i] = ~0; //ilk deger olarak butun bitleri 1 yapar.
    }
    for (i = 0; i < m; ++i) //pattern maskelerini olusturur.
    {
        pattern_mask[p[i]] &= ~(1L << i); //p[i] karakterine karsilik gelen pattern maskesinde i. biti 0 yapar.
    }
    for (i = 0; i < strlen(t); ++i) //t stringinin icinde arama yapar.
    {
        R |= pattern_mask[t[i]]; //R degiskenine t[i] karakterine karsilik gelen pattern maskeyi ekler.
        R <<= 1; //R degiskenini bir bit sola kaydirir.
        if ((R & (1L << m)) == 0) //eger R degiskeninin m. biti 0 ise, eslesme olmustur.Bu durumda i-m+1 deserini dondurur.
            return i - m + 1;   
    }
    return -1; //eslesme olmadigi durumda -1 dondurur.
}


void findAllPatterns(char *filename, char *p)
{
    FILE *fp;
    char t[10000];

    fp = fopen(filename, "r"); // dosya okunmak icin acilir
    if (fp == NULL)
    {
        printf("Dosya a��lamad�.\n"); // dosya acilamazsa hata mesaji verilir ve fonksiyondan cikilir
        return;
    }

    int position = -1; // desenin bulundugu pozisyonu takip eder, baslangicta -1'dir
    int count = 0; // toplam eslesme sayisini takip eder, baslangicta 0'dir
    while (fgets(t, sizeof(t), fp) != NULL) // dosyadan bir satir okur ve t dizisine kaydeder
    {
        do
        {
            position = shift_or(t, p); // deseni t uzerinde arar ve desenin bulundugu pozisyonu position'a kaydeder
            if (position != -1) // desen bulunursa
            {
                char *start = t; // start pointer'i t'nin baslangicina ayarlar
                start += position + 1; // start pointer'ini desen sonrasindaki karaktere tasir
                strcpy(t, start); // t dizisini start pointer'indan itibaren tekrar baslatir
                count++; // eslesme sayisini arttirir
            }
        } while (position != -1); // ayni satirda birden fazla eslesme olabilir, bu yuzden tum satirda eslesme kalmayana kadar donguye devam edilir
    }
    if (count == 0)
    {
        printf("'%s' deseni dosyada bulunamadi.\n", p); // eslesme yoksa hata mesaji verilir
    }
    else
    {
        printf("toplamda %d eslesme bulundu.\n", count); // eslesme varsa toplam eslesme sayisini yazdirilir
    }

    fclose(fp); // dosya kapatilir
}


int main()
{
    char filename[100] = "alice_in_wonderland.txt"; // arama yapilacak dosya adi
    char u[10] = "upon";                            // aranan desen stringi
    char s[10] = "sigh";
    char d[10] = "Dormouse";
    char j[10] = "jury-box";
    char sw[10] = "swim";

// dosyada aranan desenin tum eslesmeleri bulundu ve eslesme sayisi yazdirildi
    printf("\'upon\' kelimesi icin ");
    findAllPatterns(filename, u); 
    printf("\'sigh\' kelimesi icin ");
    findAllPatterns(filename, s); 
    printf("\'Dormouse\' kelimesi icin ");
    findAllPatterns(filename, d); 
    printf("\'jury-box\' kelimesi icin ");
    findAllPatterns(filename, j); 
    printf("\'swim\' kelimesi icin ");
    findAllPatterns(filename, sw); 
    return 0;
}

