/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:31:07 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/30 16:44:21 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Asigna suficiente memoria para una copia del string s1, hace la copia
**	y retorna un puntero al string
*/

char	*ft_strdup(char const *s1)
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
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

/*
**	Asigna memoria con malloc y retorna una version nueva
**	de la cadena terminando con '\0', resultado de la concatenacion
**	de s1 y s2. Si la asignacion de memoria falla retorna nulo
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;  // e la hace un malloc con los iteradores i y j + 1
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
