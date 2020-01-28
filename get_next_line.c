/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:39:48 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/28 20:44:17 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(char const *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i],
	s2[i] = '\0';
	return (s2);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;  // se la hace un malloc con los iteradores i y j + 1
	char	*tmp_s3; // var tmp a la que se le asigna a s1 y s2
	size_t	i;	
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;  // Se le asigna la var s3 con la memoria reservada
	while (*s1 != '\0')
		*tmp_s3++ = *s1++; 
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

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
}


static int		gnl_readline(int fd, char *heap, char **stack, char **line)
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
			break;
	}
	return (RET_VALUE(ret));
}
