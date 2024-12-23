// Header: Display module driver macros and functions
// File Name: 8_MD_06INKM.h
// Author: Hodnenko M.I.
// Date: 03.12.2024

#ifndef __8_MD_06INKM_H
#define __8_MD_06INKM_H
//====================================================================================================================//
//====================================COMMAND SEQUENCES OF 8-MD-06INKM================================================//
//====================================================================================================================//
#define FUTABA_CMD_DCRAM_A_DATA_WRITE         (0x01U << 0x05U)

#define FUTABA_CMD_CGRAM_DATA_WRITE           (0x01U << 0x06U)

#define FUTABA_CMD_ADRAM_DATA_WRITE           (0x03U << 0x05U)

#define FUTABA_CMD_URAM_DATA_WRITE            (0x01U << 0x07U)

#define FUTABA_CMD_DISP_TIMING_DIGIT_SET      (0x07U << 0x05U)

#define FUTABA_CMD_DIMMING_SET                (0xE4U)

#define FUTABA_CMD_DISPLAY_LIGHT_ON_OFF       (0x3AU << 0x02U)

#define FUTABA_CMD_STANDBY_MODE_SET           (0xE0U)

//====================================================================================================================//
//================================RECOMMENDED DISPLAY TIMING OF 8-MD-06INKM===========================================//
//====================================================================================================================//

#define FUTABA_CMD_RECOMMENDED_DISPLAY_TIMING (0x07U)


#endif /* __8_MD_06INKM_H */

