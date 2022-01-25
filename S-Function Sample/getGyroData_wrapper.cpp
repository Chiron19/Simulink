
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

#include "getGyroData_bus.h"

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "dataprocess.cpp"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 128
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void getGyroData_Outputs_wrapper(const uint8_T *buffer,
			gyroData *pData,
			int32_T *str,
			int32_T *len)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
int tmp = -1;
    len[0] = 128;
    for (int i = 0; i < len[0]; ++i) {
        if (buffer[i] == '[' && tmp == -1) tmp = i;
        if (buffer[i] == ']' && tmp != -1) {   
            pData[0].accl[0] =  readInt(buffer, tmp);
            pData[0].accl[1] =  readInt(buffer, tmp);
            pData[0].accl[2] =  readInt(buffer, tmp);
            pData[0].gyro[0] =  readInt(buffer, tmp);
            pData[0].gyro[1] =  readInt(buffer, tmp);
            pData[0].gyro[2] =  readInt(buffer, tmp);
            pData[0].temp = readDouble(buffer, tmp);
            tmp = -1;
        }
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


