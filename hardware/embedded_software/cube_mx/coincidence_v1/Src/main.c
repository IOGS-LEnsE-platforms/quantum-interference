/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lptim.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char 		txBuffer[20] = {0};
int			a_counter = 0, a_counter_save = 0;
int			b_counter = 0, b_counter_save = 0;
int			c_counter = 0, c_counter_save = 0;
int			ab_counter = 0, ab_counter_save = 0;
int			ac_counter = 0, ac_counter_save = 0;
int			bc_counter = 0, bc_counter_save = 0;
int			abc_counter = 0, abc_counter_save = 0;

/*Configure GPIO pins : PA4 PA5 PA6 PA7
                         PA8 PA9 PA10 PA11 */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_LPTIM1_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  // TIM16 - 16 bits Timer / Period = (PSC+1)(ARR+1) / 170MHz  (??)  ARR = 2^16
  // For PSC = 2615 -> T = 1000ms

  // Init
  txBuffer[0] = 'Z';
  txBuffer[1] = '\r';
  txBuffer[2] = '\n';
  txBuffer[3] = '\0';


  // Start TIM16 timer
  HAL_TIM_Base_Start_IT(&htim16);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	//HAL_UART_Transmit(&huart2, txBuffer, 4, 1000);
	//HAL_Delay(100);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
// Interrupt on EXTI - PA4, PA5...
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_1) // If The INT Source Is EXTI Line1 (A1 Pin)
    {
    	a_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_4) // If The INT Source Is EXTI Line4 (A4 Pin)
    {
    	b_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_6) // If The INT Source Is EXTI Line6 (A6 Pin)
    {
    	c_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_8) // If The INT Source Is EXTI Line8 (A8 Pin)
    {
    	ab_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_9) // If The INT Source Is EXTI Line9 (A9 Pin)
    {
    	abc_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_12) // If The INT Source Is EXTI Line12 (A12 Pin)
    {
    	bc_counter++;
    }
    if(GPIO_Pin == GPIO_PIN_5) // If The INT Source Is EXTI Line5 (PB5 Pin)
    {
    	ac_counter++;
    }
}

// Interrupt on TIM - TIM16
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
    a_counter_save = a_counter;
    a_counter = 0;
    b_counter_save = b_counter;
    b_counter = 0;
    c_counter_save = c_counter;
    c_counter = 0;
    ab_counter_save = ab_counter;
    ab_counter = 0;
    ac_counter_save = ac_counter;
    ac_counter = 0;
    bc_counter_save = bc_counter;
    bc_counter = 0;
    abc_counter_save = abc_counter;
    abc_counter = 0;
	sprintf(txBuffer, "A=%d\n", a_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "B=%d\n", b_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "C=%d\n", c_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "AB=%d\n", ab_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "AC=%d\n", ac_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "BC=%d\n", bc_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
	sprintf(txBuffer, "ABC=%d\n", abc_counter_save+1);
    HAL_UART_Transmit(&huart2, (uint8_t *)txBuffer, strlen(txBuffer), 1000);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
