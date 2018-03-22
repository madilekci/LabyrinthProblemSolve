//Muhammed Ali Dilekci 160202093
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sayac=0;
struct yigin{
int *veri;
struct yigin *sonraki;
};
struct yigin *yer=NULL;
int *onceki=NULL;
struct yigin* yiginOlustur(int *gveri){
    struct yigin *gecici=(struct yigin*)malloc(sizeof(struct yigin));
    gecici->veri=gveri;
    return gecici;
}

void ekle(int *veri){
    struct yigin *gecici = yiginOlustur(veri);
    gecici->sonraki=yer;
    yer=gecici;
}
void sil(){
    struct yigin *bos=yer;
    yer=yer->sonraki;
    free(bos);
}
void matrisYazdir(int *labirent,int boyut){
int i,j;
printf("\nMatris\n");
    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            printf("%d ",*((labirent+i*boyut)+j));
        } printf("\n");
    }
}
void matrisGuncelle(int *labirent,int boyut){
int i,j;
    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            if(*((labirent+i*boyut)+j)!=3 ){
                *((labirent+i*boyut)+j)=0;
            }
        }
    }
}
int main(){
int kontrol=0,deney=1,boyut=11,girisx=0,girisy=0,cikisx=0,cikisy=0,i,j;
        while(boyut>10){
        printf("Matrisin boyutunu giriniz : ");
        scanf("%d",&boyut);
        if(boyut>10){
        printf("Boyutunuz 10 dan buyuk olamaz.");
        }
    }
int labirent[boyut][boyut];
srand(time(NULL));
    for(i=0;i<boyut;i++){               //Matrisin elemanlarina rastgele 1 || 0 atama
        for(j=0;j<boyut;j++){
            labirent[i][j]=rand()%2;
        }
    }
    matrisYazdir(labirent,boyut);
    do{                                  //Girislerin kullanicidan istenmesi ve kontrolu
    kontrol=0;
    printf("Girisler :"); scanf("%d %d",&girisx,&girisy);
    girisx--;girisy--;
        if(labirent[girisx][girisy]==0){
            printf("Giris 0 olamaz.");
            kontrol=1;
            }
        else if( ((girisx!=0) && (girisy!=0) ) && (( girisx!= (boyut-1) ) && (girisy!=(boyut-1))) ){
            printf("Girisiniz duvarlar ustunde olmalidir.");
            kontrol=1;
            }
    }while(kontrol==1);
    do{         //Girislerin kullanicidan istenmesi ve kontrolu
    kontrol=0;
    printf("Cikislar :");scanf("%d %d",&cikisx,&cikisy);
    cikisx--;cikisy--;
        if(labirent[cikisx][cikisy]==0){
            printf("Cikis 0 olamaz.");
            kontrol=1;
            }
        else if( ((cikisx!=0) && (cikisy!=0) ) && (( cikisx!= (boyut-1) ) && (cikisy!=(boyut-1))) ){
            printf("Cikisiniz duvarlar ustunde olmalidir.");
            kontrol=1;
            }
    }while(kontrol==1);
    deney=yuru(labirent,boyut,girisx,girisy,cikisx,cikisy);
    if(deney){
        printf("Cikis %d adimda bulundu.",sayac);
        labirent[cikisx][cikisy]=3;
        matrisGuncelle(labirent,boyut);
        matrisYazdir(labirent,boyut);
    }
    else printf("Cikis bulunamadi !!1!!bir!");
    return 0;
}
int yuru(int *labirent,int boyut,int girisx, int girisy, int cikisx, int cikisy){
    ekle((labirent+girisx*boyut)+girisy);
    onceki=((labirent+girisx*boyut)+girisy);
    int deney=1;
    while(yer->veri!=(labirent+cikisx*boyut)+cikisy )
    {
        sayac++;
        deney=sagabak(labirent,boyut,girisx,girisy,cikisx,cikisy);
        if(deney!=1)
            break;
    }
    if(deney==1){
        return 1;
    }
    return 0;
}
int sagabak(int *labirent,int boyut,int girisx, int girisy, int cikisx, int cikisy){
    int deney=1,i;
    for(i=1;i<boyut;i++){
        if(	((yer->veri)+1)==( labirent+(i*boyut) )) {
            deney=solaBak(labirent,boyut,girisx,girisy,cikisx,cikisy);
        return deney;
        }
	}
    if( *((yer->veri)+1) == 1  )
    {
        ekle((yer->veri)+1);
        *onceki=3;
        onceki=(yer->veri);
        return deney;
    }
        deney=solaBak(labirent,boyut,girisx,girisy,cikisx,cikisy);
    return deney;
}
int solaBak(int *labirent,int boyut,int girisx, int girisy, int cikisx, int cikisy){
    int deney=1,i;
    for(i=1;i<boyut;i++){
        if(	((yer->veri)-1)==(labirent-1)+(i*boyut)  ){
            deney=asagiBak(labirent,boyut,girisx,girisy,cikisx,cikisy);
        return deney;
        }
    }
    if( *((yer->veri)-1) == 1 )
    {
        ekle((yer->veri)-1);
        *onceki=3;
        onceki=(yer->veri);
        return deney;
    }
        deney=asagiBak(labirent,boyut,girisx,girisy,cikisx,cikisy);
    return deney;

}
int asagiBak(int *labirent,int boyut,int girisx, int girisy, int cikisx, int cikisy){
    int deney=1;
   if( *((yer->veri)+boyut) == 1 )
    {
        ekle((yer->veri)+boyut);
        *onceki=3;
        onceki=(yer->veri);
        return deney;
    }
        deney=yukariBak(labirent,boyut,girisx,girisy,cikisx,cikisy);
    return deney;
}
int yukariBak(int *labirent,int boyut,int girisx, int girisy, int cikisx, int cikisy){
     if( *((yer->veri)-boyut) == 1 )                  //Yukarisi 1 ise
     {
         ekle((yer->veri)-boyut);
         *onceki=3;
         onceki=(yer->veri);
     }
     else{
        if(yer->veri==(labirent+girisx*boyut)+girisy){                  //Bulundugum yer giris ise
            return 0;
        }                       //Yanlis yoldaysam(geri don)
            *(yer->veri)=2;
            sil();
        }
return 1;
}
