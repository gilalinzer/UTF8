#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



// function declarations
int utf8_strlen(unsigned char *string);
void my_strcopy(unsigned char *dest, unsigned char *src);
unsigned char *addZeros(unsigned char *relevant_bits, int zeroes_needed);
unsigned char* HexToBin(unsigned char* hexdec);
unsigned char* BinToHex(unsigned char* bin);
void hexStringToBytes(unsigned char* hexString, unsigned char* bytes);
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


//char *my_utf8_charat(char *string, int index): Returns the UTF8 encoded character at the location specified
unsigned char *addZeros(unsigned char *relevant_bits, int zeroes_needed) {
    char *new_bin = (char *) malloc(my_standard_strlen(relevant_bits) + 1);
    // add the zeros needed to the front of the relevant bits
    for (int i = 0; i < zeroes_needed; i++) {
        new_bin[i] = '0';
    }
    // add back the relevant bits
    for (int i = 0; i < my_standard_strlen(relevant_bits); i++) {
        new_bin[i + zeroes_needed] = relevant_bits[i];
    }
    new_bin[my_standard_strlen(relevant_bits) + zeroes_needed] = '\0'; // null terminate string
    return new_bin;
}

void my_strcopy(unsigned char *dest, unsigned char *src) {
    // Check for NULL pointers or invalid input
    if (dest == NULL || src == NULL) {
        return;
    }

    // Copy characters until null terminator is encountered
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // terminate the destination string
    *dest = '\0';
}

void printString(unsigned char *prefix, unsigned char *string, int length) {
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

unsigned char* HexToBin(unsigned char* hexdec){
    int size = my_standard_strlen(hexdec);
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
            case 'a':
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
                case 'b':
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
                case 'c':
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
                case 'd':
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
                case 'e':
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
                case 'f':
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

unsigned char* BinToHex(unsigned char* bin){
    // this function converts a binary string to a hex string
// first, add zeros to the front of the binary string so that the length is a multiple of 4
    if (my_standard_strlen(bin)%4!=0){
        int zeroes_needed = 4 - my_standard_strlen(bin)%4;
        char *new_bin = (char*)malloc(my_standard_strlen(bin)+zeroes_needed+1);
        // add the zeros needed to the front of the relevant bits
        for (int i=0; i<zeroes_needed; i++){
            new_bin[i] = '0';
        }
        // add back the relevant bits
        for (int i=0; i<my_standard_strlen(bin); i++){
            new_bin[i+zeroes_needed] = bin[i];
        }
        new_bin[my_standard_strlen(bin)+zeroes_needed] = '\0'; // null terminate string
        bin = new_bin;
    }
    // now convert the binary string to a hex string
    char *hex = (char*)malloc(my_standard_strlen(bin)/4+1);
    int hex_index = 0;
    for (int i=0; i<my_standard_strlen(bin); i+=4) {
        // get the 4 bits
        char *four_bits = (char *) malloc(5);
        for (int j = 0; j < 4; j++) {
            four_bits[j] = bin[i + j];
        }
        four_bits[4] = '\0'; // null terminate string
        // convert the 4 bits to a hex value
        if (my_utf8_strcmp(four_bits, "0000") == 0) {
            hex[hex_index++] = '0';
        } else if (my_utf8_strcmp(four_bits, "0001") == 0) {
            hex[hex_index++] = '1';
        } else if (my_utf8_strcmp(four_bits, "0010") == 0) {
            hex[hex_index++] = '2';
        } else if (my_utf8_strcmp(four_bits, "0011") == 0) {
            hex[hex_index++] = '3';
        } else if (my_utf8_strcmp(four_bits, "0100") == 0) {
            hex[hex_index++] = '4';
        } else if (my_utf8_strcmp(four_bits, "0101") == 0) {
            hex[hex_index++] = '5';
        } else if (my_utf8_strcmp(four_bits, "0110") == 0) {
            hex[hex_index++] = '6';
        } else if (my_utf8_strcmp(four_bits, "0111") == 0) {
            hex[hex_index++] = '7';
        } else if (my_utf8_strcmp(four_bits, "1000") == 0) {
            hex[hex_index++] = '8';
        } else if (my_utf8_strcmp(four_bits, "1001") == 0) {
            hex[hex_index++] = '9';
        } else if (my_utf8_strcmp(four_bits, "1010") == 0) {
            hex[hex_index++] = 'A';
        } else if (my_utf8_strcmp(four_bits, "1011") == 0) {
            hex[hex_index++] = 'B';
        } else if (my_utf8_strcmp(four_bits, "1100") == 0) {
            hex[hex_index++] = 'C';
        } else if (my_utf8_strcmp(four_bits, "1101") == 0) {
            hex[hex_index++] = 'D';
        } else if (my_utf8_strcmp(four_bits, "1110") == 0) {
            hex[hex_index++] = 'E';
        } else if (my_utf8_strcmp(four_bits, "1111") == 0) {
            hex[hex_index++] = 'F';
        }
        free(four_bits); // free the four bits - no longer needed


    }
    hex[hex_index] = '\0'; // null terminate string
    return hex;
}

// Function to convert a hexadecimal string to an array of bytes
void hexStringToBytes(unsigned char* hexString, unsigned char* bytes) {
    size_t len = my_standard_strlen(hexString);

    if (len % 2 != 0) {
        fprintf(stderr, "Error: Hex string length must be even.\n");
        return;
    }

    size_t byteLen = len / 2;

    for (size_t i = 0; i < byteLen; i++) {
        // get the two hex values for the byte and store them in a char array
        char hexPair[3] = {hexString[i*2], hexString[i*2+ 1], '\0'};
        // covert the hex pair to a byte with proper formatting and store it in the bytes array
        sscanf(hexPair, "%2hhX", &bytes[i]);

    }
}

// Helper function for encode - go from unicode to UTF8 for a single point
int encode_single_point(unsigned char *input , unsigned char* output){
    char *unicode_string;
    char *bin;
    // step 1: convert the unicode to binary

    // not a unicode string - return -1 for error
    if (input[0]!='\\' || input[1]!='u') {
        return 1;
    }



    // build a new string without the unicode prefix
    unicode_string = malloc(6);
    for (int i=0; i<my_standard_strlen(input)-2; i++){
        unicode_string[i] = input[i+2];
    }
    unicode_string[my_standard_strlen(input)-2] = '\0'; // null terminate string

    // make sure it has valid number of characters for a unicode string
    if (my_standard_strlen(unicode_string)!=4 && my_standard_strlen(unicode_string)!=5){
        return 1;
    }



    // convert the unicode string to binary
    bin = HexToBin(unicode_string);

    free(unicode_string);  // Free the unicode string - no longer needed

    // step 2 : determine number of bytes needed for the UTF8 encoding
    int num_bits = 0;
    int result_index = 0;
    // the utf encoding process may require up to an additional 11 bits
    char *relevant_bits = (char*)malloc(my_standard_strlen(bin)+25);
    bool found = false;

    for (int i=0; i<my_standard_strlen(bin); i++){
        // find the location of the first non-zero bit
        if (bin[i]=='1') {
            // set the number of bits if it hasn't been set yet
            if (!found){
                num_bits = my_standard_strlen(bin) - i;
            }
            found = true;
        }
        // start a new string of relevant bits once the start has been found
        if (found) {
            relevant_bits[result_index++] = bin[i];
        }

    }



    // step 3: map the bits to the template for the UTF8 encoding
    int one_byte_max = 7; // 1 byte: 0xxxxxxx
    int two_byte_max = 11; // 2 bytes: 110xxxxx 10xxxxxx
    int three_byte_max = 16; // 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
    int four_byte_max = 21; // 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

    int num_bytes;

    if (num_bits <= one_byte_max) {
        num_bytes = 1;
    }
    else if (num_bits <= two_byte_max) {
        num_bytes = 2;
    }
    else if (num_bits <= three_byte_max) {
        num_bytes = 3;
    }
    else if (num_bits <= four_byte_max) {
        num_bytes = 4;
    }




    // 1 byte: 0xxxxxxx
    if (num_bytes==1) {
        // add zeros to the front of the relevant bits based on the number of bytes
        int zeroes_needed = one_byte_max - num_bits;
        relevant_bits = addZeros(relevant_bits, zeroes_needed);


        int r_bits_index = 0;
        // allocate space for the new binary string with the UTF8 encoding which will be 1 bit longer
        char *new_bin = (char*)malloc(my_standard_strlen(relevant_bits)+2);

        // add 0 to the front of the relevant bits
        new_bin[0] = '0';
        for (int i=1; i<my_standard_strlen(relevant_bits)+1; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        new_bin[my_standard_strlen(relevant_bits)+2] = '\0'; // null terminate string

        free(relevant_bits);  // Free the relevant bits - no longer needed
        relevant_bits = new_bin;

    }
    // 2 bytes: 110xxxxx 10xxxxxx
    else if (num_bytes==2){

        int zeroes_needed = two_byte_max - num_bits;
        int r_bits_index = 0;

        // add zeros needed to front of relevant bits
        relevant_bits = addZeros(relevant_bits, zeroes_needed);

        // allocate space for the new binary string with the UTF8 encoding which will be 5 bits longer
        char *new_bin = (char*)malloc(my_standard_strlen(relevant_bits)+6);

        // add 110 to the front of the relevant bits and 10 to the front of the last 6 bits

        new_bin[0] = '1';
        new_bin[1] = '1';
        new_bin[2] = '0';
        // add the first 5 bits
        for (int i=3; i<8; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the last 6 bits
        new_bin[8] = '1';
        new_bin[9] = '0';
        // add the last 6 bits
        for (int i=10; i<16; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        new_bin[my_standard_strlen(new_bin)+1] = '\0'; // null terminate string
        free(relevant_bits);  // Free the relevant bits - no longer needed
        relevant_bits = new_bin;

    }
    // 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
    else if (num_bytes==3){
        // add zeroes to the front
        int zeroes_needed = three_byte_max - num_bits;
        relevant_bits = addZeros(relevant_bits, zeroes_needed);

        // keep track of the index of the relevant bits
        int r_bits_index = 0;


        // add 1110 to the front of the first 4 relevant bits
        char *new_bin = (char*)malloc(my_standard_strlen(relevant_bits)+9);
        new_bin[0] = '1';
        new_bin[1] = '1';
        new_bin[2] = '1';
        new_bin[3] = '0';
        // add the first 4 bits
        for (int i=4; i<8; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the next 6 bits
        new_bin[8] = '1';
        new_bin[9] = '0';
        // add the next 6 bits
        for (int i=10; i<16; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the last 6 bits
        new_bin[16] = '1';
        new_bin[17] = '0';
        // add the last 6 bits
        for (int i=18; i<24; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        new_bin[my_standard_strlen(new_bin)+1] = '\0'; // null terminate string

        free(relevant_bits);  // Free the relevant bits - no longer needed
        relevant_bits = new_bin;
    }

    // 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    else if (num_bytes==4){
        // add zeroes to the front
        int zeroes_needed = four_byte_max - num_bits;
        relevant_bits = addZeros(relevant_bits, zeroes_needed);


        // keep track of the index of the relevant bits
        int r_bits_index = 0;


        // add 11110 to the front of the first 3 relevant bits
        char *new_bin = (char*)malloc(my_standard_strlen(relevant_bits)+12);
        new_bin[0] = '1';
        new_bin[1] = '1';
        new_bin[2] = '1';
        new_bin[3] = '1';
        new_bin[4] = '0';
        // add the first 3 bits
        for (int i=5; i<8; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the next 6 bits
        new_bin[8] = '1';
        new_bin[9] = '0';
        // add the next 6 bits
        for (int i=10; i<16; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the next 6 bits
        new_bin[16] = '1';
        new_bin[17] = '0';
        // add the next 6 bits
        for (int i=18; i<24; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        // add 10 to the front of the last 6 bits
        new_bin[24] = '1';
        new_bin[25] = '0';
        // add the last 6 bits
        for (int i=26; i<32; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        new_bin[my_standard_strlen(new_bin)] = '\0'; // null terminate string
        free(relevant_bits);  // Free the relevant bits - no longer needed
        relevant_bits = new_bin;
    }




    // convert the new binary to hex
    char* hex = BinToHex(relevant_bits);
    free(relevant_bits);  // Free the relevant bits - no longer needed
    // Null terminate the hex string
    hex[my_standard_strlen(hex)] = '\0';

    // Copy the result string to the output parameter using my str copy function
    my_strcopy(output, hex);


    return 0;
}

// Function to encode multiple Unicode points into a combined UTF-8 string
int my_utf8_encode(char *input, char *output) {
    // Assuming input is a string containing multiple Unicode points with no spaces
    // loop through the string and encode each point
    // pointer to be used later when converting to an array of bytes
    char* output_String = (char*)malloc(my_standard_strlen(input) * 4 + 1);
    char* front_of_output_string = output_String;
    while (*input!='\0') {

        if (input[0] != '\\' && input[1] != 'u') {
            // if it's not a unicode point, just add it to the output string
            *output_String = *input;
            output_String++;
            input++;

        }
        // otherwise if is a unicode point - get the next 6 characters
        if (input[0] == '\\' && input[1] == 'u') {
            char *point = (char *) malloc(7);
            for (int i = 0; i < 6; i++) {
                point[i] = input[i];
            }
            // check the next character - it could be the unicode has 7 characters
            // if it's a slash or space the unicode has 6 characters and is done
            if (input[6] == '\\' || input[6] == ' ') {
                point[6] = '\0'; // null terminate string
                // encode the point and add it to the output string
                char* hex_String = (char*)malloc(my_standard_strlen(point) * 2 + 1);
                char* front_of_hexstring = hex_String;
                encode_single_point(point, hex_String);
                // Convert the hex string to an array of bytes
                // Passing in a pointer to the front of the hex string that was saved in front_of_output_string earlier
                // the array will be written to the output parameter

                // increment the hex string pointer to the next location
                hex_String += my_standard_strlen(hex_String)+1;
                // Convert the hexadecimal string to bytes
                hexStringToBytes(front_of_hexstring, hex_String);

                // Null-terminate the array
                hex_String[my_standard_strlen(hex_String)+1] = '\0';

                // copy the hex string to the output string
                my_strcopy(output_String, hex_String);

                // move the pointer to the next location
                output_String += my_standard_strlen(output_String)+1;

                // move to the next point - 6 characters ahead
                input += 6;
            } else {
                // if it's not a slash, the unicode has 7 characters
                point[6] = input[6];
                point[7] = '\0'; // null terminate string
                char* hex_String = (char*)malloc(32);
                char* front_of_hexstring = hex_String;
                encode_single_point(point, hex_String);
                // Convert the hex string to an array of bytes
                // Passing in a pointer to the front of the hex string that was saved in front_of_output_string earlier
                // the array will be written to the output parameter

                // increment the hex string pointer to the next location
                hex_String += my_standard_strlen(hex_String)+1;
                // Convert the hexadecimal string to bytes
                hexStringToBytes(front_of_hexstring, hex_String);

                // Null-terminate the array and this time using the standard strlen because this might be utf8 encoded
                hex_String[my_standard_strlen(hex_String)+1] = '\0';

                // copy the hex string to the output string
                my_strcopy(output_String, hex_String);

                // move the pointer to the next location
                output_String += my_standard_strlen(output_String)+3;
                // move to the next point - 7 characters ahead
                input += 7;
            }

            free(point);  // Free the point - no longer needed

        }
    }
    // Null-terminate the output string
    output_String[my_standard_strlen(output_String)+1] = '\0';

    my_strcopy(output, front_of_output_string);


    return 0;

}

// Helper function for decode
// Goes from utf8 to unicode - takes a singular UTF8 encoded char and returns a unicode point
int utf8HexToUnicode(unsigned char *input, unsigned char *output){
    // allocate space for unicode string
    char *unicode = (char*)malloc(9);
    // step one - convert the hex to binary
    // transform the input string into a string of it's hex values to be converted to binary
    char *hex_string = (char*)malloc(get_num_bytes(input)*2+1);
    int bytes = get_num_bytes(input);
    // loop through the bytes of the input string
    for(int i =0; i< bytes;i++){
        // get the hex format of the byte and store it using snprintf
        // * 2 - since each byte is 2 hex characters
        // %02X - format specifier for hex the 2 means no more than 2 characters
        snprintf(hex_string+i*2, 3, "%2X", input[i]);
    }
    hex_string[get_num_bytes(input)*2+1] = '\0'; // null terminate string


    // pass that hex string into the HexToBin function to get the binary string

    char *bin = HexToBin(hex_string);


    // step two - determine the number of bytes used
    int num_bytes = my_standard_strlen(bin)/8;

    // step three - get the relevant bits from the binary string - removing the bits added for the UTF8 encoding
    char *relevant_bits = (char*)malloc(64);
    int r_bits_index = 0;
    // 1 byte: 0xxxxxxx
    if (num_bytes==1) {
        // get all the bits from the binary string except the first 0
        for (int i = 1; i < my_standard_strlen(bin); i++) {
            relevant_bits[r_bits_index++] = bin[i];
        }
    }
    // 2 bytes: 110xxxxx 10xxxxxx
    else if (num_bytes==2){
        // get the first 5 bits
        for (int i=3; i<8; i++){
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the last 6 bits
        for (int i=10; i<16; i++){
            relevant_bits[r_bits_index++] = bin[i];
        }
    }
    // 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
    else if (num_bytes==3){
        // get the first 4 bits
        for (int i=4; i<8; i++){
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the next 6 bits
        for (int i=10; i<16; i++){
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the last 6 bits
        for (int i=18; i<24; i++){
            relevant_bits[r_bits_index++] = bin[i];
        }
    }
    // 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    else if (num_bytes==4) {
        // get the first 3 bits
        for (int i = 5; i < 8; i++) {
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the next 6 bits
        for (int i = 10; i < 16; i++) {
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the next 6 bits
        for (int i = 18; i < 24; i++) {
            relevant_bits[r_bits_index++] = bin[i];
        }
        // get the last 6 bits
        for (int i = 26; i < 32; i++) {
            relevant_bits[r_bits_index++] = bin[i];
        }
    }

        // convert the relevant bits to hex
        char *hex = BinToHex(relevant_bits);
        free(relevant_bits);  // Free the relevant bits - no longer needed
        // add the unicode prefix to the hex string and add zeroes if needed
        unicode[0] = '\\';
        unicode[1] = 'u';
        // if the hex string is less than 4 characters, add zeroes to the front
        if (my_standard_strlen(hex)<4){
            int zeroes_needed = 4 - my_standard_strlen(hex);
            for (int i=2; i<2+zeroes_needed; i++){
                unicode[i] = '0';
            }
            int hex_index = 0;
            for (int i=2+zeroes_needed; i<6; i++){
                unicode[i] = hex[hex_index++];
            }
            unicode[6] = '\0'; // null terminate string
        }

        else if (my_standard_strlen(hex)==4){
            int hex_index = 0;
            for (int i=2; i<6; i++){
                unicode[i] = hex[hex_index++];
            }
            unicode[6] = '\0'; // null terminate string
        }
        else if (my_standard_strlen(hex)==5) {
            int hex_index = 0;
            for (int i = 2; i < 7; i++) {
                unicode[i] = hex[hex_index++];
            }
            unicode[7] = '\0'; // null terminate string
        }
        // could have a leading zero - check for this
        else if (my_standard_strlen(hex)==6){
            if (hex[0]=='0') {
                int hex_index = 1;
                for (int i = 2; i < 8; i++) {
                    unicode[i] = hex[hex_index++];
                }
            }
            else{
                return -1;
            }
        }

        else{
            return -1;
        }

    // copy the unicode string to the output parameter
    my_strcopy(output, unicode);

    free(unicode);  // Free the unicode string - no longer needed

    return 0;
}

// this function takes in a whole utf8 hex string and returns the unicode points for each character
// Function to decode multiple UTF-8 hex values
// Function to decode multiple UTF-8 encoded points
int my_utf8_decode(unsigned char *input, unsigned char *output) {
    while (*input != '\0') {
        // get the number of bytes for the character
        int num_bytes = get_num_bytes(input);
        // if the number of bytes is -1, there was an error
        if (num_bytes == -1) {
            return -1;
        }
        // if the number of bytes is 1, the character is ascii
        else if (num_bytes == 1) {
            // copy the current character to the output string
            *output = *input;
            // move the output pointer
            output += my_standard_strlen(output);
            // increment the input pointer one byte
            input++;
        }
        // if the number of bytes is greater than 1, the character is UTF8 and we need to decode it to unicode
        else {
            // allocate space for the hex string
            char *hex = (char *) malloc(9);
            // get the hex string for the character
            for (int i = 0; i < num_bytes; i++) {
                hex[i] = input[i];
            }
            hex[num_bytes] = '\0'; // null terminate string
            // decode the hex string to unicode
            utf8HexToUnicode(hex, output);
            // move the output pointer
            output += my_standard_strlen(output);
            // increment the input pointer
            input += num_bytes;
            // free the hex string - no longer needed
            free(hex);
        }

    }

    return 0;
}

// This function takes in a string and returns 0 if it is valid UTF8 and 1 if it is not
int my_utf8_check(unsigned char *string){
    // loop through the string
    while (*string!='\0'){
        // get the number of bytes for the character
        //this function will check the first byte of the character and return the number of bytes
        int num_bytes = get_num_bytes(string);
        // if the number of bytes is -1, there was an error with the first byte and it's not utf8
        if (num_bytes == -1) {
            return 1;
        }
        // if the number of bytes is 1, the character is ascii
        else if (num_bytes == 1) {
            // that character is valid since it was already checked  by num_bytes that it started with a 0 and not a 1
            // increment the input pointer one byte
            string++;
        }
        else if (num_bytes == 2){
            // check that the next byte starts with 10
            if ((string[1] & 0b11000000) != 0b10000000){
                return 1;
            }
            else{
                // increment the input pointer two bytes
                string += 2;
            }
        } else if (num_bytes == 3){
            // check that the next two bytes start with 10
            if ((string[1] & 0b11000000) != 0b10000000 || (string[2] & 0b11000000) != 0b10000000){
                return 1;
            }
            else{
                // increment the input pointer three bytes
                string += 3;
            }
        } else if (num_bytes == 4){
            // check that the next three bytes start with 10
            if ((string[1] & 0b11000000) != 0b10000000 || (string[2] & 0b11000000) != 0b10000000 || (string[3] & 0b11000000) != 0b10000000){
                return 1;
            }
            else{
                // increment the input pointer four bytes
                string += 4;
            }

        }
    }
    // if we got through the string without returning 1, it's valid utf8 so return 0 for success
    return 0;
}

// Function to find the number of bytes of a UTF8 character using bitwise math
int get_num_bytes(unsigned char *string){
    // if the highest bit of the byte is zero - it's a single byte character
    if ((*string & 0b10000000) == 0) {
        return 1;
        // if the highest 3 bits of the byte are 110 - it's a two byte character
    } else if ((*string & 0b11100000) == 0b11000000) {
        return 2;
        // if the highest 4 bits of the byte are 1110 - it's a three byte character
    } else if ((*string & 0b11110000) == 0b11100000) {
        return 3;
        // if the highest 5 bits of the byte are 11110 - it's a four byte character
    } else if ((*string & 0b11111000) == 0b11110000) {
        return 4;
    } else {
        // Invalid UTF-8 sequence
        return -1;
    }
}

// utf8 version of strlen that will count utf8 characters as 1 character
int utf8_strlen(unsigned char *string) {
    int length = 0;

    while (*string != '\0') {
        // if the highest bit of the byte is zero - it's a single byte character
        if ((*string & 0b10000000) == 0) {
            length++;
            // move to the next byte
            string++;
        // if the highest 3 bits of the byte are 110 - it's a two byte character
        } else if ((*string & 0b11100000) == 0b11000000) {
            // Two-byte character
            length++;
            // move two bytes ahead
            string += 2;
        // if the highest 4 bits of the byte are 1110 - it's a three byte character
        } else if ((*string & 0b11110000) == 0b11100000) {
            // Three-byte character
            length++;
            string += 3;
        // if the highest 5 bits of the byte are 11110 - it's a four byte character
        } else if ((*string & 0b11111000) == 0b11110000) {
            // Four-byte character
            length++;
            string += 4;
        } else {
            // Invalid UTF-8 sequence
            return -1;
        }
    }

    return length;
}
// standard strlen created by me since we can't use the built in one
int my_standard_strlen(unsigned char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

// Returns whether the two strings are the same (similar result set to my_utf8_strcmp() )
int my_utf8_strcmp(unsigned char *string1, unsigned char *string2){
    // Returns whether the two strings are the same (similar result set to my_utf8_strcmp() )
    // loop through the strings and compare each byte
    while (*string1!='\0' && *string2!='\0'){
        // if the bytes are not the same, return 1
        if (*string1!=*string2){
            return 1;
        }
        // otherwise, increment the pointers
        string1++;
        string2++;
    }
    // if the strings are the same length, return 0
    if (*string1=='\0' && *string2=='\0'){
        return 0;
    }
    // otherwise, return 1
    else{
        return 1;
    }
}

// This returns a pointer to the character at the index - counting a utf8 character as one character
unsigned char *my_utf8_charat(unsigned char *string, int index){
    // get the length of the utf8 string
    int length = my_standard_strlen(string);
    // if the index is greater than the length of the string or less than 0 - return null
    if (index>length || index<0){
        return NULL;
    }
    // otherwise - increment the pointer and keep track of chars encountered until the index is reached
    int chars_encountered = 0;
    while (chars_encountered<index){
        // if the highest bit of the byte is zero - it's a single byte character
        if ((*string & 0b10000000) == 0) {
            chars_encountered++;
            // move to the next byte
            string++;
            // if the highest 3 bits of the byte are 110 - it's a two byte character
        } else if ((*string & 0b11100000) == 0b11000000) {
            // Two-byte character
            chars_encountered++;
            // move two bytes ahead
            string += 2;
            // if the highest 4 bits of the byte are 1110 - it's a three byte character
        } else if ((*string & 0b11110000) == 0b11100000) {
            // Three-byte character
            chars_encountered++;
            string += 3;
            // if the highest 5 bits of the byte are 11110 - it's a four byte character
        } else if ((*string & 0b11111000) == 0b11110000) {
            // Four-byte character
            chars_encountered++;
            string += 4;
        }
    }

    // once the loop has been exited - the pointer is now pointing to the start of the character at the index
    // return the pointer
    return string;
}

// This creative function takes in a string and returns the number of utf8 characters (non-ascii) in the string
int count_utf8_chars(unsigned char* string){
    // get the length of the string
    int length = my_standard_strlen(string);
    int result = 0;
    // get the number of bytes in the string
    int num_bytes = get_num_bytes(string);
    if (num_bytes == -1){
        return -1;
    }
    // if there is exactly the same number of bytes as the length, each character is a single byte character
    // this means there are no utf8 characters in the string so return 0
    else if (num_bytes == length){
        return result;
    }

    // loop through the string to find the utf8 characters
    while (*string != '\0') {
        if ((*string & 0b10000000) == 0) {
            // it's an ascii character - move to the next byte
            string++;
            // if the highest 3 bits of the byte are 110 - it's a two byte character
        } else if ((*string & 0b11100000) == 0b11000000) {
            // Two-byte character
            result++;
            // move two bytes ahead
            string += 2;
            // if the highest 4 bits of the byte are 1110 - it's a three byte character
        } else if ((*string & 0b11110000) == 0b11100000) {
            // Three-byte character
            result++;
            string += 3;
            // if the highest 5 bits of the byte are 11110 - it's a four byte character
        } else if ((*string & 0b11111000) == 0b11110000) {
            // Four-byte character
            result++;
            string += 4;
        }
    }
        return result;
}

// This creative function takes in a char pointer and returns a pointer to the next utf8 character in the string
unsigned char* next_utf8_char(unsigned char* character){
    // get the number of bytes for the character
    int num_bytes = get_num_bytes(character);
    // if the number of bytes is -1, there was an error
    if (num_bytes == -1) {
        return NULL;
    }
    // if the number of bytes is 1, the character is ascii
    else if (num_bytes == 1) {
        // increment the input pointer one byte
        character++;
    }
        // if the number of bytes is greater than 1, the increment the pointer by the number of bytes
    else {
        // increment the input pointer
        character += num_bytes;
    }
    return character;
}

