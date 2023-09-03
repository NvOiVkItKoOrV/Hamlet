#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include "types.h"
#include "input.h"


char* make_buf (struct Length* length, struct FileNames f_names)
{
    struct stat statistic = {};

    stat(f_names.f_name, &statistic);

    length->length_of_buf = statistic.st_size;
    char *buffer         = (char*)calloc(length->length_of_buf , sizeof(char));
    return buffer;
}


void input_to_buf (char* buffer, struct FileNames f_names, struct Length* length)
{
    FILE* file_adress = fopen(f_names.f_name, "r");

    assert(file_adress);
    assert(fread(buffer, sizeof(char), length->length_of_buf, file_adress));
}

char** make_array_of_ptr_to_str(char* buffer, struct Length* length)
{
    for (int counter = 0; counter < length->length_of_buf; counter++)
    {
        if (buffer[counter] == '\n' || buffer[counter] == EOF)//возможно на еоф придется еще лдну ячейку выделять
        {
            buffer[counter] = '\0';
            length->num_of_lines++;
        }
    }

    char** array_of_ptr_to_str = (char**) calloc(length->num_of_lines, sizeof(char*));
    assert(array_of_ptr_to_str);

    return array_of_ptr_to_str;
}

void put_ptr_to_str (char** array_of_ptr_to_str, char* buffer,  struct Length* length)
{
    int symb_counter     = 0;
    int ptr_to_str_count = 0;

    while(ptr_to_str_count < length->num_of_lines)
    {
        array_of_ptr_to_str[ptr_to_str_count] = buffer + symb_counter;

        while(buffer[symb_counter] != '\0')
        {
            symb_counter++;
        }
        if(buffer[symb_counter] == '\0')
        {
            symb_counter++;
        }
        ptr_to_str_count++;
    }
}
