##
## EPITECH PROJECT, 2018
## Klax
## File description:
## Makefile
##

NAME		=	Klax

GRAPHICS_DIR	=	graphics

GAME_DIR	=	game

MANAGING_DIR	=	managing

SRCS		=	$(GAME_DIR)/Main.cpp				\
			$(GAME_DIR)/GameManager.cpp			\
			$(GAME_DIR)/Timer.cpp				\
			$(GRAPHICS_DIR)/GraphicManager.cpp		\
			$(GRAPHICS_DIR)/Background.cpp			\
			$(GRAPHICS_DIR)/Platform.cpp			\
			$(GRAPHICS_DIR)/Block.cpp			\
			$(GRAPHICS_DIR)/Text.cpp			\
			$(MANAGING_DIR)/ErrorManaging.cpp		\

LD		=	g++

ALLEGROFLAGS	=	-lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_ttf

RM		=	rm -f

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(LD) $(ALLEGROFLAGS) -lpthread -o $(NAME) $(OBJS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '-'

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS) | tr ' ' '-'

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '-'

re:		fclean all