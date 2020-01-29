/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:51:52 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/29 16:22:10 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
    char *buff;

    line = 0;
    if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
                {
                        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
                        free(buff);
                }
                printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
                if (ret == -1)
                        printf("-----------\nError\n");
                else if (ret == 0)
                        printf("-----------\nEnd of file\n");
                close(fd);
        }
        if (argc == 1)
        {
                while ((ret = get_next_line(0, &buff)) > 0)
                        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
                if (ret == -1)
                        printf("-----------\nError\n");
                else if (ret == 0)
                        printf("-----------\nEnd of stdin\n");
                close(fd);
        }
        return (0);
}