cd ..

gcc -c misc_maths.c hex_octal_conversion.c powers_and_exponents.c rng.c statistical_operations.c gcd_lcm.c misc.c guessing_game.c temperature_conversion.c prime.c

gcc main.c misc_maths.o hex_octal_conversion.o powers_and_exponents.o rng.o statistical_operations.o gcd_lcm.o misc.o guessing_game.o temperature_conversion.o prime.o -o multi.exe

del *.o

move multi.exe compile_bat_and_exe\multi.exe

cd compile_bat_and_exe