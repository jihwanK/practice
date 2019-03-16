#ifndef WORD_H_
#define WORD_H_

typedef struct _word
{
    /* data */
    char word[50];
    int len;
} Word;

goid makeWord(Word* wp, const char* str);

#endif
