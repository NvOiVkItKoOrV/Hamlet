#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/input.h"
#include "../include/sort_func.h"
#include "../include/output.h"

int main(int argc, char* argv[])
{
    struct FileNames fnames;
    fnames.f_name = argv[1];
    struct Text text = {};

    make_buf(&fnames, &text);
    input_to_buf(&fnames, &text);
    make_array_of_ptr_to_str(&text);
    put_ptr_to_str (&text);
    symb_counter(&text);

    func_to_sort(&text);

    output_func(&fnames, &text);

return 0;
}
