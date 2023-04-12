#include <stddef.h>

enum membership {OPEN = 1, SENIOR = 2};
#ifdef _TESTS_CODEWARS_MSVC
void open_or_senior (const size_t n, const int *members[2], enum membership *memberships)
#else
void open_or_senior (const size_t n, const int members[n][2], enum membership memberships[n])
#endif
{
    for (int i = 0; i < n; i++)
        memberships[i] = (members[i][0] >= 55 && members[i][1] > 7) ? SENIOR : OPEN;
}

int main()
{

}