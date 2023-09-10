// S → aSa     rule 1  
// S → bSb     rule 2  
// S → c       rule 3  

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool isValidString(char* input);
bool applyRule1(char* input, int* index);
bool applyRule2(char* input, int* index);
bool applyRule3(char* input, int* index);

int main()
{
    char input[100]; // Assuming a maximum input length of 99 characters

    printf("Enter a string: ");
    scanf("%s", input);

    // printf("You entered: %s\n", input);
    
    if (isValidString(input))
    {
        printf("Input string is valid according to the CFG rules.\n");
    }
    else 
    {
        printf("Input string is not valid according to the CFG rules.\n");
    }
    
    return 0;
}

bool isValidString(char* input)
{
    int index = 0;
    return applyRule1(input, &index) || applyRule2(input, &index) || applyRule3(input, &index);
}

bool applyRule1(char* input, int* index)
{
    if (input[*index] == 'a')
    {
        (*index)++;
        if (applyRule1(input, index)) 
        {
            if (input[*index] == 'a') 
            {
                (*index)++;
                return true;
            }
        }
    }
    return false;
}

bool applyRule2(char* input, int* index)
{
    if (input[*index] == 'b') 
    {
        (*index)++;
        if (applyRule2(input, index)) 
        {
            if (input[*index] == 'b') 
            {
                (*index)++;
                return true;
            }
        }
    }
    return false;
}

bool applyRule3(char* input, int* index)
{
    if (input[*index] == 'c')
    {
        (*index)++;
        return true;
    }
    return false;
}




//ERRORS : 
// bacab is not valid
// aaacaa is valid