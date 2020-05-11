/**
******************************************************************************
* @file    Project/STM8L15x_StdPeriph_Template/stm8l15x_it.c
* @author  MCD Application Team
* @version V1.5.0
* @date    13-May-2011
* @brief   Main Interrupt Service Routines.
*          This file provides template for all peripherals interrupt service routine.
******************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm8l15x_it.h"
#include "adf.h"
#include "board.h"
#include "task_main.h"
//#include "task_motor.h"
#include "task_key.h"
//#include "sx1278.h"
//#include "key.h"
/** @addtogroup STM8L15x_StdPeriph_Template
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
* @brief Dummy interrupt routine
* @par Parameters:
* None
* @retval
* None
*/
INTERRUPT_HANDLER(NonHandledInterrupt,0)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
#endif

/**
* @brief TRAP interrupt routine
* @par Parameters:
* None
* @retval
* None
*/
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief FLASH Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(FLASH_IRQHandler,1)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief DMA1 channel0 and channel1 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(DMA1_CHANNEL0_1_IRQHandler,2)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */

    /* Clear IT Pending Bit */
}

/**
* @brief DMA1 channel2 and channel3 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(DMA1_CHANNEL2_3_IRQHandler,3)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief RTC / CSS_LSE Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(RTC_CSSLSE_IRQHandler,4)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    /* Clear the periodic wakeup unit flag */

    if (RTC_GetITStatus(RTC_IT_WUT) != RESET)
    {
        //g_run_params.awu_flag = TRUE;
        task_main();
        wdg_reset();
        RTC_ClearITPendingBit(RTC_IT_WUT);
    }
}

/**
* @brief External IT PORTE/F and PVD Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTIE_F_PVD_IRQHandler,5)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief External IT PORTB / PORTG Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTIB_G_IRQHandler,6)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief External IT PORTD /PORTH Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTID_H_IRQHandler,7)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief External IT PIN0 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI0_IRQHandler,8)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    // ����Ƿ��
    task_key_set_pluse_counter();

    EXTI_ClearITPendingBit(EXTI_IT_Pin0);
    //printf("KEY Pressed:%d\r\n", key_get(EXTI_IT_Pin0));
}

/**
* @brief External IT PIN1 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI1_IRQHandler,9)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    EXTI_ClearITPendingBit(EXTI_IT_Pin1);
    //printf("KEY Pressed:%d\r\n", key_get(EXTI_IT_Pin1));
}

/**
* @brief External IT PIN2 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI2_IRQHandler,10)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    // ��2���ؼ��
//    if (0 == exti_read_state(E_LIGHT_2))
//    {
//        task_key_set_pluse_counter(E_LIGHT_2);
//
//#ifdef LIGHT_DEBUG
//    printf("light2 pluse\r\n");
//#endif
//    }

    EXTI_ClearITPendingBit(EXTI_IT_Pin2);
}

/**
* @brief External IT PIN3 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI3_IRQHandler,11)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */

    // ��1���ؼ��
//    if (0 == exti_read_state(E_LIGHT_1))
//    {
//        task_key_set_pluse_counter(E_LIGHT_1);
//
//#ifdef LIGHT_DEBUG
//        //printf("light1 pluse\r\n");
//#endif
//    }

    EXTI_ClearITPendingBit(EXTI_IT_Pin3);
}

/**
* @brief External IT PIN4 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI4_IRQHandler,12)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    // ����2
    EXTI_ClearITPendingBit(EXTI_IT_Pin4);
    task_key_triggered(key_get(EXTI_IT_Pin4));  // ������������

#ifdef LIGHT_DEBUG
    printf("KEY Pressed:%c\r\n", key_get(EXTI_IT_Pin4));
#endif
}

/**
* @brief External IT PIN5 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI5_IRQHandler,13)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    // ����1
//    task_key_triggered(key_get(EXTI_IT_Pin5));
    EXTI_ClearITPendingBit(EXTI_IT_Pin5);
    task_key_triggered(key_get(EXTI_IT_Pin5));  // ������������

#ifdef LIGHT_DEBUG
    printf("KEY Pressed:%c\r\n", key_get(EXTI_IT_Pin5));
#endif
}

/**
* @brief External IT PIN6 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI6_IRQHandler,14)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    EXTI_ClearITPendingBit(EXTI_IT_Pin6);
//    task_key_triggered(key_get(EXTI_IT_Pin6));
//#ifdef LIGHT_DEBUG
//    printf("KEY Pressed:%c\r\n", key_get(EXTI_IT_Pin6));
//#endif
}

/**
* @brief External IT PIN7 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI7_IRQHandler,15)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    EXTI_ClearITPendingBit(EXTI_IT_Pin7);
//    task_key_triggered(key_get(EXTI_IT_Pin7));
//#ifdef LIGHT_DEBUG
//    printf("KEY Pressed:%c\r\n", key_get(EXTI_IT_Pin7));
//#endif
}
/**
* @brief LCD /AES Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(LCD_AES_IRQHandler,16)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief CLK switch/CSS/TIM1 break Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(SWITCH_CSS_BREAK_DAC_IRQHandler,17)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief ADC1/Comparator Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(ADC1_COMP_IRQHandler,18)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief TIM2 Update/Overflow/Trigger/Break /USART2 TX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM2_UPD_OVF_TRG_BRK_USART2_TX_IRQHandler,19)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief Timer2 Capture/Compare / USART2 RX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM2_CC_USART2_RX_IRQHandler,20)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}


/**
* @brief Timer3 Update/Overflow/Trigger/Break Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM3_UPD_OVF_TRG_BRK_USART3_TX_IRQHandler,21)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief Timer3 Capture/Compare /USART3 RX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM3_CC_USART3_RX_IRQHandler,22)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief TIM1 Update/Overflow/Trigger/Commutation Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_COM_IRQHandler,23)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief TIM1 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM1_CC_IRQHandler,24)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief TIM4 Update/Overflow/Trigger Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler,25)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @brief SPI1 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(SPI1_IRQHandler,26)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}

/**
* @brief USART1 TX / TIM5 Update/Overflow/Trigger/Break Interrupt  routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(USART1_TX_TIM5_UPD_OVF_TRG_BRK_IRQHandler,27)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    //printf("USART1_TX_TIM5_UPD_OVF_TRG_BRK_IRQHandler\r\n");

    USART_ClearITPendingBit(USART1, USART_IT_TC);
}

/**
* @brief USART1 RX / Timer5 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(USART1_RX_TIM5_CC_IRQHandler,28)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
    com_isr(COM1);
}

/**
* @brief I2C1 / SPI2 Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(I2C1_SPI2_IRQHandler,29)
{
    /* In order to detect unexpected events during development,
    it is recommended to set a breakpoint on the following instruction.
    */
}
/**
* @}
*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/