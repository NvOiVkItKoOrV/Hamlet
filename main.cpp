#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "input.h"

int main()
{
    struct Length    length = {};
    struct FileNames f_names;
    char* buffer = make_buf(&length, f_names);
    input_to_buf(buffer, f_names, &length);
    char** array_of_ptr_to_str = make_array_of_ptr_to_str(buffer, &length);
    put_ptr_to_str (array_of_ptr_to_str, buffer, &length);



    //bubble sort/////////////////////





    int i = 0;
    while(i < length.num_of_lines)
    {
        printf("%d <%s>\n", i, array_of_ptr_to_str[i]);
        i++;
    }
    //printf("%s\n", array_of_str[++i]);
    //printf("%s\n %s\n", array_of_str, *array_of_str);
    free(array_of_ptr_to_str);
    free(buffer);





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
