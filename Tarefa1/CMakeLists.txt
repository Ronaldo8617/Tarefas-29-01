# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(Tarefa1 C CXX ASM)

pico_sdk_init()

add_executable(Tarefa1 Tarefa1.c)

pico_set_program_name(Tarefa1 "Tarefa1")
pico_set_program_version(Tarefa1 "0.1")

pico_enable_stdio_uart(Tarefa1 0)
pico_enable_stdio_usb(Tarefa1 1)

target_link_libraries(Tarefa1 PRIVATE
        pico_stdlib
        hardware_gpio
        hardware_timer)

target_include_directories(Tarefa1 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_add_extra_outputs(Tarefa1)
