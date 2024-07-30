# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 13:00:10 by kahoumou          #+#    #+#              #
#    Updated: 2024/07/04 14:41:02 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = pipex
# NAME_BONUS = pipex_bonus


# CC = gcc

# CFLAGS = -Werror -Wall -Wextra

# RM = rm -rf

# SRCS = 	libft/libft.a\
# 		Pipex/pipex.c\
# 		Pipex/pipex_function.c\
		
		
		

# SRCS_BONUS = 	bonus_part/pipex_bonus.c\
# 				bonus_part/pipex_bonus_function.c\
# 				libft/libft.a\
			
			

# $(NAME) :
# 	make all -C libft
# 	gcc $(CFLAGS) $(SRCS) -o $(NAME)


# all : $(NAME)

# fclean : clean
# 	$(RM) $(NAME)
# 	make fclean -C libft

# clean :
# 	$(RM) $(NAME)
# 	make clean -C libft

# re : fclean all

# bonus : clean
# 	make all -C libft
# 	cc $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)


NAME = pipex
NAME_BONUS = pipex_bonus

CC = gcc
CFLAGS =  -Werror -Wextra -Wall -g3
RM = rm -rf

# Liste des sources principales
SRCS = Pipex/pipex.c \
       Pipex/pipex_function.c\
	   Pipex/exec.c

# Liste des sources bonus
SRCS_BONUS = 	bonus_part/close.c\
				bonus_part/exec_cmd.c\
				bonus_part/exit_free.c\
				bonus_part/fork_pid.c\
				bonus_part/heredoc.c\
				bonus_part/main.c\
				bonus_part/open.c\
				bonus_part/process_command.c\
				bonus_part/geth_path.c
				
				
				
				
				
# Chemin vers la bibliothèque libft
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# Cibles pour le projet principal
$(NAME): $(LIBFT) $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

# Cibles pour la version bonus
$(NAME_BONUS): $(LIBFT) $(SRCS_BONUS:.c=.o)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS)

# Règle pour construire la bibliothèque libft
$(LIBFT):
	make -C $(LIBFT_PATH)

# Cibles pour tout compiler
all: $(NAME)

# Nettoyage des fichiers objets et des exécutables
clean:
	$(RM) $(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_PATH)

# Reconstruire tout
re: fclean all

# Cible pour compiler les bonus
bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
