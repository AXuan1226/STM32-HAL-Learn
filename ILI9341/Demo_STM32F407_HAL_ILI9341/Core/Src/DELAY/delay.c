#include "delay.h"
#include "stm32f4xx_hal.h"
// 根据你的CubeMX工程，TIM1句柄通常在tim.c中定义，此处声明extern变量
extern TIM_HandleTypeDef htim1;

/* 
 * 根据你的 TIM1 配置：
 * TIM1 Tick Frequency = 168,000,000 / (Prescaler+1) ≈ 16800 Hz 
 */
#define TIM1_TICK_FREQ      16800.0f
#define TIM1_TICK_PERIOD_US (1000000.0f / TIM1_TICK_FREQ)  // 约 59.52 µs

/**
 * @brief 初始化延时模块，启动 TIM1
 */
void delay_init(void)
{
    // 启动 TIM1，建议放在系统初始化后调用
    HAL_TIM_Base_Start(&htim1);
}

/**
 * @brief 毫秒延时函数
 *
 * 利用 TIM1 的计数器计时，计算需要等待的计数“步数”。注意该函数适用于延时值较大，
 * 因为 TIM1的一个计数周期大约 60 µs，每毫秒大约需要 16.8 个 tick 。
 *
 * @param ms 毫秒数
 */
void delay_ms(uint32_t ms)
{
    uint32_t start = __HAL_TIM_GET_COUNTER(&htim1);
    // 计算需要等待的计数步数：tick_needed = (ms * 1000) / T_tick
    uint32_t ticks_needed = (uint32_t)((ms * 1000.0f) / TIM1_TICK_PERIOD_US);
    // 利用无符号数做自动wrap-around处理
    while ((((uint16_t)__HAL_TIM_GET_COUNTER(&htim1) - (uint16_t)start)) < ticks_needed);
}

/**
 * @brief 微秒延时函数
 *
 * @param us 微秒数；由于 TIM1 的分辨率约为 60 µs，
 * 若 us 小于 60，内部会自动延时至少一个 tick。
 */
void delay_us(uint32_t us)
{
    uint32_t start = __HAL_TIM_GET_COUNTER(&htim1);
    uint32_t ticks_needed = (uint32_t)(us / TIM1_TICK_PERIOD_US);
    if(ticks_needed < 1)
        ticks_needed = 1;
    while ((((uint16_t)__HAL_TIM_GET_COUNTER(&htim1) - (uint16_t)start)) < ticks_needed);
}
