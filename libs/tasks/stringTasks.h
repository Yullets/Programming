//
// Created by Yulia on 01.03.2022.
//

#ifndef COURSE_STRINGTASKS_H
#define COURSE_STRINGTASKS_H

#include "../string/string_.h"
#include "assert.h"

void removeNonLetters(char *s);

void removeExtraSpaces(char *s);

void digitToEnd(wordDescriptor word);

void digitToEndReverse(char *stringStart);

void replaceNumber(char *s);

int getCountOfPalindromes(char *s);

char *getEndOfString(char *s);

int areWordsEqual(wordDescriptor w1,
                  wordDescriptor w2);

void replace(char *source, char *w1, char *w2);

bool orderedByAlfa(char *s);

void getBagOfWords(BagOfWords *ws, char *s);

void printWordsAndReverse(char *s);

void reverseTheOrderOfWords(char *s);

void mixTwoStrings(char *s1, char *s2, char *s3);

bool isLetterA(wordDescriptor w);

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, wordDescriptor *wordBefore);

void printWordBeforeFirstWordWithA(char *s);

bool getLastWordOfString1AlsoHasInString2(char *s1, char *s2, wordDescriptor *word);

bool isOnlyUniqueWords(char *s);

void sortSymbolsOfWord(wordDescriptor word);

bool thereIsWordsWithEqualSymbols(char *s);

#endif //COURSE_STRINGTASKS_H

