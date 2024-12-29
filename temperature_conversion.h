#ifndef TEMPERATURE_CONVERSION_H
#define TEMPERATURE_CONVERSION_H

#define MAX_ARRAY_LIMIT 100

void temp_convert(void);
void celsius(double array[MAX_ARRAY_LIMIT], int array_size);
void fahrenheit(double array[MAX_ARRAY_LIMIT], int array_size);
void kelvin(double array[MAX_ARRAY_LIMIT], int array_size);

#endif