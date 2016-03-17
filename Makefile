NAME		=	Aaaa # Binary name
DIRSRC		=	. # ./path/to/sources/directorie/
DIROBJ		=	. # ./path/to/object/directorie/
INCLUDE		=	. # ./path/to/include/directorie/
SUB_MAKE	=	# ./path/to/sub/makefile/directorie/ (Put nothing if isn't)
INC_LIB		=	# -L./path/to/lib/directorie -lname
SRC		=	ft_printf.c\
			main.c\
			ft_choose.c\
			ft_choose3_bis.c\
			ft_putchar.c\
			ft_init_struct.c\
			ft_retur.c\
			ft_choose_type.c\
			ft_printf_percent.c\
			ft_printf_str.c\
			ft_putstr.c\
			ft_strlen.c\
			#ft_printf_char.c\



OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)

CC			=	/usr/bin/gcc
CFLAGS		=	-Werror -Wall -Wextra
RM			=	/bin/rm -f
DELETE		=	/bin/rm -f *~ .*
ECHO		=	/bin/echo -e


$(NAME)	:		$(OBJ)
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE))
endif
				$(CC) -o $(NAME) $(SRC)
				@$(ECHO) '> Compiled'

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) clean)
endif
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)



fclean	:		clean
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				#-@$(RM) $(NAME)~
				-@$(DELETE)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

%.o		:		$(DIRSRC)/%.c
				$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
