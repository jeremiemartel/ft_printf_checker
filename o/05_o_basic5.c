/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_o_basic5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 17:47:40 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			o_basic5(void)
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


	unsigned long		nb;
	nb = 12356549864789;
	ft_printf("test o:%lo\n", nb);
	ft_printf("hash:%#lo\n", nb);
	ft_printf("precision / grande:%.5lo\n", nb);
	ft_printf("precision / petite:%.0lo\n", nb);
	ft_printf("Prec + hash / grande:%#.5lo\n", nb);
	ft_printf("Prec + hash / petite:%#.1lo\n", nb);
	ft_printf("Prec + 0:%0.5lo\n", nb);
	ft_printf("Prec + minus:%-.5lo\n", nb);
	ft_printf("Size:%5lo\n", nb);
	ft_printf("size + prec:%7.3lo\n", nb);
	ft_printf("size + minus:%-5lo\n", nb);
	ft_printf("size + zero:%05lo\n", nb);
	ft_printf("size + zero + hash:%#05lo\n", nb);
	ft_printf("size + zero + prec:%05.3lo\n", nb);
	ft_printf("size + minus + prec:%-5.3lo\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3lo\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3lo\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3lo\n", nb);

	dprintf(2, "test o:%lo\n", nb);
	dprintf(2, "hash:%#lo\n", nb);
	dprintf(2, "precision / grande:%.5lo\n", nb);
	dprintf(2, "precision / petite:%.0lo\n", nb);
	dprintf(2, "Prec + hash / grande:%#.5lo\n", nb);
	dprintf(2, "Prec + hash / petite:%#.1lo\n", nb);
	dprintf(2, "Prec + 0:%0.5lo\n", nb);
	dprintf(2, "Prec + minus:%-.5lo\n", nb);
	dprintf(2, "Size:%5lo\n", nb);
	dprintf(2, "size + prec:%7.3lo\n", nb);
	dprintf(2, "size + minus:%-5lo\n", nb);
	dprintf(2, "size + zero:%05lo\n", nb);
	dprintf(2, "size + zero + hash:%#05lo\n", nb);
	dprintf(2, "size + zero + prec:%05.3lo\n", nb);
	dprintf(2, "size + minus + prec:%-5.3lo\n", nb);
	dprintf(2, "size + hash + zero + prec:%#05.3lo\n", nb);
	dprintf(2, "size + hash + zero + prec:%0#5.3lo\n", nb);
	dprintf(2, "size + hash + minus + prec:%-#7.3lo\n", nb);

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
