#include <stdio.h>
#include <math.h>   

void oteleme(char *kelime,int size,int kullanici){
    for (int i = 0; i < kullanici; i++)
    {
        char sontutucu = *kelime;
        for (int j = 0; j < size; j++){
            *(kelime+j-1) = *(kelime+j);
        }
        kelime[size-1] = sontutucu;
    }
    


    
    
    
}
void listeyazdir(char *liste,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%c",*(liste+i));
    }
    
}


int main(){
    char kelime[7] = {'Y','A','Z','I','L','I','M'};
    int kaydir, size = sizeof(kelime)/sizeof(kelime[0]);
    printf("Kac defa kaydiralim: ");
    scanf("%d",&kaydir);
    oteleme(kelime,size,kaydir);
    listeyazdir(kelime,size);




    return 0;
}