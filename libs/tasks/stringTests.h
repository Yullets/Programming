//
// Created by Yulia on 01.03.2022.
//

#ifndef COURSE_STRINGTESTS_H
#define COURSE_STRINGTESTS_H

#include "../string/string_.h"
#include "stringTests.h"

#define ASSERT_STRING(expected, got) assertString (expected, got, \
                                                   __FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

void test_removeNonLetters();

void test_removeExtraSpaces();

void test_digitToEndReverse();

void test_replaceNumber();

void test_getCountOfPalindromes1();

void test_getCountOfPalindromes2();

void test_replace();

void tests();

#endif //COURSE_STRINGTESTS_H
