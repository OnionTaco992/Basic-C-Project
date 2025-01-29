cd ..

gcc -c *.c

gcc *.o -o multi.exe

del *.o

move multi.exe compile_bat_and_exe\multi.exe

cd compile_bat_and_exe

cls

multi.exe