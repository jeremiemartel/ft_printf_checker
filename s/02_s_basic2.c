/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_s_basic2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 14:00:32 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			s_basic2(void)
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

	char	*str;
	str = "Okalmos Speculos";

	ft_printf("test basique:%s", str);
	ft_printf("precision / zero:%.0s", str);
	ft_printf("precision / petite:%.5s", str);
	ft_printf("precision / grande:%.15s", str);
	ft_printf("prec + minus:%-.5s", str);
	ft_printf("size / petite:%5s", str);
	ft_printf("size / grande:%15s", str);
	ft_printf("Minus + size / petite:%-5s", str);
	ft_printf("Minus + size / grande:%-15s", str);
	ft_printf("Minus + size + prec:%-15.5s", str);
	ft_printf("NULL:%12s", NULL);
	ft_printf("NULL:%1s", NULL);
	ft_printf("NULL:%-5.6s", NULL);
	ft_printf("NULL:%-.8s", NULL);
	ft_printf("NULL:%.12s", NULL);
	ft_printf("empty:%-.5s", "");
	ft_printf("empty:%-1.32s", "");
	ft_printf("empty:%1.4s", "");
	ft_printf("empty:%23s", "");

	dprintf(2, "test basique:%s", str);
	dprintf(2, "precision / zero:%.0s", str);
	dprintf(2, "precision / petite:%.5s", str);
	dprintf(2, "precision / grande:%.15s", str);
	dprintf(2, "prec + minus:%-.5s", str);
	dprintf(2, "size / petite:%5s", str);
	dprintf(2, "size / grande:%15s", str);
	dprintf(2, "Minus + size / petite:%-5s", str);
	dprintf(2, "Minus + size / grande:%-15s", str);
	dprintf(2, "Minus + size + prec:%-15.5s", str);
	dprintf(2, "NULL:%12s", NULL);
	dprintf(2, "NULL:%1s", NULL);
	dprintf(2, "NULL:%-5.6s", NULL);
	dprintf(2, "NULL:%-.8s", NULL);
	dprintf(2, "NULL:%.12s", NULL);
	dprintf(2, "empty:%-.5s", "");
	dprintf(2, "empty:%-1.32s", "");
	dprintf(2, "empty:%1.4s", "");
	dprintf(2, "empty:%23s", "");

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

