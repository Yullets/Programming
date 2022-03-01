//
// Created by Yulia on 26.02.2022.
//

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "string_.h"
#include <ctype.h>
#include <memory.h>


size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && (*lhs == *rhs))
        lhs++, rhs++;

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, sizeof(char) * (endSource - beginSource));

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, sizeof(char));
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination, rbeginSource, sizeof(char));
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

