/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_library.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:07:39 by jmartel           #+#    #+#             */
/*   Updated: 2018/12/01 15:22:01 by thberrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		putstr_safe(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return ;
}

char		*strdup_safe(const char *s1)
{
	int			len;
	char		*res;

	len = 0;
	while (s1[len] != 0)
		len++;
	if (!(res = (char*)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = 0;
	return (res);
}

static void	ft_setinfos(int n, int *decimal, int *sign)
{
	*decimal = 1;
	*sign = 1;
	if (n < 0)
		*sign = -1;
	while (n / *decimal >= 10 || n / *decimal <= -10)
		*decimal *= 10;
}

void		putnbr_safe(int n)
{
	int		decimal;
	int		sign;
	char	digit;

	ft_setinfos(n, &decimal, &sign);
	if (n < 0)
		putstr_safe("-");
	while (decimal > 0)
	{
		digit = (n / decimal * sign) + '0';
		putstr_safe(&digit);
		n %= decimal;
		decimal /= 10;
	}
}
