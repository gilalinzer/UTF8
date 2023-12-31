#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



// function declarations
int utf8_strlen(char *string);
void my_strcopy(char *dest, const char *src);
char *addZeros(const char *relevant_bits, int zeroes_needed);
char* HexToBin(char* hexdec);
char* BinToHex(char* bin);
int get_num_bytes(char *string);
int my_utf8_encode(char *input , char* output);
int my_utf8_decode(char *input, char *output);
int my_utf8_check(char *string);
char *my_utf8_charat(char *string, int index);


//char *my_utf8_charat(char *string, int index): Returns the UTF8 encoded character at the location specified
char *addZeros(const char *relevant_bits, int zeroes_needed) {
    char *new_bin = (char *) malloc(utf8_strlen(relevant_bits) + 1);
    // add the zeros needed to the front of the relevant bits
    for (int i = 0; i < zeroes_needed; i++) {
        new_bin[i] = '0';
    }
    // add back the relevant bits
    for (int i = 0; i < utf8_strlen(relevant_bits); i++) {
        new_bin[i + zeroes_needed] = relevant_bits[i];
    }
    new_bin[utf8_strlen(relevant_bits) + zeroes_needed] = '\0'; // null terminate string
    return new_bin;
}

void my_strcopy(char *dest, const char *src) {
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

char* HexToBin(char* hexdec){
    int size = utf8_strlen(hexdec);
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

char* BinToHex(char* bin){
    // this function converts a binary string to a hex string
// first, add zeros to the front of the binary string so that the length is a multiple of 4
    if (utf8_strlen(bin)%4!=0){
        int zeroes_needed = 4 - utf8_strlen(bin)%4;
        char *new_bin = (char*)malloc(utf8_strlen(bin)+zeroes_needed+1);
        // add the zeros needed to the front of the relevant bits
        for (int i=0; i<zeroes_needed; i++){
            new_bin[i] = '0';
        }
        // add back the relevant bits
        for (int i=0; i<utf8_strlen(bin); i++){
            new_bin[i+zeroes_needed] = bin[i];
        }
        new_bin[utf8_strlen(bin)+zeroes_needed] = '\0'; // null terminate string
        bin = new_bin;
    }
    // now convert the binary string to a hex string
    char *hex = (char*)malloc(utf8_strlen(bin)/4+1);
    int hex_index = 0;
    for (int i=0; i<utf8_strlen(bin); i+=4) {
        // get the 4 bits
        char *four_bits = (char *) malloc(5);
        for (int j = 0; j < 4; j++) {
            four_bits[j] = bin[i + j];
        }
        four_bits[4] = '\0'; // null terminate string
        // convert the 4 bits to a hex value
        if (strcmp(four_bits, "0000") == 0) {
            hex[hex_index++] = '0';
        } else if (strcmp(four_bits, "0001") == 0) {
            hex[hex_index++] = '1';
        } else if (strcmp(four_bits, "0010") == 0) {
            hex[hex_index++] = '2';
        } else if (strcmp(four_bits, "0011") == 0) {
            hex[hex_index++] = '3';
        } else if (strcmp(four_bits, "0100") == 0) {
            hex[hex_index++] = '4';
        } else if (strcmp(four_bits, "0101") == 0) {
            hex[hex_index++] = '5';
        } else if (strcmp(four_bits, "0110") == 0) {
            hex[hex_index++] = '6';
        } else if (strcmp(four_bits, "0111") == 0) {
            hex[hex_index++] = '7';
        } else if (strcmp(four_bits, "1000") == 0) {
            hex[hex_index++] = '8';
        } else if (strcmp(four_bits, "1001") == 0) {
            hex[hex_index++] = '9';
        } else if (strcmp(four_bits, "1010") == 0) {
            hex[hex_index++] = 'A';
        } else if (strcmp(four_bits, "1011") == 0) {
            hex[hex_index++] = 'B';
        } else if (strcmp(four_bits, "1100") == 0) {
            hex[hex_index++] = 'C';
        } else if (strcmp(four_bits, "1101") == 0) {
            hex[hex_index++] = 'D';
        } else if (strcmp(four_bits, "1110") == 0) {
            hex[hex_index++] = 'E';
        } else if (strcmp(four_bits, "1111") == 0) {
            hex[hex_index++] = 'F';
        }
        free(four_bits); // free the four bits - no longer needed


    }
    hex[hex_index] = '\0'; // null terminate string
    return hex;
}
// go from unicode to UTF8
// takes an input string and returns a UTF8 encoded string
int my_utf8_encode(char *input , char* output){
    char *unicode_string;
    char *bin;
    // step 1: convert the unicode to binary

    // not a unicode string - return -1 for error
    if (input[0]!='\\' || input[1]!='u') {
        return 1;
    }



    // build a new string without the unicode prefix
    unicode_string = malloc(6);
    for (int i=0; i<utf8_strlen(input)-2; i++){
        unicode_string[i] = input[i+2];
    }
    unicode_string[utf8_strlen(input)-2] = '\0'; // null terminate string

    // make sure it has valid number of characters for a unicode string
    if (utf8_strlen(unicode_string)!=4 && utf8_strlen(unicode_string)!=5){
        return 1;
    }


    // convert the unicode string to binary
    bin = HexToBin(unicode_string);

    free(unicode_string);  // Free the unicode string - no longer needed

    // step 2 : determine number of bytes needed for the UTF8 encoding
    int num_bits = 0;
    int result_index = 0;
    // the utf encoding process may require up to an additional 11 bits
    char *relevant_bits = (char*)malloc(utf8_strlen(bin)+25);
    bool found = false;

    for (int i=0; i<utf8_strlen(bin); i++){
        // find the location of the first non-zero bit
        if (bin[i]=='1') {
            // set the number of bits if it hasn't been set yet
            if (!found){
                num_bits = utf8_strlen(bin) - i;
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
        char *new_bin = (char*)malloc(utf8_strlen(relevant_bits)+2);

        // add 0 to the front of the relevant bits
        new_bin[0] = '0';
        for (int i=1; i<utf8_strlen(relevant_bits)+1; i++){
            new_bin[i] = relevant_bits[r_bits_index++];
        }
        new_bin[utf8_strlen(relevant_bits)+2] = '\0'; // null terminate string

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
        char *new_bin = (char*)malloc(utf8_strlen(relevant_bits)+6);

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
        new_bin[utf8_strlen(new_bin)+1] = '\0'; // null terminate string
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
        char *new_bin = (char*)malloc(utf8_strlen(relevant_bits)+9);
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
        new_bin[utf8_strlen(new_bin)+1] = '\0'; // null terminate string

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
        char *new_bin = (char*)malloc(utf8_strlen(relevant_bits)+12);
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
        new_bin[utf8_strlen(new_bin)] = '\0'; // null terminate string
        printf("UTF8 binary string is %s\n", new_bin);
        free(relevant_bits);  // Free the relevant bits - no longer needed
        relevant_bits = new_bin;
    }




    // convert the new binary to hex
    char* hex = BinToHex(relevant_bits);
    free(relevant_bits);  // Free the relevant bits - no longer needed
    // Null terminate the hex string
    hex[utf8_strlen(hex)] = '\0';
    // Copy the result string to the output parameter using my str copy function
    my_strcopy(output, hex);
    // free(hex);  // Free the hex string - no longer needed
    return 0;
}

// go from utf8 to unicode - takes a UTF8 encoded string and returns a unicode string
int my_utf8_decode(char *input, char *output){
    // allocate space for unicode string
    char *unicode = (char*)malloc(9);
    // step one - convert the hex to binary
    char *bin = HexToBin(input);


    // step two - determine the number of bytes used
    int num_bytes = utf8_strlen(bin)/8;

    // step three - get the relevant bits from the binary string - removing the bits added for the UTF8 encoding
    char *relevant_bits = (char*)malloc(64);
    int r_bits_index = 0;
    // 1 byte: 0xxxxxxx
    if (num_bytes==1) {
        // get all the bits from the binary string except the first 0
        for (int i = 1; i < utf8_strlen(bin); i++) {
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
        if (utf8_strlen(hex)<4){
            int zeroes_needed = 4 - utf8_strlen(hex);
            for (int i=2; i<2+zeroes_needed; i++){
                unicode[i] = '0';
            }
            int hex_index = 0;
            for (int i=2+zeroes_needed; i<6; i++){
                unicode[i] = hex[hex_index++];
            }
            unicode[6] = '\0'; // null terminate string
        }
        else{
            int hex_index = 0;
            for (int i=2; i<6; i++){
                unicode[i] = hex[hex_index++];
            }
            unicode[6] = '\0'; // null terminate string
        }



    // copy the unicode string to the output parameter
    strcpy(output, unicode);

    free(unicode);  // Free the unicode string - no longer needed

    return 0;
}

int my_utf8_check(char *string){
    return 0;
}

// helper function to find the number of bytes of a UTF8 character
int get_num_bytes(char *string){
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

int utf8_strlen(char *string) {
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

char *my_utf8_charat(char *string, int index){
    // get the length of the string using the function above
    int length = utf8_strlen(string);
    // if the index is greater than the length of the string or less than 0 - return null
    if (index>length || index<0){
        return NULL;
    }


    return "a";
}

int main() {
    unsigned char *str1 = "\\u0418";
    unsigned char *str2 = "D098";
    int max_output = 8;

    // allocate memory for the output and pass in a pointer to the memory
    char* out = (char*)malloc(max_output+1);

    my_utf8_encode(str1,out);

    printf("Output for encoding: %s\n",out );

    char *output2 = (char*)malloc(max_output+1);

    my_utf8_decode(str2,output2);
    printf("Output for decoding: %s\n",output2 );



    return 0;
}

