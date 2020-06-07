

//#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** lteration_5(char **coding2,int k,int r,int p,int blocksize,int i0,int i1,int i2,int i3,int i4){
extern void galois_region_xor1(   char *r1,         /* Region 1 */
                                  char *r2,         /* Region 2 */
                                  char *r3,         /* Sum region (r3 = r1 ^ r2) -- can be r1 or r2 */
                                  int nbytes);
extern char** shift_value(int b1, int tau,int p,int M);
extern int finite_mod(int i,int M);
printf("\nlteration---r=5-------------------------------\n");
if(r!=5){fprintf(stderr,  "r shoule be equal to 5 \n");  exit(0);}
int G;

int i,j,j1,j2;

char *shift0;//1
shift0=(char*)malloc(sizeof(char)*p);
char *shift4;//1
shift4=(char*)malloc(sizeof(char)*p);


int b1;
char **shift;
shift = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
shift[i] = (char *)malloc(sizeof(char)*p);}
printf("\nlteration-1-----------------------------------------\n");
	
G= pow(2,r-1);//16
printf(" \nG: \n ");
printf("\n %d \n",G);

char **shift11;//4
shift11 = (char **)malloc(sizeof(char*)*4);
for(i=0;i<4;i++){
shift11[i]=(char*)malloc(sizeof(char)*p);}
char **shift22;//6
shift22 = (char **)malloc(sizeof(char*)*6);
for(i=0;i<6;i++){
shift22[i]=(char*)malloc(sizeof(char)*p);}
char **shift33;//4
shift33 = (char **)malloc(sizeof(char*)*4);
for(i=0;i<4;i++){
shift33[i]=(char*)malloc(sizeof(char)*p);}

char **gg;
gg = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg[i]=(char*)malloc(sizeof(char)*p*blocksize);}


				int a;	
				a=finite_mod((i1+i2+i3+i4),p);

			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}

 				int b;	
				b=finite_mod((i1+i2+i3),p);
				int c;	
				c=finite_mod((i1+i2+i4),p);
				int d;	
				d=finite_mod((i1+i3+i4),p);
				int e;	
				e=finite_mod((i2+i3+i4),p);

				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-b),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-c),p);}
				for(i=0;i<p;i++){
				shift11[2][i]=finite_mod((i-d),p);}
				for(i=0;i<p;i++){
				shift11[3][i]=finite_mod((i-e),p);}
				
				int f;	
				a=finite_mod((i1+i2),p);
				b=finite_mod((i1+i3),p);	
				c=finite_mod((i1+i4),p);
				d=finite_mod((i2+i3),p);	
				e=finite_mod((i2+i4),p);
				f=finite_mod((i3+i4),p);

				for(i=0;i<p;i++){
				shift22[0][i]=finite_mod((i-a),p);}
				for(i=0;i<p;i++){
				shift22[1][i]=finite_mod((i-b),p);}
				for(i=0;i<p;i++){
				shift22[2][i]=finite_mod((i-c),p);}
				for(i=0;i<p;i++){
				shift22[3][i]=finite_mod((i-d),p);}
				for(i=0;i<p;i++){
				shift22[4][i]=finite_mod((i-e),p);}
				for(i=0;i<p;i++){
				shift22[5][i]=finite_mod((i-f),p);}
	
				for(i=0;i<p;i++){
				shift33[0][i]=finite_mod((i-i1),p);}
				for(i=0;i<p;i++){
				shift33[1][i]=finite_mod((i-i2),p);}
				for(i=0;i<p;i++){
				shift33[2][i]=finite_mod((i-i3),p);}
				for(i=0;i<p;i++){
				shift33[3][i]=finite_mod((i-i4),p);}



				for(i=0;i<p;i++){
				shift4[i]=finite_mod((i-0),p);}
				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}

				for(i=1;i<5;i++){//i =1 2 3 4
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}
	
				for(i=5;i<11;i++){//i = 5 6 7 8 9 10
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg[i][j*blocksize+j2]=*(coding2[shift22[i-5][j]]+2*blocksize+j2);}}}

				for(i=11;i<15;i++){//i =11  12 13 14
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg[i][j*blocksize+j2]=*(coding2[shift33[i-11][j]]+3*blocksize+j2);}}}	



				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg[15][j*blocksize+j2]=*(coding2[shift4[j]]+4*blocksize+j2);}}



				for(i=0;i<(G-1);i++){			
		                galois_region_xor1((gg[i]),(gg[i+1]),(gg[i+1]),p*blocksize);}	


char **ss4;
ss4 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
ss4[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **ss4_1;
ss4_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
ss4_1[i]=(char*)malloc(sizeof(char)*blocksize);}	
char **ss3;
ss3 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
ss3[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **ss3_1;
ss3_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
ss3_1[i]=(char*)malloc(sizeof(char)*blocksize);}			

char **ss2;
ss2 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
ss2[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **ss2_1;
ss2_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
ss2_1[i]=(char*)malloc(sizeof(char)*blocksize);}

char **ss1;
ss1 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
ss1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **ss1_1;
ss1_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
ss1_1[i]=(char*)malloc(sizeof(char)*blocksize);}

			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i0)),p);}

			for(i=0;i<p;i++){
			ss4_1[i]=gg[G-1]+shift0[i]*blocksize;}

			b1=i1-i0;
			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			ss4[i][j*blocksize+j2]=*(ss4_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){		
		        galois_region_xor1((ss4[i]),(ss4[i+1]),(ss4[i+1]),p*blocksize);}
				
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-(p-i0)),p);}

				for(i=0;i<p;i++){
				ss3_1[i]=ss4[(p-1)/2-1]+shift0[i]*blocksize;}

				b1=i2-i0;
				shift=shift_value(b1,1,p,p);

				for(i=0;i<((p-1)/2);i++){
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				ss3[i][j*blocksize+j2]=*(ss3_1[shift[i][j]]+j2);}}}

				for(i=0;i<((p-1)/2-1);i++){		
		        	galois_region_xor1((ss3[i]),(ss3[i+1]),(ss3[i+1]),p*blocksize);}
			
			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i0)),p);}

			for(i=0;i<p;i++){
			ss2_1[i]=ss3[(p-1)/2-1]+shift0[i]*blocksize;}

			b1=i3-i0;
			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			ss2[i][j*blocksize+j2]=*(ss2_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		       	galois_region_xor1((ss2[i]),(ss2[i+1]),(ss2[i+1]),p*blocksize);}

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-(p-i0)),p);}

				for(i=0;i<p;i++){
				ss1_1[i]=ss2[(p-1)/2-1]+shift0[i]*blocksize;}

				b1=i4-i0;
				shift=shift_value(b1,1,p,p);

				for(i=0;i<((p-1)/2);i++){
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				ss1[i][j*blocksize+j2]=*(ss1_1[shift[i][j]]+j2);}}}

				for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		       		galois_region_xor1((ss1[i]),(ss1[i+1]),(ss1[i+1]),p*blocksize);}

printf("\nss1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",ss1[(p-1)/2-1][j1*blocksize]);}
printf("\nlteration-2-----------------------------------------\n");
	
G= pow(2,r-1-1);//8
printf(" \nG: \n ");
printf("\n %d \n",G);



char **gg0;
gg0 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg0[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **coding3;
coding3 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding3[i]=(char*)malloc(sizeof(char)*blocksize);}
char **coding4;
coding4 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding4[i]=(char*)malloc(sizeof(char)*blocksize);}

char **coding5;
coding5 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding5[i]=(char*)malloc(sizeof(char)*blocksize);}
				
				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(ss1[(p-1)/2-1]+i*blocksize),(coding3[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding3[i][j1];}}


				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i0),p);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(ss1[(p-1)/2-1]+shift0[i]*blocksize),(coding4[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1+blocksize]=coding4[i][j1];}}

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-2*i0),p);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+2*blocksize),(ss1[(p-1)/2-1]+shift0[i]*blocksize),(coding5[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1+2*blocksize]=coding5[i][j1];}}

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-3*i0),p);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+3*blocksize),(ss1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+3*blocksize),blocksize);}
	


				
				a=finite_mod((i2+i3+i4),p);

			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}

 				
				b=finite_mod((i2+i3),p);
				
				c=finite_mod((i2+i4),p);
					
				d=finite_mod((i3+i4),p);

				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-b),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-c),p);}
				for(i=0;i<p;i++){
				shift11[2][i]=finite_mod((i-d),p);}
				

				for(i=0;i<p;i++){
				shift22[0][i]=finite_mod((i-i2),p);}
				for(i=0;i<p;i++){
				shift22[1][i]=finite_mod((i-i3),p);}
				for(i=0;i<p;i++){
				shift22[2][i]=finite_mod((i-i4),p);}



				for(i=0;i<p;i++){
				shift4[i]=finite_mod((i-0),p);}
				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}





				for(i=1;i<(G/2);i++){//i =1 2 3
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}

				for(i=G/2;i<(G-1);i++){//i =4 5 6 
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[i][j*blocksize+j2]=*(coding2[shift22[i-4][j]]+2*blocksize+j2);}}}




				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[7][j*blocksize+j2]=*(coding2[shift4[j]]+3*blocksize+j2);}}



				for(i=0;i<(G-1);i++){//i=0 1 2			
		                galois_region_xor1((gg0[i]),(gg0[i+1]),(gg0[i+1]),p*blocksize);}	


	
char **xx3;
xx3 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
xx3[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **xx3_1;
xx3_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
xx3_1[i]=(char*)malloc(sizeof(char)*blocksize);}			

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
			shift0[i]=finite_mod((i-(p-i1)),p);}

			for(i=0;i<p;i++){
			xx3_1[i]=gg0[G-1]+shift0[i]*blocksize;}

			b1=i2-i1;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){// 0 1 2 p=7
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			xx3[i][j*blocksize+j2]=*(xx3_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1 		
		        galois_region_xor1((xx3[i]),(xx3[i+1]),(xx3[i+1]),p*blocksize);}

			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-(p-i1)),p);}

				for(i=0;i<p;i++){
				xx2_1[i]=xx3[(p-1)/2-1]+shift0[i]*blocksize;}

				b1=i3-i1;
				printf(" \nb1:\n ");
				printf(" %d ",b1);

				shift=shift_value(b1,1,p,p);

				for(i=0;i<((p-1)/2);i++){
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				xx2[i][j*blocksize+j2]=*(xx2_1[shift[i][j]]+j2);}}}

				for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		       		galois_region_xor1((xx2[i]),(xx2[i+1]),(xx2[i+1]),p*blocksize);}


			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i1)),p);}

			for(i=0;i<p;i++){
			xx1_1[i]=xx2[(p-1)/2-1]+shift0[i]*blocksize;}


			b1=i4-i1;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			xx1[i][j*blocksize+j2]=*(xx1_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		        galois_region_xor1((xx1[i]),(xx1[i+1]),(xx1[i+1]),p*blocksize);}

printf("\nxx1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[(p-1)/2-1][j1*blocksize]);}

printf("\nlteration-3------------------------\n");
	
G= pow(2,(r-1-1-1));//4

char **gg1;
gg1 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **coding1;
coding1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding1[i]=(char*)malloc(sizeof(char)*blocksize);}
char **coding0;
coding0 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding0[i]=(char*)malloc(sizeof(char)*blocksize);}
	
				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(xx1[(p-1)/2-1]+i*blocksize),(coding0[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding0[i][j1];}}


				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i1),p);}

			
				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(xx1[(p-1)/2-1]+shift0[i]*blocksize),(coding1[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1+blocksize]=coding1[i][j1];}}
					
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-2*i1),p);}

				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+2*blocksize),(xx1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+2*blocksize),blocksize);}
	

					
				a=finite_mod((i3+i4),p);

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}
	
				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-i3),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-i4),p);}
			
				
		
				for(i=0;i<p;i++){
				shift4[i]=finite_mod((i-0),p);}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}





				for(i=1;i<(G-1);i++){//i =1 2 
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}





				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[3][j*blocksize+j2]=*(coding2[shift4[j]]+2*blocksize+j2);}}



				for(i=0;i<(G-1);i++){//i=0 1 2			
		                galois_region_xor1((gg1[i]),(gg1[i+1]),(gg1[i+1]),p*blocksize);}	


	
			

char **yy2;
yy2 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
yy2[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **yy2_1;
yy2_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
yy2_1[i]=(char*)malloc(sizeof(char)*blocksize);}

char **yy1;
yy1 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
yy1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **yy1_1;
yy1_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
yy1_1[i]=(char*)malloc(sizeof(char)*blocksize);}

			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i2)),p);}

			for(i=0;i<p;i++){
			yy2_1[i]=(gg1[G-1]+shift0[i]*blocksize);}


			b1=i3-i2;
			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){// 0 1 2 p=7
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			yy2[i][j*blocksize+j2]=*(yy2_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1 		
		        galois_region_xor1((yy2[i]),(yy2[i+1]),(yy2[i+1]),p*blocksize);}


			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i2)),p);}

			for(i=0;i<p;i++){
			yy1_1[i]=yy2[(p-1)/2-1]+shift0[i]*blocksize;}


			b1=i4-i2;
			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			yy1[i][j*blocksize+j2]=*(yy1_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		        galois_region_xor1((yy1[i]),(yy1[i+1]),(yy1[i+1]),p*blocksize);}

printf("\nyy1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy1[(p-1)/2-1][j1*blocksize]);}


printf("\nlteration-3-----------------------------------------\n");
	

G= pow(2,(r-1-1-1-1));
char **gg2;//2
gg2 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<(G);i++){
gg2[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **coding6;
coding6 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding6[i]=(char*)malloc(sizeof(char)*blocksize);}



				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(yy1[(p-1)/2-1]+i*blocksize),(coding6[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding6[i][j1];}}

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i2),p);}



				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(yy1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+blocksize),blocksize);}

	
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i4),p);}
				

				for(i=0;i<p;i++){
				shift4[i]=finite_mod((i-0),p);}
				


				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg2[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg2[1][j*blocksize+j2]=*(coding2[shift4[j]]+blocksize+j2);}}



				for(i=0;i<(G-1);i++){//i=0 			
		                galois_region_xor1((gg2[i]),(gg2[i+1]),(gg2[i+1]),p*blocksize);}	


char **zz1;
zz1 = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
zz1[i]=(char*)malloc(sizeof(char)*p*blocksize);}
char **zz1_1;
zz1_1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
zz1_1[i]=(char*)malloc(sizeof(char)*blocksize);}


			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i3)),p);}

			for(i=0;i<p;i++){
			zz1_1[i]=gg2[G-1]+shift0[i]*blocksize;}


			b1=i4-i3;
			shift=shift_value(b1,1,p,p);

			for(i=0;i<((p-1)/2);i++){
			for(j=0;j<p;j++){
			for(j2=0;j2<blocksize;j2++){
			zz1[i][j*blocksize+j2]=*(zz1_1[shift[i][j]]+j2);}}}

			for(i=0;i<((p-1)/2-1);i++){			
		        galois_region_xor1((zz1[i]),(zz1[i+1]),(zz1[i+1]),p*blocksize);}
printf("\nzz1===== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",zz1[(p-1)/2-1][j1*blocksize]);}
printf("\nlteration-4-----------------------------------------\n");
char **s1;
s1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
s1[i]=(char*)malloc(sizeof(char)*blocksize);}

		
			for(i=0;i<p;i++){			
		        galois_region_xor1((coding2[i]),(zz1[(p-1)/2-1]+i*blocksize),(s1[i]),blocksize);}

printf("\ns1==== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",s1[j1][0]);}







char **fdata;
fdata=(char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
fdata[i]=(char *)malloc(sizeof(char)*r*blocksize);}

for(i=0;i<p;i++){ 

memcpy(fdata[i],(ss1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+blocksize),(xx1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+2*blocksize),(yy1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+3*blocksize),(zz1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+4*blocksize),s1[i],blocksize);}

return fdata;

}//hanshu

