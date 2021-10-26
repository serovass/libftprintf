# libftprintf
A library that contains ft_printf, a function that will mimic the real printf

External functs: malloc, free, write, va_start, va_arg, va_copy, va_end

The function must not do the buffer management like the real printf

The function must be prototyped as follows: int ft_printf(const char *, ...);

Manages
- any combination of the following conversions : cspdiuxX%
- any combination of the following flags : -0.*
