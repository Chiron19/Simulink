#include <iostream>
#include "dataprocess.cpp"

gyroData g[5];
uint8_T buf[256] = "1, Y = 122, Z=30\nTemp=34.423]\n[Accl X=101, Y = -111, Z=1023\nGyro  X=-10231, Y = 1101, Z=0230\nTemp=23.7893]\n[Accl X=321, Y = -211, Z=-23\nGyro  X=231, Y = 122, Z=30\nTemp=33.643]\n";

int subGyroData(const uint8_T *buffer, gyroData *pData)
{
    int k = 0;
    int len = strlen(buffer), tmp = -1;
    for (int i = 0; i < len; ++i) {
        if (buffer[i] == '[' && tmp == -1) tmp = i;
        if (buffer[i] == ']' && tmp != -1) {
            pData[k].accl[0] =  readInt(buffer, tmp);
            pData[k].accl[1] =  readInt(buffer, tmp);
            pData[k].accl[2] =  readInt(buffer, tmp);
            pData[k].gyro[0] =  readInt(buffer, tmp);
            pData[k].gyro[1] =  readInt(buffer, tmp);
            pData[k].gyro[2] =  readInt(buffer, tmp);
            pData[k].temp = readDouble(buffer, tmp);
            ++k;
            tmp = -1;
        }
    }
    return k;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    g[5] = new(gyroData);
    int k = subGyroData(buf, g);
    std::cout << k << std::endl;
    for (int i = 0; i < k; ++i) {
        std::cout << g[i].accl[0] << ' ' << g[i].accl[1] << ' ' << g[i].accl[2] << std::endl;
        std::cout << g[i].gyro[0] << ' ' << g[i].gyro[1] << ' ' << g[i].gyro[2] << std::endl;
        std::cout << g[i].temp << std::endl << std::endl;
    }
    return 0;
}