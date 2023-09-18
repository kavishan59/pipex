SRCS := main.c check_args_init.c get_path.c close.c

SRCS_BONUS := main_bonus.c check_args_init.c get_path.c close.c  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c main_bonus2.c

OBJS := $(SRCS:.c=.o)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)

DEPS := $(OBJS:.o=.d)

DEPS_BONUS := $(OBJS_BONUS:.o=.d)

CC := gcc

CFLAGS := -Werror -Wall -Wextra 

CPPFLAGS := -MMD -MP

LIBS := ft

LIBS_TARGET := libft/libft.a

LDFLAGS := $(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS := $(addprefix -l,$(LIBS))

NAME = pipex

NAME_BONUS = pipex_bonus

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(LIBS_TARGET) : 
	cd ./libft && make

$(NAME) : $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)

-include $(DEPS) $(DEPS_BONUS)

clean:
	cd ./libft && make fclean
	rm -f $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
