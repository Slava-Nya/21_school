/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:46:55 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/06 17:17:46 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *res;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	res = (int*)malloc(sizeof(*res) * (max - min));
	while (min < max)
	{
		res[i] = min;
		min++;
		i++;
	}
	return (res);
}
