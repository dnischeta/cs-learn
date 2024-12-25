#!/bin/bash

# Компилируем main.c с использованием статических библиотек
cc main.c -L./include -lcli -lcalc -lmath_utils -o calculator

# Проверяем успешность компиляции
if [ $? -eq 0 ]; then
    echo "Компиляция успешно завершена. Исполняемый файл: calculator"
else
    echo "Ошибка при компиляции"
    exit 1
fi
