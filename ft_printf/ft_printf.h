/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:16:29 by muhademi          #+#    #+#             */
/*   Updated: 2023/10/27 01:16:29 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int	print_uint(unsigned int num);
int	print_hex(size_t hex, char c);
int	int_len(int num);
int	print_int(int num);
int	print_str(char *str);
int	print_char(char c);
int	ft_printf(const char *string, ...);

#endif
