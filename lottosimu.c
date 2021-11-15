/*----------------------------------------------------------------------+
 |                                                                      |
 |     lotto.c -- demonstrate lotto number simulation / quick and dirty |
 |                Eurojackpot                                           |
 |                                                                      |
 +----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() 
{ 
  int b0[5],bb[5],i,ii,total,game,cash,sw,saldo;
  int b1[5];
  int b2[5];
  int b3[5];
  int b4[5];
  int b5[5];
  int b6[5];
  int b7[5];
  int b8[5];
  int b9[5];
  int bt0[2],bbt[2];
  int bt1[2],totalbt;
  int bt2[2];
  int bt3[2];
  int bt4[2];
  int bt5[2];
  int bt6[2];
  int bt7[2];
  int bt8[2];
  int bt9[2];
  int ir1,ir2,irr1,irr2;

 srand(time(0));
 cash=0;
 ir1=0;
 ir2=0;
 irr1=0;
 irr2=0;
 for(game=0;game<5200;game++)    
 {

/*----------------------------------------------------------------------+
 |                                                                      |
 |                                                                      |
 |                Eurojackpot - input rows                              |
 |                                                                      |
 +----------------------------------------------------------------------*/  
  sw=0;
  //printf("\nSyota eurojackpot numerot 5kpl 1-50 R1: "); 
  for(i=0;i<5;i++) 
  { 
    b0[i]=rand() % 51 +1;  
    for(ii=0;ii<5;ii++) 
    {   
      if(b0[ii] == b0[i] && (ii != i)) sw=1;
    }
    if(sw==1){ 
    i--;
    sw=0;
    }
  }
  sw=0;
  //printf("\nSyota eurojackpot tahtinumerot 2kpl 1-10 R1: "); 
  for(i=0;i<2;i++) 
  {
    bt0[i]=rand() % 11 +1;
    for(ii=0;ii<2;ii++) 
    {  
      if(bt0[ii] == bt0[i] && (ii != i)) sw=1;
    }
    if(sw==1){ 
    i--;
    sw=0;
    }
  }
  
/*
  ir1=0;
  ir2=0;   
  for(i=0;i<5;i++) 
  { 
    for(ii=0;ii<5;ii++) 
    {
      if(b0[ii] == b0[i] && (ii != i)){
      ir1++;
      if(ir1>1) printf("\nArrayssa samat numerot ir1\n");  
      }
    }
  }
   
  for(i=0;i<2;i++) 
  {
    for(ii=0;ii<2;ii++) 
    {
      if(bt0[ii] == bt0[i] && (ii != i)){
      ir2++;
      if(ir2>1) printf("\nArrayssa samat numerot ir2\n"); 
      }
    }
  }  
*/ 
   
/*----------------------------------------------------------------------+
 |                                                                      |
 |                                                                      |
 |                Eurojackpot - input right row                         |
 |                                                                      |
 +----------------------------------------------------------------------*/  
  sw=0;
  //printf("\nSyota oikeat eurojackpot numerot 5kpl 1-50: "); 
  for(i=0;i<5;i++) 
  { 
    bb[i]=rand() % 51 +1;
    for(ii=0;ii<5;ii++) 
    {     
      if(bb[ii] == bb[i] && (ii != i)) sw=1;
    }
    if(sw==1){ 
    i--;
    sw=0;
    }
  }
  sw=0;
  //printf("\nSyota oikeat eurojackpot tahtinumerot 2kpl 1-10: ");
  for(i=0;i<2;i++) 
  {
    bbt[i]=rand() % 11 +1;
    for(ii=0;ii<2;ii++) 
    {  
      if(bbt[ii] == bbt[i] && (ii != i)) sw=1;
    }
    if(sw==1){ 
    i--;
    sw=0;
    }
  } 

/*
  irr1=0;
  irr2=0;
  for(i=0;i<5;i++) 
  { 
    for(ii=0;ii<5;ii++) 
    {
      if(bb[ii] == bb[i] && (ii != i)){
      irr1++;
      if(irr1>1) printf("\nArrayssa samat numerot irr1\n");  
      }
    }
  }
  for(i=0;i<2;i++) 
  {
    for(ii=0;ii<2;ii++) 
    {
      if(bbt[ii] == bbt[i] && (ii != i)){ 
      irr2++;
      if(irr2>1) printf("\nArrayssa samat numerot irr2\n");
      }
    }  
  } 
*/

/*----------------------------------------------------------------------+
 |                                                                      |
 |                                                                      |
 |                Eurojackpot - output results                          |
 |                                                                      |
 +----------------------------------------------------------------------*/

  total=0;  
  for(i=0;i<5;i++) 
  { 
    for(ii=0;ii<5;ii++) 
    { 
      if(bb[i]==b0[ii])
      { 
        total++;
      }
    }  
  }
  totalbt=0;
  for(i=0;i<2;i++) 
  { 
    for(ii=0;ii<2;ii++) 
    { 
      if(bbt[i]==bt0[ii])
      { 
        totalbt++;
      }
    }  
  }
      
  //printf("\nEurojackpot numeroita oikein R1:\t\t\t %d+%d\n",total,totalbt);
  if(total==5 && totalbt==2) {
    cash=cash+20000000;
    printf("\nEurojackpot 20 000 000 euron voitto\n");
     }
  if(total==5 && totalbt==1) {
    cash=cash+500000;
    printf("\nEurojackpot 500 000 euron voitto\n");
  }
  if(total==5 && totalbt==0) {
    cash=cash+100000;
    printf("\nEurojackpot 100 000 euron voitto\n");
  }
  if(total==4 && totalbt==2) {
    cash=cash+4200;
    printf("\nEurojackpot 4200 euron voitto\n");
  }
  if(total==4 && totalbt==1) {
    cash=cash+240;
    printf("\nEurojackpot 240 euron voitto\n");
  }
  if(total==4 && totalbt==0) {
    cash=cash+100;
    printf("\nEurojackpot 100 euron voitto\n");
  }
  if(total==3 && totalbt==2) cash=cash+60;
  if(total==2 && totalbt==2) cash=cash+20;
  if(total==3 && totalbt==1) cash=cash+18;
  if(total==1 && totalbt==2) cash=cash+10;
  if(total==2 && totalbt==1) cash=cash+8;
  saldo = cash - game * 2;
  
  if(saldo > 1) printf("\nEurojackpot kierros, voitot, 1 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 10) printf("\nEurojackpot kierros, voitot, 10 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 100) printf("\nEurojackpot kierros, voitot, 100 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 1000) printf("\nEurojackpot kierros, voitot, 1 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 10000) printf("\nEurojackpot kierros, voitot, 10 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 100000) printf("\nEurojackpot kierros, voitot, 100 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 1000000) printf("\nEurojackpot kierros, voitot, 1000 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 10000000) printf("\nEurojackpot kierros, voitot, 10 000 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  if(saldo > 100000000) printf("\nEurojackpot kierros, voitot, 100 000 000 euron tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
  }
  printf("\nEurojackpot kierros, voitot, tulos:\t\t\t %d+%d+%d\n",game,cash,saldo);
} 

