.global _main              // точка входа для macOS
.align 2

_main:
    // вывод строки
    mov     x0, #1          // файловый дескриптор 1 (stdout)
    adrp    x1, hello@PAGE  // загружаем страницу с адресом строки
    add     x1, x1, hello@PAGEOFF  // добавляем смещение
    mov     x2, #11         // длина строки
    mov     x16, #4         // системный вызов 4 (write) для macOS
    svc     #0x80           // вызов системы

    // выход из программы
    mov     x0, #0          // код возврата 0
    mov     x16, #1         // системный вызов 1 (exit) для macOS
    svc     #0x80           // вызов системы

.data
    hello: .ascii "Hello World\n"