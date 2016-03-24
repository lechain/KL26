
#ifndef __APP_H__
#define __APP_H__

#include "stdint.h"
#include "include.h"
typedef struct {
	float m_angle;
	float m_rate;
} angleTypeDef;

typedef struct {
	uint32_t leftDuty;
	uint32_t rightDuty;
} dutyTypeDef;

typedef struct {
	float m_accz;
	float m_gyro;
} balanceDataTypeDef;

typedef struct {
	float m_Left;
	float m_Right;
} speedDataTypeDef;


typedef struct {
	uint32_t m_value[4];
	int32_t m_dir_flag;
} directionDataTypeDef;

//采集平衡环所需数据
void getBalanceData(balanceDataTypeDef* data);

void getDirectionData(directionDataTypeDef* data);

//计算平衡环占空比
void balanceCtrl(angleTypeDef* angle, dutyTypeDef* output);

//计算方向环占空比
void directionCtrl(directionDataTypeDef* data, dutyTypeDef* output);

//使用占空比控制电机
void motorCtrl(const dutyTypeDef* output);

// 卡尔曼滤波函数
void kalmanFilter(const balanceDataTypeDef* data, angleTypeDef* outAngle);

#endif
