/*
S -> AaB | BbA | ε
A -> Aa | ε
B -> Bb | ε
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int position = 0;

bool S();
bool A();
bool B();

void error()
{
    printf("Rejected\n");
    exit(1);
}

bool match(char expected) 
{
    if (input[position] == expected) 
    {
        position++;
        return true;
    }
    return false;
}

bool S() 
{
    if ((A() && match('a') && B()) || (B() && match('b') && A())) 
    {
        return true;
    } 
    else 
    {
        // S -> ε (epsilon)
        return true;
    }
}

bool A() 
{
    if (match('a') && A()) 
    {
        return true;
    } 
    else 
    {
        // A -> ε (epsilon)
        return true;
    }
}

bool B() 
{
    if (match('b') && B()) 
    {
        return true;
    } 
    else 
    {
        // B -> ε (epsilon)
        return true;
    }
}

int main() 
{
    printf("Enter a string of 'a's and 'b's: ");
    scanf("%s", input);

    if (S() && input[position] == '\0') 
    {
        printf("Accepted\n");
    } 
    else 
    {
        printf("Rejected\n");
    }

    return 0;
}