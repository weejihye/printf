/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:40:14 by jwee              #+#    #+#             */
/*   Updated: 2022/08/18 21:48:33 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_rlt(const char *s, t_spec *spec)
{
	write(1, s, 1);
	spec->result++;
}

void	ft_putstr_rlt(const char *s, t_spec *spec)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	spec->result += len;
}

void	ft_putnbr_rlt(int n, t_spec *spec)
{
	long long		nb;
	unsigned char	c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		spec->result++;
		nb *= -1;
	}
	if (nb >= 10)
	{
		c = nb % 10 + '0';
		ft_putnbr_rlt(nb / 10, spec);
	}
	else
		c = nb + '0';
	write(1, &c, 1);

}

void	ft_print_spec(const char *s, va_list ap, t_spec *spec)
{
	if (spec->spec == 'c')
	{
		spec->c = va_arg(ap, int);
		ft_putchar_rlt(&spec->c, spec);
	}
	else if (spec->spec == 's')
	{
		spec->s = va_arg(ap, char *);
		ft_putstr_rlt(spec->s, spec);
	}
	else if (spec->spec == 'd' || spec->spec == 'i')
	{
		spec->d = va_arg(ap, int);
		ft_putnbr_rlt(spec->d, spec);
	}
}

void	ft_init_spec(t_spec *spec)
{
	spec->spec = 0;
	spec->c = 0;
	spec->u = 0;
	spec->s = 0;
	spec->d = 0;
	spec->x = 0;
	spec->p = 0;
	spec->result = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_spec	*spec;

	spec = malloc(sizeof(t_form));
	if (!spec)
		return (-1);
	ft_init_spec(spec);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			spec->spec = *s;
			ft_print_spec(s, ap, spec);
			s++;
		}
		while (*s != '%')
		{
			ft_putchar_rlt(s, spec);
			s++;
		}
	}
	return (spec->result);
}
//void	ft_specify_format(const char **s)
//{
//	t_form	*format;
//
//	while (**s)
//	{
//		while (ft_isdigit(**s))
//		{
//			format->width = format->width * 10 + **s - '0';
//			s++;
//		}
//		if (**s == '-')
//			format->align = 1;
//		if (**s == '+')
//			format->plus = 1;
//		if (**s == '.')
//			format->dot = 1;
//		while (ft_isdigit(**s))
//		{
//			format->prec = format->prec * 10 + **s - '0';
//			(*s)++;
//		}
//		if (ft_strchr("cspdiuxX%", **s))
//		{
//			format->spec = **s;
//			s++;
//		}
//		s++;
//	}
//}
