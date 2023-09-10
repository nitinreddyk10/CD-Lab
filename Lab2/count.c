//NOTE: Delimeter contains '','\n','\t' , ie, token will split the word at elements in Delimeter

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//CS21B2028
//NitinReddyK

#define maxsize 1024

int is_vowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    const char* file_name = "input.c";
    FILE* file;
    char buffer[maxsize];
    char* token;

    int lines = 0, words = 0, characters = 0;
    int vowels = 0, consonants = 0, digits = 0, others = 0;

    file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

   while (fgets(buffer, maxsize, file) != NULL)
   {
        lines++;

        for (int i = 0; buffer[i] != '\0'; i++) 
        {
            char ch = buffer[i];
            if (isalpha(ch))
            {
                characters++;
                if (is_vowel(ch))
                    vowels++;
                else
                    consonants++;
            } 
            else if (isdigit(ch)) 
            {
                characters++;
                digits++;
            } else if (!isspace(ch)) 
            {
                characters++;
                others++;
            }
        }

        token = strtok(buffer, " \t\n");
        while (token != NULL) {
            words++;
            token = strtok(NULL, " \t\n");
        }
    }
       
    fclose(file);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of other characters: %d\n", others);
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);

    printf("Number of characters: %d\n", characters);
    printf("1+2+3+4=%d",vowels+consonants+digits+others);

    return 0;
}

//Everything that has ascii number is a character