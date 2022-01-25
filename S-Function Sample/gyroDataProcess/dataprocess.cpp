#include "dataprocess.h"

inline int readInt(const uint8_T *buffer, int &i)
{
    while (!(buffer[i] == '-' || isdigit(buffer[i]))) ++i;
    int neg = 1, x = 0;
    if (buffer[i] == '-') neg = -1, ++i;
    while (isdigit(buffer[i])) {
        x = x * 10 + buffer[i] - '0';
        ++i;
    }
    return neg * x;
}

inline double readDouble(const uint8_T *buffer, int &i)
{
    long long s = 0, w = 1, k = 0, n = 0, m = 0;
    while(!isdigit(buffer[i]))
    {
        if(buffer[i] == '-') w = -1;
        ++i;
    }
    while(isdigit(buffer[i]) || buffer[i] == '.')
    {
        if (buffer[i] == '.') n = 1;
        else if (n == 0) s = s * 10 + buffer[i] - '0';
        else k = k * 10 + buffer[i] - '0', m++;
        i++;
    }
    return (pow(0.1, m) * k + s) * w;
}
