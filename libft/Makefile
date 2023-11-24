
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEADER = libft.h

SRCS_DIR = char_check conversion linked_list memory output string_manipulation
SRCS = $(foreach dir,$(SRCS_DIR),$(wildcard $(dir)/*.c))
GET_NEXT_LINE_DIR = output/get_next_line
GET_NEXT_LINE_SRCS = $(wildcard $(GET_NEXT_LINE_DIR)/*.c)

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o) $(GET_NEXT_LINE_SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	$(foreach dir,$(SRCS_DIR),mkdir -p $(OBJDIR)/$(dir);)

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
