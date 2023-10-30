//
// Created by Artem Sannikov on 30.10.2023.
//

#ifndef BOARD_FOR_AUCTUS_AUCTUS_H
#define BOARD_FOR_AUCTUS_AUCTUS_H

#endif //BOARD_FOR_AUCTUS_AUCTUS_H

#include "main.h"

uint8_t Timeout = 50;

uint8_t STR_CONNECT[] = "AT+DMOCONNECT\n";
uint8_t STR_DISCONNECT[] = "AT+DMODISCONNECT\n";
uint8_t STR_SWITCH[] = "AT+DMOSWITCH=";
uint8_t STR_GROUP[] = "AT+DMOSETGROUP=";
uint8_t STR_CURRCH[] = "AT+DMOGETCURRCH\n";
uint8_t STR_VOLUME[] = "AT+DMOSETVOLUME=";
uint8_t STR_MIC[] = "AT+DMOSETMIC=";
uint8_t STR_GRPADDR[] = "AT+DMOSETGRPADDR=";

uint8_t simple_setup_auctus(UART_HandleTypeDef *huart, uint8_t  volume, uint32_t addr, uint8_t dmo_channel, uint32_t freq);
