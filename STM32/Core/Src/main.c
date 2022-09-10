/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
	int redMainCounter = 5;
	int greenMainCounter = 3;
	int yellowMainCounter = 2;

	int redSideCounter = 5;
	int greenSideCounter = 3;
	int yellowSideCounter = 2;

	GPIO_PinState RED_MAIN_STATE;
	GPIO_PinState YELLOW_MAIN_STATE;
	GPIO_PinState GREEN_MAIN_STATE;
	GPIO_PinState RED_SIDE_STATE;
	GPIO_PinState YELLOW_SIDE_STATE;
	GPIO_PinState GREEN_SIDE_STATE;

	int firstInit = 0;

	void readAllPinState(){
		RED_MAIN_STATE = HAL_GPIO_ReadPin(LED_RED_GPIO_Port, LED_RED_Pin);
		YELLOW_MAIN_STATE = HAL_GPIO_ReadPin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
		GREEN_MAIN_STATE = HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		RED_SIDE_STATE = HAL_GPIO_ReadPin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
		YELLOW_SIDE_STATE = HAL_GPIO_ReadPin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
		GREEN_SIDE_STATE = HAL_GPIO_ReadPin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
	}

	void displayMain7SEG(int counter){
		HAL_GPIO_WritePin (A_MAIN_GPIO_Port, A_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (B_MAIN_GPIO_Port, B_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (C_MAIN_GPIO_Port, C_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (D_MAIN_GPIO_Port, D_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (F_MAIN_GPIO_Port, F_MAIN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (G_MAIN_GPIO_Port, G_MAIN_Pin, GPIO_PIN_RESET);

		switch (counter){
			case 1:
				HAL_GPIO_WritePin (A_MAIN_GPIO_Port, A_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (D_MAIN_GPIO_Port, D_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_MAIN_GPIO_Port, F_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (G_MAIN_GPIO_Port, G_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 2:
				HAL_GPIO_WritePin (F_MAIN_GPIO_Port, F_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (C_MAIN_GPIO_Port, C_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 3:
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_MAIN_GPIO_Port, F_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 4:
				HAL_GPIO_WritePin (A_MAIN_GPIO_Port, A_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (D_MAIN_GPIO_Port, D_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 5:
				HAL_GPIO_WritePin (B_MAIN_GPIO_Port, B_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 6:
				HAL_GPIO_WritePin (B_MAIN_GPIO_Port, B_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 7:
				HAL_GPIO_WritePin (D_MAIN_GPIO_Port, D_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_MAIN_GPIO_Port, F_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 8:
				break;
			case 9:
				HAL_GPIO_WritePin (E_MAIN_GPIO_Port, E_MAIN_Pin, GPIO_PIN_SET);
				break;
			case 0:
				HAL_GPIO_WritePin (G_MAIN_GPIO_Port, G_MAIN_Pin, GPIO_PIN_SET);
				break;
		}
	}

	void displaySide7SEG(int counter){
		HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (C_SIDE_GPIO_Port, C_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_RESET);

		switch (counter){
			case 1:
				HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 2:
				HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (C_SIDE_GPIO_Port, C_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 3:
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 4:
				HAL_GPIO_WritePin (A_SIDE_GPIO_Port, A_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 5:
				HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 6:
				HAL_GPIO_WritePin (B_SIDE_GPIO_Port, B_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 7:
				HAL_GPIO_WritePin (D_SIDE_GPIO_Port, D_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin (F_SIDE_GPIO_Port, F_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 8:
				break;
			case 9:
				HAL_GPIO_WritePin (E_SIDE_GPIO_Port, E_SIDE_Pin, GPIO_PIN_SET);
				break;
			case 0:
				HAL_GPIO_WritePin (G_SIDE_GPIO_Port, G_SIDE_Pin, GPIO_PIN_SET);
				break;
		}
	}

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (firstInit == 0){
		HAL_GPIO_WritePin (LED_RED_GPIO_Port ,LED_RED_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin (LED_YELLOW_GPIO_Port ,LED_YELLOW_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin (LED_GREEN_GPIO_Port ,LED_GREEN_Pin ,GPIO_PIN_RESET);

		HAL_GPIO_WritePin (LED_RED_1_GPIO_Port ,LED_RED_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin (LED_YELLOW_1_GPIO_Port ,LED_YELLOW_1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin (LED_GREEN_1_GPIO_Port ,LED_GREEN_1_Pin ,GPIO_PIN_SET);
		firstInit = 1;
	  }


	  if (redMainCounter <= 0){
		redMainCounter = 5;
		HAL_GPIO_WritePin (LED_RED_GPIO_Port ,LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin (LED_GREEN_GPIO_Port ,LED_GREEN_Pin ,GPIO_PIN_RESET);
	  }
	  else if (yellowMainCounter <= 0){
		yellowMainCounter = 2;
		HAL_GPIO_WritePin (LED_RED_GPIO_Port ,LED_RED_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin (LED_YELLOW_GPIO_Port ,LED_YELLOW_Pin ,GPIO_PIN_SET);
	  }
	  else if (greenMainCounter <= 0){
		greenMainCounter = 3;
		HAL_GPIO_WritePin (LED_YELLOW_GPIO_Port ,LED_YELLOW_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin (LED_GREEN_GPIO_Port ,LED_GREEN_Pin ,GPIO_PIN_SET);
	  }

	  if (redSideCounter <= 0){
		redSideCounter = 5;
		HAL_GPIO_WritePin (LED_RED_1_GPIO_Port ,LED_RED_1_Pin ,GPIO_PIN_SET);
		HAL_GPIO_WritePin (LED_GREEN_1_GPIO_Port ,LED_GREEN_1_Pin ,GPIO_PIN_RESET);
	  }
	  else if (yellowSideCounter <= 0){
		yellowSideCounter = 2;
		HAL_GPIO_WritePin (LED_RED_1_GPIO_Port ,LED_RED_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin (LED_YELLOW_1_GPIO_Port ,LED_YELLOW_1_Pin ,GPIO_PIN_SET);
	  }
	  else if (greenSideCounter <= 0){
		greenSideCounter = 3;
		HAL_GPIO_WritePin (LED_YELLOW_1_GPIO_Port ,LED_YELLOW_1_Pin ,GPIO_PIN_RESET);
		HAL_GPIO_WritePin (LED_GREEN_1_GPIO_Port ,LED_GREEN_1_Pin ,GPIO_PIN_SET);
	  }

	  readAllPinState();

	  if (RED_MAIN_STATE == GPIO_PIN_RESET){
		  displayMain7SEG(redMainCounter);
		  redMainCounter--;
	  }
	  else if (YELLOW_MAIN_STATE == GPIO_PIN_RESET){
		  displayMain7SEG(yellowMainCounter);
		  yellowMainCounter--;
	  }
	  else if (GREEN_MAIN_STATE == GPIO_PIN_RESET){
		  displayMain7SEG(greenMainCounter);
		  greenMainCounter--;
	  }

	  if (RED_SIDE_STATE == GPIO_PIN_RESET){
		  displaySide7SEG(redSideCounter);
		  redSideCounter--;
	  }
	  else if (YELLOW_SIDE_STATE == GPIO_PIN_RESET){
		  displaySide7SEG(yellowSideCounter);
		  yellowSideCounter--;
	  }
	  else if (GREEN_SIDE_STATE == GPIO_PIN_RESET){
		  displaySide7SEG(yellowSideCounter);
		  greenSideCounter--;
	  }

	  HAL_Delay(1000);

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin|A_MAIN_Pin|B_MAIN_Pin
                          |C_MAIN_Pin|D_MAIN_Pin|E_MAIN_Pin|F_MAIN_Pin
                          |G_MAIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_SIDE_Pin|B_SIDE_Pin|C_SIDE_Pin|D_SIDE_Pin
                          |E_SIDE_Pin|F_SIDE_Pin|G_SIDE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_RED_1_Pin
                           LED_YELLOW_1_Pin LED_GREEN_1_Pin A_MAIN_Pin B_MAIN_Pin
                           C_MAIN_Pin D_MAIN_Pin E_MAIN_Pin F_MAIN_Pin
                           G_MAIN_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin|A_MAIN_Pin|B_MAIN_Pin
                          |C_MAIN_Pin|D_MAIN_Pin|E_MAIN_Pin|F_MAIN_Pin
                          |G_MAIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_SIDE_Pin B_SIDE_Pin C_SIDE_Pin D_SIDE_Pin
                           E_SIDE_Pin F_SIDE_Pin G_SIDE_Pin */
  GPIO_InitStruct.Pin = A_SIDE_Pin|B_SIDE_Pin|C_SIDE_Pin|D_SIDE_Pin
                          |E_SIDE_Pin|F_SIDE_Pin|G_SIDE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
