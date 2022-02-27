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

//возвращает кол-во символов в стоке (не считая 0-символ)
size_t strlen_ ( char *begin);

//возвращает указатель на первый элемент с кодом ch,
//расположенным на ленте памяти между адресами begin
//и end не включая end. Если символ не найден, возвращается значение end.
char* find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа.
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ, расположенный на ленте
//памяти начиная с адреса begin или на первый ноль-символ.
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin и заканчивая rend. если символ
//не найден, возвращается адрес rend.
char* findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char* findSpaceReverse(char *rbegin, const char *rend);

#endif //COURSE_STRING__H
