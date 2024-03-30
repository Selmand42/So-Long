/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:16:29 by muhademi          #+#    #+#             */
/*   Updated: 2023/10/27 01:16:29 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int num)
{
	int	res;

	res = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		res += 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		res += 1;
	}
	return (res);
}

int	print_int(int num)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
		print_int(num * -1);
	else
	{
		if (num > 9)
			print_int(num / 10);
		print_char((num % 10) + 48);
	}
	return (int_len(num));
}

int	print_uint(unsigned int num)
{
	int	i;

	i = 0;
	if (num >= 10)
		i += print_uint(num / 10);
	i += print_char((num % 10) + 48);
	return (i);
}

int	print_hex(unsigned long hex, char c)
{
	char	*base;
	int		res;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	res = 0;
	if (hex / 16)
	{
		res += print_hex(hex / 16, c);
		res += print_hex(hex % 16, c);
	}
	else
		res += print_char(base[hex]);
	return (res);
}
