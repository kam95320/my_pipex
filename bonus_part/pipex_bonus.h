/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:13:07 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/04 16:57:20 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define HEREDOC ".heredoc_tmp"
# include "../libft/libft.h"
# include "pipex_bonus.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
#include<stdbool.h>
# include <errno.h>
# define UNEXISTING_FILE ": No such file or directory"
# define BAD_ACCESS ": Permission denied"

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_pipex
{
    int fd_in;
    int fd_out;
    int tmp;
    int fd;
    int p_fd[2];
    int here_doc;
    char **env;
} t_pipex;

typedef struct s_variables
{
    int i;
    char *exec;
    char **allpath;
    char *path_part;
    char *path_env;
    char **s_cmd;
    int j;
    char *sub;
    pid_t pid;
    char *path;
} t_variables;


void ft_free_tab(char **tab);
void exec_cmd(char *cmd, t_pipex *pipex);
 void put_text_of_here_doc(char **av, int *p_fd);
void here_doc_init(char **av, t_pipex *pipex);
void exit_handler(int n_exit);
char *find_road_for_env(char *name, char **env);
char *get_path(char *cmd, char **env);
void process_commands(char **av, t_pipex *pipex);
void	ft_dup_two(t_pipex *pipex, char *in_out, int zero_one);
void	ft_close(t_pipex *pipex, char *fd_in_out, int fd_zero_one);
int	    ft_fork(pid_t pid);
void	ft_pid(t_pipex *pipex);
void ft_free_tab(char **tab);
void exit_handler(int n_exit);
void free_in_path(char **allpath, char **s_cmd);
void	process_commands(char **av, t_pipex *pipex);
void    clear_all(t_pipex *pipex);
int     open_file(char *file, int in_or_out, t_pipex *pipex);

#endif

