#include<stdio.h>
int main(int argc,char **argv)
{
	system("clear");
	if(argc != 2){                                     //if more than 2 or less arguments exit from program
		printf("\nUsage  : ./a.out filename \n");
		return;
	}
	FILE *fp;                                          //declare file pointer fp 
	fp=fopen(argv[1],"r+");                             //open the file in read and write mode 
	if(fp==0)                                          //if file not found exit from program
	{
		printf("File not found\n");
		return;} 

        /*Main part of the program*/

	char ch;
	int check=0,k=0;
	while((ch=fgetc(fp))!=-1)               //Loop execute till end of file fgetc read one character from file and assign to ch
	{
		k=1;                            // k is a veriable to check whether file is empyty of not
		if(ch==' '|| ch=='\n')          // if a space or end of file is read then the variable check is cleared and next character is fetched 
		{     check=0;continue;}                      
		if(check==0)                    //if check is zero the charcter in ch is the first letter of a word oherwise else part executed
		{
			if(ch>=97 && ch<=122){  // check whether the letter is lower case 
				fseek(fp,-1,SEEK_CUR); //Move current position indicator one position backward
				fputc((ch-32),fp);}    //Make the lower case letter to upper case
		}
		check=1;
	}
	if(k==1)
		printf("\t\tSuccess\n");
	else
		printf("\t\tNo Data found\n");
	fclose(fp);

 
        sleep(3);
        system("clear");
	return(0);
}
