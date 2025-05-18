#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化延时模块，启动 TIM1 计数器。
 */
void delay_init(void);

/**
 * @brief 延时指定的毫秒数
 *
 * @param ms 需要延时的毫秒数
 */
void delay_ms(uint32_t ms);

/**
 * @brief 延时指定的微秒数
 *
 * @param us 需要延时的微秒数
 */
void delay_us(uint32_t us);

#ifdef __cplusplus
}
#endif

#endif /* DELAY_H */
