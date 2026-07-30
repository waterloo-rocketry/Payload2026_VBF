/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KX132_H



#define __KX132_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


void configure_accels(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3);
void check_whoami(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff);
void check_status(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff);
void check_configuration(SPI_HandleTypeDef* phspi, GPIO_TypeDef* GPIO, uint16_t pin, uint8_t* rx_buff);
void read_accels(SPI_HandleTypeDef* phspi1, SPI_HandleTypeDef* phspi3, uint8_t* rx_buff);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */