#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;

    char *filename = "output.txt";
    char *content = "I am Nitin Reddy K,CS21B2028,This line is getting added to 'output.txt' file.\n";

    fp = fopen("output.txt", "a");

    /* Write content to file */
    fprintf(fp, "%s\n", content);
    fclose(fp);

    //Reading and Printing
    fp = fopen("output.txt", "r");

   printf("\nContents of %s  -\n","output.txt");
   while ((ch = fgetc(fp))!= EOF)
   {
      printf ("%c", ch);
   }
   fclose(fp);
    return 0;
}