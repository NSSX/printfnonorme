/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:21:20 by avella            #+#    #+#             */
/*   Updated: 2015/12/01 16:53:44 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"
#include <limits.h>

static int		ft_count(unsigned long long int n, int count)
{
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char		*mystr(char *chaine, int negativ, int count, unsigned long long int myn)
{
	if (negativ == 1)
		chaine[0] = '-';
	while (myn)
	{
		count--;
		chaine[count] = (myn % 10) + '0';
		myn /= 10;
	}
	return (chaine);
}

char			*my_utoa(unsigned long long int n)
{
	char	*chaine;
	int		count;
	unsigned long long int		myn;
	int		negativ;

	negativ = 0;
	count = 0;
	myn = n;
	if (n == 0)
	  return (ft_strdup("0"));
	count = ft_count(n, count);
	chaine = (char *)malloc(sizeof(char) * (count + 10));
	if (chaine == NULL)
		return (NULL);
	mystr(chaine, negativ, count, myn);
	chaine[count] = '\0';
	return (chaine);
}
