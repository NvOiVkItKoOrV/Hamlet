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

    constructor(&fnames, &text);

    func_to_sort(&text);

    output_func(&fnames, &text);
    destructor(&fnames, &text);
    return 0;
}
