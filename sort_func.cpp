#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "input.h"
#include "sort_func.h"


void func_to_sort(struct Text* text)
{
    int (*adress_of_func2sort)(char** str1, char** str2);
    adress_of_func2sort = sort_pair_of_str;
    my_bubble_sort(text->adress_of_str_parameters, text->n_lines, adress_of_func2sort);

}


void my_bubble_sort(Str_parameters* adress_of_str_parameters, int length,
                    int (*check_pair)(char** str1, char** str2))      //qsort prototype
{
    for(int str_counter = 0; str_counter < length - 1; str_counter++)
        for(int counter = 0; counter < length - 1; counter++)
        {
            int check = check_pair(&((adress_of_str_parameters + counter)->ptr2str),
                                   &((adress_of_str_parameters + counter + 1)->ptr2str));
            switch(check)
            {
            case IS_GREATER:
                swap(&((adress_of_str_parameters+ counter)->ptr2str),
                     &((adress_of_str_parameters + counter + 1)->ptr2str));
                break;

            case IS_LESS:
                break;

            case IS_EQUAL:
                break;
            }

        }
}

int sort_pair_of_str(char** str1, char** str2)
{
    char* isletter1 = *str1;
    char* isletter2 = *str2;

    int counter = 0;

    while(!isalpha(*isletter1))
        isletter1++;

    while(!isalpha(*isletter2))
        isletter2++;

    int res_of_comp = my_strcmp(isletter1, isletter2);

    return res_of_comp;

}


void sort_pair_of_str_fr_end (char** str1, char** str2)
{
    char* isletter1 = *str1;
    char* isletter2 = *str2;


}


int my_strcmp_fr_end (char* str1, char* str2)
{

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
