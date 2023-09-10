#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ch;
    FILE *fp,*fq;

    fp=fopen("input.txt","r");
    fq=fopen("output.txt","w");

    if(fp==NULL||fq==NULL)
    {
        printf("File Donot Exist\n");
    }
    else
    {
        while((ch=fgetc(fp))!=EOF)
        {
            fputc(ch,fq);
        }
    }

    printf("File Copied!\n");

    return 0;
}