/*!
 * @file DFRobot_TM6605.cpp
 * @brief  Implementation of DFRobot_TM6605 class methods
 * @copyright	Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [fary](feng.yang@dfrobot.com)
 * @version V1.0
 * @date 2025-04-22
 * @url https://github.com/DFRobot/DFRobot_TM6605
 */
#include "DFRobot_TM6605.h"

byte DFRobot_TM6605::begin(void){
	_pWire->begin();
    _pWire->beginTransmission(_deviceAddr);
    return _pWire->endTransmission();
}

void DFRobot_TM6605::play(void){
	writeReg(TM6605_REG_CONTROL,0x01);
}


void DFRobot_TM6605::stop(void){
	writeReg(TM6605_REG_CONTROL,0x00);
}


void DFRobot_TM6605::selectEffect(eEffect_t effect)
{
	writeReg(TM6605_REG_EFFECT,(uint8_t)effect);
}

void DFRobot_TM6605::writeReg(uint8_t reg,uint8_t data){
	_pWire->beginTransmission(_deviceAddr);
	_pWire->write(reg);
	_pWire->write(data);
	_pWire->endTransmission();
}

