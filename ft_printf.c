/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:40:14 by jwee              #+#    #+#             */
/*   Updated: 2022/08/16 22:03:18 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int ft_printf(const int format, ...)
{
	va_list	ap;
	int		arg;
	int		i;

	va_start(ap, format);
	i = 5;
	printf("%d", format);
	while (--i > format)
	{
		arg = va_arg(ap, int);
		printf("%d", arg);
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	int	a = 1, b = 2, c = 3, d = 4;
	ft_printf(a, b, c, d);
	return (0);
}

int	ft_count_set(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i - 1] != '%')
			count++;
		i++;
	}
	return (count);
}

void	ft_printf(const char *, ...)
{
	va_list ap;

	va_start(ap, str);
	//예외처리
	i
