/**
  ******************************************************************************
  * @file    usbd_usr.c
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    19-March-2012
  * @brief   This file includes the user application layer
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbd_usr.h"
#include "usbd_ioreq.h"
//#include "lcd_log.h"

#include "usb_conf.h"

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
* @{
*/

/** @defgroup USBD_USR 
* @brief    This file includes the user application layer
* @{
*/ 

/** @defgroup USBD_USR_Private_TypesDefinitions
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBD_USR_Private_Defines
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBD_USR_Private_Macros
* @{
*/ 
__IO uint8_t DeviceConfigured = 0;
/**
* @}
*/ 


/** @defgroup USBD_USR_Private_Variables
* @{
*/ 

USBD_Usr_cb_TypeDef USR_cb =
{
  USBD_USR_Init,
  USBD_USR_DeviceReset,
  USBD_USR_DeviceConfigured,
  USBD_USR_DeviceSuspended,
  USBD_USR_DeviceResumed,
  
  USBD_USR_DeviceConnected,
  USBD_USR_DeviceDisconnected,  
  
  
};



/**
* @}
*/

/** @defgroup USBD_USR_Private_Constants
* @{
*/ 

/**
* @}
*/



/** @defgroup USBD_USR_Private_FunctionPrototypes
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBD_USR_Private_Functions
* @{
*/ 

#define USER_INFORMATION1      "[Key]:RemoteWakeup"
#define USER_INFORMATION2      "[Joystick]:Mouse emulation"


/**
* @brief  USBD_USR_Init 
*         Displays the message on LCD for host lib initialization
* @param  None
* @retval None
*/
void USBD_USR_Init(void)
{    
//  /* Configure the IOE on which the JoyStick is connected */
//  Key_Config();
//  
//  /* Setup SysTick Timer for 20 msec interrupts 
//  This interrupt is used to probe the joystick */
//  if (SysTick_Config(SystemCoreClock / 144))
//  { 
//    /* Capture error */ 
//    while (1);
//  } 
//  /* Initialize the LCD */
//#if defined (USE_STM322xG_EVAL)
//  STM322xG_LCD_Init();
//#elif defined(USE_STM324xG_EVAL)
//  STM324xG_LCD_Init();
//#elif defined (USE_STM3210C_EVAL)
//  STM3210C_LCD_Init();
//#else
// #error "Missing define: Evaluation board (ie. USE_STM322xG_EVAL)"
//#endif

//  LCD_LOG_Init();

//#ifdef USE_USB_OTG_HS 
//  LCD_LOG_SetHeader(" USB OTG HS HID Device");
//#else
//  LCD_LOG_SetHeader(" USB OTG FS HID Device");
//#endif
//  LCD_UsrLog("> USB device library started.\n"); 
//  LCD_LOG_SetFooter ("     USB Device Library v1.1.0" ); 
//  
//  /* Information panel */
//  LCD_SetTextColor(Green);
//  LCD_DisplayStringLine( LCD_PIXEL_HEIGHT - 42, USER_INFORMATION1);
//  LCD_DisplayStringLine( LCD_PIXEL_HEIGHT - 30, USER_INFORMATION2);
//  LCD_SetTextColor(LCD_LOG_DEFAULT_COLOR);
  
}

/**
* @brief  USBD_USR_DeviceReset 
*         Displays the message on LCD on device Reset Event
* @param  speed : device speed
* @retval None
*/
void USBD_USR_DeviceReset(uint8_t speed )
{
 switch (speed)
 {
   case USB_OTG_SPEED_HIGH: 
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [HS]" );
     break;

  case USB_OTG_SPEED_FULL_OLD: 
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [FS]" );
     break;
 default:
     //LCD_LOG_SetFooter ("     USB Device Library v1.1.0 [??]" );
     break;
 }
}


/**
* @brief  USBD_USR_DeviceConfigured
*         Displays the message on LCD on device configuration Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConfigured (void)
{
  DeviceConfigured = 1;
  //LCD_UsrLog("> HID Interface started.\n");
}


/**
* @brief  USBD_USR_DeviceConnected
*         Displays the message on LCD on device connection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceConnected (void)
{
  //LCD_UsrLog("> USB Device Connected.\n");
}


/**
* @brief  USBD_USR_DeviceDisonnected
*         Displays the message on LCD on device disconnection Event
* @param  None
* @retval Staus
*/
void USBD_USR_DeviceDisconnected (void)
{
  //LCD_UsrLog("> USB Device Disconnected.\n");
}

/**
* @brief  USBD_USR_DeviceSuspended 
*         Displays the message on LCD on device suspend Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceSuspended(void)
{
  //LCD_UsrLog("> USB Device in Suspend Mode.\n");
  /* Users can do their application actions here for the USB-Reset */
}


/**
* @brief  USBD_USR_DeviceResumed 
*         Displays the message on LCD on device resume Event
* @param  None
* @retval None
*/
void USBD_USR_DeviceResumed(void)
{
    //LCD_UsrLog("> USB Device in Idle Mode.\n");
  /* Users can do their application actions here for the USB-Reset */
}

/**
* @}
*/ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/






























