/*    Make lower case to upper case in file
by Amal Poulose   amalpoulose95@hotmail.com  +919446047003*/
#include<stdio.h>
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("\t          Invalid format\n\tUse:./a.out  path/filename\n");
		return;
	}
	FILE *fp;
	fp=fopen(argv[1],"r+");
	if(!fp)
	{
		printf("\tFile not found\n");
		return;
	}
	char ch;
	while((ch=fgetc(fp))!=-1)   //read character from file and store it in ch
		if(ch>=97&&ch<=122)  //check for lower case alphabet
		{
			fseek(fp,-1,SEEK_CUR); //if lower case alphabet found cuurent location indicator moves to one position backward from current
			fputc(ch-32,fp);   //replace with Upper case letter
		}
	printf("\tSuccess\n");
	return 0;
}
      
