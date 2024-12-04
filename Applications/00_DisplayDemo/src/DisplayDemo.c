// Header: Static image demo for FUTABA 8-MD-06INKM display module
// File Name: DisplayDemo.c
// Author: Hodnenko M.I.
// Date: 03.12.2024

#include "RTE_Components.h"             // Component selection
#include CMSIS_device_header
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

#include "main.h"

#include "DisplayDemo.h"
#include "Driver_SPI.h"

#include "8_MD_06INKM.h"

/* SPI Driver */
extern ARM_DRIVER_SPI Driver_SPI1;

osThreadId_t tid_app_displayDemo;

static void app_displayDemo (void * arg);

void applicationSPI_callback(uint32_t event)
{
    switch (event)
    {
    case ARM_SPI_EVENT_TRANSFER_COMPLETE:
        /* Success: Wakeup Thread */
#ifdef USE_DISPLAY_THREAD_REGISTER_CALLBACK
#error "Callbacks are currently not implemented."
#else
        osThreadFlagsSet(tid_app_displayDemo, 0x01);
#endif
        break;
    case ARM_SPI_EVENT_DATA_LOST:
        /*  Occurs in slave mode when data is requested/sent by master
            but send/receive/transfer operation has not been started
            and indicates that data is lost. Occurs also in master mode
            when driver cannot transfer data fast enough. */
        __BKPT(0);  /* Error: Call debugger or replace with custom error handling */
        break;
    case ARM_SPI_EVENT_MODE_FAULT:
        /*  Occurs in master mode when Slave Select is deactivated and
            indicates Master Mode Fault. */
        __BKPT(1);  /* Error: Call debugger or replace with custom error handling */
        break;
    }
}

void app_displayDemo_init(void) {
    
    tid_app_displayDemo = osThreadNew(app_displayDemo, NULL, NULL);    // Create application thread
    if(tid_app_displayDemo == NULL)
    {
        //    If thread creation is unsuccessful, return ERROR status
    }
}

void app_displayDemo_deinit(void) {
    
    osThreadTerminate(tid_app_displayDemo);    // Terminate application thread
    
}

static void app_displayDemo (void * arg) {
    
    ARM_DRIVER_SPI* SPIdrv = &Driver_SPI1;
    uint32_t flags;
    
    uint8_t VFD_Sequence [] = { FUTABA_CMD_DISP_TIMING_DIGIT_SET, FUTABA_CMD_RECOMMENDED_DISPLAY_TIMING,\
                                FUTABA_CMD_DIMMING_SET, 0xF5,\
                                FUTABA_CMD_DCRAM_A_DATA_WRITE, 0x31, 0x37, 0x12, 0x21, 0x30, 0x80, 0x45, 0x33,\
                                FUTABA_CMD_STANDBY_MODE_SET, FUTABA_CMD_DISPLAY_LIGHT_ON_OFF\
                                };
    
#ifdef DEBUG
    ARM_DRIVER_VERSION   version;
    ARM_SPI_CAPABILITIES drv_capabilities;
 
    version = SPIdrv->GetVersion();
    if (version.api < 0x200) /* requires at minimum API version 2.00 or higher */
    {                        /* error handling                                 */
        return;
    }
 
    drv_capabilities = SPIdrv->GetCapabilities();
    if (drv_capabilities.event_mode_fault == 0)
    {                        /* error handling */
        return;
    }
#endif
    
    /* Set reset pin for display matrix */
    HAL_GPIO_WritePin(DISPLAY_RESET_GPIO_Port, DISPLAY_RESET_Pin, GPIO_PIN_RESET);
    osDelay(1);
    
    /* Enable voltage converter on board */
    HAL_GPIO_WritePin(DISPLAY_EN_GPIO_Port, DISPLAY_EN_Pin, GPIO_PIN_SET);
    
    osDelay(1);
    
    /* Disable reset pin for display matrix */
    HAL_GPIO_WritePin(DISPLAY_RESET_GPIO_Port, DISPLAY_RESET_Pin, GPIO_PIN_SET);
    
    /* Time delay needed for display reset */
    osDelay(1);
    
    /* Initialize the SPI driver */
#ifdef USE_DISPLAY_THREAD_REGISTER_CALLBACK
#error "Callbacks are currently not implemented."
#else
    SPIdrv->Initialize(applicationSPI_callback);
#endif
    /* Power up the SPI peripheral */
    SPIdrv->PowerControl(ARM_POWER_FULL);
    /* Configure the SPI to Master, 8-bit mode @10000 kBits/sec */
    SPIdrv->Control(ARM_SPI_MODE_MASTER | ARM_SPI_CPOL1_CPHA1 | ARM_SPI_LSB_MSB | ARM_SPI_SS_MASTER_UNUSED |\
    ARM_SPI_DATA_BITS(8), 400000);
    
    /* SS line = INACTIVE = HIGH */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
    
    /* SS line = ACTIVE = LOW */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_RESET);
    /* Transmit some data */
    SPIdrv->Send(VFD_Sequence, 2);
    /* Wait for completion */
    flags = osThreadFlagsWait(0x01, osFlagsWaitAny, 2000);
    if (flags == osFlagsErrorTimeout) {
        __BKPT(0); /* Timeout error: Call debugger */
    }
    /* SS line = INACTIVE = HIGH */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
    
    /* SS line = ACTIVE = LOW */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_RESET);
    /* Transmit some data */
    SPIdrv->Send(VFD_Sequence + 2, 2);
    /* Wait for completion */
    flags = osThreadFlagsWait(0x01, osFlagsWaitAny, 2000);
    if (flags == osFlagsErrorTimeout) {
        __BKPT(0); /* Timeout error: Call debugger */
    }
    /* SS line = INACTIVE = HIGH */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
    
    /* SS line = ACTIVE = LOW */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_RESET);
    /* Transmit some data */
    SPIdrv->Send(VFD_Sequence + 14, 1);
    /* Wait for completion */
    flags = osThreadFlagsWait(0x01, osFlagsWaitAny, 2000);
    if (flags == osFlagsErrorTimeout) {
        __BKPT(0); /* Timeout error: Call debugger */
    }
    /* SS line = INACTIVE = HIGH */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
    
    /* SS line = ACTIVE = LOW */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_RESET);
    /* Transmit some data */
    SPIdrv->Send(VFD_Sequence + 13, 1);
    /* Wait for completion */
    flags = osThreadFlagsWait(0x01, osFlagsWaitAny, 2000);
    if (flags == osFlagsErrorTimeout) {
        __BKPT(0); /* Timeout error: Call debugger */
    }
    /* SS line = INACTIVE = HIGH */
    HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
    
    while(1) {
        /* SS line = ACTIVE = LOW */
        HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_RESET);
        /* Transmit some data */
        SPIdrv->Send(VFD_Sequence + 4, 9);
        VFD_Sequence[5]++; VFD_Sequence[6]++; VFD_Sequence[7]++; VFD_Sequence[8]++;
        VFD_Sequence[9]++; VFD_Sequence[10]++; VFD_Sequence[11]++; VFD_Sequence[12]++;
        /* Wait for completion */
        flags = osThreadFlagsWait(0x01, osFlagsWaitAny, 2000);
        if (flags == osFlagsErrorTimeout) {
            __BKPT(0); /* Timeout error: Call debugger */
        }
        /* SS line = INACTIVE = HIGH */
        HAL_GPIO_WritePin(DISPLAY_CS_GPIO_Port, DISPLAY_CS_Pin, GPIO_PIN_SET);
        osDelay(5);
    }
}