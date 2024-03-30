/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:16:29 by muhademi          #+#    #+#             */
/*   Updated: 2023/10/27 01:16:29 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_type(char c, va_list *args)
{
	if (c == 's')
		return (print_str(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(*args, int)));
	else if (c == 'c')
		return (print_char(va_arg(*args, int)));
	else if (c == 'u')
		return (print_uint(va_arg(*args, unsigned int)));
	else if (c == 'X' || c == 'x')
		return (print_hex(va_arg(*args, unsigned int), c));
	else if (c == 'p' && print_str("0x"))
		return (print_hex(va_arg(*args, size_t), c) + 2);
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int			i;
	int			len;
	va_list		args;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			len += find_type(string[i + 1], &args);
			i++;
		}
		else
		{
			write(1, &string[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
