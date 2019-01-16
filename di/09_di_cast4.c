/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_di_cast4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 15:59:43 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			di_cast4(void)
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
	ft_printf("space% hd ", nb);
	ft_printf("plus:%+hd ", nb);
	ft_printf("precision:%.5hd ", nb);
	ft_printf("space + prec:% .5hd ", nb);
	ft_printf("Plus + prec / grande:%+.5hd ", nb);
	ft_printf("Prec + 0:%0.5hd ", nb);
	ft_printf("Prec + minus:%-.5hd ", nb);
	ft_printf("size:%5hd ", nb);
	ft_printf("size + space:% 5hd ", nb);
	ft_printf("size + plus:%+5hd ", nb);
	ft_printf("size + minus:%-5hd ", nb);
	ft_printf("size + 0:%05hd ", nb);
	ft_printf("size + 0 + plus:%+05hd ", nb);
	ft_printf("size + 0 + plus:%0+5hd ", nb);
	ft_printf("size + 0 + prec:%05.3hd ", nb);
	ft_printf("size + minus + prec:%-5.3hd ", nb);
	ft_printf("size + plus + 0 + prec:%+05.3hd ", nb);
	ft_printf("size + espace + zero + prec:%0 5.3hd ", nb);
	ft_printf("size + espace + zero + prec:% 05.3hd ", nb);
	ft_printf("size + minus + plus + prec:%-+5.3hd ", nb);

	dprintf(2, "space% hd ", nb);
	dprintf(2, "plus:%+hd ", nb);
	dprintf(2, "precision:%.5hd ", nb);
	dprintf(2, "space + prec:% .5hd ", nb);
	dprintf(2, "Plus + prec / grande:%+.5hd ", nb);
	dprintf(2, "Prec + 0:%0.5hd ", nb);
	dprintf(2, "Prec + minus:%-.5hd ", nb);
	dprintf(2, "size:%5hd ", nb);
	dprintf(2, "size + space:% 5hd ", nb);
	dprintf(2, "size + plus:%+5hd ", nb);
	dprintf(2, "size + minus:%-5hd ", nb);
	dprintf(2, "size + 0:%05hd ", nb);
	dprintf(2, "size + 0 + plus:%+05hd ", nb);
	dprintf(2, "size + 0 + plus:%0+5hd ", nb);
	dprintf(2, "size + 0 + prec:%05.3hd ", nb);
	dprintf(2, "size + minus + prec:%-5.3hd ", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3hd ", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3hd ", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3hd ", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3hd ", nb);


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
