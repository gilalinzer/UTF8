#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



// figure out number of bytes based on first chars of encoding
// take the relevant bits
// convert to hex and return
//int my_utf8_decode(char *input, char *output): Takes a UTF8 encoded string, and returns a string, with ASCII representation where possible, and UTF8 character representation for non-ASCII characters.

//int my_utf8_check(char *string): Validates that the input string is a valid UTF8 encoded string.
//int my_utf8_strlen(char *string): Returns the number of characters in the string.
//char *my_utf8_charat(char *string, int index): Returns the UTF8 encoded character at the location specified
void printString(char *prefix, unsigned char *string, int length) {
    printf("printing out characters for string %s\n", prefix);
    for (int i = 0; i < length; i++) {
        printf("  %s: location %d, char=0x%x\n", prefix, i, string[i]);
        // Print binary representation of string by getting each of the 8 bytes in the char
        for (int j = 7; j >= 0; j--) {
            printf("%d", (string[i] >> j) & 1);
        }
        printf("\n");
    }


    printf("\n");
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

char* HexToBin(char* hexdec){
    int size = strlen(hexdec);
    char* result = (char*)malloc(size * 4 + 1);

    if (result == NULL) {
        fprintf(stderr, "Memory allocation error in HexToBin function\n");
        exit(EXIT_FAILURE);
    }

    int result_index = 0;

// loop through each character and convert to 4 binary digits
    for (int i=0; i< size; i++){
        switch (hexdec[i]) {
            case '0':
                // add each binary values to the char
                for (int j=0; j<4; j++){
                    result[result_index++] = '0';
                }
                break;

            case '1':
                // here making the value 0001 and adding it to the char
                for (int j=0; j<4; j++){
                    if (j<3){
                        result[result_index++] = '0';
                    }
                    else{
                        result[result_index++] = '1';
                    }

                }
                break;
            case '2':
                // here making the value 0010 and adding it to the char
                for (int j=0; j<4; j++){
                    if (j<2 || j==3){
                        result[result_index++] = '0';
                    }
                    else{
                        result[result_index++] = '1';
                    }

                }
                break;
            case '3':
                // here making the value 0011 and adding it to the char
                for (int j=0; j<4; j++){
                    if (j<2){
                        result[result_index++] = '0';
                    }
                    else{
                        result[result_index++] = '1';
                    }

                }
                break;
                case '4':
                    // here making the value 0100 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==0 || j==2 || j==3){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case '5':
                    // here making the value 0101 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==0 || j==2){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case '6':
                    // here making the value 0110 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==0 || j==3){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case '7':
                    // here making the value 0111 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==0){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case '8':
                    // here making the value 1000 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j>0){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case '9':
                    // here making the value 1001 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==1 || j==2){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'A':
                    // here making the value 1010 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==1 || j==3){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'B':
                    // here making the value 1011 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==1){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'C':
                    // here making the value 1100 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==2 || j==3){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'D':
                    // here making the value 1101 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==2){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'E':
                    // here making the value 1110 and adding it to the char
                    for (int j=0; j<4; j++){
                        if (j==3){
                            result[result_index++] = '0';
                        }
                        else{
                            result[result_index++] = '1';
                        }

                    }
                break;
                case 'F':
                    // here making the value 1111 and adding it to the char
                    for (int j=0; j<4; j++){
                        result[result_index++] = '1';
                    }
                break;



        }
    }
    result[result_index] = '\0'; // null terminate string
    return result;
}

// go from unicode to UTF8
// takes an input string and returns a UTF8 encoded string
int my_utf8_encode(char *input, char *output){
    char *unicode_string;
    char *bin;
    // step 1: convert the unicode to binary

    // not a unicode string - return -1 for error
    if (input[0]!='\\' || input[1]!='u') {
        return -1;
    }
    else{
        // build a new string without the unicode prefix
        unicode_string = malloc(sizeof(char)*strlen(input)-2);
        for (int i=0; i<strlen(input)-2; i++){
            unicode_string[i] = input[i+2];
        }
        printf("unicode string is %s\n", unicode_string);


    }
    // convert the unicode string to binary
    bin = HexToBin(unicode_string);
    printf("bin is %s\n", bin);
    free(unicode_string);  // Free the unicode string - no longer needed

    // step 2 : determine number of bytes needed for the UTF8 encoding
    int num_bits = 0;
    int result_index = 0;
    char *relevant_bits = (char*)malloc(strlen(bin)+1);
    bool found = false;
    for (int i=0; i<strlen(bin); i++){
        // find the location of the first non-zero bit
        if (bin[i]=='1') {
            num_bits = strlen(bin) - i;
            found = true;
        }
        // start a new string of relevant bits once the start has been found
        if (found) {
            relevant_bits[result_index++] = bin[i];
        }

    }


    // step 3: map the bits to the template for the UTF8 encoding



    // convert the new binary to hex

    return 0;
}
int main() {
    unsigned char *str1 = "\\u56A0";
    unsigned char *str2 = "u56A0";

    unsigned char *output = (unsigned char*)malloc(sizeof(unsigned char) * 256); // Allocate memory for the output

    if (output == NULL) {
        fprintf(stderr, "Memory allocation error for output\n");
        return EXIT_FAILURE;
    }

    // Initialize output to an empty string
    output[0] = '\0';


    int result = my_utf8_encode(str1, output);

    // Use result variable to avoid the "unused variable" warning
    printf("Result: %d\n", result);

    free(output);  // Free the allocated memory for output

    return 0;
}

