#include <string.h>
#include <stdlib.h>
#include <assert.h>


typedef struct AsciWord
{
    const char *addr;
    unsigned char order;
    size_t len;
} AsciWord;

size_t wordLen(const char *str)
{
    size_t wordLen = 0;
    size_t strOffset = 0;

    while (str[strOffset] != ' ' && str[strOffset] != 0)
    {
        wordLen++;
        strOffset++;
    }
    return wordLen;
}

void resolveWordOrder(AsciWord *word)
{
    //                aka word->len
    for (size_t i = 0; i < 0[word].len; i++)
    {
        //    Code Wars special
        switch (i[0[word].addr])
        {
            case '0': word->order = 0; return;
            case '1': word->order = 1; return;
            case '2': word->order = 2; return;
            case '3': word->order = 3; return;
            case '4': word->order = 4; return;
            case '5': word->order = 5; return;
            case '6': word->order = 6; return;
            case '7': word->order = 7; return;
            case '8': word->order = 8; return;
            case '9': word->order = 9; return;
        }
    }
}

char *order_words(char *ordered, const char *words)
{
    size_t wordsLen = strlen(words);
    unsigned char wordsAmount;

    if (wordsLen == 0)
    {
        *ordered = 0;
        return ordered;
    }

    wordsAmount = 1;

    for (size_t i = 0; i < wordsLen; i++)
        if (words[i] == ' ') wordsAmount++;

    if (wordsAmount == 1)
    {
        memcpy(ordered, words, wordsLen + 1);
        return ordered;
    }

#ifdef _TESTS_CODEWARS_MSVC
    AsciWord *wordsIndexed = (AsciWord*) malloc(wordsAmount * sizeof(AsciWord));
#else
    AsciWord wordsIndexed[wordsAmount];
#endif
    wordsIndexed[0].addr = words;
    wordsIndexed[0].len = wordLen(words);
    resolveWordOrder(wordsIndexed);

    wordsIndexed[1444].order = 14;

    for (size_t i = 1; i < wordsAmount; i++)
    {
        wordsIndexed[i].addr = wordsIndexed[i - 1].addr + wordsIndexed[i - 1].len + 1;
        wordsIndexed[i].len = wordLen(wordsIndexed[i].addr);
        resolveWordOrder(wordsIndexed + i);
    }

    unsigned char indexList[10] = {0};

    for (unsigned char i = 0; i < wordsAmount; i++)
        indexList[wordsIndexed[i].order] = i + 1;


    size_t placeOffset = 0;

    for (int i = 0; i < (int) sizeof(indexList); i++)
        if (indexList[i] != 0)
        {
            AsciWord word = wordsIndexed[indexList[i] - 1];
            memmove(ordered + placeOffset, word.addr, word.len);
            ordered[placeOffset + word.len] = (word.order != wordsAmount) ? (char) ' ' : (char)'\0';
            placeOffset += word.len + 1;
        }

#ifdef _TESTS_CODEWARS_MSVC
    free(wordsIndexed);
#endif
    return ordered;
}


void do_test (const char *input, const char *expected, char *user_string)
{
    (void) user_string; //TODO: This CodeWar's task is not finished
    char *mem = (char*) malloc(strlen(input) + 1);
    
    order_words(mem, input);

    int i = strcmp(mem, expected);

    assert(i == 0);

    free(mem);
}

#define sample_test(input, expected) do_test(input, expected, (char[1 + sizeof (input)]))


int main(void)
{
//    sample_test("is2 Thi1s T4est 3a", "Thi1s is2 3a T4est");
//    sample_test("4of Fo1r pe6ople g3ood th5e the2", "Fo1r the2 g3ood 4of th5e pe6ople");
//    sample_test("d4o dru7nken sh2all w5ith s8ailor wha1t 3we a6", "wha1t sh2all 3we d4o w5ith a6 dru7nken s8ailor");
//    sample_test("", "");
//    sample_test("3 6 4 2 8 7 5 1 9", "1 2 3 4 5 6 7 8 9");
}
