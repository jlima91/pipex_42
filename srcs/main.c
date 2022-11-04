/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:11:53 by jlima             #+#    #+#             */
/*   Updated: 2022/07/11 12:50:20 by jlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int *fd, char *argv[], char *envp[])
{
	int		input_fd;
	char	**commands;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		msg_error("Input file");
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	commands = ft_split(argv[2], ' ');
	if (!path(commands[0], envp))
		command_error(commands);
	execve(path(commands[0], envp), commands, envp);
	free_split(commands);
}

void	child_two(int *fd, char *argv[], char *envp[])
{
	int		output_fd;
	char	**commands;

	output_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (output_fd == -1)
		msg_error("Output file");
	dup2(fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	close(fd[0]);
	close(fd[1]);
	commands = ft_split(argv[3], ' ');
	if (!path(commands[0], envp))
		command_error(commands);
	execve(path(commands[0], envp), commands, envp);
	free_split(commands);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		return (ft_printf("Invalid number of arguments.\n"));
	if (pipe(fd) == -1)
		msg_error("Pipe");
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
		child_one(fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
		child_two(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
