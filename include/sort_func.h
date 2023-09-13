#ifndef SORT_FUNC_H
#define SORT_FUNC_H

void func_to_sort    (struct Text* text);
int  my_strcmp       (char* str1, char* str2, int comp);
void swap            (char** ptr1, char** ptr2, int* sz1, int* sz2);
int  sort_pair_of_str(Str_parameters** str1, Str_parameters** str2, int comp);

void my_bubble_sort(Str_parameters* adress_of_str_parameters, size_t length,
int (*check_pair)(Str_parameters** str1, Str_parameters** str2, int comp));


#endif /*SORT_FUNC_H*/
