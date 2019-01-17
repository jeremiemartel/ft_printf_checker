/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_di_cast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 15:58:28 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			di_cast2(void)
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


	long long		nb;
	nb = 5643254623165146555;
	ft_printf("space% lld ", nb);
	ft_printf("plus:%+lld ", nb);
	ft_printf("precision:%.5lld ", nb);
	ft_printf("space + prec:% .5lld ", nb);
	ft_printf("Plus + prec / grande:%+.5lld ", nb);
	ft_printf("Prec + 0:%0.5lld ", nb);
	ft_printf("Prec + minus:%-.5lld ", nb);
	ft_printf("size:%5lld ", nb);
	ft_printf("size + space:% 5lld ", nb);
	ft_printf("size + plus:%+5lld ", nb);
	ft_printf("size + minus:%-5lld ", nb);
	ft_printf("size + 0:%05lld ", nb);
	ft_printf("size + 0 + plus:%+05lld ", nb);
	ft_printf("size + 0 + plus:%0+5lld ", nb);
	ft_printf("size + 0 + prec:%05.3lld ", nb);
	ft_printf("size + minus + prec:%-5.3lld ", nb);
	ft_printf("size + plus + 0 + prec:%+05.3lld ", nb);
	ft_printf("size + espace + zero + prec:%0 5.3lld ", nb);
	ft_printf("size + espace + zero + prec:% 05.3lld ", nb);
	ft_printf("size + minus + plus + prec:%-+5.3lld ", nb);

	dprintf(2, "space% lld ", nb);
	dprintf(2, "plus:%+lld ", nb);
	dprintf(2, "precision:%.5lld ", nb);
	dprintf(2, "space + prec:% .5lld ", nb);
	dprintf(2, "Plus + prec / grande:%+.5lld ", nb);
	dprintf(2, "Prec + 0:%0.5lld ", nb);
	dprintf(2, "Prec + minus:%-.5lld ", nb);
	dprintf(2, "size:%5lld ", nb);
	dprintf(2, "size + space:% 5lld ", nb);
	dprintf(2, "size + plus:%+5lld ", nb);
	dprintf(2, "size + minus:%-5lld ", nb);
	dprintf(2, "size + 0:%05lld ", nb);
	dprintf(2, "size + 0 + plus:%+05lld ", nb);
	dprintf(2, "size + 0 + plus:%0+5lld ", nb);
	dprintf(2, "size + 0 + prec:%05.3lld ", nb);
	dprintf(2, "size + minus + prec:%-5.3lld ", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3lld ", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3lld ", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3lld ", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3lld ", nb);


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
