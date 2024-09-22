## C program to ASM

```
cc -S ./main.c -o main.s
```

## Compile ASM

```
as main.s  -o main.o -arch arm64
ld -o main main.o -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64
```
