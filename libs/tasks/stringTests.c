//
// Created by Yulia on 01.03.2022.
//
#include "../string/string_.h"
#include "stringTasks.h"
#include "stringTests.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters() {
    char s[] = "Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces() {
    char s[] = "dreams  come  true";
    removeExtraSpaces(s);
    ASSERT_STRING("dreams come true", s);
}

void test_digitToEndReverse() {
    char s[] = "favou9572rite";
    digitToEndReverse(s);
    ASSERT_STRING("favourite2759", s);
}

void test_replaceNumber() {
    char s[100] = "a3b0c1";
    replaceNumber(s);
    ASSERT_STRING("a   bc ", s);
}
 void test_getCountOfPalindromes(){
    char s[] = "abba, children, polliillop";
    int res = getCountOfPalindromes(s);
    assert(res == 2);
}

void tests() {
    test_removeNonLetters();
    test_digitToEndReverse();
    test_removeExtraSpaces();
    test_replaceNumber();
    test_getCountOfPalindromes();
}