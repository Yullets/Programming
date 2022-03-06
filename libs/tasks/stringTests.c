//
// Created by Yulia on 01.03.2022.
//
#include "../string/string_.h"
#include "stringTasks.h"
#include "stringTests.h"
#include "../string/string_.h"

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

void test_mixTwoStrings() {
    char s1[] = "man has his price";
    char s2[] = "it is the tip of the iceberg";
    char s3[MAX_STRING_SIZE];
    mixTwoStrings(s1, s2, s3);
    ASSERT_STRING("man it has is his the price tip of the iceberg", s3);
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

void test_reverseTheOrderOfWords1() {
    char s[] = "better late than never";
    reverseTheOrderOfWords(s);
    ASSERT_STRING("never than late better", s);
}

void test_reverseTheOrderOfWords2() {
    char s[] = "";
    reverseTheOrderOfWords(s);
    ASSERT_STRING("", s);
}

void test_printWordBeforeFirstWordWithA() {
    char s[] = "be smart";
    printWordBeforeFirstWordWithA(s);
}

void test_getLastWordOfString1AlsoHasInString2() {
    char s1[] = "you cannot eat your cake and eat it too";
    char s2[] = "learn to walk before you run";

    wordDescriptor result_wd;
    bool result = getLastWordOfString1AlsoHasInString2(s1, s2, &result_wd);

    char resultWord[MAX_STRING_SIZE];
    wordDescriptorToString(result_wd, resultWord);
    char expectedWord[] = "you";
    bool expectedResult = true;

    assert(expectedResult == result);
    ASSERT_STRING(expectedWord, resultWord);
}

void test_isOnlyUniqueWords() {
    char s[] = "keep your friends close and your enemies closer";
    int res = isOnlyUniqueWords(s);
    assert(res == false);
    printf("test_isOnlyUniqueWords - OK");
    printf("\n");
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
    //test_printWordsAndReverse();
    test_reverseTheOrderOfWords1();
    test_reverseTheOrderOfWords2();
    test_isOnlyUniqueWords();
    //test_printWordBeforeFirstWordWithA();
    test_mixTwoStrings();
    test_getLastWordOfString1AlsoHasInString2();
}