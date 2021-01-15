cmake_minimum_required(VERSION 3.17)
project(libftprintf.a C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf main.c)
add_library(libftprintf.a
        STATIC
        ft_base_conversions.c
        ft_handle_char.c
        ft_handle_hexa.c
        ft_handle_modulo.c
        ft_handle_numbers.c
        ft_handle_options.c
        ft_printf.h
        ft_printf_utils.c
        ft_printf_utils_2.c
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        initialize_structs.c
        parse.c
        parse_options.c)
target_link_libraries(ft_printf LINK_PUBLIC libftprintf.a)
