#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
	FILE * fp; //�ļ�ָ��
	int ch; //��¼ÿ�ζ�ȡ���ַ�
	int countW = 0; //��¼������
	int countC = 0; //��¼�ַ���

	if((fp=fopen (argv[2],"r")) == NULL ){
		printf("the file: %s can not open!\n",argv[2]);
		return ;
	}
	ch = fgetc (fp);

	//ͳ���ַ���
	if(strcmp (argv[1] ,"-c")==0){
		while (ch!=EOF ){
		countC ++;
		ch = fgetc(fp);
		}
		printf("�ַ�����%d \n",countC );
		return 0;
	}
	//ͳ�Ƶ�����
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

		printf("��������%d \n",countW+1 );
	}
	else {
		printf ("������������\n");
	}
	return 0;
}