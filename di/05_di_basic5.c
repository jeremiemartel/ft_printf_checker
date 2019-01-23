/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_di_basic5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 14:16:31 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			di_basic5(void)
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


	int		nb;
	nb = 56432;
	ft_printf("space% d ", nb);
	ft_printf("plus:%+d ", nb);
	ft_printf("precision:%.5d ", nb);
	ft_printf("space + prec:% .5d ", nb);
	ft_printf("Plus + prec / grande:%+.5d ", nb);
	ft_printf("Prec + 0:%0.5d ", nb);
	ft_printf("Prec + minus:%-.5d ", nb);
	ft_printf("size:%5d ", nb);
	ft_printf("size + space:% 5d ", nb);
	ft_printf("size + plus:%+5d ", nb);
	ft_printf("size + minus:%-5d ", nb);
	ft_printf("size + 0:%05d ", nb);
	ft_printf("size + 0 + plus:%+05d ", nb);
	ft_printf("size + 0 + plus:%0+5d ", nb);
	ft_printf("size + 0 + prec:%05.3d ", nb);
	ft_printf("size + minus + prec:%-5.3d ", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d ", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d ", nb);
	ft_printf("size + espace + zero + prec:% 05.3d ", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d ", nb);

	dprintf(2, "space% d ", nb);
	dprintf(2, "plus:%+d ", nb);
	dprintf(2, "precision:%.5d ", nb);
	dprintf(2, "space + prec:% .5d ", nb);
	dprintf(2, "Plus + prec / grande:%+.5d ", nb);
	dprintf(2, "Prec + 0:%0.5d ", nb);
	dprintf(2, "Prec + minus:%-.5d ", nb);
	dprintf(2, "size:%5d ", nb);
	dprintf(2, "size + space:% 5d ", nb);
	dprintf(2, "size + plus:%+5d ", nb);
	dprintf(2, "size + minus:%-5d ", nb);
	dprintf(2, "size + 0:%05d ", nb);
	dprintf(2, "size + 0 + plus:%+05d ", nb);
	dprintf(2, "size + 0 + plus:%0+5d ", nb);
	dprintf(2, "size + 0 + prec:%05.3d ", nb);
	dprintf(2, "size + minus + prec:%-5.3d ", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3d ", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3d ", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3d ", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3d ", nb);


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
