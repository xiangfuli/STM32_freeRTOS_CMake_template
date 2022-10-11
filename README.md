CMake Template of project using STM32F4 with FreeRTOS
==

This project is based on STM32F4 standard peripheral library and [FreeRTOS LTS 202012.05](https://www.freertos.org/a00104.html).

Directories in template project
--

```
Directory
├── compile_files                         ->          LD scripts used in linking procedure of compiling process
├── debug_files                           ->          STM32F4 register specification
├── include
│   ├── commons                           ->          (provided by users) common files that could be shared among different modules
│   ├── devices
│   │   └── mcus
│   │       ├── stm32f4
│   │       │   ├── boot                  ->          start up files needed by nrf52840
│   │       │   └── std_libs              ->          standard peripheral library files
│   ├── drivers
│   │   ├── stm32_usbd                    ->          STM32 USB device library
│   │   ├── stm32_usbotg                  ->          STM32 USB OTG library
│   ├── DSP_libs                          ->          Digital processing library used by stm32f4
│   ├── freeRTOS                          ->          free RTOS files
│   │   ├── freeRTOS_port                 ->          macros used by different compilers
│   └── system                            ->          (provided by users)
│   │   ├── usb                           ->          user defined usb configuration
└── src
    ├── ....
```

Build
==

Tools required
--

1. Command line tools
   1. st-link executable - tool for programming through ST-LINK programmers and debuggers, you can download this tool from the official website: [st-link Command Line Tools](https://www.st.com/en/development-tools/stsw-link004.html)
2. Program tools
   1. ST-Link device


Compile
--

```
mkdir build && cd build && cmake .. && make
```

Flash
--

After you have compile the whole project, using following command to flash the executable files

```
cd build && make flash
```




