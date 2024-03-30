/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:26 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/30 03:21:43 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strchr(char *str, int c);
int		ft_strlen(char *s);
void	str_part_cpy(char *s1, char *s2, int srci, int len);
char	*join(char *s1, char *s2);
char	*get_line_from_buffer(char *buffer);
char	*get_next_line(int fd);
char	*clean_buffer(char *buffer);

#endif
