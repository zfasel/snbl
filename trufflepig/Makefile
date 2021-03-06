PROJECT_NAME     := truffle_pig_dc26
TARGETS          := nrf52832_xxaa
OUTPUT_DIRECTORY := _build
NRFJPROG_DIR := /Users/zfasel/repos/snbl/build/nRF5x-Command-Line-Tools_9_7_3_OSX/nrfjprog

SDK_ROOT := ../build/nRF5_SDK_15.0.0_a53641a
PROJ_DIR := ./

$(OUTPUT_DIRECTORY)/nrf52832_xxaa.out: \
  LINKER_SCRIPT  := gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52.S \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
	$(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c \
	$(SDK_ROOT)/components/libraries/atomic_flags/nrf_atflags.c \
	$(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
	$(SDK_ROOT)/components/ble/common/ble_advdata.c \
  $(SDK_ROOT)/components/ble/ble_advertising/ble_advertising.c \
	$(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage.c \
	$(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage_sd.c \
	$(SDK_ROOT)/components/ble/common/ble_srv_common.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh.c \
	$(SDK_ROOT)/components/softdevice/common/nrf_sdh_ble.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh_soc.c \
	$(SDK_ROOT)/components/libraries/bsp/bsp.c \
	$(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
	$(SDK_ROOT)/components/libraries/queue/nrf_queue.c \
	$(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_rng.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_rng.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_timer.c \
	$(SDK_ROOT)/components/libraries/timer/app_timer.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_spim.c \
	$(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_spi.c \
	$(SDK_ROOT)/components/ble/nrf_ble_qwr/nrf_ble_qwr.c \
	$(SDK_ROOT)/components/ble/ble_services/ble_lbs/ble_lbs.c \
	$(SDK_ROOT)/components/ble/common/ble_conn_params.c \
	$(SDK_ROOT)/components/ble/common/ble_conn_state.c \
	$(SDK_ROOT)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c \
	$(PROJ_DIR)/util/drv_apa102.c \
	$(PROJ_DIR)/util/util.c \
	$(PROJ_DIR)/util/util_button.c \
	$(PROJ_DIR)/util/util_led.c \
	$(PROJ_DIR)/util/util_math.c \
	$(PROJ_DIR)/util/util_timers.c \
	$(PROJ_DIR)/util/util_ble.c \
	$(PROJ_DIR)/animations/v1.c \
	$(PROJ_DIR)/main.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/libraries/experimental_memobj \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/softdevice/s132/headers \
  ./config \
	./util \
	$(PROJ_DIR)/animations \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/experimental_log \
  $(SDK_ROOT)/components/libraries/experimental_log/src \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/modules/nrfx \
	$(SDK_ROOT)/integration/nrfx/legacy \
	$(SDK_ROOT)/modules/nrfx/drivers/include \
	$(SDK_ROOT)/components/libraries/sortlist \
  $(SDK_ROOT)/modules/nrfx/mdk \
	$(SDK_ROOT)/components/libraries/timer \
	$(SDK_ROOT)/components/libraries/timer/experimental \
	$(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/components/libraries/strerror \
	$(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/softdevice/common \
  $(SDK_ROOT)/components/softdevice/s132/headers/nrf52 \
  $(SDK_ROOT)/modules/nrfx/hal \
	$(SDK_ROOT)/components/ble/common \
	$(SDK_ROOT)/components/ble/ble_advertising \
	$(SDK_ROOT)/components/libraries/atomic \
	$(SDK_ROOT)/components/libraries/atomic_flags \
	$(SDK_ROOT)/components/ble/ble_db_discovery \
	$(SDK_ROOT)/components/libraries/queue \
	$(SDK_ROOT)/components/ble/nrf_ble_qwr \
	$(SDK_ROOT)/components/ble/ble_services/ble_lbs \
	$(SDK_ROOT)/components/ble/ble_services/ble_lbs_c \
	$(SDK_ROOT)/components/ble/ble_services/ble_nus \
	$(SDK_ROOT)/components/ble/ble_link_ctx_manager \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
	$(SDK_ROOT)/components/libraries/fstorage \
	$(SDK_ROOT)/components/libraries/atomic_fifo \
  $(PROJ_DIR) \
  $(SDK_ROOT)/components/libraries/util \
	$(SDK_ROOT)/components/ble/nrf_ble_gatt \
	$(SDK_ROOT)/components/libraries/pwr_mgmt

# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O3 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DBOARD_CUSTOM

#CFLAGS += -DAPP_TIMER_V2
#CFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
# CFLAGS += -DBSP_DEFINES_ONLY
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52
CFLAGS += -DNRF52832_XXAA
CFLAGS += -DNRF52_PAN_74
CFLAGS += -DNRF_SD_BLE_API_VERSION=6
CFLAGS += -DS132
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall -Werror
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)

# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBOARD_CUSTOM
#ASMFLAGS += -DAPP_TIMER_V2 # fuck you you fucking fucklajsdfkl;ajdfkl;ajfd
#ASMFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
# ASMFLAGS += -DBSP_DEFINES_ONLY
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52
ASMFLAGS += -DNRF52832_XXAA
ASMFLAGS += -DNRF52_PAN_74
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=6
ASMFLAGS += -DS132
ASMFLAGS += -DSOFTDEVICE_PRESENT

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

nrf52832_xxaa: CFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm


.PHONY: default help

# Default target - first one defined
default: nrf52832_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52832_xxaa
	@echo		flash_softdevice
	@echo		sdk_config - starting external tool for editing sdk_config.h
	@echo		flash      - flashing binary

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc


include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash flash_softdevice erase

# Flash the program
flash: $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex
	@echo Flashing: $<
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --program $< --sectorerase
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --reset

# Flash softdevice
flash_softdevice:
	@echo Flashing: s132_nrf52_6.0.0_softdevice.hex
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --eraseall
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --program $(SDK_ROOT)/components/softdevice/s132/hex/s132_nrf52_6.0.0_softdevice.hex --sectorerase
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --reset

	# Flash softdevice
fullflash: $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex
		@echo Flashing: s132_nrf52_6.0.0_softdevice.hex
		$(NRFJPROG_DIR)/nrfjprog -f nrf52 --eraseall
		$(NRFJPROG_DIR)/nrfjprog -f nrf52 --program $(SDK_ROOT)/components/softdevice/s132/hex/s132_nrf52_6.0.0_softdevice.hex --sectorerase
		$(NRFJPROG_DIR)/nrfjprog -f nrf52 --program $< --sectorerase
		$(NRFJPROG_DIR)/nrfjprog -f nrf52 --reset

reset:
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --reset

erase:
	$(NRFJPROG_DIR)/nrfjprog -f nrf52 --eraseall

SDK_CONFIG_FILE := ../config/sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
