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

char getEndOfString(char *s) {
    char *end = s;
    while (*s != '\0')
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
