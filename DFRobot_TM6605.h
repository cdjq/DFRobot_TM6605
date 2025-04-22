/*!
 * @file DFRobot_TM6605.h
 * @brief DFRobot_TM6605 class infrastructure
 * @copyright	Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [fary](feng.yang@dfrobot.com)
 * @version V1.0
 * @date 2025-04-22
 * @url https://github.com/DFRobot/DFRobot_TM6605
 */
#ifndef _DFRobot_TM6605_H_
#define _DFRobot_TM6605_H_

#include <Arduino.h>
#include <Wire.h>



#define ENABLE_DBG 

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define TM6605_REG_CONTROL     0x0C
#define TM6605_REG_EFFECT      0x04
#define TM6605_IIC_ADDRESS     0x2D
class DFRobot_TM6605{
public:
typedef enum{
    eSharpClick=1,
    eInstantClick=4,
    eLightTap=7,
    eDoubleClick=10,
    eLightPulse=13,
    eStrongAlert=14,
    eMediumDurationAlert=15,
    eSharpClick2=17,
    eMediumClick=21,
    eFlashStrike=24,
    eDoubleHighClickShort=27,
    eDoubleMediumClickShort=31,
    eDoubleFlashStrikeShort=34,
    eDoubleInstantClickLong=37,
    eDoubleMediumInstantClickLong=41,    
    eDoubleFlashStrikeLong=44,
    eAlert=47,
    eToggleClick=58,
    eLongSlowFadeTransition1=70,
    eLongSlowFadeTransition2=71,
    eMediumSlowFadeTransition1=72,
    eMediumSlowFadeTransition2=73,
    eShortSlowFadeTransition1=74,
    eShortSlowFadeTransition2=75,
    eLongFastFadeTransition1=76,
    eLongFastFadeTransition2=77,
    eMediumFastFadeTransition1=78,
    eMediumFastFadeTransition2=79,
    eShortFastFadeTransition1=80,
    eShortFastFadeTransition2=81,
    eLongSlowBoostTransition1=82,
    eLongSlowBoostTransition2=83,
    eMediumSlowBoostTransition1=84,
    eMediumSlowBoostTransition2=85,
    eShortSlowBoostTransition1=86,
    eShortSlowBoostTransition2=87,
    eLongFastBoostTransition1=88,
    eLongFastBoostTransition2=89,
    eMediumFastBoostTransition1=90,
    eMediumFastBoostTransition2=91,
    eShortFastBoostTransition1=92,
    eShortFastBoostTransition2=93,
    eLongAlert=118,
    eSoftNoise=119,
    eSleepCommand=123,
  }eEffect_t;
  /**
   * @fn DFRobot_TM6605
   * @brief Constructor, passing in IIC bus device
  */
  DFRobot_TM6605(TwoWire *pWire = &Wire)
  {
    _pWire=pWire;
    _deviceAddr=TM6605_IIC_ADDRESS;
  }

  /**
   * @fn begin
   * @brief Check whether the TM6605 device exists on the IIC bus.
   * @return Whether the sensor device is found.
   * @retval 0: Sensor device exists, other values: Sensor device does not exist.
  */
  byte begin(void);

  /**
   * @fn play
   * @brief Start effect playback
   * @return null
  */
  void play(void);

  /**
   * @fn stop
   * @brief Stop effect playback
   * @return null
  */
  void stop(void);

  /**
   * @fn selectEffect
   * @brief Select vibration effect
   * @return null
  */
  void selectEffect(eEffect_t effect);

protected:

  /**
   * @fn writeReg
   * @brief Write command functions
   * @param command sensor control command
   * @return None
  */
  void writeReg(uint8_t reg,uint8_t data);
  
private:
  TwoWire *_pWire;
  uint8_t _deviceAddr;  
};

#endif