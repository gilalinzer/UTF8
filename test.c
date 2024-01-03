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
           (*expected == *dest ? "PASSED" : "FAILED"),
           dest, src, expected);
}

void test_addZeros(unsigned char* relevant_bits, int zeroes_needed, unsigned char* expected) {
    unsigned char* actual = addZeros(relevant_bits, zeroes_needed);
    printf("addZeros test %s: relevant_bits=%s, zeroes_needed=%d, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           relevant_bits, zeroes_needed, expected, actual);
}

void test_HexToBin(unsigned char* hexdec, unsigned char* expected) {
    unsigned char* actual = HexToBin(hexdec);
    printf("HexToBin test %s: hexdec=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           hexdec, expected, actual);
}

void test_BinToHex(unsigned char* bin, unsigned char* expected) {
    unsigned char* actual = BinToHex(bin);
    printf("BinToHex test %s: bin=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           bin, expected, actual);
}

void test_hexStringToBytes(unsigned char* hexString, unsigned char* expected) {
    unsigned char* actual = malloc(sizeof(unsigned char) * 4);
    hexStringToBytes(hexString, actual);
    printf("hexStringToBytes test %s: hexString=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           hexString, expected, actual);
}

void test_get_num_bytes(unsigned char* string, int expected) {
    int actual = get_num_bytes(string);
    printf("get_num_bytes test %s: string=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string, expected, actual);
}

void test_my_utf8_encode(char* input, char* expected) {
    char* actual = malloc(sizeof(char) * 4);
    my_utf8_encode(input, actual);
    printf("my_utf8_encode test %s: input=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           input, expected, actual);
}


void test_my_utf8_decode(unsigned char* input, unsigned char* expected) {
    unsigned char* actual = malloc(sizeof(unsigned char) * 4);
    my_utf8_decode(input, actual);
    printf("my_utf8_decode test %s: input=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           input, expected, actual);
}



void test_utf8HexToUnicode(unsigned char* input, unsigned char* expected) {
    unsigned char* actual = malloc(sizeof(unsigned char) * 4);
    utf8HexToUnicode(input, actual);
    printf("utf8HexToUnicode test %s: input=%s, expected=%s, actual=%s\n",
           (*expected == *actual ? "PASSED" : "FAILED"),
           input, expected, actual);
}

void test_my_standard_strlen(unsigned char* str, int expected) {
    int actual = my_standard_strlen(str);
    printf("my_standard_strlen test %s: str=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           str, expected, actual);
}

void test_my_utf8_strcmp(unsigned char* string1, unsigned char* string2, int expected) {
    int actual = my_utf8_strcmp(string1, string2);
    printf("my_utf8_strcmp test %s: string1=%s, string2=%s, expected=%d, actual=%d\n",
           (expected == actual ? "PASSED" : "FAILED"),
           string1, string2, expected, actual);
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
           (expected == actual ? "PASSED" : "FAILED"),
           string, index, expected, actual);
}



void test_next_utf8_char(unsigned char* string, unsigned char* expected) {
    unsigned char* actual = next_utf8_char(string);
    printf("next_utf8_char test %s: string=%s, expected=%s, actual=%s\n",
           (expected == actual ? "PASSED" : "FAILED"),
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
    unsigned char *hexdec5 = "4";
    unsigned char *expected5 = "0100";
    test_HexToBin(hexdec5, expected5);
    unsigned char *hexdec9 = "8";
    unsigned char *expected9 = "1000";
    test_HexToBin(hexdec9, expected9);
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






int main() {
    utf8_strlen_tests();
    my_strcopy_tests();
    addZeros_tests();
    HexToBin_tests();

    return 0;
}