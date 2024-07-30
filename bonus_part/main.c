/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:05:15 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/04 17:39:36 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **env) {
    t_pipex pipex;

    if (ac < 5)
        exit_handler(1);
    pipex.env = env;
    pipex.here_doc = (ft_strncmp(av[1], "here_doc", 8) == 0);
    if (pipex.here_doc) {
        if (ac < 6)
            exit_handler(1);
        pipex.fd_out = open_file(av[ac - 1], 2, &pipex);
        here_doc_init(av, &pipex);
   
    } else {
        pipex.fd_in = open_file(av[1], 0, &pipex);
        pipex.fd_out = open_file(av[ac - 1], 1, &pipex);
    }
    process_commands(av, &pipex);
    clear_all(&pipex);
    return 0;
}
