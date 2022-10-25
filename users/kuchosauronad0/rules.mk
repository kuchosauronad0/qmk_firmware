SRC += kuchosauronad0.c \
	   process_records.c
ifneq ($(PLATFORM),CHIBIOS)
  LTO_ENABLE = yes
endif
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no

ifneq ($(strip $(NO_SECRETS)), yes)
  ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    SRC += secrets.c
  endif
  ifeq ($(strip $(NO_SECRETS)), lite)
       OPT_DEFS += -DNO_SECRETS
  endif
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
     SRC += tap_dances.c
endif

ifneq ($(strip $(RGBLIGHT_ENABLE)),yes )
     SRC += rgblight_user.c
endif


ifeq ($(strip $(ENCODER_ENABLE)), yes)
     SRC += encoder.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
     SRC += combo.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
     SRC += leader.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
     SRC += unicode.c
endif

ifeq ($(strip $(MACROS_ENABLED)), yes)
     OPT_DEFS += -DMACROS_ENABLED
endif

ifdef CONSOLE_ENABLE
     ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
         OPT_DEFS += -DKEYLOGGER_ENABLE
     endif
endif

ifeq ($(strip $(MAKE_BOOTLOADER)), yes)
     OPT_DEFS += -DMAKE_BOOTLOADER
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled_user.c
endif

ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
    ifneq ($(strip $(SPLIT_TRANSPORT)), custom)
        SPLIT_TRANSPORT = custom
        QUANTUM_LIB_SRC += kuchosauronad0_transport.c
        OPT_DEFS += -DUSER_CUSTOM_TRANSPORT
        # Unused functions are pruned away, which is why we can add multiple drivers here without bloat.
        ifeq ($(PLATFORM),AVR)
            ifneq ($(NO_I2C),yes)
                QUANTUM_LIB_SRC += i2c_master.c \
                                   i2c_slave.c
            endif
        endif

        SERIAL_DRIVER ?= bitbang
        OPT_DEFS += -DSERIAL_DRIVER_$(strip $(shell echo $(SERIAL_DRIVER) | tr '[:lower:]' '[:upper:]'))
        ifeq ($(strip $(SERIAL_DRIVER)), bitbang)
            QUANTUM_LIB_SRC += serial.c
        else
            QUANTUM_LIB_SRC += serial_$(strip $(SERIAL_DRIVER)).c
        endif
    endif
endif
