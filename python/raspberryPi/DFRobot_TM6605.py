# -*- coding: utf-8 -*-
'''
  @file DFRobot_TM6605.py
  @brief Define the basic structure and methods of the DFRobot_TM6605 class.
  @copyright   Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT license (MIT)
  @author [fary](feng.yang@dfrobot.com)
  @version  V1.0
  @date  2025-04-22
  @https://github.com/DFRobot/DFRobot_TM6605
'''
from smbus import SMBus
import struct
from enum import Enum
class DFRobot_TM6605:
    TM6605_REG_CONTROL      = 0x0C
    TM6605_REG_EFFECT       = 0x04
    TM6605_IIC_ADDRESS      = 0x2D
    class effect(Enum):
        sharp_click = 1
        instant_click = 4
        light_tap = 7
        double_click = 10
        light_pulse = 13
        strong_alert = 14
        medium_duration_alert = 15
        sharp_click_2 = 17
        medium_click = 21
        flash_strike = 24
        double_high_click_short = 27
        double_medium_click_short = 31
        double_flash_strike_short = 34
        double_instant_click_long = 37
        double_medium_instant_click_long = 41
        double_flash_strike_long = 44
        alert = 47
        toggle_click = 58
        long_slow_fade_transition_1 = 70
        long_slow_fade_transition_2 = 71
        medium_slow_fade_transition_1 = 72
        medium_slow_fade_transition_2 = 73
        short_slow_fade_transition_1 = 74
        short_slow_fade_transition_2 = 75
        long_fast_fade_transition_1 = 76
        long_fast_fade_transition_2 = 77
        medium_fast_fade_transition_1 = 78
        medium_fast_fade_transition_2 = 79
        short_fast_fade_transition_1 = 80
        short_fast_fade_transition_2 = 81
        long_slow_boost_transition_1 = 82
        long_slow_boost_transition_2 = 83
        medium_slow_boost_transition_1 = 84
        medium_slow_boost_transition_2 = 85
        short_slow_boost_transition_1 = 86
        short_slow_boost_transition_2 = 87
        long_fast_boost_transition_1 = 88
        long_fast_boost_transition_2 = 89
        medium_fast_boost_transition_1 = 90
        medium_fast_boost_transition_2 = 91
        short_fast_boost_transition_1 = 92
        short_fast_boost_transition_2 = 93
        long_alert = 118
        soft_noise = 119
        sleep_command = 123
    
    def __init__(self, bus=1):
        self.bus = SMBus(1)
        self.address = self.TM6605_IIC_ADDRESS

    def _write_reg(self, reg,data):
        '''
        @fn _write_command
        @brief Write command functions
        @param command sensor control command
        @return None
        '''
        self.bus.write_byte_data(self.address,reg,data)
    
    def begin(self):
        '''
        @fn begin
        @brief Check whether the TM6605 device exists on the IIC bus.
        @return Whether the sensor device is found.
        @retval 0: Sensor device exists, -1: Sensor device does not exist.
        '''
        try:
            self.bus.write_byte(self.address, 0)
            return 0
        except Exception as e:
            print("Init error: {}".format(e))
            return -1
        
    def play(self):
        '''
        @fn play
        @brief Start effect playback
        '''
        self._write_reg(self.TM6605_REG_CONTROL,0x01)

    def stop(self):
        '''
        @fn stop
        @brief Stop effect playback
        '''
        self._write_reg(self.TM6605_REG_CONTROL,0x00)

    def selectEffect(self,effect):
        '''
        @fn selectEffect
        @brief Select vibration effect
        '''
        self._write_reg(self.TM6605_REG_EFFECT,effect)