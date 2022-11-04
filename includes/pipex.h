/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:12:19 by jlima             #+#    #+#             */
/*   Updated: 2022/07/11 15:28:27 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/

/* malloc, free, exit */
# include <stdlib.h>

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

/* open, unlink */
# include <fcntl.h>

/* strerror */
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

/* waitpid, wait */
# include <sys/wait.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/

char	*path(char *cmd, char **envp);
int		command_error(char *cmd[]);
void	msg_error(char *err);
void	free_split(char **args);

#endif