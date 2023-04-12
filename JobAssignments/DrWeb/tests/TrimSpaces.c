#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <assert.h>

#define TESTS_USE_RANDOM 0

#if TESTS_USE_RANDOM
#define RANDOM_PERSISTENT_SEED 0xfafa5555
#endif


#ifndef RANDOM_PERSISTENT_SEED
#include <time.h>
#endif


void TrimRight( char *s );

int main()
{
    uint64_t seed;

#ifndef RANDOM_PERSISTENT_SEED
    seed = time(NULL);
#else
    seed = RANDOM_PERSISTENT_SEED;
#endif

    printf("SEED: %llu\n\n", (long long)seed);

#if TESTS_USE_RANDOM
    srand(seed);
#endif

    unsigned long long maxMemSize = 1024UL * 1024UL * 1024UL * 3UL;

    char *string = (char *) malloc(maxMemSize + 1);

    for (int i = 0; i < 100; i++)
    {

        int frontSize;
        int tailSize;

#if !TESTS_USE_RANDOM
        frontSize = 458559;
        tailSize = 47702288;
#else
        frontSize = rand();
        tailSize = rand();
        frontSize |= ((rand() & 0x7fff) << 8);
        tailSize |= ((rand() & 0x7fff) << 8);
#endif

        if (frontSize + tailSize + 1 > maxMemSize)
            continue;

        // Don't trust CLION's diagnostic here if TESTS_USE_RANDOM is 0
        // https://youtrack.jetbrains.com/issue/CPP-32240
        // it seems Arseniy Terekhov will not fix this
        if (frontSize == 0 || tailSize == 0)
            continue;

        memset(string, '^', frontSize);
        memset(string + frontSize, ' ', tailSize);

        string[tailSize + frontSize - 1] = 0;

        printf("Bench #%d: frontSize = %d | tailSize = %d\n", i, frontSize, tailSize);
        fflush(stdout);
        TrimRight(string);

        assert(string[frontSize] == 0);

    }
    free(string);

}

#include <string.h>


void TrimRightSized(char *s , size_t stringLen);

void TrimRight( char *s )
{
    /*
        Так как в задании дается сигнатура без возвращаемого значения то,
        по моему мнению, реализация данной функции сводится к нахождению
        первого символа пробела в конце переданной строки и замена
        этого символа на символ завершающего нуля.

        В постановке задачи нет однозначного пояснения о том, чем является параметр "s"

        В связи с этим, данная функция реализована с допущением
        наличия символа завершающего нуля в передаваемой строке
    */

    /*
        Алгоритм основан на бинарном поиске границы строки и завершающих пробелов.
    */

    /*
        Для бинарного поиска необходима длина строки, которую мы выясним с помощью функции strlen
        Реализация strlen в большинстве случаев использует платформозависимые
        инструкции, которые минимизируют количество операций доступа к памяти

        В особых случаях компилятор реализует strlen через x86 инструкцию "repne scasb"
        https://youtu.be/WiyUf8u78-w
    */
    size_t stringLen = strlen(s);

    TrimRightSized(s, stringLen);

}


/**
 * Максимальное количество пробелов в строке между словами <hr>
 * <pre>
 * "Hello World           " -> 1 пробел
 * "Hello  World          " -> 2 пробела
 * "Hello   World         " -> 3 пробела
 * </pre>
 */
#define INSTRING_MAX_SPACE_SEQUENCE_LENGTH 2

static char IsThereWordBehind(const char *s)
{
    for (int i = INSTRING_MAX_SPACE_SEQUENCE_LENGTH; i > 0; i--)
        if (s[-i] != ' ')
            return 1;
    return 0;
}

/**
 * Максимальная длина строки при которой происходит итеративный поиск границы символов
 */
#define ITERATIVE_SEARCH_MAX_LENGTH 20


void TrimRightSized(char *s , size_t stringLen)
{
    ptrdiff_t stepSize = (ptrdiff_t) stringLen / 2;

    char isInFront = 0;

    if (s[stepSize] == ' ')
        isInFront = IsThereWordBehind(s + stepSize);
    else
        isInFront = 1;

    if (stringLen <= ITERATIVE_SEARCH_MAX_LENGTH)
    {
        if (!isInFront)
            stepSize *= 0;

        int backIterativeSearchIndex = 0;
        while (s[stringLen + stepSize - backIterativeSearchIndex] == ' ')
            backIterativeSearchIndex++;
        s[stringLen + stepSize - backIterativeSearchIndex + 1] = 0;

        return;
    }

    if (isInFront)
        TrimRightSized(s + stepSize, stepSize);
    else
        TrimRightSized(s, stepSize);
}



// Первая версия алгоритма с нестабильным поведением на последних итерациях рядом с границей символов
void TrimRightSizedUnstable(char *s , size_t stringLen)
{
    ptrdiff_t signedStepSize = (ptrdiff_t) -stringLen;
    size_t searchIndex = stringLen - 1;

    if (stringLen < 10)
    {
        int index = stringLen - 1;

        while (s[index] == ' ') index--;
        s[index + 1] = 0;
        return;
    }


    while (1)
    {
        if (s[searchIndex] == ' ')
        {
            for (int i = INSTRING_MAX_SPACE_SEQUENCE_LENGTH; i > 0; i--)
                if (s[searchIndex - i] != ' ') break;

            if (signedStepSize != -1)
            {
                signedStepSize /= 2;
            }
            else break;

            searchIndex += signedStepSize;

        } else break;
    }

    TrimRightSizedUnstable(s + searchIndex, -signedStepSize);

}




void TrimRightOld( char *s )
{
    // Для начала поиска с конца строки необходимо вычислить её длинну
    size_t stringLen = strlen(s);


    ptrdiff_t signedStepSize = (ptrdiff_t) stringLen / -2;
    size_t lastNonSpaceIndex = stringLen - 1;
    unsigned char isLastNonSpaceIndexFound = 0;

    do
    {

        lastNonSpaceIndex += signedStepSize;

        if (s[lastNonSpaceIndex] == ' ')
        {
            char isInSpaceTail = 1;

            // Check if index in between words
            for (short i = 1; i < INSTRING_MAX_SPACE_SEQUENCE_LENGTH && isInSpaceTail; i++)
                if (s[lastNonSpaceIndex + i] != ' ') isInSpaceTail = 0;


            if (isInSpaceTail)
                signedStepSize /= 2;
            else
                signedStepSize /= -2;
        }
        else
            signedStepSize = 1;

        if(signedStepSize == 1 || signedStepSize == -1)
        {
            do
            {
                lastNonSpaceIndex -= signedStepSize;
            }
            while (s[lastNonSpaceIndex] == ' ');

            lastNonSpaceIndex += signedStepSize;
            isLastNonSpaceIndexFound = 1;
        }

    }
    while (!isLastNonSpaceIndexFound);

    s[lastNonSpaceIndex] = 0;

}