//
// Created by Artem Sannikov on 30.10.2023.
//
#include "auctus.h"
#include <string.h>
#include "stdio.h"

uint8_t Timeout = 255;

uint8_t STR_CONNECT[] = "AT+DMOCONNECT";
uint8_t STR_DISCONNECT[] = "AT+DMODISCONNECT\n";
uint8_t STR_SWITCH[] = "AT+DMOSWITCH=";
uint8_t STR_GROUP[] = "AT+DMOSETGROUP=";
uint8_t STR_CURRCH[] = "AT+DMOGETCURRCH";
uint8_t STR_VOLUME[] = "AT+DMOSETVOLUME=";
uint8_t STR_MIC[] = "AT+DMOSETMIC=";
uint8_t STR_GRPADDR[] = "AT+DMOSETGRPADDR=";
uint8_t STR_SEND[] = "AT+ SENDMSG=";

/**
 * @Note Функция базовой настройки модуля
 * @param huart - Последовательный порт к которому подключен модуль
 * @param volume - Установка усиления динамика модуля, дапазон: 0 - 31
 * @param addr - ID группы, диапазон: 0 - 16777215
 * @param dmo_channel - Переключение канала, диапазон: 0 - 15
 * @param freq_in - Частота на прием, диапазон: 100000000 - 999999999 Гц
 * @param freq_out - Частота на передачу, диапазон: 100000000 - 999999999 Гц
 * @return 0 - успешное выполнение, 1 - ошибка
 */
uint8_t simple_setup_auctus(UART_HandleTypeDef *huart, uint8_t  volume, uint32_t addr, uint8_t dmo_channel, uint32_t freq_in, uint32_t freq_out)
{
    uint8_t response[60];
    uint8_t state;
    uint8_t STR_1[60];
    uint8_t STR_2[60];
    uint8_t STR_3[60];
    uint8_t STR_4[60];
    uint8_t STR_5[60];
    uint8_t STR_6[60];
    uint8_t STR_7[60];
    char rtr = 0x0D;

    snprintf(STR_1, sizeof STR_1, "%s%c", STR_CONNECT, rtr);
    snprintf(STR_2, sizeof STR_2, "%s%d%c", STR_SWITCH, dmo_channel, rtr);
    snprintf(STR_3, sizeof STR_3, "%s2,0,%lu,%lu,00,00,3,2%c", STR_GROUP, freq_in, freq_out, rtr);
    snprintf(STR_4, sizeof STR_4, "%s%c", STR_CURRCH, rtr);
    snprintf(STR_5, sizeof STR_5, "%s%d%c", STR_VOLUME, volume, rtr);
    snprintf(STR_6, sizeof STR_6, "%s%d%c", STR_MIC, 6, rtr);
    snprintf(STR_7, sizeof STR_7, "%s%lu%c", STR_GRPADDR, addr, rtr);

    HAL_UART_Transmit(huart,STR_1, strlen(STR_1), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_2, strlen(STR_2), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_3, strlen(STR_3), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_4, strlen(STR_4), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_5, strlen(STR_5), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_6, strlen(STR_6), 800);
    HAL_Delay(300);
    HAL_UART_Transmit(huart,STR_7, strlen(STR_7), 800);


    /* не работает :(
    //HAL_UART_Receive_IT(huart, response, 60);

    state = HAL_UART_GetState(huart);
    while((state == HAL_UART_STATE_BUSY_RX) || (state == HAL_UART_STATE_BUSY_TX_RX)){
        state = HAL_UART_GetState(huart);
    }
    //if (response[12] != 48) return 1;
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
    */


    return 0;
}

/**
 * @Note Функция функция отправки сообщений до 180 байт
 * @param huart - Последовательный порт к которому подключен модуль
 * @param type - Тип вызова: 0 - индивидуально, 1 - групповой
 * @param  addr - id адресата , диапазон: 0 - 16777215
 * @param size - размер сообщения для отправки не более 180 байт исключая терминатор '/0'
 * @return 0 - успешное выполнение, 1 - ошибка
 */
uint8_t send_sms(UART_HandleTypeDef *huart, uint8_t type,  uint32_t addr, uint8_t size, uint8_t  *message) {
    uint8_t STR_1[200];
    char rtr = 0x0D;
    snprintf(STR_1, sizeof(STR_1), "%s%d,%lu,%d,%s%c", STR_SEND, type, addr, size, message, rtr);

    HAL_UART_Transmit(huart,STR_1, strlen(STR_1), 800);

    return 0;
}


/**
 * @Note Функция настройки цифрового режима
 * @param huart - Последовательный порт к которому подключен модуль
 * @return 0 - успешное выполнение, 1 - ошибка
 */
uint8_t digital_setup(UART_HandleTypeDef *huart) {

}
