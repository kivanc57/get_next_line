/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgordu <kgordu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:25:55 by kgordu            #+#    #+#             */
/*   Updated: 2024/09/09 17:26:57 by kgordu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	main(void)
{
	char *line;
	int fd;

	fd = open("./text/test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;
		}
		printf("%s", line);
		free(line);
		line = NULL;
		printf("Press Enter to continue...");
		getchar();
	}
	close(fd);
	return (0);
}