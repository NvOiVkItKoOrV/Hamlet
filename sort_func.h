#ifndef SORT_FUNC_H
#define SORT_FUNC_H

void func_to_sort(struct Text* text);
int my_strcmp(char* str1, char* str2);
void swap(char** ptr1, char** ptr2);
int sort_pair_of_str(char** str1, char** str2);
void my_bubble_sort(Str_parameters* adress_of_str_parameters, int length,
                    int (*check_pair)(char** str1, char** str2));

#endif /*SORT_FUNC_H*/
