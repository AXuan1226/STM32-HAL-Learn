#ifndef __TESTRUN_H
#define __TESTRUN_H

#include "stm32f4xx_hal.h"

#include "lcd.h"
#include "delay.h"
#include "gui.h"
#include "pic.h"

// 如果需要，声明 SPI 句柄为外部全局变量
extern SPI_HandleTypeDef hspi1;

void test_display(void);

void DrawTestPage(uint8_t *str);
void Test_Color(void);
void Test_FillRec(void);
void Test_Circle(void);
void Test_Triangle(void);
void English_Font_test(void);
void Chinese_Font_test(void);
void Pic_test(void);
void Load_Drow_Dialog(void);
void Rotate_Test(void);


#endif 
