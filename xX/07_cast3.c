/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_cast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 16:20:26 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			xx_cast3(void)
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


	unsigned char	nb;
	nb = CHAR_MAX;
	ft_printf("%hhx", nb);
	ft_printf("test X:%hhx", nb);
	ft_printf("Hash:%#hhx", nb);
	ft_printf("prec / grande:%.5hhx", nb);
	ft_printf("hash + prec / grande:%#.5hhx", nb);
	ft_printf("hash + prec / petite:%#.1hhx", nb);
	ft_printf("prec + 0: %0.5hhx", nb);
	ft_printf("Prec + minus:%-.5hhx", nb);
	ft_printf("size:%5hhx", nb);
	ft_printf("size + prec:%7.3hhx", nb);
	ft_printf("size + mminus:%-5hhx", nb);
	ft_printf("size + 0:%05hhx", nb);
	ft_printf("size + 0 + hash:%#05hhx", nb);
	ft_printf("size + 0 + prec:%05.3hhx", nb);
	ft_printf("size + minus + prec:%-5.3hhx", nb);
	ft_printf("size + hash + 0 + prec:%#05.3hhx", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3hhx", nb);
	ft_printf("size + hash + minus + prec:%-#7.3hhx", nb);

	dprintf(2, "%hhx", nb);
	dprintf(2, "test X:%hhx", nb);
	dprintf(2, "Hash:%#hhx", nb);
	dprintf(2, "prec / grande:%.5hhx", nb);
	dprintf(2, "hash + prec / grande:%#.5hhx", nb);
	dprintf(2, "hash + prec / petite:%#.1hhx", nb);
	dprintf(2, "prec + 0: %0.5hhx", nb);
	dprintf(2, "Prec + minus:%-.5hhx", nb);
	dprintf(2, "size:%5hhx", nb);
	dprintf(2, "size + prec:%7.3hhx", nb);
	dprintf(2, "size + mminus:%-5hhx", nb);
	dprintf(2, "size + 0:%05hhx", nb);
	dprintf(2, "size + 0 + hash:%#05hhx", nb);
	dprintf(2, "size + 0 + prec:%05.3hhx", nb);
	dprintf(2, "size + minus + prec:%-5.3hhx", nb);
	dprintf(2, "size + hash + 0 + prec:%#05.3hhx", nb);
	dprintf(2, "size + hash + 0 + prec:%0#5.3hhx", nb);
	dprintf(2, "size + hash + minus + prec:%-#7.3hhx", nb);

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
