
#include<stdlib.h>
#include<string.h>
int main(int argc ,char **argv)
{
	if(argc!=3){
		printf("Usage:./a.out filename word\n");
		return;
	}
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("File not found\n");
		return ;
	}
	int i=0,j,k,n=0;
	char *str,ch;
        while((ch=fgetc(fp))!=EOF)
                   n++;
        rewind(fp);
        str=malloc(n+1);
        
        while((ch=fgetc(fp))!=EOF)
         str[i++]=ch;      
  
        for(i=0;str[i];i++)
         {
            if(str[i]==argv[2][0] && (str[i-1]==' '||str[i-1]=='\n'))
            {
              for(j=i,k=0;str[j]==argv[2][k];j++,k++);    
              if(argv[2][k]=='\0'){
              for(k=i;str[k]=str[j];k++,j++);
              i--;}
            }
         }
        
        fclose(fp);
        fp=fopen(argv[1],"w");
        fputs(str,fp);
        free(str);
	fclose(fp);
	return 0;
}


