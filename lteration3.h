

#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** lteration_3(char **coding2,int k,int r,int p,int blocksize,int i0,int i1,int i2){

printf("\nlteration---r=3-------------------------------\n");
if(r!=3){fprintf(stderr,  "r shoule be equal to 3 \n");  exit(0);}
int G;
G= pow(2,r-1);
printf(" \nG: \n ");
printf("\n %d \n",G);
int i,j,j1,j2;
//int i0,i1,i2;
char *shift0;
shift0=(char*)malloc(sizeof(char)*p);
char *shift2;
shift2=(char*)malloc(sizeof(char)*p);

//i0=k;
//i1=k+1;
//i2=k+2;
int b1;
char **shift;
shift = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
shift[i] = (char *)malloc(sizeof(char)*p);}
printf("\nlteration-1-----------------------------------------\n");
	
/*int *erase;
erase = (char *)malloc(sizeof(char)*r);
eraser[0]=k;eraser[1]=k+1;eraser[2]=k+2;*/

char **shift11;
shift11 = (char **)malloc(sizeof(char*)*(G-2));//2
for(i=0;i<(G-2);i++){
shift11[i]=(char*)malloc(sizeof(char)*p);}

char **gg0;//4//
gg0 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg0[i]=(char*)malloc(sizeof(char)*p*blocksize);}






int a;	
				a=finite_mod((i1+i2),p);
printf(" \na= %d \n",a);
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 	
				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-i1),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-i2),p);}
 				
				
				
printf(" \nshift11: \n ");
for(i=0;i<(G-2);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift11[i][j1]);}
printf(" \n ");}		
				for(i=0;i<p;i++){
				shift2[i]=finite_mod((i-0),p);}
printf(" \nshift2: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift2[j1]);}
				

printf("\ncoding2\n");
for(i=0;i<p;i++){
printf(" %d ",coding2[i][0]);}
				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}





				for(i=1;i<(G-1);i++){//i =1 2 
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}





				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[3][j*blocksize+j2]=*(coding2[shift2[j]]+2*blocksize+j2);}}

printf("\ngg0\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg0[j][i*blocksize]);}
printf(" \n ");}


				for(i=0;i<(G-1);i++){//i=0 1 2			
		                galois_region_xor1((gg0[i]),(gg0[i+1]),(gg0[i+1]),p*blocksize);}	

printf("\ngg0-XOR\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg0[j][i*blocksize]);}
printf(" \n ");}
	
			

char **xx2;
xx2 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
xx2[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **xx2_1;
xx2_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
xx2_1[i]=(char*)malloc(sizeof(char)*blocksize);}

char **xx1;
xx1 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
xx1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **xx1_1;
xx1_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
xx1_1[i]=(char*)malloc(sizeof(char)*blocksize);}

			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i0)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
			for(i=0;i<p;i++){
			xx2_1[i]=gg0[G-1]+shift0[i]*blocksize;}


			b1=i1-i0;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

			shift=shift_value(b1,1,p,p);
printf("\nshift \n");				
for(i=0;i<((p-1)/2);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift[i][j1]);}
printf("\n");}
			for(i=0;i<((p-1)/2);i++){// 0 1 2 p=7
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			xx2[i][j*blocksize+j2]=*(xx2_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1 		
		        galois_region_xor1((xx2[i]),(xx2[i+1]),(xx2[i+1]),p*blocksize);}


			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i0)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
			for(i=0;i<p;i++){
			xx1_1[i]=xx2[(p-1)/2-1]+shift0[i]*blocksize;}


			b1=i2-i0;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

			shift=shift_value(b1,1,p,p);
printf("\nshift \n");				
for(i=0;i<((p-1)/2);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift[i][j1]);}
printf("\n");}
			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			xx1[i][j*blocksize+j2]=*(xx1_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		        galois_region_xor1((xx1[i]),(xx1[i+1]),(xx1[i+1]),p*blocksize);}
printf("\nxx1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[(p-1)/2-1][j1*blocksize]);}


printf("\nlteration-2-----------------------------------------\n");
	

G= pow(2,(r-1)-1);
char **gg1;//2
gg1 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<(G);i++){
gg1[i]=(char*)malloc(sizeof(char)*p*blocksize);}

printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}

printf("\ncoding2-s0\n");
for(i=0;i<p;i++){
printf(" %d ",coding2[i][0]);}

char **coding3;
coding3 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding3[i]=(char*)malloc(sizeof(char)*blocksize);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(xx1[(p-1)/2-1]+i*blocksize),(coding3[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding3[i][j1];}}

printf("\ncoding2-s0-XOR\n");
for(i=0;i<p;i++){
printf(" %d ",coding2[i][0]);}	
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i0),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
				//for(i=0;i<p;i++){
				//for(j2=0;j2<blocksize;j2++){
				//xx1[(p-1)/2-1][i*blocksize+j2]=*(xx1[(p-1)/2-1]+shift0[i]*blocksize+j2);}}
printf("\ncoding2 S1\n");
for(i=0;i<p;i++){
printf(" %d ",coding2[i][blocksize]);}
printf("\nxx1--shift\n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[(p-1)/2-1][shift0[j1]*blocksize]);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(xx1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+blocksize),blocksize);}
printf("\ncoding2 S1-XOR\n");
for(i=0;i<p;i++){
printf(" %d ",coding2[i][blocksize]);}
	
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i2),p);}
				
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
				for(i=0;i<p;i++){
				shift2[i]=finite_mod((i-0),p);}
				
 printf(" \nshift2: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift2[j1]);}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[1][j*blocksize+j2]=*(coding2[shift2[j]]+blocksize+j2);}}

printf("\ngg1\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg1[j][i*blocksize]);}
printf(" \n ");}

				for(i=0;i<(G-1);i++){//i=0 			
		                galois_region_xor1((gg1[i]),(gg1[i+1]),(gg1[i+1]),p*blocksize);}	

printf("\ngg1--XOR\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg1[j][i*blocksize]);}
printf(" \n ");}
char **yy1;
yy1 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
yy1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **yy1_1;
yy1_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
yy1_1[i]=(char*)malloc(sizeof(char)*blocksize);}


			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i1)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
			for(i=0;i<p;i++){
			yy1_1[i]=gg1[G-1]+shift0[i]*blocksize;}

printf("\nyy1_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy1_1[j1][0]);}
			b1=i2-i1;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

			shift=shift_value(b1,1,p,p);
printf("\nshift \n");				
for(i=0;i<((p-1)/2);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift[i][j1]);}
printf("\n");}
			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			yy1[i][j*blocksize+j2]=*(yy1_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){			
		        galois_region_xor1((yy1[i]),(yy1[i+1]),(yy1[i+1]),p*blocksize);}
printf("\nyy1===== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy1[(p-1)/2-1][j1*blocksize]);}
printf("\nlteration-3-----------------------------------------\n");
char **z1;
z1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
z1[i]=(char*)malloc(sizeof(char)*blocksize);}

		
			for(i=0;i<p;i++){			
		        galois_region_xor1((coding2[i]),(yy1[(p-1)/2-1]+i*blocksize),(z1[i]),blocksize);}
printf("\ns0 \n");
for(j1=0;j1<p;j1++){
printf(" %d ",coding2[j1][0]);}	
printf("\nz1==== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",z1[j1][0]);}







char **fdata;
fdata=(char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
fdata[i]=(char *)malloc(sizeof(char)*r*blocksize);}

for(i=0;i<p;i++){ 

memcpy(fdata[i],(xx1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+blocksize),(yy1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+2*blocksize),z1[i],blocksize);}

return fdata;

}//hanshu

