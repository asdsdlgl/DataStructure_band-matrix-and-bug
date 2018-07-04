#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int temp[200][200]={0};
int count=0;
void value(int n,int a,int b,int i,int j,int e[]){
		e[count]=temp[i][j];
		printf("e[%d] = %d    d(%d,%d)\n",count,e[count],i,j);
		count++;
}
int main(){
	FILE *fp;
	char c;
	int i,j,num,max,a,b,k;
	char str[50];
	printf("Please input the file name:");
	scanf("%s",str);
	fp = fopen(str,"r");
	if(fp==NULL){
		printf("無此檔案!!!");
		return 0;
	}
	
	printf("a:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	
	fscanf(fp,"%d",&num);
	
	if(a>num||b>num||a<=0||b<=0){
		printf("輸入錯誤");
		return 0;
	}	
	max = (2*num-b+1)*b/2+(2*num-a+1)*a/2-num;
	int *e = (int *)calloc(max,sizeof(int));
	for(i=0;i<num;i++){
		for(j=0;j<num;j++)
			fscanf(fp,"%d",&temp[i][j]);
		}
	for(k = a-1;k>=0;k--){
		for(i=k,j=0;i<num;i++,j++)
			value(num,a,b,i,j,e);
		}
		
	for(k = 1;k<b;k++){
		for(i=0,j=k;j<num;i++,j++)
			value(num,a,b,i,j,e);
		}
	free(e);
	fclose(fp);
}
