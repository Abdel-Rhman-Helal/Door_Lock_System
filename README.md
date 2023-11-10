# Door_Lock_System
Components Used in Each Microcontroller:

##ATmega32 Microcontroller 1 (HMI_ECU):
- 8Mhz frequency
- 2x16 LCD
- 4x4 keypad

##ATmega32 Microcontroller 2 (CONTROL_ECU):
- 8Mhz frequency

##Layers in the Project:

1. HMI_ECU (Human Machine Interface):
   - Responsible for user interaction
   - Features a 2x16 LCD and a 4x4 keypad

2. CONTROL_ECU:
   - Manages all processing and decisions in the system

##Behavior of the Project:

###Step 1 - Create a System Password:
- Display "Please Enter Password" on the LCD
- User enters a 5-digit password, with '*' displayed for each digit
- Confirm by re-entering the password
- HMI_ECU sends passwords to CONTROL_ECU via UART
- If matched, save password in EEPROM and proceed to Step 2
- If unmatched, repeat Step 1

###Step 2 - Main Options:
- Always displays main system options on the LCD

###Step 3 - Open Door:
- Display "Please Enter Password"
- User enters password
- HMI_ECU sends password to CONTROL_ECU
- If matched, rotate motor for 15s clockwise, display "Door is Unlocking"
- Hold motor for 3s
- Rotate motor for 15s anticlockwise, display "Door is Locking"

###Step 4 - Change Password:
- Display "Please Enter Password"
- User enters password
- HMI_ECU sends password to CONTROL_ECU
- If matched, repeat Step 1

###Step 5 - Password Verification:
- If passwords are unmatched in Step 3 or Step 4, ask user again
- If passwords match, proceed to open the door or change the password
- If passwords are not matched for the third consecutive time:
  - Activate Buzzer for 1 minute
  - Display error message on LCD for 1 minute
  - Lock the system, no keypad inputs accepted
  - Go to Step 2 (Main Options) again
