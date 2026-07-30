#include "KX132.h"

#include "stm32h7_can.h"
#include <stdbool.h>
#include <stdint.h>

/*
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET); // J8 Chip Select
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET); // J7 Chip Select
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); // J4 Chip Select
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); // J10 Chip Select
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); // J11 Chip Select
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // J9 Chip Select
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); // J3 Chip Select
*/

//
//  CONFIGURATION
//
void configure_cntl1(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure to leave standby mode
  tx_buff[0] = 0x18; // CNTL1 buffer
  tx_buff[1] =  0b11001000; // high power, high res, interrupt off, +/- 4g range (pg 15 of datasheet), 0, wake up off, 0

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}

void configure_odcntl(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure Output Data Rate
  tx_buff[0] = 0x1B; // ODCNTL buffer
  tx_buff[1] =  0b01001111; // low pass roll of set to ODR/2, ODR set to 25600Hz

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}


void configure_accels(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  configure_odcntl(phspi1, phspi3);
  //BUF_CNTL2?
  
  configure_cntl1(phspi1, phspi3);
}


//
// READ DATA REGISTERS
//
void read_accels(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3, uint8_t* rx_buff) {
  uint8_t tx_buff[7] = {0x00};
  tx_buff[0] = 0x08 | 0x80;

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi3, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi1, &tx_buff[0], &rx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}


//
// READ CONFIG AND STATUS REGISTERS
//
void check_whoami(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff) {
  uint8_t tx_buff[2] = {0x00};
  tx_buff[0] = 0x0F | 0x80;

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi, &tx_buff[0], rx_buff, 2, 200);
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);
}

void check_status(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff) {
  uint8_t tx_buff[2] = {0x00};
  tx_buff[0] = 0x18 | 0x80;

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi, &tx_buff[0], rx_buff, 2, 200);
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);
}

void check_configuration(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff) {
  uint8_t tx_buff[2] = {0x00};
  tx_buff[0] = 0x18 | 0x80;

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi, &tx_buff[0], rx_buff, 2, 200);
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);
}