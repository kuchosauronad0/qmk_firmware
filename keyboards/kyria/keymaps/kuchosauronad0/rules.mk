###BOOTLOADER = atmel-dfu
###EXTRAFLAGS += -flto
###
###OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
###ENCODER_ENABLE = yes       # Enables the use of one or more encoders
###RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
###RGBLIGHT_STARTUP_ANIMATION = no
###LEADER_ENABLE = yes        # Enable the Leader Key feature
###
###TAP_DANCE_ENABLE  = no      #(+1254)
###COMBO_ENABLE      = no
###UNICODEMAP_ENABLE = no
###
###INDICATOR_LIGHTS  = yes
###MACROS_ENABLED    = no
###
###NO_SECRETS = no
###
###BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
###MOUSEKEY_ENABLE = no       # Mouse keys
###EXTRAKEY_ENABLE = no      # Audio control and System control
###CONSOLE_ENABLE = no        # Console for debug
###COMMAND_ENABLE = no        # Commands for debug and configuration
###NKRO_ENABLE = no           # USB Nkey Rollover
###BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
###MIDI_ENABLE = no           # MIDI support
###UNICODE_ENABLE = no        # Unicode
###BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
###AUDIO_ENABLE = no          # Audio output on port C6
###
###STENO_ENABLE = no
###SWAP_HANDS_ENABLE = no
###KEY_LOCK_ENABLE = no
#### SPLIT_TRANSPORT = mirror
###
#### TAP_DANCE_ENABLE = yes

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGBLIGHT_STARTUP_ANIMATION = no

BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no      # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no           # USB Nkey Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no           # MIDI support
UNICODE_ENABLE = no        # Unicode
BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no          # Audio output on port C6
BOOTLOADER = atmel-dfu

# SPLIT_TRANSPORT = mirror

# TAP_DANCE_ENABLE = yes
#

TAP_DANCE_ENABLE  = no      #(+1254)
EXTRAFLAGS += -flto
COMBO_ENABLE = no
AUTO_SHIFT_ENABLE = no
KEY_LOCK_ENABLE = no
POINTING_DEVICE_ENABLE = no
STENO_ENABLE = no
SWAP_HANDS_ENABLE = no
NO_USB_STARTUP_CHECK = no
