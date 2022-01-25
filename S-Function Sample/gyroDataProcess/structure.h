//
// Created by surface on 2022/1/21.
//

#ifndef _STRUCTURE_H
#define _STRUCTURE_H
typedef char uint8_T;
typedef short int16;

struct gyroData{
    int16_t accl[3], gyro[3];
    double temp;
};
#endif //_STRUCTURE_H
