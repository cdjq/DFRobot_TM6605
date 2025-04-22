# -*- coding: utf-8 -*-
'''
  @file demo.py
  @brief This demo showcases all the vibration effects of the TM6605.
  @copyright	Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author [fary](feng.yang@dfrobot.com)
  @version V1.0
  @date 2025-04-22
  @url https://github.com/DFRobot/DFRobot_TM6605
'''
import sys
sys.path.append("../")
import time
from DFRobot_TM6605 import DFRobot_TM6605

tm = DFRobot_TM6605()
if tm.begin() != 0:
    print("Sensor initialization failed!")
    exit(1)

print("Sensor initialization succeeded!")

# Get all vibration effects.
effects = DFRobot_TM6605.effect
# Traverse all effects
for effect in effects:
    if effect.name == DFRobot_TM6605.effect.sleep_command.name:
        continue
    print("\nPlaying effect:{} (id:{})".format(effect.name,effect.value))
    # Set and trigger the effect.
    tm.selectEffect(effect.value) 
    time.sleep(0.5) 
    tm.play()
    if effect.name == DFRobot_TM6605.effect.long_alert.name:
        time.sleep( 8)
    time.sleep(2)
    
    
    tm.stop()
    
    time.sleep(0.5)

print("\nAll vibration effects demonstration completed.")