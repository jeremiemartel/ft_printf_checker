/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_multiargs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 16:51:35 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			multiargs2(void)
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

	ft_printf("int : %d hex %x %lx ", INT_MAX, INT_MAX, LONG_MAX);
	dprintf(2,"int : %d hex %x %lx ", INT_MAX, INT_MAX, LONG_MAX);

	ft_printf("int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx ", INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX);
	dprintf(2,"int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx int : %d hex %x %lx ", INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX, INT_MAX, INT_MAX, LONG_MAX);


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
