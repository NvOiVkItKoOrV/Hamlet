#ifndef TYPES_H
#define TYPES_H

struct Str_parameters
{
    char* ptr2str;
    int sz_of_str;
};

struct FileNames
{
    char* f_name      /*= "Hamlet.txt"*/;
    char* sort_f_name /*= "SortHamlet.txt"*/;
};

struct Text {
     char* adress_of_buf = nullptr;
     size_t size_of_buf = 0;
     size_t n_lines = 0;
     struct Str_parameters* adress_of_str_parameters = nullptr;
     struct Str_parameters str_parameters = {};
     struct FileNames file_names = {};
 };

enum RES_OF_COMPARE
{
    IS_LESS,
    IS_EQUAL,
    IS_GREATER
};

#endif /*TYPES_H*/
