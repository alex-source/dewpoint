# Корневой каталог исходников Arduino Core
ARDUINO_DIR=/usr/share/arduino/hardware/archlinux-arduino/avr/
# Выбираем целевой контроллер (Arduino Uno, Nano, Mini)
ARDUINO_MCU=atmega328p
# Частота тактирования контроллера
ARDUINO_FCPU = 16000000L

QT -=gui core
CONFIG -= qt
TEMPLATE = app

DESTDIR = ../bin
TARGET = ds18b20

INCLUDEPATH += $$ARDUINO_DIR/cores/arduino
INCLUDEPATH += $$ARDUINO_DIR/variants/standard
INCLUDEPATH += $$ARDUINO_DIR/libraries
INCLUDEPATH += /usr/avr/include

QMAKE_CC = /usr/bin/avr-gcc
QMAKE_CFLAGS += -c -g -Os -w -ffunction-sections -fdata-sections
QMAKE_CFLAGS += -MMD -mmcu=$$ARDUINO_MCU -DF_CPU=$$ARDUINO_FCPU
QMAKE_CFLAGS += -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

QMAKE_CXX = /usr/bin/avr-g++
QMAKE_CXXFLAGS += -c -g -Os -w  -ffunction-sections -fdata-sections
QMAKE_CXXFLAGS += -fno-exceptions -fno-threadsafe-statics
QMAKE_CXXFLAGS += -MMD -mmcu=$$ARDUINO_MCU -DF_CPU=$$ARDUINO_FCPU
QMAKE_CXXFLAGS += -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

QMAKE_LINK = /usr/bin/avr-gcc
QMAKE_LFLAGS = -w -Os -Wl,--gc-sections -mmcu=$$ARDUINO_MCU
QMAKE_LIBS = -lm

QMAKE_POST_LINK += /usr/bin/avr-objcopy -O ihex -j .text -j .data -S ${TARGET} ${TARGET}.hex

HEADERS += $$files($$ARDUINO_DIR/cores/arduino/*.h) \
HEADERS += $$files($$ARDUINO_DIR/variants/standard/*.h)

SOURCES += $$files($$ARDUINO_DIR/cores/arduino/*.c)
SOURCES += $$files($$ARDUINO_DIR/cores/arduino/*.cpp)

INCLUDEPATH += ./include
HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)

INCLUDEPATH += /home/aaz/Arduino/libraries/OneWire
HEADERS += /home/aaz/Arduino/libraries/OneWire/onewire.h
SOURCES += /home/aaz/Arduino/libraries/OneWire/onewire.cpp

INCLUDEPATH += /home/aaz/Arduino/libraries/DallasTemperature
HEADERS += /home/aaz/Arduino/libraries/DallasTemperature/DallasTemperature.h
SOURCES += /home/aaz/Arduino/libraries/DallasTemperature/DallasTemperature.cpp

