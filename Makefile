NAME = libftprintf.a

SRCS =  parse.c \
		parse_opt.c \
		ft_handle_hexa_opts.c \
		initialize_structs.c \
		ft_printf_utils_2.c \
		ft_printf_utils.c \
		ft_handle_char.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_handle_nb_opts.c \
		ft_handle_opt.c \
		ft_base_conversions.c \
		ft_handle_numbers.c \
		ft_handle_hexa.c \
		ft_handle_modulo.c
		
SURPL_O = 	parse.o \
            parse_opt.o \
            initialize_structs.o \
            ft_handle_hexa_opts.o \
    		    ft_handle_nb_opts.o \
            ft_printf_utils_2.o \
            ft_printf_utils.o \
            ft_handle_char.o \
           	ft_putchar.o \
            ft_putstr.o \
            ft_handle_opt.o \
            ft_base_conversions.o \
            ft_handle_numbers.o \
            ft_handle_hexa.o \
            ft_handle_modulo.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
