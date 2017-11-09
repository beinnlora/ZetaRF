/*! @file radio_config.h
 * @brief This file contains the automatically generated
 * configurations.
 *
 * @n WDS GUI Version: 3.2.11.0
 * @n Device: Si4455 Rev.: B1                                 
 *
 * @b COPYRIGHT
 * @n Silicon Laboratories Confidential
 * @n Copyright 2017 Silicon Laboratories, Inc.
 * @n http://www.silabs.com
 */

#ifndef RADIO_CONFIG_H_
#define RADIO_CONFIG_H_

// USER DEFINED PARAMETERS
// Define your own parameters here

// INPUT DATA
/*
// Crys_freq(Hz): 30000000    Crys_tol(ppm): 30    IF_mode: 2    High_perf_Ch_Fil: 1    OSRtune: 0    Ch_Fil_Bw_AFC: 0    ANT_DIV: 0    PM_pattern: 0    
// MOD_type: 2    Rsymb(sps): 4800    Fdev(Hz): 30000    RXBW(Hz): 114000    Manchester: 1    AFC_en: 1    Rsymb_error: 0.0    Chip-Version: 2    
// RF Freq.(MHz): 433    API_TC: 28    fhst: 250000    inputBW: 0    BERT: 0    RAW_dout: 0    D_source: 0    Hi_pfm_div: 0    
// 
// # WB filter 1 (BW = 114.46 kHz);  NB-filter 1 (BW = 114.46 kHz)  // 
// Modulation index: 12
*/


// CONFIGURATION PARAMETERS
#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ                     30000000L
#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER                    0x00
#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH               0x08
#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP        0x03
#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET       0xF000
#define RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD					   {0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5}


// CONFIGURATION COMMANDS

/*
// Command:                  RF_POWER_UP
// Description:              Command to power-up the device and select the operational mode and functionality.
*/
#define RF_POWER_UP 0x02, 0x01, 0x00, 0x01, 0xC9, 0xC3, 0x80

/*
// Set properties:           RF_INT_CTL_ENABLE_2
// Number of properties:     2
// Group ID:                 0x01
// Start ID:                 0x00
// Default values:           0x04, 0x00, 
// Descriptions:
//   INT_CTL_ENABLE - This property provides for global enabling of the three interrupt groups (Chip, Modem and Packet Handler) in order to generate HW interrupts at the NIRQ pin.
//   INT_CTL_PH_ENABLE - Enable individual interrupt sources within the Packet Handler Interrupt Group to generate a HW interrupt on the NIRQ output pin.
*/
#define RF_INT_CTL_ENABLE_2 0x11, 0x01, 0x02, 0x00, 0x05, 0x38

/*
// Set properties:           RF_INT_CTL_CHIP_ENABLE_1
// Number of properties:     1
// Group ID:                 0x01
// Start ID:                 0x03
// Default values:           0x04, 
// Descriptions:
//   INT_CTL_CHIP_ENABLE - Enable individual interrupt sources within the Chip Interrupt Group to generate a HW interrupt on the NIRQ output pin.
*/
#define RF_INT_CTL_CHIP_ENABLE_1 0x11, 0x01, 0x01, 0x03, 0x6C

/*
// Set properties:           RF_FRR_CTL_A_MODE_4
// Number of properties:     4
// Group ID:                 0x02
// Start ID:                 0x00
// Default values:           0x01, 0x02, 0x09, 0x00, 
// Descriptions:
//   FRR_CTL_A_MODE - Fast Response Register A Configuration.
//   FRR_CTL_B_MODE - Fast Response Register B Configuration.
//   FRR_CTL_C_MODE - Fast Response Register C Configuration.
//   FRR_CTL_D_MODE - Fast Response Register D Configuration.
*/
#define RF_FRR_CTL_A_MODE_4 0x11, 0x02, 0x04, 0x00, 0x09, 0x04, 0x06, 0x08

/*
// Set properties:           RF_EZCONFIG_XO_TUNE_1
// Number of properties:     1
// Group ID:                 0x24
// Start ID:                 0x03
// Default values:           0x40, 
// Descriptions:
//   EZCONFIG_XO_TUNE - Configure the internal capacitor frequency tuning bank for the crystal oscillator.
*/
#define RF_EZCONFIG_XO_TUNE_1 0x11, 0x24, 0x01, 0x03, 0x52

/*
// Command:                  RF_WRITE_TX_FIFO
// Description:              Writes data byte(s) to the TX FIFO.
*/
#define RF_WRITE_TX_FIFO 0x66, 0xA2, 0xC9, 0x3A, 0xB9, 0x8F, 0x82, 0x2D, 0xC9, 0xA6, 0x6C, 0x9F, 0x3E, 0x0D, 0x58, 0x9E, 0x8C, 0xB7, 0x93, 0xF0, \
0x45, 0xC5, 0x9A, 0x20, 0xF0, 0x2B, 0x52, 0x39, 0xC3, 0xF5, 0xE6, 0x43, 0xF1, 0x55, 0xD3, 0xCF, 0xE7, 0xA4, 0xA7, 0xEE, \
0xD3, 0x75, 0xD8, 0xCF, 0x54, 0x6B, 0x5B, 0x42, 0xFD, 0x46, 0x9B, 0x6D, 0xA4, 0xD5, 0x92, 0x91, 0x0A, 0x89, 0x9B, 0xC4, \
0x8A, 0x5C, 0xB5, 0x46, 0x28, 0x51, 0xE8, 0x40, 0xA3, 0x4E, 0x6B, 0xDC, 0x17, 0x39, 0xC3, 0xFA, 0xBA, 0x8B, 0x58, 0xC5, \
0x65, 0x71, 0x7C, 0xA6, 0x5E, 0xAE, 0x27, 0x98, 0x29, 0x52, 0x36, 0x80, 0x54, 0x08, 0x0E, 0xDE, 0x09, 0x64, 0x6F, 0xB3, \
0x77, 0x30, 0xDA, 0x8C, 0xA6, 0x19, 0x7D, 0x02, 0xA6, 0xD0, 0xA7, 0x12, 0xDF, 0xB7

/*
// Command:                  RF_NOP
// Description:              No Operation command.
*/
#define RF_NOP 0x00

/*
// Command:                  RF_WRITE_TX_FIFO_1
// Description:              Writes data byte(s) to the TX FIFO.
*/
#define RF_WRITE_TX_FIFO_1 0x66, 0x3B, 0x61, 0x7C, 0x11, 0x7F, 0x1A, 0xB8, 0xE0, 0x20, 0xBA, 0x08, 0x20, 0xF6, 0xC2, 0x7C, 0xEA, 0xC2, 0xDE, 0x83, \
0x33, 0x41, 0x00, 0xC6, 0x4C, 0x04, 0xF3, 0xB0, 0x54, 0x4B, 0x75, 0x9F, 0x42, 0x86, 0xFC, 0x5C, 0x0A, 0xB2, 0xB2, 0xB9, \
0x3D, 0xD5, 0x59, 0x07, 0x36, 0xAD, 0x71, 0x67, 0xBC, 0xEB, 0x7C, 0x79, 0xEB, 0xFF, 0x55, 0x95, 0x74, 0x48, 0xA6, 0xCB, \
0x9C, 0xF5, 0x51, 0x78, 0x08, 0x28, 0xE7, 0x0E, 0x8D, 0x0E, 0x28, 0x7A, 0x13, 0xC1, 0xCE, 0xB7, 0xE1, 0xF3, 0x41, 0x0A, \
0x47, 0xA3, 0x75, 0x5E, 0x02, 0xC3, 0xA2, 0xEF, 0x55, 0x98, 0x8C, 0xC0, 0x37, 0x6F, 0xBB, 0x5F, 0xC0, 0x43, 0x61, 0x65, \
0xEF, 0x3D, 0xCE, 0x80, 0x56, 0xF9, 0xCF, 0x18, 0x05, 0x49, 0x83, 0x1F

/*
// Command:                  RF_EZCONFIG_CHECK
// Description:              Validates the EZConfig array was written correctly.
*/
#define RF_EZCONFIG_CHECK 0x19, 0x9E, 0x06

/*
// Command:                  RF_GPIO_PIN_CFG
// Description:              Configures the GPIO pins.
*/
#define RF_GPIO_PIN_CFG 0x13, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00


// AUTOMATICALLY GENERATED CODE! 
// DO NOT EDIT/MODIFY BELOW THIS LINE!
// --------------------------------------------

#ifndef FIRMWARE_LOAD_COMPILE
#define RADIO_CONFIGURATION_DATA_ARRAY { \
        0x07, RF_POWER_UP, \
        0x06, RF_INT_CTL_ENABLE_2, \
        0x05, RF_INT_CTL_CHIP_ENABLE_1, \
        0x08, RF_FRR_CTL_A_MODE_4, \
        0x05, RF_EZCONFIG_XO_TUNE_1, \
        0x72, RF_WRITE_TX_FIFO, \
        0x01, RF_NOP, \
        0x70, RF_WRITE_TX_FIFO_1, \
        0x03, RF_EZCONFIG_CHECK, \
        0x08, RF_GPIO_PIN_CFG, \
        0x00 \
 }
#else
#define RADIO_CONFIGURATION_DATA_ARRAY { 0 }
#endif

// DEFAULT VALUES FOR CONFIGURATION PARAMETERS
#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ_DEFAULT                     30000000L
#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER_DEFAULT                    0x00
#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH_DEFAULT               0x10
#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP_DEFAULT        0x01
#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET_DEFAULT       0x1000
#define RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD_DEFAULT  		           {0x42, 0x55, 0x54, 0x54, 0x4F, 0x4E, 0x31} // BUTTON1 

#define RADIO_CONFIGURATION_DATA_RADIO_PATCH_INCLUDED                      0x00
#define RADIO_CONFIGURATION_DATA_RADIO_PATCH_SIZE                          0x00
#define RADIO_CONFIGURATION_DATA_RADIO_PATCH                               {  }

#ifndef RADIO_CONFIGURATION_DATA_ARRAY
#error "This property must be defined!"
#endif

#ifndef RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ
#define RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ          RADIO_CONFIGURATION_DATA_RADIO_XO_FREQ_DEFAULT 
#endif

#ifndef RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER
#define RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER         RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER_DEFAULT 
#endif

#ifndef RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH
#define RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH    RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH_DEFAULT 
#endif

#ifndef RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP
#define RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP   RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP_DEFAULT 
#endif

#ifndef RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET
#define RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET  RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET_DEFAULT 
#endif

#ifndef RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD
#define RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD         RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD_DEFAULT 
#endif

#define RADIO_CONFIGURATION_DATA { \
                            Radio_Configuration_Data_Array,                            \
                            RADIO_CONFIGURATION_DATA_CHANNEL_NUMBER,                   \
                            RADIO_CONFIGURATION_DATA_RADIO_PACKET_LENGTH,              \
                            RADIO_CONFIGURATION_DATA_RADIO_STATE_AFTER_POWER_UP,       \
                            RADIO_CONFIGURATION_DATA_RADIO_DELAY_CNT_AFTER_RESET,      \
                            RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD                    \
                            }

#endif /* RADIO_CONFIG_H_ */
