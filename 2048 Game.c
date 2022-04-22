
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int main (){

int oyun[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int oyunyedek[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int hamle,i,j,k,l,yenisayi1,yenisayi2,yenisayi3,baslangic;
int skor=0;
int highscore=0;
int sayac2048=0;
int sayac0=14;
int cikis=0;
 //oyunun ac�l�s ekran�nda gelen 2 ya da 4 rastgele bir yere at�l�r.
srand(time(NULL));

i=rand()%4;
j=rand()%4;

k=rand()%4;
if(k==i){
	k=rand()%4;
}
l=rand()%4;
if(l==j){
	l=rand()%4;
}

yenisayi1=rand()%2;
if(yenisayi1==0){
	yenisayi1=2;
}
else{
	yenisayi1=4;
}

yenisayi2=rand()%2;
if(yenisayi2==0){
	yenisayi2=2;
}
else{
	yenisayi2=4;
}
//�nceki hamleye d�nmek i�in kullan���m oyuunyedek matrisine rastgele say�lar� att�m.
oyun[i][j]=yenisayi1;
oyun[k][l]=yenisayi2;
oyunyedek[i][j]=yenisayi1;
oyunyedek[k][l]=yenisayi2;
//oyun ekrana bast�r�l�r.
printf(" W = yukari\n A = sol\n S = asagi\n D = sag\n R = onceki hamle\n E = oyunu bitir\n X = oyunu resetle\n");
printf("--------2048 OYUNU--------");
printf("\n");
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		printf("|  %d",oyun[i][j]);
	}
	printf("\n");
}
printf("-------------------------");
printf("\n");
printf("Skorunuz : %d ",skor);
printf("\n");
printf("En yuksek skor : %d",highscore);

while(1){
	//0 say�s� ve 2048 in olup olmad���n� kontrol eder.
	sayac0=0;
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		if(oyun[i][j]==0){
			sayac0=sayac0+1;
		}
		else if(oyun[i][j]==32){
			sayac2048=1;
		}
	}
}
if(sayac0==0){
	break ;
}
else if(sayac2048==1){
	break;
}
else{


scanf("%c",&hamle);
//y�n se�ilditen sonra kayd�rma ve toplama i�lemlerinden �nce yedek matris g�ncellenir.
    if(hamle=='w'){
    	for(i=0;i<4;i++){
        	for(j=0;j<4;j++){
        		oyunyedek[i][j]=oyun[i][j];
			}
		}
	//�nce istenilen tarafa kayd�r�l�r.
	    for(j=0;j<4;j++){
	    	for(k=0;k<4;k++){
			    for(i=3;0<i;i--){
				    if(oyun[i-1][j]==0){
					oyun[i-1][j]=oyun[i][j];
					oyun[i][j]=0;
				    }
				}
			}
			//ayn� olan say�lar toplan�r.
		for(i=1;i<4;i++){
			if(oyun[i][j]==oyun[i-1][j]){
					oyun[i-1][j]=oyun[i-1][j]*2;
					oyun[i][j]=0;
					skor=skor+oyun[i-1][j];
					if(skor>highscore){
						highscore=skor;
					}
		    }
		}
		//tekrar kayd�r�l�r.
		for(k=0;k<4;k++){
		    for(i=3;0<i;i--){
				if(oyun[i-1][j]==0){
					oyun[i-1][j]=oyun[i][j];
					oyun[i][j]=0;					
				}
		    }
	    }
	    }
	    //0 say�s� ve 2048 e ula��p ula��lmad��� sayac taraf�ndan tutulur.
		sayac0=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(oyun[i][j]==2048){
					sayac2048=1;
				}
				else if(oyun[i][j]==0){
					sayac0=sayac0+1;
				}
			}
		} 
		//kayd�rma i�lemlerinden sonra rastgele bir say� atan�r.
		yenisayi3=rand()%2;
            if(yenisayi3==0){
	            yenisayi3=2;
            }
            else{
	            yenisayi3=4;
            }
    while(1){
    	
			k=rand()%4;
            l=rand()%4; 
            
            if(oyun[k][l]==0){
		oyun[k][l]=yenisayi3;
		break;
	    }
    } 
    }
    
	else if(hamle=='a'){
		//y�n se�ilditen sonra kayd�rma ve toplama i�lemlerinden �nce yedek matris g�ncellenir.
		for(i=0;i<4;i++){
        	for(j=0;j<4;j++){
        		oyunyedek[i][j]=oyun[i][j];
			}
		}
		//�nce istenilen tarafa kayd�r�l�r.
		for(i=0;i<4;i++){
			for(k=0;k<4;k++){
			    for(j=3;0<j;j--){
				    if(oyun[i][j-1]==0){
					oyun[i][j-1]=oyun[i][j];
					oyun[i][j]=0;
					
				}
			}
		}
		//ayn� olan say�lar toplan�r.
			for(j=1;j<4;j++){
				if(oyun[i][j]==oyun[i][j-1]){
					oyun[i][j-1]=oyun[i][j-1]*2;
					oyun[i][j]=0;
					skor=skor+oyun[i][j-1];
					if(skor>highscore){
						highscore=skor;
					}
				}
			}
			//tekrar kayd�r�l�r.
			for(k=0;k<4;k++){
			    for(j=3;0<j;j--){
				    if(oyun[i][j-1]==0){
					oyun[i][j-1]=oyun[i][j];
					oyun[i][j]=0;
					}
			    }
            }
	}
	//0 say�s� ve 2048 e ula��p ula��lmad��� sayac taraf�ndan tutulur.
		sayac0=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(oyun[i][j]==2048){
					sayac2048=1;
				}
				else if(oyun[i][j]==0){
					sayac0=sayac0+1;
				}
			}
		}
		//kayd�rma i�lemlerinden sonra rastgele bir say� atan�r.
		yenisayi3=rand()%2;
            if(yenisayi3==0){
	            yenisayi3=2;
            }
            else{
	            yenisayi3=4;
            }
    while(1){
    	
			k=rand()%4;
            l=rand()%4; 
            
            if(oyun[k][l]==0){
		oyun[k][l]=yenisayi3;
		break;
	    }
    }     
    }
    
	else if(hamle=='s'){
		//y�n se�ilditen sonra kayd�rma ve toplama i�lemlerinden �nce yedek matris g�ncellenir.
		for(i=0;i<4;i++){
        	for(j=0;j<4;j++){
        		oyunyedek[i][j]=oyun[i][j];
			}
		}
		//�nce istenilen tarafa kayd�r�l�r.
		for(j=0;j<3;j++){
			for(k=0;k<4;k++){
			    for(i=0;i<3;i++){
				    if(oyun[i+1][j]==0){
					oyun[i+1][j]=oyun[i][j];
					oyun[i][j]=0;
					
				    }
			    }
	        }
	        //ayn� olan say�lar toplan�r.
		for(i=2;0<=i;i--){
				if(oyun[i][j]==oyun[i+1][j]){
					oyun[i+1][j]=oyun[i+1][j]*2;
					oyun[i][j]=0;
					skor=skor+oyun[i+1][j];
					if(skor>highscore){
						highscore=skor;
					}
				}
			}
			//tekrar kayd�r�l�r.
			for(k=0;k<4;k++){
			    for(i=0;i<3;i++){
				    if(oyun[i+1][j]==0){
					oyun[i+1][j]=oyun[i][j];
					oyun[i][j]=0;
					}
			    }
	        }
	    }
	    //0 say�s� ve 2048 e ula��p ula��lmad��� sayac taraf�ndan tutulur.
		sayac0=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(oyun[i][j]==2048){
					sayac2048=1;
				}
				else if(oyun[i][j]==0){
					sayac0=sayac0+1;
				}
			}
		}
		//kayd�rma i�lemlerinden sonra rastgele bir say� atan�r.
		yenisayi3=rand()%2;
            if(yenisayi3==0){
	            yenisayi3=2;
            }
            else{
	            yenisayi3=4;
            }
    while(1){
    	
			k=rand()%4;
            l=rand()%4; 
            
            if(oyun[k][l]==0){
		oyun[k][l]=yenisayi3;
		break;
	    }
    }   
    }
    
	else if(hamle=='d'){
		//y�n se�ilditen sonra kayd�rma ve toplama i�lemlerinden �nce yedek matris g�ncellenir.
		for(i=0;i<4;i++){
        	for(j=0;j<4;j++){
        		oyunyedek[i][j]=oyun[i][j];
			}
		}
		//�nce istenilen tarafa kayd�r�l�r.
		for(i=0;i<4;i++){
			for(k=0;k<4;k++){
			    for(j=0;j<3;j++){
				    if(oyun[i][j+1]==0){
					oyun[i][j+1]=oyun[i][j];
					oyun[i][j]=0;
					
				}
			}
		}
		//ayn� olan say�lar toplan�r.
			for(j=2;0<=j;j--){
				if(oyun[i][j]==oyun[i][j+1]){
					oyun[i][j+1]=oyun[i][j+1]*2;
					oyun[i][j]=0;
					skor=skor+oyun[i][j+1];
					if(skor>highscore){
						highscore=skor;
					}
				}
			}
			//tekrar kayd�r�l�r.
			for(j=0;j<3;j++){
				if(oyun[i][j+1]==0){
					oyun[i][j+1]=oyun[i][j];
					oyun[i][j]=0;
					
				}
			}
	    }
	    //0 say�s� ve 2048 e ula��p ula��lmad��� sayac taraf�ndan tutulur.
		sayac0=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(oyun[i][j]==2048){
					sayac2048=1;
				}
				else if(oyun[i][j]==0){
					sayac0=sayac0+1;
				}
			}
		}
		//kayd�rma i�lemlerinden sonra rastgele bir say� atan�r.
		yenisayi3=rand()%2;
            if(yenisayi3==0){
	            yenisayi3=2;
            }
            else{
	            yenisayi3=4;
            }
    while(1){
    	
			k=rand()%4;
            l=rand()%4; 
            
            if(oyun[k][l]==0){
		oyun[k][l]=yenisayi3;
		break;
	    }
    }   
	}
	else if(hamle=='x'){
		//x e bas�ld���nda oyunyedek matrisini oyun matrisine atarak bir �nceki hamleye d�neriz.
        	for(i=0;i<4;i++){
	            for(j=0;j<4;j++){
		        oyun[i][j]=oyunyedek[i][j];
	            }
            }
		}
		//e ye bas�ld���nda oyun biter ve skor yazd�r�l�r.
	else if(hamle=='e'){
			system("cls");
			printf("OYUN BITTI SKORUNUZ : %d",skor);
			break;
		}
	else if(hamle=='r'){
		//r ye bas�ld���nda matrisler s�f�rlan�r ve oyun ba�tan ba�lar.
			system("cls");
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					oyun[i][j]=0;
					oyunyedek[i][j]=0;
				}
			}
			oyun[i][j]=yenisayi1;
            oyun[k][l]=yenisayi2;
            oyunyedek[i][j]=yenisayi1;
            oyunyedek[k][l]=yenisayi2;
            printf(" W = yukari\n A = sol\n S = asagi\n D = sag\n R = onceki hamle\n E = oyunu bitir\n X = oyunu resetle\n");
            
			skor=0;
		}
	//her i�lemden sonra ekran temizlenir ve oyun ekrana bas�l�r.
			system("cls");
		
		printf(" W = yukari\n A = sol\n S = asagi\n D = sag\n X = onceki hamle\n E = oyunu bitir\n R = oyunu resetle\n");
		printf("--------2048 OYUNU--------");
		printf("\n");
		
		for(i=0;i<4;i++){
	        for(j=0;j<4;j++){
		        printf("|  %d",oyun[i][j]);
	            if(i==k && j==l){
	            	printf("*");
				}
	        }
	        printf("\n");
        }
        printf("-------------------------");
        printf("\n");
        printf("Skorunuz : %d ",skor);
        printf("\n");
        printf("En yuksek skor : %d",highscore);
        printf("\n \n \n \n");
        printf("ONCEKI HAMLE");
        printf("\n");
        for(i=0;i<4;i++){
        	for(j=0;j<4;j++){
        		printf("  %d",oyunyedek[i][j]);
			}
			printf("\n");
		}
          
        scanf("%c",&hamle);
       
    }
    }
    //matriste 0 kalmad���nda ya da 2048 e ula��ld���nda oyunun i�inde oldu�u while d�ng�s�nden ��k�l�r.
    //0 kalmad�ysa ekrana kaybettiniz yazd�r�l�r.
	if(sayac0==0){
	system("cls");
	printf("\n");
	printf("KAYBETTINIZ SKORUNUZ : %d ",skor);	
}
//2048 e ula��ld�ysa tebrikler yazd�r�l�r.
else if(sayac2048==1){
	system("cls");
	printf("\n");
	printf("TEBRIKLER 2048 E ULASTINIZ");
}

	return 0;
}
