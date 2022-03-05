//
// Created by Yulia on 26.02.2022.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct wordDescriptor {
    char *begin;
    char *end;
} wordDescriptor;

typedef struct BagOfWords {
    wordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

static char _stringBuffer[MAX_STRING_SIZE + 1];

static BagOfWords _bag;
static BagOfWords _bag2;

//возвращает кол-во символов в стоке (не считая 0-символ)
size_t strlen_(char *begin);

//возвращает указатель на первый элемент с кодом ch,
//расположенным на ленте памяти между адресами begin
//и end не включая end. Если символ не найден, возвращается значение end.
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ, расположенный на ленте
//памяти начиная с адреса begin или на первый ноль-символ.
char *findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin и заканчивая rend. если символ
//не найден, возвращается адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

//возвращает отрицательное значение, если lhs располагается до rhs,
//значение 0, если lhs и rhs равны, иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса
//beginSource до endSource. Возвращает указатель на следующий свободный
//фрагмент памяти в destination.
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f. Функция
//возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f. Функция возвращает значение
//beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

void removeNonLetters(char *s);

#endif //COURSE_STRING__H
