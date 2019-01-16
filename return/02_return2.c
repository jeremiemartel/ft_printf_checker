/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_return2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 15:50:45 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			return2(void)
{
	int		pipeans[2];
	int		pipecor[2];
	int		ans;
	int		cor;


	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);

	ans = ft_printf("%s %s %s %d", "asdqwdas das", "asdasd asdasasdasdw qbhd", "", -569521);
	cor = dprintf(2, "%s %s %s %d", "asdqwdas das", "asdasd asdasasdasdw qbhd", "", -569521);
	if (ans != cor)
		exit (FAILURE);

	ans = ft_printf("");
	cor = dprintf(2, "");
	if (ans != cor)
		exit (FAILURE);

	ans = ft_printf("%-43d %12s %096.5d", -321, "Oaklaasd", -9658);
	cor = dprintf(2, "%-43d %12s %096.5d", -321, "Oaklaasd", -9658);
	if (ans != cor)
		exit (FAILURE);


	close(pipeans[1]);
	close(pipecor[1]);
	close(pipeans[0]);
	close(pipecor[0]);

	exit (SUCCESS);
}
