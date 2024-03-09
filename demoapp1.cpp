#!/usr/bin/env python
import time
from flyt_python import api
drone = api.navigation(timeout=120000) # instance of flyt droneigation class
# at least 3sec sleep time for the drone interface to initialize properly
time.sleep(3)
print ' drone taking off at hight of 5 m at point A of square ABCD'
drone.take_off(5.0)
print ' moving towards point B at side length of 6.5 m of square ABCD'
drone.position_set(6.5, 0, 0, relative=True)
print ' moving towards point c at side length of 6.5 m of square ABCD'
drone.position_set(0, 6.5, 0, relative=True)
print ' moving towards point D at side length of 6.5 m of square ABCD'
drone.position_set(-6.5, 0, 0, relative=True)
print ' moving towards origin point A at side length of 6.5 m of square ABCD'
drone.position_set(0, -6.5, 0, relative=True)
print 'Landing'
drone.land(async=False)
# shutdown the instance
drone.disconnect()
