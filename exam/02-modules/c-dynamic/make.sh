#!/bin/bash

# Создаем динамические библиотеки
cd include

# Компилируем math_utils в динамическую библиотеку
cc -c -fPIC math_utils.c
cc -shared -o libmath_utils.dylib math_utils.o

# Компилируем calc в динамическую библиотеку
cc -c -fPIC calc.c
cc -shared -o libcalc.dylib calc.o -L. -lmath_utils

# Компилируем cli в динамическую библиотеку
cc -c -fPIC cli.c
cc -shared -o libcli.dylib cli.o -L. -lcalc

cd ..

# Копируем библиотеки в корневую директорию для удобства запуска
cp include/*.dylib .

# Компилируем main.c и линкуем с динамическими библиотеками
cc -o calculator main.c -L. -lcli -lcalc -lmath_utils -Wl,-rpath,.

# Проверяем успешность компиляции
if [ $? -eq 0 ]; then
    echo "Компиляция успешно завершена. Исполняемый файл: calculator"
    echo "Теперь можно запустить программу командой: ./calculator"
else
    echo "Ошибка при компиляции"
    exit 1
fi
