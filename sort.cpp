#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "input.h"

enum RES_OF_COMPARE
{
IS_LESS,
IS_EQUAL,
IS_GREATER
};

int my_strcmp (char* str1, char* str2);
void swap(char** ptr1, char** ptr2);
void sort_pair_of_str(char** str1, char** str2);

int main()
{


char buf1[] = "abcde";
char buf2[] = "abcd";
    char* s1 = buf1;
    char* s2 = buf2;
    sort_pair_of_str(&s1, &s2);
    //sort_pair_of_str(s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}



void sort_pair_of_str(char** str1, char** str2)
{
    char* isletter1 = *str1;
    char* isletter2 = *str2;

    int counter = 0;

    while(!isalpha(*isletter1))
        isletter1++;

    while(!isalpha(*isletter2))
        isletter2++;

    int res_of_comp = my_strcmp(isletter1, isletter2);


    switch(res_of_comp)
    {
    case IS_GREATER:
        swap(str1, str2);
        break;

    case IS_LESS:
        break;

    case IS_EQUAL:
        break;
    }

}



int my_strcmp (char* str1, char* str2)
{
    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 < *str2)
        {
            return IS_LESS;
            break;
        }
        else if(*str1 > *str2)
        {
            return IS_GREATER;
            break;
        }
        else if(*str1 == '\0' && *str2 != '\0')
        {
            return IS_GREATER;
            break;
        }
        else if(*str1 != '\0' && *str2 == '\0')
        {
            return IS_LESS;
            break;
        }
        str1++;
        str2++;
    }
    return IS_EQUAL;
}

void swap(char** ptr1, char** ptr2)
{
    char* changer =  *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = changer;
}
