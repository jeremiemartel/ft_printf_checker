/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 16:46:35 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			f_basic1(void)
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


	double		nb;
	nb = -12547.58;

	ft_printf("test basique:");
    ft_printf("space:% f\n", nb);
    ft_printf("plus:%+f\n", nb);
    ft_printf("hash:%#f\n", nb);
    ft_printf("precision:%.2f\n", nb);
    ft_printf("big prec:%.14f\n", nb);
    ft_printf("precision + hash:%#.0f\n", nb);
    ft_printf("space + prec:% .5f\n", nb);
    ft_printf("space + prec + hash:%# .0f\n", nb);
    ft_printf("space + prec + hash:% #.0f\n", nb);
    ft_printf("Plus + prec / grande:%+.5f\n", nb);
    ft_printf("Plus + prec / petite:%+.0f\n", nb);
    ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    ft_printf("Prec + 0:%0.5f\n", nb);
    ft_printf("Prec + minus:%-.5f\n", nb);
    ft_printf("size:%5f\n", nb);
    ft_printf("size + space:% 5f\n", nb);
    ft_printf("size + plus:%+5f\n", nb);
    ft_printf("size + space:%# 5f\n", nb);
    ft_printf("size + plus:%#+5f\n", nb);
    ft_printf("size + minus:%-5f\n", nb);
    ft_printf("size + 0:%05f\n", nb);
    ft_printf("size + 0 + plus:%+05f\n", nb);
    ft_printf("size + 0 + plus:%0+5f\n", nb);
    ft_printf("size + 0 + prec:%05.3f\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf("size + minus + prec:%-5.3f\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	dprintf(2, "test basique:");
	dprintf(2, "space:% f\n", nb);
	dprintf(2, "plus:%+f\n", nb);
	dprintf(2, "hash:%#f\n", nb);
	dprintf(2, "precision:%.2f\n", nb);
	dprintf(2, "big prec:%.14f\n", nb);
	dprintf(2, "precision + hash:%#.0f\n", nb);
	dprintf(2, "space + prec:% .5f\n", nb);
	dprintf(2, "space + prec + hash:%# .0f\n", nb);
	dprintf(2, "space + prec + hash:% #.0f\n", nb);
	dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
	dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
	dprintf(2, "Prec + 0:%0.5f\n", nb);
	dprintf(2, "Prec + minus:%-.5f\n", nb);
	dprintf(2, "size:%5f\n", nb);
	dprintf(2, "size + space:% 5f\n", nb);
	dprintf(2, "size + plus:%+5f\n", nb);
	dprintf(2, "size + space:%# 5f\n", nb);
	dprintf(2, "size + plus:%#+5f\n", nb);
	dprintf(2, "size + minus:%-5f\n", nb);
	dprintf(2, "size + 0:%05f\n", nb);
	dprintf(2, "size + 0 + plus:%+05f\n", nb);
	dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	dprintf(2, "size + 0 + prec:%05.3f\n", nb);
	dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
	dprintf(2, "size + minus + prec:%-5.3f\n", nb);
	dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
	dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
	dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
	dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	close(pipeans[1]);
	close(pipecor[1]);
	ians = read(pipeans[0], ans, READING_SIZE);
	icor = read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	if (ians >= 0)
		ans[ians] = 0;
	if (icor >= 0)
		cor[icor] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
//	dprintf(2, "%s\n\n", ans);
//	dprintf(2, "%s\n\n", cor);
	exit(FAILURE);
}
