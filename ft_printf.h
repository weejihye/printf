/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwee <jwee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:46:53 by jwee              #+#    #+#             */
/*   Updated: 2022/08/18 21:45:41 by jwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct spec_list
{
	int				spec;
	char			c;
	char			*s;
	long			d;
	unsigned int	u;
	unsigned int	x;
	unsigned long	p;
	int	result;
}	t_spec;

typedef struct f_list
{
	int	width;
}	t_form;

int	ft_printf(const char *, ...);

#endif
