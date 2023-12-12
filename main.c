#include <stdio.h>
//int my_utf8_encode(char *input, char *output): Encoding a UTF8 string, taking as input an ASCII string, with UTF8 characters encoded using the “U+” notation, and returns a UTF8 encoded string.  For examples, see https://en.wikipedia.org/wiki/UTF-8#Encoding_process
//int my_utf8_decode(char *input, char *output): Takes a UTF8 encoded string, and returns a string, with ASCII representation where possible, and UTF8 character representation for non-ASCII characters.
//int my_utf8_check(char *string): Validates that the input string is a valid UTF8 encoded string.
//int my_utf8_strlen(char *string): Returns the number of characters in the string.
//char *my_utf8_charat(char *string, int index): Returns the UTF8 encoded character at the location specified

int my_utf8_encode(char *input, char *output){
    return 0;
}
int my_utf8_decode(char *input, char *output){
    return 0;
}

int my_utf8_check(char *string){
    return 0;
}

int my_utf8_strlen(char *string){
    return 0;
}

char *my_utf8_charat(char *string, int index){
    return "a";
}



int test() {
    printf("test\n");
    int object;
    int *ptr;
    int *ptr2;

    object = 4;
    ptr = &object;


    printf("object = %d\n", object);
    printf("ptr = %p\n", ptr);
    ptr++;
    printf("ptr after ++ = %p\n", ptr);
    ptr2 = &object;
    printf("ptr 2 = %p\n", ptr2);

    return 0;
}

int main() {
    printf("Hello, World!\n");
    test();
    return 0;

}

