/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcontent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:10:31 by hcherif           #+#    #+#             */
/*   Updated: 2026/07/27 14:15:21 by hcherif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	FILE	*fp = fopen("file.txt", "r");
	char	ch;

	if (fp == NULL)
	{
		printf("Unable to open file");
		return 1;
	}
	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	fclose(fp);

	return 0;
}
