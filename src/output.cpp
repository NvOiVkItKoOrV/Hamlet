#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/output.h"

void output_func(struct FileNames* fnames, struct Text* text)
{
    char buf[MAX_VALUE] = "SORT_";
    fnames->sort_f_name = strcat(buf, fnames->f_name);

    FILE *fp = fopen(fnames->sort_f_name, "w");
    size_t counter = 0;
    while(counter < text->n_lines)
    {
        fprintf(fp,"%d <%s>\n",(text->adress_of_str_parameters + counter)->sz_of_str,
                               (text->adress_of_str_parameters + counter)->ptr2str);
        counter++;
    }
    fclose(fp);
}

void destructor(struct FileNames* fnames, struct Text* text)
{
    free(text->adress_of_buf);
    free(text->adress_of_str_parameters);

    text->file_names = {};
    text->str_parameters = {};
    text->n_lines = 0;
    text->size_of_buf = 0;

    fnames = {};
}
