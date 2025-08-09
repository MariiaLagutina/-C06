#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_is_sorted(char **argv, int argc)
{
	int i = 1;

	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_argv(char **argv, int argc)
{
	int		i;
	char	*tmp;

	while (!ft_is_sorted(argv, argc))
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int i = 1;
	int j;

	ft_sort_argv(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}