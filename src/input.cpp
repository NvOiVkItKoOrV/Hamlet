#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/input.h"

void constructor(struct FileNames* fnames,  struct Text* text)
{
    make_buf(fnames, text);
    input_to_buf(fnames, text);
    make_array_of_ptr_to_str(text);
    put_ptr_to_str (text);
    symb_counter(text);
}
void make_buf(struct FileNames* fnames, struct Text* text)
{
    assert(fnames);
    assert(text);
    struct stat statistic = {};

    stat(fnames->f_name, &statistic);

    text->size_of_buf = (size_t)statistic.st_size;
    text->adress_of_buf = (char*)calloc(text->size_of_buf, sizeof(char));

    assert(text->adress_of_buf);
}


void input_to_buf(struct FileNames* fnames, struct Text* text)
{
    assert(fnames);
    assert(text);

    FILE* file_adress = fopen(fnames->f_name, "r");
    assert(file_adress);

    fread(text->adress_of_buf, sizeof(char), text->size_of_buf, file_adress);
    assert(*text->adress_of_buf);
    fclose(file_adress);
}

void make_array_of_ptr_to_str(struct Text* text)
{
    assert(text);

    for (size_t counter = 0; counter < text->size_of_buf; counter++)
    {
        if (text->adress_of_buf[counter] == '\n' || text->adress_of_buf[counter] == EOF)
        {
            text->adress_of_buf[counter] = '\0';
            text->n_lines++;
        }
    }

    text->adress_of_str_parameters = (Str_parameters*)calloc(text->n_lines, sizeof(Str_parameters));
    assert(text->adress_of_str_parameters);

}

void put_ptr_to_str(struct Text* text)
{
    assert(text);

    int symb_counter     = 0;
    size_t ptr_to_str_count = 0;

    while(ptr_to_str_count < text->n_lines)
    {
        (text->adress_of_str_parameters + ptr_to_str_count)->ptr2str = text->adress_of_buf + symb_counter;

        while(*(text->adress_of_buf + symb_counter) != '\0')
        {
            symb_counter++;
        }
        if(*(text->adress_of_buf + symb_counter) == '\0')
        {
            symb_counter++;
        }
        ptr_to_str_count++;
    }
}

void symb_counter(struct Text* text)
{
    assert(text);

    size_t counter = 0;
    while(counter < text->n_lines)
    {
        (text->adress_of_str_parameters + counter)->sz_of_str = (int)strlen((text->adress_of_str_parameters + counter)->ptr2str);
        counter++;
    }

}
