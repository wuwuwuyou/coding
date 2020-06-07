

//#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** lteration_4(char **coding2,int k,int r,int p,int blocksize,int i0,int i1,int i2,int i3){
extern void galois_region_xor1(   char *r1,         /* Region 1 */
                                  char *r2,         /* Region 2 */
                                  char *r3,         /* Sum region (r3 = r1 ^ r2) -- can be r1 or r2 */
                                  int nbytes);
extern char** shift_value(int b1, int tau,int p,int M);
extern int finite_mod(int i,int M);
printf("\nlteration---r=4-------------------------------\n");
if(r!=4){fprintf(stderr,  "r shoule be equal to 4 \n");  exit(0);}
int G;

int i,j,j1,j2;
//int i0,i1,i2;
char *shift0;
shift0=(char*)malloc(sizeof(char)*p);
char *shift3;
shift3=(char*)malloc(sizeof(char)*p);


int b1;
char **shift;
shift = (char **)malloc(sizeof(char*)*((p-1)/2));
for(i=0;i<((p-1)/2);i++){
shift[i] = (char *)malloc(sizeof(char)*p);}
printf("\nlteration-1-----------------------------------------\n");
	
G= pow(2,r-1);
printf(" \nG: \n ");
printf("\n %d \n",G);

char **shift11;
shift11 = (char **)malloc(sizeof(char*)*(G-2)/2);
for(i=0;i<((G-2)/2);i++){
shift11[i]=(char*)malloc(sizeof(char)*p);}
char **shift22;
shift22 = (char **)malloc(sizeof(char*)*(G-2)/2);
for(i=0;i<((G-2)/2);i++){
shift22[i]=(char*)malloc(sizeof(char)*p);}

char **gg0;
gg0 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg0[i]=(char*)malloc(sizeof(char)*p*blocksize);}


				int a;	
				a=finite_mod((i1+i2+i3),p);
printf(" \na: ",a);
			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);} 
 				int b;	
				b=finite_mod((i1+i2),p);
				int c;	
				c=finite_mod((i1+i3),p);
				int d;	
				d=finite_mod((i2+i3),p);
printf(" \nb: ",b);
				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-b),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-c),p);}
				for(i=0;i<p;i++){
				shift11[2][i]=finite_mod((i-d),p);}
				
printf("\nshift11 \n");				
for(i=0;i<(G/2-1);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift11[i][j1]);}
printf("\n");}
				for(i=0;i<p;i++){
				shift22[0][i]=finite_mod((i-i1),p);}
				for(i=0;i<p;i++){
				shift22[1][i]=finite_mod((i-i2),p);}
				for(i=0;i<p;i++){
				shift22[2][i]=finite_mod((i-i3),p);}

printf("\nshift22 \n");				
for(i=0;i<(G/2-1);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift22[i][j1]);}
printf("\n");}

				for(i=0;i<p;i++){
				shift3[i]=finite_mod((i-0),p);}
printf(" \nshift3: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift3[j1]);} 
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}





				for(i=1;i<(G/2);i++){//i =1 2 3
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}	
				for(i=G/2;i<(G-1);i++){//i =4 5 6 
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[i][j*blocksize+j2]=*(coding2[shift22[i-4][j]]+2*blocksize+j2);}}}

printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}					



				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg0[7][j*blocksize+j2]=*(coding2[shift3[j]]+3*blocksize+j2);}}

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
			shift0[i]=finite_mod((i-(p-i0)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
			for(i=0;i<p;i++){
			xx3_1[i]=gg0[G-1]+shift0[i]*blocksize;}
printf("\nxx3_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx3_1[j1][0]);}
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
			xx3[i][j*blocksize+j2]=*(xx3_1[shift[i][j]]+j2);}}}
printf("\nxx3\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx3[i][j1*blocksize]);}
printf("\n");}
			for(i=0;i<((p-1)/2-1);i++){//i=0 1 		
		        galois_region_xor1((xx3[i]),(xx3[i+1]),(xx3[i+1]),p*blocksize);}
printf("\nxx3-XOR\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx3[i][j1*blocksize]);}
printf("\n");}
			
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-(p-i0)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
				for(i=0;i<p;i++){
				xx2_1[i]=xx3[(p-1)/2-1]+shift0[i]*blocksize;}
printf("\nxx2_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx2_1[j1][0]);}
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
				xx2[i][j*blocksize+j2]=*(xx2_1[shift[i][j]]+j2);}}}
printf("\nxx2\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx2[i][j1*blocksize]);}
printf("\n");}
				for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		       		galois_region_xor1((xx2[i]),(xx2[i+1]),(xx2[i+1]),p*blocksize);}
printf("\nxx2-xor\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx2[i][j1*blocksize]);}
printf("\n");}

			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i0)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
			for(i=0;i<p;i++){
			xx1_1[i]=xx2[(p-1)/2-1]+shift0[i]*blocksize;}
printf("\nxx1_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx1_1[j1][0]);}

			b1=i3-i0;
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
printf("\nxx1\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[i][j1*blocksize]);}
printf("\n");}
			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		        galois_region_xor1((xx1[i]),(xx1[i+1]),(xx1[i+1]),p*blocksize);}
printf("\nxx1-xor\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[i][j1*blocksize]);}
printf("\n");}
printf("\nxx1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",xx1[(p-1)/2-1][j1*blocksize]);}

printf("\nlteration-2-----------------------------------------\n");
	
G= pow(2,(r-1-1));

char **gg1;
gg1 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<G;i++){
gg1[i]=(char*)malloc(sizeof(char)*p*blocksize);}

char **coding3;
coding3 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding3[i]=(char*)malloc(sizeof(char)*blocksize);}
char **coding4;
coding4 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding4[i]=(char*)malloc(sizeof(char)*blocksize);}
char **coding1;
coding1 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding1[i]=(char*)malloc(sizeof(char)*blocksize);}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}	
				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(xx1[(p-1)/2-1]+i*blocksize),(coding3[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding3[i][j1];}}
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
				//for(j1=0;j1<blocksize;j1++){
				//coding1[i][j1]=coding2[i][blocksize+j1];}}
				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(xx1[(p-1)/2-1]+shift0[i]*blocksize),(coding4[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1+blocksize]=coding4[i][j1];}}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}					
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-2*i0),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+2*blocksize),(xx1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+2*blocksize),blocksize);}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}	

				//int a;	
				a=finite_mod((i2+i3),p);

				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-a),p);}
 printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}	
				for(i=0;i<p;i++){
				shift11[0][i]=finite_mod((i-i2),p);}
				for(i=0;i<p;i++){
				shift11[1][i]=finite_mod((i-i3),p);}
 printf("\nshift11 \n");				
for(i=0;i<(G/2);i++){
for(j1=0;j1<p;j1++){
printf(" %d ",shift11[i][j1]);}
printf("\n");}				
				
		
				for(i=0;i<p;i++){
				shift3[i]=finite_mod((i-0),p);}
 printf(" \nshift3: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift3[j1]);}
				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}





				for(i=1;i<(G-1);i++){//i =1 2 
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[i][j*blocksize+j2]=*(coding2[shift11[i-1][j]]+blocksize+j2);}}}





				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg1[3][j*blocksize+j2]=*(coding2[shift3[j]]+2*blocksize+j2);}}

printf("\ngg1\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg1[j][i*blocksize]);}
printf(" \n ");}

				for(i=0;i<(G-1);i++){//i=0 1 2			
		                galois_region_xor1((gg1[i]),(gg1[i+1]),(gg1[i+1]),p*blocksize);}	


printf("\ngg1\n");
for(j=0;j<(G);j++){
for(i=0;i<p;i++){
printf(" %d ",gg1[j][i*blocksize]);}
printf(" \n ");}	
			

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
			shift0[i]=finite_mod((i-(p-i1)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
			for(i=0;i<p;i++){
			yy2_1[i]=(gg1[G-1]+shift0[i]*blocksize);}

printf("\nyy2_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy2_1[j1][0]);}
			b1=i2-i1;
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
			yy2[i][j*blocksize+j2]=*(yy2_1[shift[i][j]]+j2);}}}
printf("\nyy2\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",yy2[i][j1*blocksize]);}
printf("\n");}
			for(i=0;i<((p-1)/2-1);i++){//i=0 1 		
		        galois_region_xor1((yy2[i]),(yy2[i+1]),(yy2[i+1]),p*blocksize);}
printf("\nyy2-xor\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",yy2[i][j1*blocksize]);}
printf("\n");}

			for(i=0;i<p;i++){
			shift0[i]=finite_mod((i-(p-i1)),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}
			for(i=0;i<p;i++){
			yy1_1[i]=yy2[(p-1)/2-1]+shift0[i]*blocksize;}

printf("\nyy1_1\n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy1_1[j1][0]);}
			b1=i3-i1;
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
printf("\nyy1\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",yy1[i][j1*blocksize]);}
printf("\n");}
			for(i=0;i<((p-1)/2-1);i++){//i=0 1			
		        galois_region_xor1((yy1[i]),(yy1[i+1]),(yy1[i+1]),p*blocksize);}
printf("\nyy1-xor\n");
for(i=0;i<(p-1)/2;i++){
for(j1=0;j1<p;j1++){
printf(" %d ",yy1[i][j1*blocksize]);}
printf("\n");}
printf("\nyy1======================================== \n");
for(j1=0;j1<p;j1++){
printf(" %d ",yy1[(p-1)/2-1][j1*blocksize]);}


printf("\nlteration-3-----------------------------------------\n");
	

G= pow(2,(r-1-1-1));
char **gg2;//2
gg2 = (char **)malloc(sizeof(char*)*G);
for(i=0;i<(G);i++){
gg2[i]=(char*)malloc(sizeof(char)*p*blocksize);}



char **coding5;
coding5 = (char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
coding5[i]=(char*)malloc(sizeof(char)*blocksize);}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}
				for(i=0;i<p;i++){			
		        	galois_region_xor1(coding2[i],(yy1[(p-1)/2-1]+i*blocksize),(coding5[i]),blocksize);}
				for(i=0;i<p;i++){
				for(j1=0;j1<blocksize;j1++){
				coding2[i][j1]=coding5[i][j1];}}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}
		
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i1),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}


				for(i=0;i<p;i++){			
		        	galois_region_xor1((coding2[i]+blocksize),(yy1[(p-1)/2-1]+shift0[i]*blocksize),(coding2[i]+blocksize),blocksize);}
printf("\ncoding-----------:\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++){
printf(" %d ",coding2[i][j*blocksize]);}
printf("\n");}
	
				for(i=0;i<p;i++){
				shift0[i]=finite_mod((i-i3),p);}
printf(" \nshift0: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift0[j1]);}				

				for(i=0;i<p;i++){
				shift3[i]=finite_mod((i-0),p);}
				
printf(" \nshift3: \n ");
for(j1=0;j1<p;j1++){
printf(" %d ",shift3[j1]);}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg2[0][j*blocksize+j2]=*(coding2[shift0[j]]+j2);}}

				
				for(j=0;j<p;j++){
				for(j2=0;j2<blocksize;j2++){
				gg2[1][j*blocksize+j2]=*(coding2[shift3[j]]+blocksize+j2);}}



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
			shift0[i]=finite_mod((i-(p-i2)),p);}

			for(i=0;i<p;i++){
			zz1_1[i]=gg2[G-1]+shift0[i]*blocksize;}


			b1=i3-i2;
			printf(" \nb1:\n ");
			printf(" %d ",b1);

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

char *test1;
test1 = (char *)malloc(sizeof(char)*8);
test1[0]=-84;test1[1]=57;test1[2]=19;test1[3]=121;test1[4]=-113;test1[5]=100;test1[6]=116;test1[7]=-72;
char *test2;
test2 = (char *)malloc(sizeof(char)*8);
test2[0]=-65;test2[1]=64;test2[2]=-36;test2[3]=-84;test2[4]=-6;test2[5]=-113;test2[6]=-21;test2[7]=-125;
char *test3;
test3 = (char *)malloc(sizeof(char)*8);

galois_region_xor1(test1,test2,test3,8);
printf("-------\n");
for(i=0;i<8;i++){
printf(" %d ",test3[i]);}





char **fdata;
fdata=(char **)malloc(sizeof(char*)*p);
for(i=0;i<p;i++){
fdata[i]=(char *)malloc(sizeof(char)*r*blocksize);}

for(i=0;i<p;i++){ 

memcpy(fdata[i],(xx1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+blocksize),(yy1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+2*blocksize),(zz1[(p-1)/2-1]+i*blocksize),blocksize);
memcpy((fdata[i]+3*blocksize),s1[i],blocksize);}

return fdata;

}//hanshu

