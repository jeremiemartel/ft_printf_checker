/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_nullprec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/15 15:53:59 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			nullprec3(void)
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

	float		nb;
	nb = 0;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = 12.5;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = -25632.2541;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = -1.0123;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);
	nb = 12354.569874;
	ft_printf("null prec : %+.0f\n", nb);
	dprintf(2, "null prec : %+.0f\n", nb);

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
