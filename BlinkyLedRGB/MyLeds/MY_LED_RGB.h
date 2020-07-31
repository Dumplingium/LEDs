#ifndef DMY_LED_RGB
#define DMY_LED_RGB

#include "mbed.h"
#include <iostream>


class MY_LED_RGB
{
    protected:
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        SPI_HandleTypeDef SpiHandle;
        DMA_HandleTypeDef tx_DMA_Handle, rx_DMA_Handle;
        void spiInit(SPI_HandleTypeDef &SpiHandle, int Num_SPI)
        {   
            switch(Num_SPI)
            {
                case 1:
                {
                    __HAL_RCC_SPI1_CLK_ENABLE();
                    SpiHandle.Instance = SPI1;
                    break;
                }

                case 2:
                {
                    __HAL_RCC_SPI2_CLK_ENABLE();
                    SpiHandle.Instance = SPI2;
                    break;
                }

                case 3:
                {
                    __HAL_RCC_SPI3_CLK_ENABLE();
                    SpiHandle.Instance = SPI3;
                    break;
                }
            }

            __HAL_SPI_DISABLE(&SpiHandle);
            
            SpiHandle.Init.Mode = SPI_MODE_MASTER;
            SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32; // 2 is 45 mhz 32 is 2.81mhz
            SpiHandle.Init.Direction = SPI_DIRECTION_2LINES;
            SpiHandle.Init.CLKPhase = SPI_PHASE_1EDGE; // mode 0
            SpiHandle.Init.CLKPolarity = SPI_POLARITY_LOW;
            SpiHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
            SpiHandle.Init.CRCPolynomial = 7;
            SpiHandle.Init.DataSize = SPI_DATASIZE_8BIT;
            SpiHandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
            SpiHandle.Init.NSS = SPI_NSS_SOFT;
            SpiHandle.Init.TIMode = SPI_TIMODE_DISABLED;
            
            if (HAL_SPI_Init(&SpiHandle) != HAL_OK) {
            error("Cannot initialize SPI");
            }
        
            __HAL_SPI_ENABLE(&SpiHandle);
        }
        void dmaInit(DMA_HandleTypeDef &tx_DMA_Handle, DMA_HandleTypeDef &rx_DMA_Handle,
         SPI_HandleTypeDef &SpiHandle, int Num_SPI)
        {
            switch(Num_SPI)
            {
                case 1:
                {
                    __HAL_RCC_DMA2_CLK_ENABLE();
                    __DMA2_CLK_ENABLE();
                    tx_DMA_Handle.Instance = DMA2_Stream5;
                    tx_DMA_Handle.Init.Channel = DMA_CHANNEL_3;
                    break;
                }

                case 2:
                {
                    __HAL_RCC_DMA1_CLK_ENABLE();
                    __DMA1_CLK_ENABLE();
                    tx_DMA_Handle.Instance = DMA1_Stream4;
                    tx_DMA_Handle.Init.Channel = DMA_CHANNEL_0;
                    break;
                }

                case 3:
                {
                    __HAL_RCC_DMA1_CLK_ENABLE();
                    __DMA1_CLK_ENABLE();
                    tx_DMA_Handle.Instance = DMA1_Stream5;
                    tx_DMA_Handle.Init.Channel = DMA_CHANNEL_0;
                    break;
                }
            }
            
            
            tx_DMA_Handle.State = HAL_DMA_STATE_READY;
            HAL_DMA_DeInit(&tx_DMA_Handle);
            
            tx_DMA_Handle.Init.Direction = DMA_MEMORY_TO_PERIPH;
            tx_DMA_Handle.Init.PeriphInc = DMA_PINC_DISABLE;
            tx_DMA_Handle.Init.MemInc = DMA_MINC_ENABLE;
            tx_DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
            tx_DMA_Handle.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
            tx_DMA_Handle.Init.Mode = DMA_NORMAL;
            tx_DMA_Handle.Init.Priority = DMA_PRIORITY_LOW;
            tx_DMA_Handle.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
            tx_DMA_Handle.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
            tx_DMA_Handle.Init.MemBurst = DMA_MBURST_SINGLE;
            tx_DMA_Handle.Init.PeriphBurst = DMA_PBURST_SINGLE;
            HAL_DMA_Init(&tx_DMA_Handle);
            tx_DMA_Handle.Parent = &SpiHandle;
            SpiHandle.hdmatx = &tx_DMA_Handle;
            SpiHandle.hdmarx = NULL;
        }
        void gpioInit(GPIO_InitTypeDef &GPIO_InitStruct, int Num_SPI)
        {
            switch(Num_SPI){
                case 1:
                {
                    __HAL_RCC_GPIOB_CLK_ENABLE();

                    GPIO_InitStruct.Pin = GPIO_PIN_5; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_4; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_3; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1; 
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
                    break;
                }
                case 2:
                {
                    __HAL_RCC_GPIOB_CLK_ENABLE();

                    GPIO_InitStruct.Pin = GPIO_PIN_15; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_14; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_13; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1; 
                    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
                    break;
                }
                case 3:
                {
                    __HAL_RCC_GPIOC_CLK_ENABLE();

                    GPIO_InitStruct.Pin = GPIO_PIN_12; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_11; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
                    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

                    GPIO_InitStruct.Pin = GPIO_PIN_10; 
                    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
                    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1; 
                    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
                    break;
                }
            }
            
        }
        void spiSend(uint8_t *data, uint16_t bytes, DMA_HandleTypeDef &tx_DMA_Handle,
         SPI_HandleTypeDef &SpiHandle)
        {
            HAL_SPI_Transmit_DMA(&SpiHandle, data, bytes); // TODO
            HAL_DMA_PollForTransfer(&tx_DMA_Handle, HAL_DMA_FULL_TRANSFER, 2000);
            HAL_SPI_Abort(&SpiHandle);
        }

    public:
        MY_LED_RGB(int Num_SPI)
        {
            // GPIO_InitTypeDef GPIO_InitStruct = {0};
            gpioInit(GPIO_InitStruct, Num_SPI);

            // SPI_HandleTypeDef SpiHandle;
            spiInit(SpiHandle, Num_SPI);

            // DMA_HandleTypeDef tx_DMA_Handle, rx_DMA_Handle;
            dmaInit(tx_DMA_Handle, rx_DMA_Handle, SpiHandle, Num_SPI);
        }
        void LightOneLed(uint8_t *buff)
        {
            spiSend(buff, 9, tx_DMA_Handle, SpiHandle);
            uint8_t buff_0[27] = {0};
            spiSend(buff_0, 27, tx_DMA_Handle, SpiHandle);
        }
};

#endif