/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/29 13:05:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	creat_envp(&data, argc, argv, envp);
	creat_cmd(&data);
	creat_pipe(&data);
	file_check(&data);
	i = 0;
	while (i <= data.npipe)
	{
		data.pipenum = i;
		child(&data, 0);
		if (data.pipenum == 0 && data.hdflag == 1)
			unlink("here_doc_tmp");
		i++;
	}
	close_pipe(&data);
	while (wait(0) > 0)
		write(1, "", 0);
	return (0);
}
