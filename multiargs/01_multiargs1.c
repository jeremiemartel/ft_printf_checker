/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_multiargs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 16:48:13 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			multiargs1(void)
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

	ft_printf("%X %o %s %x %d qdaze %c", -123, -432, "okqsd", 5643, 123654, 'S');
	dprintf(2,"%X %o %s %x %d qdaze %c", -123, -432, "okqsd", 5643, 123654, 'S');

	ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	dprintf(2,"%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');

	ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	dprintf(2,"%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');

	ft_printf("%X %o %s %x %d qdaze %c \n %c %X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	dprintf(2,"%X %o %s %x %d qdaze %c \n %c %X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');

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
