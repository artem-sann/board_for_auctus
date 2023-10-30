//
// Created by Artem Sannikov on 30.10.2023.
//
#include "auctus.h"
#include <string.h>
#include <stdlib.h>

/**
 * @Note Функция базовой настройки модуля
 * @param huart - Последовательный порт к которому подключен модуль
 * @param volume - Установка усиления динамика модуля, дапазон: 0 - 31
 * @param addr - ID группы, диапазон: 0 - 16777215
 * @param dmo_channel - Переключение канала, диапазон: 0 - 15
 * @param freq - Частота на прием и передачу, диапазон: 100000000 - 999999999 Гц
 * @return 0 - успешное выполнение, 1 - ошибка
 */
uint8_t simple_setup_auctus(UART_HandleTypeDef *huart, uint8_t  volume, uint32_t addr, uint8_t dmo_channel, uint32_t freq)
{
    uint8_t *response = malloc(60);
    uint8_t state;

    while(HAL_UART_Transmit_IT(huart,STR_CONNECT, strlen(STR_CONNECT)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }



    free(response);
    return 0;
}