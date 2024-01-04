#include <assert.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void test_utf8_strlen(unsigned char* string, int expected) {
    int actual = utf8_strlen(string);
    printf("utf8_strlen test %s: string=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void test_my_strcopy(unsigned char* dest, unsigned char* src, unsigned char* expected) {
    my_strcopy(dest, src);
    printf("my_strcopy test %s: dest=%s, src=%s, expected=%s\n",
           (!my_utf8_strcmp(expected,src) ? "PASSED" : "FAILED"),
           dest, src, expected);
}

void test_addZeros(unsigned char* relevant_bits, int zeroes_needed, unsigned char* expected) {
    unsigned char* actual = addZeros(relevant_bits, zeroes_needed);
    printf("addZeros test %s: relevant_bits=%s, zeroes_needed=%d, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           relevant_bits, zeroes_needed, expected, actual);
}

void test_HexToBin(unsigned char* hexdec, unsigned char* expected) {
    unsigned char* actual = HexToBin(hexdec);
    printf("HexToBin test %s: hexdec=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           hexdec, expected, actual);
}

void test_BinToHex(unsigned char* bin, unsigned char* expected) {
    unsigned char* actual = BinToHex(bin);
    printf("BinToHex test %s: bin=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           bin, expected, actual);
}

void test_hexStringToBytes(unsigned char* hexString, unsigned char* expected) {
    unsigned char* actual = malloc(sizeof(unsigned char) * 4);
    hexStringToBytes(hexString, actual);
    printf("hexStringToBytes test %s: hexString=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           hexString, expected, actual);
}

void test_get_num_bytes(unsigned char* string, int expected) {
    int actual = get_num_bytes(string);
    printf("get_num_bytes test %s: string=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void test_my_utf8_encode(char* input, char* expected) {
    char* actual = malloc(my_standard_strlen(expected) * 4);
    my_utf8_encode(input, actual);
    printf("my_utf8_encode test %s: input=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           input, expected, actual);
}

void test_my_utf8_decode(unsigned char* input, unsigned char* expected) {
    unsigned char* actual = malloc(sizeof(unsigned char) * 4);
    my_utf8_decode(input, actual);
    printf("my_utf8_decode test %s: input=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           input, expected, actual);
}


void test_count_utf8_chars(unsigned char* string, int expected) {
    int actual = count_utf8_chars(string);
    printf("count_utf8_chars test %s: string=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void test_my_utf8_check(unsigned char* string, int expected) {
    int actual = my_utf8_check(string);
    printf("my_utf8_check test %s: string=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void test_my_utf8_charat(unsigned char* string, int index, unsigned char* expected) {
    unsigned char* actual = my_utf8_charat(string, index);
    printf("my_utf8_charat test %s: string=%s, index=%d, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           string, index, expected, actual);
}

void test_next_utf8_char(unsigned char* string, unsigned char* expected) {
    unsigned char* actual = next_utf8_char(string);
    printf("next_utf8_char test %s: string=%s, expected=%s, actual=%s\n",
           (!my_utf8_strcmp(expected,actual) ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void utf8_strlen_tests() {
    test_utf8_strlen("", 0);
    test_utf8_strlen("a", 1);
    test_utf8_strlen("ab", 2);
    test_utf8_strlen("abc", 3);
    test_utf8_strlen("abcd", 4);
    test_utf8_strlen("abcde", 5);
    test_utf8_strlen("abcdef", 6);
    // now some with utf8 characters
    test_utf8_strlen("a\xC3\xA9", 2);
    test_utf8_strlen("a\xC3\xA9\xC3\xA9", 3);
    test_utf8_strlen("a\xC3\xA9\xC3\xA9\xC3\xA9", 4);
    test_utf8_strlen("a\xC3\xA9\xC3\xA9\xC3\xA9\xC3\xA9", 5);
    test_utf8_strlen("a\xC3\xA9\xC3\xA9\xC3\xA9\xC3\xA9\xC3\xA9", 6);
    test_utf8_strlen("a\xD7\x90", 2);
    test_utf8_strlen("a\xD7\x90\xD7\x90", 3);
}
void my_strcopy_tests() {
    unsigned char* dest = malloc(sizeof(unsigned char) * 4);
    unsigned char* src = "abcd";
    unsigned char* expected = "abcd";
    test_my_strcopy(dest, src, expected);
    unsigned char* dest2 = malloc(sizeof(unsigned char) * 4);
    unsigned char* src2 = "a\xC3\xA9";
    unsigned char* expected2 = "a\xC3\xA9";
    test_my_strcopy(dest2, src2, expected2);
}
void addZeros_tests() {
    unsigned char *relevant_bits = "11";
    int zeroes_needed = 2;
    unsigned char *expected = "0011";
    test_addZeros(relevant_bits, zeroes_needed, expected);
    unsigned char *relevant_bits2 = "111";
    int zeroes_needed2 = 1;
    unsigned char *expected2 = "0111";
    test_addZeros(relevant_bits2, zeroes_needed2, expected2);
    unsigned char *relevant_bits3 = "1111";
    int zeroes_needed3 = 4;
    unsigned char *expected3 = "00001111";
    test_addZeros(relevant_bits3, zeroes_needed3, expected3);

}
void HexToBin_tests() {
    unsigned char *hexdec = "0";
    unsigned char *expected = "0000";
    test_HexToBin(hexdec, expected);
    unsigned char *hexdec2 = "1";
    unsigned char *expected2 = "0001";
    test_HexToBin(hexdec2, expected2);
    unsigned char *hexdec3 = "2";
    unsigned char *expected3 = "0010";
    test_HexToBin(hexdec3, expected3);
    unsigned char *hexdec4 = "4";
    unsigned char *expected4 = "0100";
    test_HexToBin(hexdec4, expected4);
    unsigned char *hexdec5 = "8";
    unsigned char *expected5 = "1000";
    test_HexToBin(hexdec5, expected5);
    unsigned char *hexdec12 = "B";
    unsigned char *expected12 = "1011";
    test_HexToBin(hexdec12, expected12);
    unsigned char *hexdec14 = "D";
    unsigned char *expected14 = "1101";
    test_HexToBin(hexdec14, expected14);
    // now some longer hex numbers
    unsigned char *hexdec15 = "A2F5";
    unsigned char *expected15 = "1010001011110101";
    test_HexToBin(hexdec15, expected15);
    unsigned char *hexdec16 = "34D6F657";
    unsigned char *expected16 = "00110100110101101111011001010111";
    test_HexToBin(hexdec16, expected16);

}
void BinToHex_tests() {
    unsigned char *bin = "0000";
    unsigned char *expected = "0";
    test_BinToHex(bin, expected);
    unsigned char *bin2 = "0001";
    unsigned char *expected2 = "1";
    unsigned char *bin5 = "0100";
    unsigned char *expected5 = "4";
    test_BinToHex(bin5, expected5);
    unsigned char *bin11 = "1010";
    unsigned char *expected11 = "A";
    test_BinToHex(bin11, expected11);
    unsigned char *bin15 = "1110";
    unsigned char *expected15 = "E";
    test_BinToHex(bin15, expected15);
    // now some longer binary numbers
    unsigned char *bin16 = "1010001011110101";
    unsigned char *expected16 = "A2F5";
    test_BinToHex(bin16, expected16);
    unsigned char *bin17 = "00110100110101101111011001010111";
    unsigned char *expected17 = "34D6F657";
    test_BinToHex(bin17, expected17);
}
void hexStringToBytes_tests() {
    unsigned char *hexString = "A2F5";
    unsigned char *expected = "\xA2\xF5";
    test_hexStringToBytes(hexString, expected);
    unsigned char *hexString2 = "34D6F657";
    unsigned char *expected2 = "\x34\xD6\xF6\x57";
    test_hexStringToBytes(hexString2, expected2);
    unsigned char *hexString3 = "4FD567";
    unsigned char *expected3 = "\x4F\xD5\x67";
    test_hexStringToBytes(hexString3, expected3);

    // now some valid utf8 hex strings
    unsigned char *hexString4 = "D7A9";
    unsigned char *expected4 = "\xD7\xA9";
    test_hexStringToBytes(hexString4, expected4);
    unsigned char *hexString5 = "E0A4B9";
    unsigned char *expected5 = "\xE0\xA4\xB9";
    test_hexStringToBytes(hexString5, expected5);
    unsigned char *hexString6 = "F0908D88";
    unsigned char *expected6 = "\xF0\x90\x8D\x88";
    test_hexStringToBytes(hexString6, expected6);
    // multiple utf8 characters
    unsigned char *hexString7 = "D7A9E0A4B9";
    unsigned char *expected7 = "\xD7\xA9\xE0\xA4\xB9";
    test_hexStringToBytes(hexString7, expected7);
}
void get_num_bytes_tests() {
    unsigned char *string = "a";
    int expected = 1;
    unsigned char *string2 = "\xD7\x90";
    int expected2 = 2;
    test_get_num_bytes(string2, expected2);
    unsigned char *string3 = "\xF0\x90\x8D\x88";
    int expected3 = 4;
    test_get_num_bytes(string3, expected3);
    unsigned char *string4 = "\xE0\xA4\xB9";
    int expected4 = 3;
    test_get_num_bytes(string4, expected4);
}
void my_utf8_encode_tests() {
    // test with a single utf8 character
    char *input = "\\u05D2";
    char *output = "ג";
    test_my_utf8_encode(input, output);
    // multiple utf8 characters
    char *input1 = "\\u05D2\\u05D9\\u05DC\\u05D4";
    char *output1 = "גילה";
    test_my_utf8_encode(input1, output1);
    // combination of ascii and utf8 characters
    char *input2 = "My name is \\u05D2\\u05D9\\u05DC\\u05D4";
    char *output2 = "My name is גילה";
    test_my_utf8_encode(input2, output2);
    // test with a single ascii character
    char *input3 = "a";
    char *output3 = "a";
    test_my_utf8_encode(input3, output3);
    // test with multiple ascii characters
    char *input4 = "abc";
    char *output4 = "abc";
    test_my_utf8_encode(input4, output4);
    // longer string tests with 5 byte unicode
    char *input5 = "The crying laughing emoji: \\u1F602";
    char *output5 = "The crying laughing emoji: 😂";
    test_my_utf8_encode(input5, output5);
    char *input6 = "The smiling face with heart eyes emoji: \\u1F60D";
    char *output6 = "The smiling face with heart eyes emoji: 😍";
    test_my_utf8_encode(input6, output6);
    char *input7 = "The face with tears of joy emoji: \\u1F602";
    char *output7 = "The face with tears of joy emoji: 😂";
    test_my_utf8_encode(input7, output7);
    char *input8 = "A whole bunch of emojis: \\u1F602\\u1F60D\\u1F976\\u1F44F";
    char *output8 = "A whole bunch of emojis: 😂😍🥶👏";
    test_my_utf8_encode(input8, output8);

}
void my_utf8_decode_tests(){
    // test with a single utf8 character
    unsigned char *input = "ג";
    unsigned char *output = "\\u05D2";
    test_my_utf8_decode(input, output);
    // multiple utf8 characters
    unsigned char *input1 = "גילה";
    unsigned char *output1 = "\\u05D2\\u05D9\\u05DC\\u05D4";
    test_my_utf8_decode(input1, output1);
    // combination of ascii and utf8 characters
    unsigned char *input2 = "My name is גילה";
    unsigned char *output2 = "My name is \\u05D2\\u05D9\\u05DC\\u05D4";
    test_my_utf8_decode(input2, output2);
    // test with a single ascii character
    unsigned char *input3 = "a";
    unsigned char *output3 = "a";
    test_my_utf8_decode(input3, output3);
    // test with multiple ascii characters
    unsigned char *input4 = "abc";
    unsigned char *output4 = "abc";
    test_my_utf8_decode(input4, output4);
    // More longer string tests with 5 byte unicode
    unsigned char *input5 = "The crying laughing emoji: 😂";
    unsigned char *output5 = "The crying laughing emoji: \\u1F602";
    test_my_utf8_decode(input5, output5);
    unsigned char *input6 = "The smiling face with heart eyes emoji: 😍";
    unsigned char *output6 = "The smiling face with heart eyes emoji: \\u1F60D";
    test_my_utf8_decode(input6, output6);
    unsigned char *input7 = "The face with tears of joy emoji: 😂";
    unsigned char *output7 = "The face with tears of joy emoji: \\u1F602";
    test_my_utf8_decode(input7, output7);
    unsigned char *input8 = "A whole bunch of emojis: 😂😍🥶👏";
    unsigned char *output8 = "A whole bunch of emojis: \\u1F602\\u1F60D\\u1F976\\u1F44F";
    test_my_utf8_decode(input8, output8);



}
void count_utf8_chars_tests() {
    unsigned char *string = "a";
    int expected = 0;
    test_count_utf8_chars(string, expected);
    unsigned char *string2 = "ab";
    int expected2 = 0;
    test_count_utf8_chars(string2, expected2);
    unsigned char *string5 = "a\xC3\xA9";
    int expected5 = 1;
    test_count_utf8_chars(string5, expected5);
    unsigned char *string6 = "a\xC3\xA9\xC3\xA9";
    int expected6 = 2;
    test_count_utf8_chars(string6, expected6);
    unsigned char *string7 = "a גילה";
    int expected7 = 4;
    test_count_utf8_chars(string7, expected7);
}
void my_utf8_check_tests() {
    unsigned char *string = "a";
    int expected = 0;
    test_my_utf8_check(string, expected);
    unsigned char *string2 = "ab";
    int expected2 = 0;
    test_my_utf8_check(string2, expected2);
    unsigned char *string3 = "a\xC3\xA9";
    int expected3 = 0;
    test_my_utf8_check(string3, expected3);
    unsigned char *string4 = "a\xC3\xA9\xC3\xA9";
    int expected4 = 0;
    test_my_utf8_check(string4, expected4);
    unsigned char *string5 = "a גילה";
    int expected5 = 1;
    test_my_utf8_check(string5, expected5);
    // some fake utf8 strings that should fail the check
    unsigned char *string6 = "\xFF";
    int expected6 = 1;
    test_my_utf8_check(string6, expected6);
    unsigned char *string7 = "\xFF\xF6";
    int expected7 = 1;
    test_my_utf8_check(string7, expected7);
}




int main() {
    utf8_strlen_tests();
    my_strcopy_tests();
    addZeros_tests();
    HexToBin_tests();
    BinToHex_tests();
    hexStringToBytes_tests();
    get_num_bytes_tests();
    my_utf8_encode_tests();
    my_utf8_decode_tests();
    my_utf8_strcmp_tests();
    count_utf8_chars_tests();
    my_utf8_check_tests();


    return 0;
}