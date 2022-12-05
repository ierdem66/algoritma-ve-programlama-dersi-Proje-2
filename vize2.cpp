#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ad
{
    char isim[30];
    char soyisim[30];
    long int ogrenci_no;
    int vize_not;
    int final_not;
};


typedef struct ad ad;


void hepsini_kaldir();
void menu();
void kisi_ekle();
void listeyi_kaydet();
void kisi_ara();
void kisi_sil();
void kisiyi_guncelle();
void girdi_alma(ad *p);



int main()
{
    basla();
    return 0;
}


void basla()
{
    int tercih;
    while(1)
    {
        print_menu();
        scanf("%d",&tercih);
        switch(tercih)
        {
            case 1:
                listeyi_kaydet();
                getchar();
                getchar();
                break;
            case 2:
                kisi_ekle();
                getchar();
                getchar();
                break;
            case 3:
                kisi_ara();
                getchar();
                getchar();
                break;
            case 4:
                kisi_sil();
                getchar();
                getchar();
                break;
            case 5:
                kisiyi_guncelle();
                getchar();
                getchar();
                break;
            case 6:
                hepsini_kaldir();
                getchar();
                getchar();
                break;
            default :
                system("temizle");
                printf("sistemi kullandýgýnýz icin tesekkurler : )\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}

void print_menu()
{
    system("temizle");
    printf("\t\t**********************\n");
    printf("\t\t*                  universite ders sistemine hosgeldiniz                    *\n");
    printf("\t\t**********************\n\n");
    printf("\t\t\t1) listeyi kaydet\n\n");
    printf("\t\t\t2) kisi ekle\n\n");
    printf("\t\t\t3) kisi detaylarini ara\n\n");
    printf("\t\t\t4) kisi sil\n\n");
    printf("\t\t\t5) kisiyi guncelle\n\n");
    printf("\t\t\t6) tum kisileri sil\n\n");
    printf("\t\t\t7) sistemden cik\n\n\n");

    printf("\t\t\t\tseciminizi girin lutfen : ");
}


void kisi_ekle()
{
    system("temizle");
    FILE *fp;
    fp = fopen("unisistem_db", "ab+");
    if (fp == NULL)
    {
        printf("Dosya acilisinda hata, lutfen tekrar deneyiniz. !\n");
        printf("Devam etmek icin herhangi bir tusa basin....\n");
        return;
    }
    else
    {
        ad p;
        girdi_al(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("temizle");
        printf("Kayit basariyla yapildi\n");
        printf("Devam etmek icin herhangi bir tusa basin ....\n");

    }
}


void girdi_al(ad *p)
{
    system("temizle");
    
    
    getchar();
    printf("adinizi girin : ");
    
    scanf("%[^\n]s",p->isim);

    printf("soyisminizi girin : ");
    scanf("%s",p->soyisim); 
    
    printf("ogrenci numaranýzý girin : ");
    scanf("%ld",&p->ogrenci_no); 

    printf("vize notunuzu girin : ");
    scanf("%d",p->vize_not); 
    
    printf("final notunuzu girin : ");
    scanf("%d",p->final_not); 
}


void listeyi_kaydet()
{
    system("temizle");
    FILE *fp;
    fp = fopen("unisistem_db", "rb");
    if (fp == NULL)
    {
        printf("Dosya açýlýþýnda hata, lütfen tekrar deneyiniz !\n");
        printf("Devam etmek icin herhangi bir tusa basin....\n");
        return;
    }
    else
    {
        ad p;
        printf("\n\t\t\t\t****************************\n");
        printf("\t\t\t\t*                  Tum listelenen kayitlar                   *\n");
        printf("\t\t\t\t****************************\n\n\n");
        printf("  ÝSÝM\t\t\t\t   SOYÝSÝM\t\t    OGRENCÝ NO\t\t    VÝZE NOTU\t\t             FÝNAL NOTU\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        // fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.isim);
            int len2 = 19 - strlen(p.soyisim);
            int len3 = 15;
            int len4 = 21 - strlen(p.vize_not);
            printf("%s",p.isim);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",p.soyisim);
            for(i=0;i<len2;i++) printf(" ");

            printf("%ld",p.ogrenci_no);
            for(i=0;i<len3;i++) printf(" ");

            printf("%s",p.vize_not);
            for(i=0;i<len4;i++) printf(" ");

            printf("%s",p.final_not);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nDevam etmek icin herhangi bir tusa basin....\n");
        
    }
}


void kisi_ara()
{
    system("temizle");
    long int ogr_no;
    printf("aramak istediginiz kisinin ogrenci numarasini girin : ");
    scanf("%ld",&ogr_no);

    FILE *fp;
    fp = fopen("unisitem_db", "rb");
    if (fp == NULL)
    {
        printf("Dosya acilisinda hata, lutfen tekrar deneyiniz !\n");
        printf("Devam etmek icin herhangi bir tusa basin....\n");
        return;
    }
    else
    {
        int flag = 0;
        ad p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.ogrenci_no == ogr_no)
            {
                printf("  ÝSÝM\t\t\t\t   SOYÝSÝM\t\t    OGRENCÝ NO\t\t    VÝZE NOTU\t\t     FÝNAL NOTU\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.isim);
                int len2 = 19 - strlen(p.soyisim);
                int len3 = 15;
                int len4 = 21 - strlen(p.vize_not);
                printf("%s",p.isim);
                for(i=0;i<len1;i++) printf(" ");

                printf("%s",p.soyisim);
                for(i=0;i<len2;i++) printf(" ");

                printf("%ld",p.ogrenci_no);
                for(i=0;i<len3;i++) printf(" ");

                printf("%d",p.vize_not);
                for(i=0;i<len4;i++) printf(" ");

                printf("%d",p.final_not);
                printf("\n");

                flag = 1;
                break;
            }
            else continue;
            
        }
        if(flag == 0) 
        {
            system("temizle");
            printf("kisi sistemde yok\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nDevam etmek icin herhangi bir tusa basin....\n");
    }

}


void kisi_sil()
{
    system("temizle");
    long int ogr_no;
    printf("sistemden silmek istediginiz kisinin ogrenci numarasýný girin : ");
    scanf("%ld",&ogr_no);

    FILE *fp,*temp;
    fp = fopen("unisistem_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Dosya acilisinda hata, lutfen tekrar deneyiniz !\n");
        printf("Devam etmek icin herhangi bir tusa basin....\n");
        return;
    }
    else
    {
        ad p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.ogrenci_no == ogr_no)
            {
                system("temizle");
                printf("kisi silinmesi basariyla yapildi\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("temizle");
            printf(" %d no lu ogrenci kaydi bulunamadi\n",ogr_no);
        }
        fclose(fp);
        fclose(temp);
        remove("unisistem_db");
        rename("temp","unisistem_db");
        fflush(stdin);
        printf("Devam etmek icin herhangi bir tusa basin....\n");
        
    }

}


void kisiyi_guncelle()
{

    system("temizle");
    long int ogr_no;
    printf("bilgilerini guncellemek istediginiz kisinin ogrenci numarasini igirn : ");
    scanf("%ld",&ogr_no);

    FILE *fp,*temp;
    fp = fopen("unisistem_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Dosya acilisinda hata, lutfen tekrar deneyiniz !\n");
        printf("Devam etmek icin herhangi bir tusa basin...\n");
        return;
    }
    else
    {
        int flag = 0;
        ad p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.ogrenci_no == ogr_no) 
            {   
                girdi_al(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("temizle");
                printf("kisinin bilgileri basariyle guncellendi\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("temizle");
            printf("%d numarali ogrenci bulunamadi",ogr_no);
        }
        fclose(fp);
        fclose(temp);
        remove("unisitem_db");
        rename("temp","unisistem_db");
        fflush(stdin);
        printf("Devam etmek icin herhangi bir tusa basin....\n");
    }
}



void hepsini_kaldir()
{
    char tercih;
    system("temizle");
    remove("./unisistem_db");
    printf("butun bilgiler basariyle silindi\n");
    printf("Devam etmek icin herhangi bir tusa basin ... \n");
}
