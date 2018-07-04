#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	FILE *fp;
	int imove[8]={-1,0,1,1,1,0,-1,-1};
	int jmove[8]={1,1,1,0,-1,-1,-1,0};
	int i,j,randnum,n,m,count=0,ibug=1,jbug=1,finish=0,total;
	srand(time(NULL));
	printf("n:");
	scanf("%d",&n);
	printf("m:");
	scanf("%d",&m);
	printf("Initial bug position X:");
	scanf("%d",&ibug);
	printf("Initial bug position Y:");
	scanf("%d",&jbug);
	
	total = n*m;
	if(n<=2||n>40||m<=2||m>20||ibug>=m||jbug>=n||ibug<0||jbug<0){
		printf("錯誤輸入");
		return 0;
	}
	
	int **arr = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		arr[i] = (int *)calloc(m,sizeof(int));
	}
	
	while(count<50000){
		randnum = rand()%8;
		if(ibug+imove[randnum]<m&&jbug+jmove[randnum]<n&&ibug+imove[randnum]>=0&&jbug+jmove[randnum]>=0){
			ibug = ibug + imove[randnum];
			jbug = jbug + jmove[randnum];
			arr[jbug][ibug]++;
			count++;
		}else continue;
		for(j=0;j<n;j++){
			for(i=0;i<m;i++){
				if(arr[j][i]!=0)finish++;
			}
		}
		if(finish>=total)break;
		finish = 0;
	}
	
	
	fp = fopen("Sample_output.txt","w");
	fprintf(fp,"總共%d步\n\n",count);
	for(j=0;j<n;j++){
		for(i=0;i<m;i++){
			fprintf(fp,"%4d ",arr[j][i]);
		}
		fprintf(fp,"\n");
	}
	
	for(i=0;i<n;i++){
		free(arr[i]);
	}
	free(arr);
	
	fclose(fp);
} 
