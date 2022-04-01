
NAME		=	libft.a
INCLUDES	=	../include
SRCS_DIR 	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
FILES       =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_toupper ft_tolower ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRC_FILES 	= 	$(addprefix $(SRC_FILES), $(FILES))

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

###

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			@mkdir -p $(OBJS_DIR)


clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) -f $(OBJSF)
			@echo "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
















# NAME            = libft.a

# FILES           = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_toupper ft_tolower ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
# OBJS            := ${foreach source, ${FILES}, ${source}.o}

# CC              = gcc
# CFLAGS          = -Wall -Wextra -Werror -I.

# RM              = rm -f 

# ${NAME} :       ${OBJS}
# 				ar rcs ${NAME} ${OBJS}

# all :           ${NAME}

# clean :
# 				${RM} ${OBJS}

# fclean:         clean
# 				${RM} ${NAME}

# re :            fclean all

# .PHONY:         all clean fclean re