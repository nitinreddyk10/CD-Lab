#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* ptr;
	char ch;

    //  (PART -A) Reading File //
	ptr = fopen("input.txt", "r");
	if (ptr == NULL)
    {
		printf("Cannot Open\n");
	}
    else
    {
    	printf("File's Info : \n");
    }

    while(ch!=EOF) // Printing character by character using loop.
    {
        ch = fgetc(ptr);
	 	printf("%c", ch);   
    }

	fclose(ptr); // Closing the file
	return 0;
}