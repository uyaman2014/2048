/*2番 宇山裕大 2048（パズルゲーム）*/

#include<stdio.h>
#include <stdlib.h>   /* rand, srand関数を使うため */
#include <time.h>     /* time関数を使うため */

int randam(int masu);
int randam2(int *null, int n);
int main(void)
{
   int j=0,tr=0/*bool*/,i,k,r,a[100][100]={0},masu;
   //-------------------------------------------------------------
   //初期画面
   printf("縦横の幅="); scanf("%d",&masu);
   srand((unsigned int)time(NULL));
      while(tr!=2){
         r=randam(masu*masu);
         if(a[r/masu][r%masu]==0){
         tr++;
         a[r/masu][r%masu]=2;
         }
      }
   for(i=0;i<masu*masu;i++){
      if(i%masu==0) printf("\n");
      printf("%5d",a[i/masu][i%masu]);
   }
   printf("\n");
   //---------------------------------------------------------------
   int tmp,end=0,null[10000]={0},n=0;
   char kye;
   //操作---------------------------------------------------------------
//---上移動---------------------------------------------------------------
   kye='\0';
   while(end==0){
      kye=getchar();
      if(kye=='w') {
         for(i=0;i<masu;i++){
            for(j=0;j<masu-1;j++){
               for(k=j+1;k<masu;k++){
                  if(a[j][i]==a[k][i] && a[j][i]!=0){
                     a[j][i]*=2;
                     a[k][i]=0;
                     k=masu;
                  }
                  else if(a[k][i]!=0&&a[j][i]!=0) k=masu;
                  else if(a[j][i]==0) {
                     a[j][i]=a[k][i];
                     a[k][i]=0;
                  }
               }
            }
         }
      printf("w");
      }
//----した移動-----------------------------------------------------------
      if(kye=='s') {
         for(i=0;i<masu;i++){
            for(j=masu-1;j>0;j--){
               for(k=j-1;k>=0;k--){
                  if(a[j][i]==a[k][i] && a[j][i]!=0){
                     a[j][i]*=2;
                     a[k][i]=0;
                     k=-1;
                  }
                  else if(a[k][i]!=0&&a[j][i]) k=-1;
                  else if(a[j][i]==0) {
                     a[j][i]=a[k][i];
                     a[k][i]=0;
                  }
               }
            }
         }
      printf("s");
      }
//------右移動------------------------------------------------------------
      if(kye=='d'){
        for(i=0;i<masu;i++){
            for(j=masu-1;j>0;j--){
               for(k=j-1;k>=0;k--){
                  if(a[i][j]==a[i][k] && a[i][j]!=0){
                     a[i][j]*=2;
                     a[i][k]=0;
                     k=-1;
                  }
                  else if(a[i][k]!=0&&a[i][j]!=0) k=-1;
                  else if(a[i][j]==0) {
                     a[i][j]=a[i][k];
                     a[i][k]=0;
                  }
               }
            }
         }
         printf("d");
      }
//----左移動-----------------------------------------------------------------
      if(kye=='a') {
         for(i=0;i<masu;i++){
            for(j=0;j<masu;j++){
               for(k=j+1;k<masu;k++){
                  if(a[i][j]==a[i][k] && a[i][j]!=0){
                     a[i][j]*=2;
                     a[i][k]=0;
                     k=masu;
                  }
                  else if(a[i][k]!=0&&a[i][j]!=0) k=masu;
                  else if(a[i][j]==0) {
                     a[i][j]=a[i][k];
                     a[i][k]=0;
                  }
               }
            }
         }
      printf("a");
      }

      if(kye=='q') end=1;
      tr=0;
      //空白ヲ渡す
      n=0;
      for(i=0;i<masu*masu;i++){
         if(a[i/masu][i%masu]==0){
            null[n]=i;
            n++;
         }
      }

      //2をランダムに代入する
      if(kye=='a'||kye=='s'||kye=='w'||kye=='d'){
         r=randam2(null,n);
         //printf("%d\n",r);
         a[r/masu][r%masu]=2;
         //ログ削除
         //printf("%c[2J", 27);
         //画面表示
         for(i=0;i<masu*masu;i++){
            if(i%masu==0) printf("\n");
            if(a[i/masu][i%masu]==0) printf("    -");
            else printf("%5d",a[i/masu][i%masu]);
         }
         printf("\n");
         //printf("%d",r);
         //printf("%d",a[r/masu][r%masu]);
      }
      printf("\n"); 
   /*   for(i=0;i<masu*masu;i++){
         printf("a[%d]=%d\n",i,a[i/masu][i%masu]);
      }
   */
   }
      return 0;
}
int randam(int masu)
{
   int n;
   srand((unsigned int)time(NULL));
   n=rand()%masu;
   return n;
}

int randam2(int *null, int n)
{
   int r;
   srand((unsigned int)time(NULL));
   r=rand()%n;
   return null[r];
}
