/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:44:03 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/30 17:02:57 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <unistd.h>
# include <stdlib.h>


# define MAX_FD 1024 + 1
# define RET_VALUE(ret) ret > 0 ? 1 : ret

int		get_next_line(int const fd, char **line);
char		*ft_strdup(char const *s1);
char		*ft_strjoin(char const *s1, char const *s2);

#endif