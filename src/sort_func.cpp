#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "../include/types.h"
#include "../include/input.h"
#include "../include/sort_func.h"


void func_to_sort(struct Text* text)
{
    assert(text);

    int (*adress_of_func2sort)(Str_parameters** str1, Str_parameters** str2, int comp); //typedef?
    adress_of_func2sort = sort_pair_of_str;
    my_bubble_sort(text->adress_of_str_parameters, text->n_lines, adress_of_func2sort);

}


void my_bubble_sort(Str_parameters* adress_of_str_parameters, size_t length,
                    int (*check_pair)(Str_parameters** str1, Str_parameters** str2, int comp))
{
    for(size_t str_counter = 0; str_counter < length - 1; str_counter++)
        for(size_t counter = 0; counter < length - 1; counter++)
        {
            Str_parameters* adress1 = adress_of_str_parameters + counter;
            Str_parameters* adress2 = adress_of_str_parameters + counter + 1;
            int check = check_pair(&adress1, &adress2, FROM_END);

            switch(check)
            {
            case IS_GREATER:
                swap(&(adress_of_str_parameters[counter].ptr2str),
                     &(adress_of_str_parameters[counter + 1].ptr2str),
                     &(adress_of_str_parameters[counter].sz_of_str),
                     &(adress_of_str_parameters[counter + 1].sz_of_str));
                break;

            case IS_LESS:
                break;

            case IS_EQUAL:
                break;
            }

        }
}


int sort_pair_of_str(Str_parameters** str1, Str_parameters** str2, int comp)
{
    char* isletter1;
    char* isletter2;
    if(comp == FROM_END)
    {
        int sz1 = (*str1)->sz_of_str;
        int sz2 = (*str2)->sz_of_str;

        isletter1 = (*str1)->ptr2str + sz1;
        isletter2 = (*str2)->ptr2str + sz2;

        while(!isalpha(*isletter1) && sz1 > 0)
        {
            isletter1--;
            sz1--;
        }
        while(!isalpha(*isletter2) && sz2 > 0)
        {
            isletter2--;
            sz2--;
        }
    }
    else if(comp == FROM_BEGINNING)
    {
        isletter1 = (*str1)->ptr2str;
        isletter2 = (*str2)->ptr2str;

        while(!isalpha(*isletter1))
            isletter1++;

        while(!isalpha(*isletter2))
            isletter2++;
    }

    int res_of_comp = my_strcmp(isletter1, isletter2, comp);

    return res_of_comp;
}


int my_strcmp(char* str1, char* str2, int comp)
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
        str1 += comp;
        str2 += comp;
    }
    return IS_EQUAL;
}


void swap(char** ptr1, char** ptr2, int* sz1, int* sz2)
{
    char* st_changer = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = st_changer;

    int n_changer = *sz1;
    *sz1 = *sz2;
    *sz2 = n_changer;
}
