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

//void removeExtraSpaces(char *s){
//    char *begin = s;
//    char *destination;
//    int count = 0;
//    while (begin != '.') {
//        if (begin != ' ' || (begin == ' ' && count < 2)) {
//            memcpy(begin, destination, sizeof(char));
//            begin++;
//        }
//
//
//    }
//}

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