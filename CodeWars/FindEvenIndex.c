#include <stdbool.h>
#include <assert.h>


bool check_even_index(const int *values, int length, int index)
{
    int leftSum = 0;
    int rightSum = 0;

    if (index != 0)
        for (int i = index - 1; i >= 0; i--)
            leftSum += values[i];

    if (index != length - 1)
        for (int i = index + 1; i < length; i++)
            rightSum += values[i];
    
    if (leftSum == rightSum) return true;
    
    return false;
}

int find_even_index(const int *values, int length)
{
    for (int i = 0; i < length; i++)
        if (check_even_index(values, length, i)) return i;
    
    return -1;
}


int main()
{
    {
        int arr[] = {1, 2, 3, 4, 3, 2, 1};
        int expected = 3;
        int result = find_even_index(arr, (int) (sizeof(arr) / sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 1,100,50,-51,1,1 };
        int expected = 1;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 1,2,3,4,5,6 };
        int expected = -1;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 20,10,30,10,10,15,35 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 20,10,-80,10,10,15,35 };
        int expected = 0;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 10,-80,10,10,15,35,20 };
        int expected = 6;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { 0,0,0,0,0 };
        int expected = 0;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }

    {
        int arr[] = { -1,-2,-3,-4,-3,-2,-1 };
        int expected = 3;
        int result = find_even_index(arr, (int)(sizeof(arr)/sizeof(arr[0])));
        assert(result == expected);
    }
}