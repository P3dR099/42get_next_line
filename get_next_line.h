/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconde-c <pconde-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:44:03 by pconde-c          #+#    #+#             */
/*   Updated: 2020/01/28 17:50:54 by pconde-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 42
#define MAX_FD 1024 + 1
#define RET_VALUE(ret) ret > 0 ? 1 : ret

int		get_next_line(int const fd, char **line);

#endif