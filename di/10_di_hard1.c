/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_di_hard1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 16:10:19 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			di_hard1(void)
{
	int		pipeans[2];
	int		pipecor[2];
	int		ians;
	int		icor;
	char	ans[READING_SIZE + 1];
	char	cor[READING_SIZE + 1];

	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);


	short		nb;
	nb = -23;
	ft_printf("max int :  %d", INT16_MAX);
	ft_printf("min int :  %d", INT16_MIN);
	ft_printf("max int :  %d", INT32_MAX);
	ft_printf("min int :  %d", INT32_MIN);
	ft_printf("max long :  %ld", LONG_MAX);
	ft_printf("min long :  %ld", LONG_MIN);
	ft_printf("max long long :  %lld", __LONG_LONG_MAX__);
	ft_printf("min long long :  %lld",LLONG_MIN);

	dprintf(2, "max int :  %d", INT16_MAX);
	dprintf(2, "min int :  %d", INT16_MIN);
	dprintf(2, "max int :  %d", INT32_MAX);
	dprintf(2, "min int :  %d", INT32_MIN);
	dprintf(2, "max long :  %ld", LONG_MAX);
	dprintf(2, "min long :  %ld", LONG_MIN);
	dprintf(2, "max long long :  %lld", __LONG_LONG_MAX__);
	dprintf(2, "min long long :  %lld",LLONG_MIN);

	close(pipeans[1]);
	close(pipecor[1]);
	ians = read(pipeans[0], ans, READING_SIZE);
	icor = read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	ans[ians] = 0;
	cor[icor] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
	exit(FAILURE);
}
