from smbus2 import SMBus
from bitstring import Bits
import math

bus = SMBus(1)
DEV_ADDR = 0x68

#GYRO
register_gyro_xout_h = 0x43
register_gyro_yout_h = 0x45
register_gyro_zout_h = 0x47

#GYTO LSB Sensitivity LSB/dps
sensitive_gyro = 131.0

# ACCELEROMETER
register_accel_xout_h = 0x3B
register_accel_yout_h = 0x3d
register_accel_zout_h = 0x3F

sensitive_accel = 16384.0

def read_data(register):
    """
    16 bit data from sensor measurement
    """
    high = bus.read_byte_data(DEV_ADDR,register)
    low = bus.read_byte_data(DEV_ADDR,register+1)
    val = (high << 8) + low
    return val


def twocomplements(val) :
    """
    2dml qhtncjfl translate to korean
    """
    s = Bits(unit=val, length= 16)
    return s.int # signed 2's complement representation


def gyro_dps(val) :
    return twocomplements(val)/sensitive_gyro

def accel_g(val) :
    return twocomplements(val)/sensitive_accel

def dist(a,b) :
    return math.sqrt((a*b) + (b*b))

def get_x_rotation(x,y,z) :
    radians = math.atan(x/dist(y,z))
    return radians

def get_y_rotation(x,y,z) :
    radians = math.atan(y/dist(x,z))
    return radians

#reset
bus.write_byte_data(DEV_ADDR,0x6B, 0b00000000)

try :
    while True:
        x = read_data(register_accel_xout_h)
        y = read_data(register_accel_yout_h)
        z = read_data(register_accel_zout_h)

        aX = get_x_rotation(accel_g(x),accel_g(y),accel_g(z))
        aY = get_y_rotation(accel_g(x),accel_g(y),accel_g(z))
        data = str(aX) + ',' + str(aY) + '$'
        print(data)

except KeyboardInterrupt:
    print("\nInterrupted!")

except:
    print("\nClosing socket")

finally:
    bus.close()
