from tkinter import *
from tkinter import ttk
import serial

def init_calibration_mode(event):
    ser.write(b'1')

def init_default_mode(event):
    ser.write(b'2')

def accept_cal(event):
    # char 'a' for accept.
    ser.write(b'a')

def restart_cal(event):
    # char 'r' for restart
    ser.write(b'r')

def cancel_cal(event):
    # char 'c' for cancel
    ser.write(b'c')

def RESET(event):
    # char 'R' for RESET
    ser.write(b'R')

# Read serial in from port "ACM0" or "ACM1"
# (usb ports, the device id is may be different each time)
# TODO: Generalize this statement to allow for running the GUI when hooked up to a windows PC.
# ser = serial.Serial('/dev/ttyACM0', 9600)
ser = serial.Serial('COM5', 9600)

root = Tk()

calibrationButton = Button(root, text="Calibrate Flex Sensor")
calibrationButton.bind("<Button-1>", init_calibration_mode)
calibrationButton.grid(row=0, column=1, sticky=E, padx=4)

acceptCalButton = Button(root, text="Accept Calibration")
acceptCalButton.bind("<Button-1>", accept_cal)
acceptCalButton.grid(row=1, column=1, sticky=E, padx=4)

restartCalButton = Button(root, text="Restart Calibration")
restartCalButton.bind("<Button-1>", restart_cal)
restartCalButton.grid(row=2, column=1, sticky=E, padx=4)

cancelCalButton = Button(root, text="Cancel Calibration")
cancelCalButton.bind("<Button-1>", cancel_cal)
cancelCalButton.grid(row=3, column=1, sticky=E, padx=4)

defaultButton = Button(root, text="Defaul")
defaultButton.bind("<Button-1>", init_default_mode)
defaultButton.grid(row=0, column=2, sticky=W, padx=4)

RESET_button = Button(root, text="RESET")
RESET_button.bind("<Button-1>", RESET)
RESET_button.grid(row=1, column = 2, sticky=W, padx=4)

root.mainloop()


