#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
	FILE * fp; //文件指针
	int ch; //记录每次读取的字符
	int countW = 0; //记录单词数
	int countC = 0; //记录字符数

	if((fp=fopen (argv[2],"r")) == NULL ){
		printf("the file: %s can not open!\n",argv[2]);
		return ;
	}
	ch = fgetc (fp);

	//统计字符数
	if(strcmp (argv[1] ,"-c")==0){
		while (ch!=EOF ){
		countC ++;
		ch = fgetc(fp);
		}
		printf("字符数：%d \n",countC );
		return 0;
	}
	//统计单词数
	else if(strcmp (argv [1] ,"-w")==0){
		while (ch!=EOF ){
			if(ch==' '||ch==','){
				countW ++;	
				ch=fgetc (fp);
				while (ch==' '|| ch ==','){
					ch=fgetc (fp);
				}
			}
			else {
				ch=fgetc (fp);
			}
		}

		printf("单词数：%d \n",countW+1 );
	}
	else {
		printf ("参数出错！！！\n");
	}
	return 0;
}