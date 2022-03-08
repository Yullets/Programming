//
// Created by Yulia on 01.03.2022.
//

#include <ctype.h>
#include <stdlib.h>

#include "../string/string_.h"
#include "../algorithms/array/array.h"
#include "stringTasks.h"

void removeNonLetters(char *s) {
    char *endSource = s + strlen_(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void removeExtraSpaces(char *s) {
    if (*s == '\0')
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

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
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

void replaceNumber(char *s) {
    char *begin = s;
    char *buf = _stringBuffer;
    while (*begin != '\0') {
        if (isdigit(*begin)) {
            char digit = *begin - '0';
            for (int i = 0; i < digit; i++) {
                *buf = ' ';
                buf++;
            }
        } else {
            *buf = *begin;
            buf++;
        }

        begin++;
    }

    *buf = '\0';
    copy(_stringBuffer, buf, s);
}

char *getEndOfString(char *s) {
    char *end = s;

    while (*end != '\0')
        end++;

    return end;
}

int areWordsEqual(wordDescriptor w1,
                  wordDescriptor w2) {
    size_t firstWordLength = w1.end - w1.begin - 1;
    size_t secondWordLength = w2.end - w2.begin - 1;

    if (firstWordLength != secondWordLength)
        return 0;

    return !memcmp(w1.begin, w2.begin, firstWordLength);
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    wordDescriptor word1 = {w1, w1 + w1Size};
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    wordDescriptor word;
    while (getWord(readPtr, &word)) {
        if (areWordsEqual(word, word1))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(word.begin, word.end, recPtr);

        *recPtr = ' ';
        recPtr++;
        readPtr = word.end;
    }
    *recPtr = '\0';
}

bool orderedByAlfa(char *s) {
    wordDescriptor beginWord;
    wordDescriptor nextWord;

    if (!getWord(s, &beginWord))
        return true;

    while (getWord(s, &nextWord)) {
        if (areWordsEqual(beginWord, nextWord) == false &&
            strcmp(beginWord.begin, nextWord.begin) > 0)
            return false;

        beginWord = nextWord;
        s = nextWord.end;
    }

    return true;
}

void getBagOfWords(BagOfWords *ws, char *s) {
    wordDescriptor w;
    ws->size = 0;
    while (getWord(s, &w)) {
        ws->words[ws->size++] = w;
        s = w.end;
    }
}

void printWord(wordDescriptor word) {
    char *buff_end = copy(word.begin, word.end,
                          _stringBuffer);
    *buff_end = '\0';

    printf("%s", _stringBuffer);
}

void printWordsAndReverse(char *s) {
    char *begin = s;

    BagOfWords ws;
    getBagOfWords(&ws, begin);

    for (int i = ws.size - 1; i >= 0; i--) {
        printWord(ws.words[i]);
        printf("\n");
    }
}

bool isPalindrome(wordDescriptor s) {
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
    while (*begin != '\0') {
        if (*begin == ',')
            return begin;
        begin++;
    }

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
    while (getWordWithComma(previous, &word)) {
        if (isPalindrome(word))
            count++;
        previous = word.end + (*word.end != '\0');
    }

    return count;
}

void mixTwoStrings(char *s1, char *s2, char *s3) {
    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            s3 = copy(word1.begin, word1.end, s3);
            *s3 = ' ';
            s3++;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            s3 = copy(word2.begin, word2.end, s3);
            *s3 = ' ';
            s3++;
            beginSearch2 = word2.end;
        }
    }

    *(s3 - 1) = '\0';
}

void reverseTheOrderOfWords(char *s) {
    if (*s == '\0')
        return;

    BagOfWords ws;
    getBagOfWords(&ws, s);
    char *buf = _stringBuffer;

    for (int i = ws.size - 1; i >= 0; i--) {
        buf = copy(ws.words[i].begin, ws.words[i].end, buf);
        *buf = ' ';
        buf++;
    }
    *buf = '\0';
    s = copy(_stringBuffer, buf, s);
    *(s - 1) = '\0';
}

bool isLetterA(wordDescriptor w) {
    char *begin = w.begin;

    while (begin != w.end) {
        if (*begin == 'a' || *begin == 'A')
            return true;
        begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, wordDescriptor *wordBefore) {
    wordDescriptor word1;
    char *begin = s;

    if (!getWord(begin, &word1))
        return EMPTY_STRING;

    if (isLetterA(word1))
        return FIRST_WORD_WITH_A;

    wordDescriptor word2;
    begin = word1.end;

    while (getWord(begin, &word2)) {
        if (isLetterA(word2)) {
            wordBefore->begin = word1.begin;
            wordBefore->end = word1.end;
            return WORD_FOUND;
        }
        word1.begin = word2.begin;
        word1.end = word2.end;
        begin = word2.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    wordDescriptor word;
    WordBeforeFirstWordWithAReturnCode code = getWordBeforeFirstWordWithA(begin, &word);
    if (code == WORD_FOUND) {
        char *end = copy(word.begin, word.end, _stringBuffer);
        *end = '\0';
        printf("%s", _stringBuffer);
    }
}

bool getLastWordOfString1AlsoHasInString2(char *s1, char *s2, wordDescriptor *word) {
    getBagOfWords(&_bag, s2);
    wordDescriptor *_bagEnd = _bag.words + _bag.size;
    char *endOfTheString = getEndOfString(s1);

    wordDescriptor lastWord;
    while (getWordReverse(endOfTheString - 1, s1 - 1, &lastWord)) {
        for (wordDescriptor *curWord = _bag.words; curWord < _bagEnd; curWord++) {
            if (areWordsEqual(lastWord, *curWord)) {
                *word = lastWord;
                return true;
            }
        }
        endOfTheString = lastWord.begin;
    }

    return false;
}

bool isOnlyUniqueWords(char *s) {
    getBagOfWords(&_bag, s);

    wordDescriptor *curWord = _bag.words;
    wordDescriptor *endWord = _bag.words + _bag.size - 1;

    while (curWord < endWord) {
        wordDescriptor *word = curWord + 1;
        while (word <= endWord) {
            if (areWordsEqual(*curWord, *word))
                return false;
            word++;
        }
        curWord++;
    }

    return true;
}

void sortSymbolsOfWord(wordDescriptor word) {
    int countOfElements = word.end - word.begin;
    qsort(word.begin, countOfElements, sizeof(int), compare_ints);
}

bool thereIsWordsWithEqualSymbols(char *s) {
    char *bufEnd = copy(s, getEndOfString(s), _stringBuffer);
    *bufEnd = '\0';

    getBagOfWords(&_bag, _stringBuffer);
    wordDescriptor *_bagEnd = _bag.words + _bag.size;
    for (wordDescriptor *curWord = _bag.words; curWord < _bagEnd; curWord++) {
        sortSymbolsOfWord(*curWord);
    }

    for (wordDescriptor *curWord = _bag.words; curWord < _bagEnd; curWord++) {
        for (wordDescriptor *nextWord = _bag.words; nextWord < _bagEnd; nextWord++) {
            if (areWordsEqual(*curWord, *nextWord))
                return true;
        }
    }

    return false;
}

void copyWordsOtherThanLast(char *s) {
    char *read = s;
    char *write = s;
    wordDescriptor lastWord, curWord;

    if (!getWordReverse(getEndOfString(s) - 1, s - 1, &lastWord))
        return;

    while (getWord(read, &curWord)) {
        if (!areWordsEqual(curWord, lastWord)) {
            write = copy(curWord.begin, curWord.end, write);
            *write = ' ';
            write++;
        }
        read = curWord.end;
    }
    write -= s != write;
    *write = '\0';
}

void deletePalindromes(char *s) {
    char *write = s;
    char *read = s;

    wordDescriptor word;
    while (getWord(read, &word)) {
        if (!isPalindrome(word)) {
            write = copy(word.begin, word.end, write);
            *write = ' ';
            write++;
        }
        read = word.end;
    }
    write -= s != write;
    *write = '\0';
}

void addWordsFromBiggerString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    int size1 = _bag.size;
    int size2 = _bag2.size;

    int difference = abs(size2 - size1);

    if (difference == 0)
        return;

    BagOfWords *sourceBag;
    BagOfWords *dstBag;
    char *dst;

    if (size1 < size2) {
        sourceBag = &_bag2;
        dstBag = &_bag;
        dst = getEndOfString(s1);
    } else {
        sourceBag = &_bag;
        dstBag = &_bag2;
        dst = getEndOfString(s2);
    }

    if (dstBag->size != 0) {
        *dst = ' ';
        dst++;
    }

    for (int i = sourceBag->size - difference; i < sourceBag->size; i++) {
        dst = copy(sourceBag->words[i].begin, sourceBag->words[i].end, dst);
        *dst = ' ';
        dst++;
    }

    dst--;
    *dst = '\0';
}

bool areAllLettersIncluded(char *s, wordDescriptor word) {
    bool stringSymbols[UCHAR_MAX + 1] = {false};
    while (*s != '\0') {
        stringSymbols[*s] = true;
        s++;
    }

    char *wordBegin = word.begin;
    while (wordBegin < word.end) {
        if (stringSymbols[*wordBegin] == false)
            return false;
        wordBegin++;
    }

    return true;
}