/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:40:26 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(t_flags *flags, unsigned int u)
{
	char	*s;
	int		len;
	int		to_print;

	len = 0;
	to_print = 0;
	s = ft_itoa_base(u, DEC_BASE);
	to_print += ft_strlen(s);
	if (to_print > flags->precision)
		flags->precision = to_print;
	if (flags->minus == 1)
		len = ft_handle_left_justify(flags, len, 0, s);
	else
		len = ft_handle_right_justify(flags, len, 0, s);
	free(s);
	return (len + flags->precision);
}

int	ft_printf_print_u(t_flags *flags, va_list ap)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(ap, unsigned int);
	if (u == 0 && flags->dot && !flags->precision && !flags->width)
		return (0);
	else if (u == 0 && flags->dot && !flags->precision && flags->width)
	{
		while (len < flags->width)
			len += ft_putchar(' ');
		return (len);
	}
	return (ft_put_u(flags, u));
}
