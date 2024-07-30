/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:22:20 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/04 17:39:01 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void put_text_of_here_doc(char **av, int *p_fd) {
    char *ret;
    int fd;

    fd = open(HEREDOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) {
        close(p_fd[1]);
        exit_handler(1);
    }

    while (1) {
        ft_putstr_fd("heredoc> ", 1);
        ret = get_next_line(0);
        if (!ret || (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0 && 
                     ret[ft_strlen(av[2])] == '\n')) {
            free(ret);
            break;
        }
        ft_putstr_fd(ret, fd);
        free(ret);
    }
    close(fd);
    close(p_fd[1]);
}


void here_doc_init(char **av, t_pipex *pipex) {
    t_variables var;

    if (pipe(pipex->p_fd) == -1) {
        perror("pipe");
        exit(1);
    }
    var.pid = fork();
    if (var.pid == -1) {
        perror("fork");
        exit(1);
    }
    if (var.pid == 0) {
        close(pipex->p_fd[0]);
        put_text_of_here_doc(av, pipex->p_fd);
        exit(0);
    } else {
        close(pipex->p_fd[1]);
        wait(NULL);
        pipex->fd_in = open(HEREDOC, O_RDONLY);
        if (pipex->fd_in == -1) {
            perror("open");
            exit(1);
        }
        dup2(pipex->fd_in, 0);
        close(pipex->fd_in);
        close(pipex->p_fd[0]);
        unlink(HEREDOC); // Supprimez le fichier temporaire
    }
}
