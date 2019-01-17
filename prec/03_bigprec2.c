/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigprec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/15 17:19:23 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			bigprec2(void)
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

	float	f;

	f = 1234.12345;
	ft_printf("%12.15f\n", f);
	f = -1654.586855;
	ft_printf("%12.18f\n", f);
	f = 123121.51421;
	ft_printf("%12.11f\n", f);

	f = 1234.12345;
	dprintf(2, "%12.15f\n", f);
	f = -1654.586855;
	dprintf(2, "%12.18f\n", f);
	f = 123121.51421;
	dprintf(2, "%12.11f\n", f);

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
