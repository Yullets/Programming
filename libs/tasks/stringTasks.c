//
// Created by Yulia on 01.03.2022.
//

#include <ctype.h>

#include "../string/string_.h"
#include "stringTasks.h"

void removeNonLetters(char *s) {
    char *endSource = s + strlen_(s);;
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void removeExtraSpaces(char *s) {
    if(*s == '\0')
        return;

    char *begin = s;
    s++;
    while (*s != '\0') {
        if (isspace(*s) && isspace(*begin))
            *begin = ' ';
        else
            *(++begin) = *s;

        s++;
    }
    *(++begin) = '\0';
}

int getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitsToStartReverse(char *stringStart) {
    char *beginString = stringStart;
    wordDescriptor word;
    while (getWord(beginString, &word)) {
        digitToStart(word);
        beginString = word.end;
    }
}

void digitToEnd(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin,
                                 word.end,
                                 _stringBuffer);

    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin,
                               isalpha);

    copyIfReverse(endStringBuffer - 1,
                  _stringBuffer - 1,
                  recPosition,
                  isdigit);
}

void digitToEndReverse(char *stringStart) {
    char *beginString = stringStart;
    wordDescriptor word;
    while (getWord(beginString, &word)) {
        digitToEnd(word);
        beginString = word.end;
    }
}

void replaceNumber (char *s) {
    char *begin = s;
    char *buf = _stringBuffer;
    while (*begin != '\0') {
        if (isalpha(*begin)) {
            *buf = *begin;
            buf++;
        } else if (isdigit(*begin)) {
            char k = *begin - '0';
            for(int i = 0; i < k; i++) {
                *buf = ' ';
                buf++;
            }
        }

        begin++;
    }

    *buf = '\0';
    copy(_stringBuffer, buf, s);
}

bool isPalindrome (wordDescriptor s) {
    char *left = s.begin;
    char *right = s.end - 1;
    while (right > left) {
        if (*(left) != *(right))
            return false;

        left++;
        right--;
    }

    return true;
}

char *findComma(char *begin) {
    while (*begin != '\0')
        if(*begin == ',')
            return begin;

        begin++;

    return begin;
}

int getWordWithComma(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findComma(word->begin);

    return 1;
}

int getCountOfPalindromes(char *s) {
    wordDescriptor word;
    int count = 0;

    if (*s == '\0')
        return count;

    char *previous = s;
    while (getWordWithComma(s, &word)) {
        if(isPalindrome(word))
            count++;

        previous = word.end + 1;
    }

    return count;
}
