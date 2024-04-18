//
// Created by Artem Sannikov on 30.10.2023.
//

#ifndef BOARD_FOR_AUCTUS_AUCTUS_H
#define BOARD_FOR_AUCTUS_AUCTUS_H

#endif //BOARD_FOR_AUCTUS_AUCTUS_H

#include "main.h"

uint8_t simple_setup_auctus(UART_HandleTypeDef *huart, uint8_t  volume, uint32_t addr, uint8_t dmo_channel, uint32_t freq_in, uint32_t freq_out);
uint8_t send_sms(UART_HandleTypeDef *huart, uint8_t type,  uint32_t addr, uint8_t size, uint8_t  *message);
uint8_t digital_setup(UART_HandleTypeDef *huart);