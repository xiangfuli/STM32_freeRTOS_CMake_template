#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.19)

# specify cross compilers and tools
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
SET(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
SET(CMAKE_AR arm-none-eabi-ar)
SET(CMAKE_OBJCOPY arm-none-eabi-objcopy)
SET(CMAKE_OBJDUMP arm-none-eabi-objdump)
SET(SIZE arm-none-eabi-size)
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
SET(ST_FLASH st-flash)

# project SETtings
project(STM32_FREERTOS_CMAKE_TEMPLATE C CXX ASM)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_C_STANDARD 11)


# uncomment to mitigate c++17 absolute addresses warnings
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(
    include
    include/commons
    include/devices/boards
    include/devices/boards/rt-opflow-v1
    include/devices/mcus/STM32F4
    include/devices/mcus/STM32F4/boot
    include/devices/mcus/STM32F4/std_libs
    include/drivers
    include/drivers/stm32_usbd
    include/drivers/stm32_usbotg
    include/DSP_libs
    include/freeRTOS
    include/freeRTOS/freeRTOS_port/gcc
    include/system
)

file(GLOB_RECURSE SOURCES
        "include/**"
        "src/**"
        )

add_definitions(-DUSE_STDPERIPH_DRIVER -DSTM32F40_41xxx -DARM_MATH_CM4 -D__VFP_FP__ -D__FPU_PRESENT)

SET(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/compile_files/STM32F407VGTx_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

# build related commands
SET(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
SET(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

# enable float support in snprintf
SET(NO_SYS_LIB_FLAGS "-specs=nosys.specs -specs=nano.specs")
SET(COMMON_FLAGS "-u _printf_float -u _scanf_float")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${NO_SYS_LIB_FLAGS}")

# enable fpu support
add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

# enable arm math DSP libs support
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_ROUNDING)

# enable arm std peripheral libs support
add_compile_definitions(USE_STDPERIPH_DRIVER)

# specify chip selection
add_compile_definitions(STM32F40_41xxx)

add_compile_definitions(__VFP_FP__)

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMENT "Building ${HEX_FILE}
            Building ${BIN_FILE}"
)

add_custom_target(flash
    COMMAND ${ST_FLASH} write ${BIN_FILE} 0x08000000
    COMMAND ${ST_FLASH} reset
    COMMENT "ST-LINK flashing ${BIN_FILE}"    
)