
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER = libft.h

SRCS = char_check/ft_isalnum.c char_check/ft_isalpha.c char_check/ft_isascii.c char_check/ft_isdigit.c char_check/ft_isprint.c conversion/ft_atoi.c conversion/ft_tolower.c conversion/ft_toupper.c linked_list/ft_lstadd_back.c linked_list/ft_lstadd_front.c linked_list/ft_lstclear.c linked_list/ft_lstdelone.c linked_list/ft_lstiter.c linked_list/ft_lstlast.c linked_list/ft_lstmap.c linked_list/ft_lstnew.c linked_list/ft_lstsize.c memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c output/get_next_line/get_next_line.c output/get_next_line/get_next_line_bonus.c output/ft_printf.c output/ft_putbase_getlen.c output/ft_putbase.c output/ft_putchar_fd.c output/ft_putchar_getlen.c output/ft_putchar.c output/ft_putendl_fd.c output/ft_putint_getlen.c output/ft_putint.c output/ft_putnbr_fd.c output/ft_putptr_getlen.c output/ft_putptr.c output/ft_putstr_fd.c output/ft_putstr_getlen.c output/ft_putstr.c string_manipulation/ft_itoa.c string_manipulation/ft_split.c string_manipulation/ft_strchr.c string_manipulation/ft_strdup.c string_manipulation/ft_striteri.c string_manipulation/ft_strjoin.c string_manipulation/ft_strlcat.c string_manipulation/ft_strlcpy.c string_manipulation/ft_strlen.c string_manipulation/ft_strmapi.c string_manipulation/ft_strncmp.c string_manipulation/ft_strnstr.c string_manipulation/ft_strrchr.c string_manipulation/ft_strtrim.c string_manipulation/ft_substr.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	$(foreach src,$(SRCS),mkdir -p $(OBJDIR)/$(dir $(src));)

$(OBJDIR)/%.o: %.c $(HEADER) | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
