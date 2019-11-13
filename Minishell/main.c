/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:04:58 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/22 18:03:27 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	get_comm(char *line)
{
	pid_t ret;
	char *argv[] = {"/bin/ls", "-lG", NULL};

	if (ft_strequ("ls", line))
	{
		ret = fork();
		if (ret == 0)
		{
			printf("child\n");
			execv("/bin/ls", argv);
		}
		else
			error("fork error");
	}
	
	int res;
	pid_t cidX;
	int status = 0;
	int waitoptions = 0;
	if( (ret = fork()) == 0 ) //child1
    {
        printf("in child1\n");
        if( (res = execv(argv[0], argv)) < 0 ) // GIVE ADDRESS OF 2nd element as starting point to skip source.txt
        {
        	printf("error: child1: %d exec failed %d\n", ret, errno);
        	printf("error: cannot execv %s\n",argv[0]);
        	exit(91); //must exit child
        }
    }
    else if(ret > 0 ) //cid>0, parent, waitfor child
    {
        cidX = waitpid(ret, &status, waitoptions);
        printf("child1: %d res %d\n", ret, res);
    }
    else //cid1 < 0, error
    {
        printf("error shit");
	}
}

int		main(int argc, char **argv)
{
	char *line;

	while (1)
	{
		ft_printf("$>");
		get_next_line(0, &line);
		get_comm(line);
		free(line);
	}
	return (0);
}
