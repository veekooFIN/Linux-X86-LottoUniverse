/*                                                                                                                     
  __    _ ______  ______  __  __  _____  _____  ______  ____  ____   _   ______  _____  _____   ____  ____   _  ______  
 \  \  //|   ___||   ___||  |/ / /     \/     \|   ___||    ||    \ | | |   ___|/     \|     \ |    ||    \ | ||   ___| 
  \  \// |   ___||   ___||     \ |     ||     ||   ___||    ||     \| | |   |__ |     ||      \|    ||     \| ||   |  | 
   \__/  |______||______||__|\__\\_____/\_____/|___|   |____||__/\____| |______|\_____/|______/|____||__/\____||______| 
                                                                                                                        
                                                                                                                        */ 
/*----------------------------------------------------------------------+
 |                                                                      |
 |     KTEM_lottosimufix.c -- demonstrate lotto number simulation       |
 |                        of All or nothing                             |
 |                                                                      |
 +----------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void main()
{
  int b0[12],bb[12],i,ii,total,game,sw,it;
  long cash,saldo;
  int bt0[1],bbt[1];
  int totalbt,eit,egame;
  int sil; //printout silence mode
  int cup; //cupoung silence mode
  int big; //big saldo annoucements mode 0-10000

  printf("All or nothing simulation:\n");
  printf("\nOne fixed row:\n");
  printf("Enter 1-24 nbe#1:");
  scanf("%d",&b0[0]); 
  printf("Enter 1-24 nbe#2:");
  scanf("%d",&b0[1]); 
  printf("Enter 1-24 nbe#3:");
  scanf("%d",&b0[2]); 
  printf("Enter 1-24 nbe#4:");
  scanf("%d",&b0[3]); 
  printf("Enter 1-24 nbe#5:");
  scanf("%d",&b0[4]); 
  printf("Enter 1-24 nbe#6:");
  scanf("%d",&b0[5]); 
  printf("Enter 1-24 nbe#7:");
  scanf("%d",&b0[6]); 
  printf("Enter 1-24 nbe#8:");
  scanf("%d",&b0[7]); 
  printf("Enter 1-24 nbe#9:");
  scanf("%d",&b0[8]); 
  printf("Enter 1-24 nbe#10:");
  scanf("%d",&b0[9]); 
  printf("Enter 1-24 nbe#11:");
  scanf("%d",&b0[10]); 
  printf("Enter 1-24 nbe#12:");
  scanf("%d",&b0[11]);
  printf("Enter 1-4 clover nbr#1:");
  scanf("%d",&bt0[0]);     
  printf("Nbr of iterations:");
  scanf("%d",&eit);
  printf("Nbr of games:");
  scanf("%d",&egame);
  printf("Printout silence 0/1:");
  scanf("%d",&sil);
  printf("Cupoung silence 0/1:");
  scanf("%d",&cup);
  printf("Big saldo info 0/nbr:");
  scanf("%d",&big);
  
  srand(time(0));

  for(it=0;it<eit;it++) //iterations 1-10000
  {
    cash=0;

    for(game=0;game<egame;game++) //game rounds how many weeks 1-52
    {
      if(cup != 1) printf("\nMy row:%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d*%d",b0[0],b0[1],b0[2],b0[3],b0[4],b0[5],b0[6],b0[7],b0[8],b0[9],b0[10],b0[11],bt0[0]);
      sw=0;
      bb[0]=0;
      bb[1]=0;
      bb[2]=0;
      bb[3]=0;
      bb[4]=0;
      bb[5]=0;
      bb[6]=0;
      bb[7]=0;
      bb[8]=0;
      bb[9]=0;
      bb[10]=0;
      bb[11]=0;

      for(i=0;i<12;i++)
      {
        bb[i]=rand() % 24 +1;
        for(ii=0;ii<12;ii++)
        {
          if(bb[ii] == bb[i] && (ii != i)) sw=1;
        }
        if(sw==1){
          i--;
          sw=0;
        }
      }

      bbt[0]=rand() % 4 +1;
      
      if(cup != 1) printf("\nWin row:%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d+%d*%d",bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7],bb[8],bb[9],bb[10],bb[11],bbt[0]);

      total=0;

      for(i=0;i<12;i++)
      {
        for(ii=0;ii<12;ii++)
        {
          if(bb[i]==b0[ii])
          {
            total++;
          }
        }
      }
      totalbt=0;

      if(bbt[0]==bt0[0])
          {
            totalbt++;
          }
  
      if(cup != 1) printf("\nNumbers correct:%d*%d",total,totalbt);

      if((total==12 && totalbt==1)||(total==0 && totalbt==1)) {
      cash=cash+500000;
      if(sil != 1) printf("\n500 000 euro win");
      }
      if((total==12 && totalbt==0)||(total==0 && totalbt==0)) {
      cash=cash+125000;
      if(sil != 1) printf("\n125 000 euro win");
      }
      if((total==11 && totalbt==1)||(total==1 && totalbt==1)) {
      cash=cash+1000;
      if(sil != 1) printf("\n1000 euro win");
      }
      if((total==11 && totalbt==0)||(total==1 && totalbt==0)) {
      cash=cash+250;
      if(sil != 1) printf("\n250 euro win");
      }
      if((total==10 && totalbt==1)||(total==2 && totalbt==1)) {
      cash=cash+100;
      if(sil != 1) printf("\n100 euro win");
      }
      if((total==10 && totalbt==0)||(total==2 && totalbt==0)) {
      cash=cash+25;
      if(sil != 1) printf("\n25 euro win");
      }
      if((total==9 && totalbt==1)||(total==3 && totalbt==1)) {
      cash=cash+20;
      if(sil != 1) printf("\n20 euro win");
      }
      if((total==9 && totalbt==0)||(total==3 && totalbt==0)) {
      cash=cash+5;
      if(sil != 1) printf("\n5 euro win");
      }
      if((total==8 && totalbt==1)||(total==4 && totalbt==1)) {
      cash=cash+4;
      if(sil != 1) printf("\n4 euro win");
      }   
      if((total==8 && totalbt==0)||(total==4 && totalbt==0)) {
      cash=cash+1;
      if(sil != 1) printf("\n1 euro win");
      }
      if((total==7 && totalbt==1)||(total==5 && totalbt==1)||(total==6 && totalbt==1)) {
      cash=cash+1;
      if(sil != 1) printf("\n1 euro win");
      }

      saldo = cash - game * 2 -2;

      if(sil != 1 && saldo > 100) printf("\nGame,win,100 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 1000) printf("\nGame,win,1000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 10000) printf("\nGame,win,10000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 100000) printf("\nGame,win,100000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 1000000) printf("\nGame,win,1000000 euro saldo:%d+%ld+%ld",game,cash,saldo);
      if(sil != 1 && saldo > 10000000) printf("\nGame,win,10000000 euro saldo:%d+%ld+%ld",game,cash,saldo);
    }
    if(big == 0) {
      printf("\nIteration,game,win,saldo:");
      printf("\n%d+%d+%ld+%ld",it,game,cash,saldo);
    }
    if(big > 0 && saldo > big) {
      printf("\nIteration,game,win,saldo:");
      printf("\n%d+%d+%ld+%ld",it,game,cash,saldo);
    }
  }
}
