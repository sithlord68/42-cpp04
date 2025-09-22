# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 19:34:50 by yoda              #+#    #+#              #
#    Updated: 2025/09/22 09:40:43 by pjolidon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	polymorphism

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				Unicorn.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

SRCDIR		=	./
OBJDIR		=	./
BIN			=	${NAME}
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wshadow
TFLAGS		=	${FLAGS} -g3

# Add folder to files and objects
SRCS		:=	${addprefix ${SRCDIR}, ${SRC}}
OBJS		:=	${addprefix ${OBJDIR}, ${SRC:.c=.o}}

all:	${NAME}

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${BIN}

test:	fclean
	${CC} ${TFLAGS} ${SRC} -o ${BIN}

clean:
	${RM} ${OBJ}	
	${RM} ask.txt || true

fclean:	clean
	${RM} ${BIN}

re:	fclean all

#########################################################################
# git push
push:		ppush repos

# git push end-of-day
pushend:	ppushend repos

# prepare git for rendering
render:		prender repos

# git push to all repos
repos:
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		@REMOTES=$$(git remote); \
		for REMOTE in $$REMOTES; do \
			echo "**** PUSH vers $$REMOTE ****"; \
			git push $$REMOTE; \
			echo "###########################"; \
			echo "# PUSHED $$REMOTE"; \
			echo "###########################"; \
		done; \
		echo "######################################################"; \
		echo "# ${DATE} - pushed"; \
		echo "######################################################"; \

# Debug level request if test commpilation
COMMSG		?= ${shell bash -c 'read -p "Message de commit: " commsg; echo $$commsg'}
	
# prepare Git push 
ppush:		fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		git commit -m "${DATE} ${COMMSG} - make push"

# prepare End of day git push
ppushend:	fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		git commit -m "${DATE} - make pushend"

# prepare Git push for rendering
prender:	fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		${IGNORE} ${OBJS} || true
		${IGNORE} ${TSTFIL} || true
		${IGNORE} *pdf || true
		${IGNORE} *txt || true
		${IGNORE} gnl${SVFILE} || true
		${IGNORE} ./vers || true
		${IGNORE} ${SVFILE} || true
		git commit -m "${DATE} - make render"

ask:	fclean
	@cat Makefile > ask.txt
	@cat *hpp >> ask.txt	
	@cat *cpp >> ask.txt	

.PHONY:		all clean fclean re push pushend render repos ppush ppushend prender ask
