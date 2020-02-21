/*2番 宇山裕大 2048（パズルゲーム）*/

#include<stdio.h>
#include <signal.h>
#include <stdlib.h>   /* rand, srand関数を使うため */
#include <time.h>     /* time関数を使うため */

void show();
int randam(int masu);
int randam2(int *null, int n);
int a[100][100]={0},masu, end=0;
int main(void)
{
	void stop();
   int j=0,tr=0/*bool*/,i,k,r;
   //-------------------------------------------------------------
   //初期画面
   printf("縦横の幅="); scanf("%d",&masu);
	signal(SIGTSTP,stop);//ゲームが始まったらシグナルハンドラ設定
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
   int tmp,null[10000]={0},n=0;
   char kye[2];
   //操作---------------------------------------------------------------
//---上移動---------------------------------------------------------------
   while(end==0){
      scanf("%s",kye);
		printf("入力したのは%s",kye);
      if(kye[0]=='w') {
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
      }
//----した移動-----------------------------------------------------------
      else if(kye[0]=='s') {
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
      }
//------右移動------------------------------------------------------------
      else if(kye[0]=='d'){
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
      }
//----左移動-----------------------------------------------------------------
      else if(kye[0]=='a') {
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
      }
		else if(kye[0]=='q')
		{
			end=1;
		}

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
      if(kye[0]=='a'||kye[0]=='s'||kye[0]=='w'||kye[0]=='d'){
         r=randam2(null,n);
         a[r/masu][r%masu]=2;
			show();
      }
      printf("\n"); 
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

void show()
{
	int i=0;
   //画面表示
   for(i=0;i<masu*masu;i++){
      if(i%masu==0) printf("\n");
      if(a[i/masu][i%masu]==0) printf("    -");
      else printf("%5d",a[i/masu][i%masu]);
   }
   printf("\n");
}

void stop()
{
	//割り込みで操作方法を表示
	printf("\n操作方法\n右移動a:左移動d:上移動w:下移動s\nゲーム終了q\n");
}
