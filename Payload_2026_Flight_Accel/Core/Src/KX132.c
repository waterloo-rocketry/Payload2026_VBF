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
  tx_buff[1] =  0b11011000; // high power, high res, interrupt off, +/- 4g range (pg 15 of datasheet), 0, wake up off, 0


  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}

void put_in_standby(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure to leave standby mode
  tx_buff[0] = 0x18; // CNTL1 buffer
  tx_buff[1] =  0b00000000; // high power, high res, interrupt off, +/- 16g range (pg 15 of datasheet), 0, wake up off, 0

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}

void configure_buff_cntl1(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure to leave standby mode
  tx_buff[0] = 0x3A; // BUFF_CNTL1 address, in Write mode 
  tx_buff[1] =  0x2B; // 43 byte buffer max for 16 bit resolution

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}


void configure_buff_cntl2(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure to leave standby mode
  tx_buff[0] = 0x3B; // BUFF_CNTL2 address, in Write mode 
  tx_buff[1] = 0b11100001; // enabled, 16 bit resolution, stream mode

  // J3 Accelerometer
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

  // J4 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

  // J6 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET); // J6 Chip Select

  // J7 Accelerometer
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

  // J8 Accelerometer
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

  // J9 Accelerometer
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  // J10 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi3, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

  // J11 Accelerometer
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi1, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
}


void configure_odcntl(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3) {
  uint8_t tx_buff[2] = {0x00};
  uint8_t rx_buff[2] = {0x00};
  
  // Configure Output Data Rate
  tx_buff[0] = 0x1B; // ODCNTL buffer
  tx_buff[1] =  0b010001100; // low pass roll of set to ODR/2, ODR set to 6.4kHz

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
  HAL_Delay(1000);

  put_in_standby(phspi1, phspi3);

  configure_odcntl(phspi1, phspi3); // configure output data rate
  configure_buff_cntl1(phspi1, phspi3); // configure buffer size
  configure_buff_cntl2(phspi1, phspi3); //configure buffer behaviour

  configure_odcntl(phspi1, phspi3); // configure output data rate
  configure_buff_cntl1(phspi1, phspi3); // configure buffer size
  configure_buff_cntl2(phspi1, phspi3); //configure buffer behaviour

  HAL_Delay(1000);
  configure_cntl1(phspi1, phspi3);// Configure accelerometer sampling behaviour. Takes accels out of standby mode, do not reconfigure after this
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

void check_buff_cntl1_configuration(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff) {
  uint8_t tx_buff[2] = {0x00};
  tx_buff[0] = 0x3A | 0x80;

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi, &tx_buff[0], rx_buff, 2, 200);
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);
}

uint8_t check_buff_status(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff_address) {
  uint8_t tx_buff_stat[2] = {0x00};
  tx_buff_stat[0] = 0x3C | 0x80; // reading from buffer status register
  uint8_t rx_buff_stat[2];

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  if (HAL_SPI_TransmitReceive(phspi, &tx_buff_stat[0], &rx_buff_stat[0], 2, 500) != HAL_OK) {
    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_5);
    HAL_Delay(1000);
  };
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);

  return rx_buff_stat[1];
}

uint8_t check_buff_full_status(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff_address) {
  uint8_t tx_buff_stat[2] = {0x00};
  tx_buff_stat[0] = 0x3D | 0x80; // reading from buffer status register
  uint8_t rx_buff_stat[2];

  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(phspi, &tx_buff_stat[0], &rx_buff_stat[0], 2, 500);
  HAL_GPIO_WritePin(GPIO, pin, GPIO_PIN_SET);

  return rx_buff_stat[1];
}

void configure_one_accel(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t GPIO_PIN){
  uint8_t tx_buff[2] = {0x00};
  
  // PUT IN STANDBY
  tx_buff[0] = 0x18; // CNTL1 buffer
  tx_buff[1] =  0b00000000; 

  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_SET);

  // CONFIGURE ODCNTL
  tx_buff[0] = 0x1B; // ODCNTL buffer
  tx_buff[1] =  0b010001100; // low pass roll of set to ODR/2, ODR set to 6.4kHz

  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_SET);
  
  // CONFIGURE BUFF_CNTL1
  tx_buff[0] = 0x3A; // BUFF_CNTL1 address, in Write mode 
  tx_buff[1] =  0x2B; // 43 byte buffer max for 16 bit resolution
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_SET);

  // CONFIGURE BUFF_CNTL2
  tx_buff[0] = 0x3B; // BUFF_CNTL2 address, in Write mode 
  tx_buff[1] = 0b11100001; // enabled, 16 bit resolution, stream mode

  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_SET);

  // SET ACCELEROMETER AND TAKE OUT OF STANDBY
  tx_buff[0] = 0x18; // CNTL1 buffer
  tx_buff[1] =  0b11011000; // high power, high res, interrupt off, +/- 16g range (pg 15 of datasheet), 0, wake up off, 0

  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_RESET);
  HAL_SPI_Transmit(phspi, &tx_buff[0], 2, 200);
  HAL_GPIO_WritePin(GPIO, GPIO_PIN, GPIO_PIN_SET);

}
