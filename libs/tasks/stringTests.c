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

void test_getCountOfPalindromes1() {
    char s[] = "abba, children, polliillop";
    int res = getCountOfPalindromes(s);
    assert(res == 2);
}

void test_getCountOfPalindromes2() {
    char s[] = "aaaa, aa, ";
    int res = getCountOfPalindromes(s);
    assert(res == 2);
}

void test_replace() {
    char source[MAX_STRING_SIZE] = "love smile smile smile";
    char w1[] = "smile";
    char w2[] = "happy";
    replace(source, w1, w2);
    ASSERT_STRING("love happy happy happy ", source);
}

void test_orderedByAlfa1() {
    char s[] = "put your best foot forward";
    int res = orderedByAlfa(s);
    assert(res == false);
    printf("test_orderedByAlfa1 - OK");
    printf("\n");
}

void test_orderedByAlfa2() {
    char s[] = "happy new year";
    int res = orderedByAlfa(s);
    assert(res == true);
    printf("test_orderedByAlfa2 - OK");
    printf("\n");
}

void test_printWordsAndReverse() {
    char s[] = "no man is an island";
    printWordsAndReverse(s);
}

void tests() {
    test_removeNonLetters();
    test_digitToEndReverse();
    test_removeExtraSpaces();
    test_replaceNumber();
    test_getCountOfPalindromes1();
    test_getCountOfPalindromes2();
    test_replace();
    test_orderedByAlfa1();
    test_orderedByAlfa2();
    test_printWordsAndReverse();
}