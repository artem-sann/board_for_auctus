//
// Created by Artem Sannikov on 30.10.2023.
//
#include "auctus.h"
#include <string.h>
#include "stdio.h"

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
    uint8_t response[60];
    uint8_t state;
    uint8_t STR_2[60];
    uint8_t STR_3[60];
    uint8_t STR_4[60];
    uint8_t STR_5[60];
    uint8_t STR_6[60];
    uint8_t STR_7[60];


    snprintf(STR_2, sizeof STR_2, "%s%d\n", STR_SWITCH, dmo_channel);
    snprintf(STR_3, sizeof STR_3, "%s2,0,%lu,%lu,00,00,3,2\n", STR_GROUP, freq, freq);
    snprintf(STR_4, sizeof STR_4, "%s", STR_CURRCH);
    snprintf(STR_5, sizeof STR_5, "%s%d\n", STR_VOLUME, volume);
    snprintf(STR_6, sizeof STR_6, "%s%d\n", STR_MIC, 6);
    snprintf(STR_7, sizeof STR_7, "%s%lu\n", STR_GRPADDR, addr);


    while(HAL_UART_Transmit_IT(huart,STR_CONNECT, strlen(STR_CONNECT)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    if (response[12] != 48) return 1;
    memset(response,0,sizeof(response));


    while(HAL_UART_Transmit_IT(huart, STR_2, strlen(STR_2)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    while(HAL_UART_Transmit_IT(huart, STR_3, strlen(STR_3)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    while(HAL_UART_Transmit_IT(huart, STR_4, strlen(STR_4)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    while(HAL_UART_Transmit_IT(huart, STR_5, strlen(STR_5)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    while(HAL_UART_Transmit_IT(huart, STR_6, strlen(STR_6)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    while(HAL_UART_Transmit_IT(huart, STR_7, strlen(STR_7)) == HAL_BUSY );
    HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    memset(response,0,sizeof(response));

    return 0;
}