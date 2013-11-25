//*****************************************************************************
//
// Title        : AVR based USB<>CAN adaptor
// Authors      : Michael Wolf
// File Name    : 'main.h'
// Date         : August 24, 2005
// Version      : 1.00
// Target MCU   : Atmel AVR ATmega162
// Editor Tabs  : 2
//
// NOTE: The authors in no way will be responsible for damages that you
//       coul'd be using this code.
//       Use this code at your own risk.
//
//       This code is distributed under the GNU Public License
//       which can be found at http://www.gnu.org/licenses/gpl.txt
//
// Change Log
//
// Version  When        Who           What
// -------  ----        ---           ----
// 1.00     24/08/2005  Michael Wolf  Initial Release
// 1.01     29/08/2005  Michael Wolf  + L, R, W command
// 1.04     22/10/2005  Michael Wolf  * changed R command to G
//                                    + added R and r command for remote
//                                      frame support
// 1.05     12/10/2006  Michael Wolf  + added definitions for new command 'v'
//
//*****************************************************************************
#ifndef __MAIN_H__
#define __MAIN_H__

#define HW_VER        0x10		// hardware version
#define SW_VER        0x10		// software version
#define SW_VER_MAJOR  0x01    // software major version
#define SW_VER_MINOR  0x07    // software minor version
#define SERIAL        "0001"	// device serial number

#if !defined(CR)
#define CR            13	// command end tag (ASCII CR)
#endif

#if !defined(ERROR)
#define ERROR         7		// error tag (ASCII BEL)
#endif

#define SET_BITRATE     'S'	// set CAN bit rate
#define SET_BTR         's'	// set CAN bit rate via
#define OPEN_CAN_CHAN   'O'	// open CAN channel
#define CLOSE_CAN_CHAN  'C'	// close CAN channel
#define SEND_11BIT_ID   't'	// send CAN message with 11bit ID
#define SEND_29BIT_ID   'T'	// send CAN message with 29bit ID
#define SEND_R11BIT_ID  'r'	// send CAN remote message with 11bit ID
#define SEND_R29BIT_ID  'R'	// send CAN remote message with 29bit ID
#define READ_STATUS     'F'	// read status flag byte
#define SET_ACR         'M'	// set Acceptance Code Register
#define SET_AMR         'm'	// set Acceptance Mask Register
#define GET_VERSION     'V'	// get hardware and software version
#define GET_SW_VERSION  'v' // get software version only
#define GET_SERIAL      'N'	// get device serial number
#define TIME_STAMP      'Z'	// toggle time stamp setting
#define READ_ECR        'E'	// read Error Capture Register
#define READ_ALCR       'A'	// read Arbritation Lost Capture Register
#define READ_REG        'G'	// read register conten from SJA1000
#define WRITE_REG       'W'	// write register content to SJA1000
#define LISTEN_ONLY     'L'	// switch to listen only mode

#define TIME_STAMP_TICK 1000	// microseconds

/*
	define command receive buffer length
	minimum length is define as follow:
	1 byte	: command identifier
	8 byte	: CAN identifier (for both 11bit and 29bit ID)
	1 byte	: CAN data length (0-8 byte)
	2*8 byte: CAN data (one data byte is send as two ASCII chars)
	1 byte  : [CR] command end tag
	---
	27 byte
*/
#define CMD_BUFFER_LENGTH  30

// calculate timer0 overflow value
#define OCR_VALUE ((unsigned char)((unsigned long)(TIME_STAMP_TICK) / (1000000L / (float)((unsigned long)MCU_XTAL / 64L))))

// CAN tx message
extern struct {
    uint8_t format;		// Extended/Standard Frame
    uint32_t id;		    // Frame ID
    uint8_t rtr;		    // RTR/Data Frame
    uint8_t len;		    // Data Length
    uint8_t data[8];		// Data Bytes
} CAN_tx_msg;			      // length 15 byte/each
// CAN rx message
extern struct {
    uint8_t format;		// Extended/Standard Frame
    uint32_t id;		    // Frame ID
    uint8_t rtr;		    // RTR/Data Frame
    uint8_t len;		    // Data Length
    uint8_t data[8];		// Data Bytes
} CAN_rx_msg;			      // length 15 byte/each

// CAN init values
extern struct {
    uint8_t acr[4];
    uint8_t amr[4];
    uint8_t btr0;
    uint8_t btr1;
    uint8_t fixed_rate;
} CAN_init_val;

extern volatile uint16_t CAN_flags;
extern volatile uint8_t last_ecr;
extern volatile uint8_t last_alc;
#endif // __MAIN_H__
