#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifier - conversion specifier structure
 * @spec: conversion specifier
 * @f: function pointer
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
