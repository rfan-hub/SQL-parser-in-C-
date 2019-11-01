#include<stdio.h>
#include<string.h>
#define N 10000
#define max(a,b) (a>b?a:b)
#define max3(a,b,c) (max(a,max(b,c)))

  int a[N][20];
int main(){
	int n;
 
    while(scanf("%d",&n),n){
    int x,t,tmax=0;
    int i,j;
   	memset(a, 0, sizeof(a));
    	for(i=0;i<n;i++){
    	scanf("%d%d",&x,&t);
    	tmax=max(tmax,t);
    	a[t][x]++;
    	}
   
	for(i=tmax-1;i>=0;i--){
		for(j=0;j<=10;j++){
		//	a[i][j]+=max3(a[i+1][j-1],a[i+1][j],a[i+1][j+1]);
		a[i][j] += max3(a[i+1][j-1], a[i+1][j], a[i+1][j+1]);
		}
	}
		printf("%d\n",a[0][5]);
    }

	return 0;
}
