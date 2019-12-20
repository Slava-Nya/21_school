/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:29:50 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/10 16:13:30 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	temp = (char *)malloc(sizeof(*temp) * (len + 1));
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
