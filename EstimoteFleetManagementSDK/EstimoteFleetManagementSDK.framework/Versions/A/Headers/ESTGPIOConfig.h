//  Estimote Fleet Management SDK
//  Copyright © 2016 Estimote. All rights reserved.

#define ESTGPIOConfigErrorDomain @"ESTGPIOConfigErrorDomain"

/**
 *  Describes GPIO Config validation error.
 */
typedef NS_ENUM(NSUInteger, ESTGPIOConfigError)
{
    /**
     *  Provided value does not belong to the ESTGPIOConfig enum.
     */
    ESTGPIOConfigErrorValueNotAllowed = 1
};

/**
 *  All available configurations for GPIO ports.
 */
typedef NS_ENUM(uint8_t, ESTGPIOConfig)
{
    /**
     *  GPIO used as an input No-Pull.
     */
    ESTGPIOConfigInputNoPull = 0x00,
    /**
     *  GPIO used as an input with Pull-Down.
     */
    ESTGPIOConfigInputPullDown = 0x01,
    /**
     *  GPIO used as an input with Pull-Up.
     */
    ESTGPIOConfigInputPullUp = 0x02,
    /**
     *  GPIO used as an output.
     */
    ESTGPIOConfigOutput = 0x03,
    /**
     *  GPIO used for UART. When applied Port 0 turns to Rx (Receiver) 
     *  and Port 1 turns to Tx (Transmitter).
     */
    ESTGPIOConfigUART = 0x04
};
