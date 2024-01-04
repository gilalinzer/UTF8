

#ifndef UTF8_MAIN_H
#define UTF8_MAIN_H
// function declarations
int utf8_strlen(unsigned char *string);
void my_strcopy(unsigned char *dest, unsigned char *src);
unsigned char *addZeros(unsigned char *relevant_bits, int zeroes_needed);
unsigned char* HexToBin(unsigned char* hexdec);
unsigned char* BinToHex(unsigned char* bin);
int hexStringToBytes(unsigned char* hexString, unsigned char* bytes);
int get_num_bytes(unsigned char *string);
int my_utf8_decode(unsigned char *input, unsigned char *output);
int encode_single_point(unsigned char *input , unsigned char* output);
int utf8HexToUnicode(unsigned char *input, unsigned char *output);
int my_standard_strlen(unsigned char *str);
int my_utf8_strcmp(unsigned char *string1, unsigned char *string2);
int count_utf8_chars(unsigned char* string);
int my_utf8_check(unsigned char *string);
unsigned char *my_utf8_charat(unsigned char *string, int index);
int my_utf8_encode(char *input, char *output);
unsigned char *next_utf8_char(unsigned char *string);
unsigned char* reverse_utf8_string(unsigned char *string);


#endif //UTF8_MAIN_H
