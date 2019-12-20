/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:20:58 by hlorrine          #+#    #+#             */
/*   Updated: 2019/09/09 16:02:01 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] && b[i] && (a[i] == b[i]))
	{
		i++;
	}
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

void	ft_change(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (j < argc - 2)
	{
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				ft_change(&argv[i + 1], &argv[i]);
			i++;
		}
		j++;
		i = 1;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
		ft_putchar('\n');
	}
	return (0);
}
