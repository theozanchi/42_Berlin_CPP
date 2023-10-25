# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 14:58:35 by tzanchi           #+#    #+#              #
#    Updated: 2023/10/25 17:39:43 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler targets and libraries
CC			=	c++
CFLAGS		=	-g
NAME		=	global_banksters

# Directories
SRCS_DIR	=	./
OBJ_DIR		=	${SRCS_DIR}.o

# Colours, symbols and utils
GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
YELLOW		=	\033[1;33m
RED			=	\033[1;31m
NC			=	\033[0m
BOLD		=	\033[1m
TICK		=	✓

# Generate log file name with timestamp
LOGFILE = $(shell date +'%Y%m%d_%H%M%S').log

SRC			=	Account.cpp \
				tests.cpp \

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})
SRC_NR		=	$(words ${SRCS})

OBJS		=	$(patsubst ${SRCS_DIR}%, ${OBJ_DIR}/%, $(SRCS:.cpp=.o))

all:			project_logo ${NAME}

${NAME}:		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "${YELLOW}\nCompilation complete, ${NAME} executable at the root of the directory${NC}\n"

$(OBJ_DIR)/%.o:	$(SRCS_DIR)%.cpp
				@mkdir -p $(dir $@)
				@printf "Compiling $(notdir $<)"; \
				${CC} ${CFLAGS} -I Account.hpp -c $< -o $@; \
				printf "${GREEN}"; \
				printf " ${TICK}\n"; \
				printf "${NC}"; 

run:			${NAME}
				@echo "\nRunning the test code";
				@./${NAME} > ${LOGFILE}
				@echo "${RED}\nLog file ${LOGFILE} generated${NC}\n"

clean:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "Repo already clean"; \
				else \
					echo "Removing all .o files"; \
					rm -r ${OBJ_DIR}; \
				fi
				@echo "Removing logfiles from root"
				@rm -f 2*.log

fclean:			clean
				@echo "Removing executable from root"
				@rm -f ${NAME}

re:				fclean all


project_logo:
				@echo "${RED}   ___     _     _________     _     ____"
				@echo "  /   \   / \   /         \   / \   /    \ "
				@echo " ( ${CYAN}C++${RED} ) ( - ) ( ${CYAN}Module_00${RED} ) ( - ) ( ${CYAN}ex02${RED} )"
				@echo "  \___/   \_/   \_________/   \_/   \____/${NC}"
				@echo "\n               ${NC}a 42 project by ${BOLD}Théo Zanchi${NC}\n"

.PHONY:			all run clean fclean re project_logo