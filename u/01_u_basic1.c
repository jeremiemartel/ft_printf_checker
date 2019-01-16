/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_u_basic1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 17:34:58 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			u_basic1(void)
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
	nb = 0;
	ft_printf("precision:%.5u\n", nb);
	ft_printf("Prec + 0:%0.5u\n", nb);
	ft_printf("Prec + minus:%-.5u\n", nb);
	ft_printf("size:%5u\n", nb);
	ft_printf("size + minus:%-5u\n", nb);
	ft_printf("size + 0:%05u\n", nb);
	ft_printf("size + 0 + prec:%05.3u\n", nb);
	ft_printf("size + minus + prec:%-5.3u\n", nb);
	ft_printf("%-5.3u\n", nb);
	ft_printf("%-1.45u\n", nb);
	ft_printf("%-55.35u\n", nb);

	dprintf(2, "precision:%.5u\n", nb);
	dprintf(2, "Prec + 0:%0.5u\n", nb);
	dprintf(2, "Prec + minus:%-.5u\n", nb);
	dprintf(2, "size:%5u\n", nb);
	dprintf(2, "size + minus:%-5u\n", nb);
	dprintf(2, "size + 0:%05u\n", nb);
	dprintf(2, "size + 0 + prec:%05.3u\n", nb);
	dprintf(2, "size + minus + prec:%-5.3u\n", nb);
	dprintf(2, "%-5.3u\n", nb);
	dprintf(2, "%-1.45u\n", nb);
	dprintf(2, "%-55.35u\n", nb);


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
