#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input.h"
#include "sort_func.h"

int main(/*int argc, char* argv[]*/)
{
    struct FileNames fnames;
    //fnames.f_name = argv[1];
    struct Text text = {};

    make_buf(&fnames, &text);      // ctor_text(&text) == constuct buffer; dtor_buf
    input_to_buf(&fnames, &text);
    make_array_of_ptr_to_str(&text);
    put_ptr_to_str (&text);

    func_to_sort(&text);




    FILE *fp = fopen(fnames.sort_f_name, "w");
    int i = 0;
    while(i < text.n_lines)
    {
        fprintf(fp,"%d <%s>\n", (text.adress_of_str_parameters + i)->sz_of_str, (text.adress_of_str_parameters + i)->ptr2str);//mistake in strlen in string structure
        i++;
    }
    //printf("%s\n", array_of_str[++i]);
    //printf("%s\n %s\n", array_of_str, *array_of_str);
    free(text.adress_of_buf);
    free(text.adress_of_str_parameters);





//openning file with Hamlet
    //open file
    //count all symbols

//copying all strings to buffer

//sorting it

//putting it to sorting file

//cleaning the buffer

//bubble-sort
//qsort
//через воид: 2 любых параметра и указатель на функцию сравнения
return 0;
}
