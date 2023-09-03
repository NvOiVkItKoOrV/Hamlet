#ifndef INPUT_H
#define INPUT_H

char* make_buf (struct Length* length, struct FileNames f_names);
void input_to_buf (char* buffer, struct FileNames f_names, struct Length* length);
char** make_array_of_ptr_to_str(char* buffer, struct Length* length);
void put_ptr_to_str (char** array_of_ptr_to_str, char* buffer,  struct Length* length);

#endif /*INPUT_H*/
