NAME = libft.a

SRC =	ft_strlen.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_strcpy.c\
		ft_strcat.c\
		ft_strncpy.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		free_double_chartab.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_ishexa.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_bzero.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strnjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_power.c\
		ft_nb_words.c\
		ft_count_tab.c\
		ft_counter_number.c\
		free_double_inttab.c\
		create_double_inttab.c\
		get_next_line.c\
		ft_realloc.c\
		ft_atoi_base.c\
		ft_count_simpletab.c\
		ft_search_final_caract.c\
		ft_nbr_of_caract.c\
		ft_strrev.c\
		ft_sort_double_tab.c\
		ft_cpy_double_chartab.c\

OBJECTS = $(patsubst %.c,%.o,$(SRC))

HEADER = libft.h

CC = clang

WFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) $(HEADERS) -c -o $@ $^
	@echo "$@"

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
