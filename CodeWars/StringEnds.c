#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    size_t string_len = strlen(string);
    size_t ending_len = strlen(ending);

    bool status = true;

    if (ending_len == 0) return true;
    if (ending_len > string_len) return false;

    for (ptrdiff_t i = (ptrdiff_t) ending_len - 1; (i >= 0) && status; i--)
        if (ending[i] != string[i + string_len - ending_len]) status = false;

    return status;
}



int main()
{
    bool var1 = solution("abc", "bc");
    bool var2 = solution("abc", "d");
    bool var3 = solution("abc", "");
    bool var4 = solution("ails", "fails");
}