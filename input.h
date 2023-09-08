#ifndef INPUT_H
#define INPUT_H

void make_buf (struct FileNames* fnames, struct Text* text);
void input_to_buf (struct FileNames* fnames, struct Text* text);
void make_array_of_ptr_to_str(struct Text* text);
void put_ptr_to_str (struct Text* text);

#endif /*INPUT_H*/
