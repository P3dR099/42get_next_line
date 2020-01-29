/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:39:48 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/29 17:51:09 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_verify_line(char **stack, char **line)
{
	char	*tmp_stack;   // Variable temporal del stack
	char	*strchr_stack;
	int		i;

	i = 0;
	strchr_stack = *stack;   // strchr_stack ahora es doble puntero
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++]) // Si strchr_stack está vacío
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}


static int		gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int		ret;
	char	*tmp_stack;  // var stack temporal

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0) // read retorna un fd
	{
		heap[ret] = '\0';
		if (*stack)  //Si el stack no esta vacío
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (gnl_verify_line(stack, line))
			break  ;
	}
	return (RET_VALUE(ret));
}

int		get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD]; // Esta var es doble puntero
	char			*heap;
	int				ret;
	int				i;

	if ( !line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
	|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])  // Si contiene algo el buffer
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = gnl_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] = '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
