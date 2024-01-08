#include <stdio.h>
#include <string.h>

void otele(char liste[],char yenilist[],int anahtar,int boyut){
    for (int i = 0; i < boyut-anahtar+1; i++)
    {
        yenilist[i] = liste[anahtar+i];
    }
    for (int a=0, i = boyut-anahtar; i < boyut; i++,a++)
    {
        yenilist[i] = liste[a];
    }
    
}
void listeyazdir(char liste[],int boyut){
    for (int i = 0; i < boyut; i++)
    {
        printf("%c",liste[i]);
    }
    
}

void eslestir(char liste1[],char liste2[],char liste3[],int boyut,int boyut2){
    for (int i = 0; i<boyut2; i++)
    {
        for (int j = 0; j < boyut; j++)
        {
            if (liste1[i]==liste2[j])
            {
                liste1[i]= liste3[j];
                break;
            }
            
        }
        
        
    }

}
void sifrecoz(char liste1[],char liste2[],char liste3[],int boyut,int boyut2){
    for (int i = 0; i<boyut2; i++)
    {
        for (int j = 0; j < boyut; j++)
        {
            if (liste1[i]==liste3[j])
            {
                liste1[i]= liste2[j];
                break;
            }
            
        }
        
        
    }

}

int main(){
    char R1[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char R2[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int boyut = sizeof(R1)/sizeof(R1[0]);
    char bosliste[26];
    int anahtar,anahtar2,islem,boyut2;
    char kullanicigirdisi[250];
    FILE *dosya;
    char satir[250];
    printf("R1 icin Anahtari Giriniz: ");
    scanf("%d",&anahtar);
    printf("R2 icin Anahtari Giriniz: ");
    scanf("%d",&anahtar2);
    otele(R1,bosliste,anahtar,boyut);
    otele(R2,R1,anahtar2,boyut);
    printf("Hangi Islemi Yapmak Istersiniz?(1 = SifreCOZ 2= SifreOlustur): ");
    scanf("%d",&islem);
    switch (islem)
    {
    case 1:
        dosya = fopen("ENIGMA.txt", "r");

        if (dosya == NULL) {
            printf("Dosya acilamadi!\n");
            return 1;
        }
        for (int i = 0; i < sizeof(kullanicigirdisi); i++) {
            kullanicigirdisi[i] = '\0';
            }   

        while (fgets(satir, sizeof(satir), dosya) != NULL) {
            strcat(kullanicigirdisi, satir);
        }

        fclose(dosya);

        boyut2 = strlen(kullanicigirdisi);
        sifrecoz(kullanicigirdisi,bosliste,R1,boyut,boyut2);
        listeyazdir(kullanicigirdisi,boyut2);
        break;
    case 2:
        dosya = fopen("ENIGMA.txt", "w");

        if (dosya == NULL) {
            printf("Dosya acilamadi!\n");
            return 1;
        }

        printf("Sifrelenmek Istenen mesaji giriniz: ");
        fflush(stdin);
        fgets(kullanicigirdisi,sizeof(kullanicigirdisi),stdin);
        boyut2 = strlen(kullanicigirdisi);
        eslestir(kullanicigirdisi,bosliste,R1,boyut,boyut2);
        for (int i = 0; i < boyut2; i++) {
            fprintf(dosya, "%c", kullanicigirdisi[i]);
        }
        fclose(dosya);
        break;
    
    default:
        printf("Hatali Giris!");
        break;
    }
    
    
    return 0;
}