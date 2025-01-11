void test_cofactor(t_matrix m, t_matrix expected)
{
	int index;
	float cofac;
	int x, y;

	index = -1;
	while (++index < 16)
	{
		x = (index % 4);
		y = (index / 4);
		cofac = cofactor(m, x, y);
		printf("Cofactor for {%d %d} = %f\n", x, y, cofac);
		if (cofac != expected.raw[x][y])
		{
			fprintf(stderr, 
			"ERROR:"
			" The expected cofactor doesn't match with result "
			"at {%d, %d}, result = %f, expected = %f\n",
			x, y, cofac, expected.raw[x][y]);
		}
	}
}

void	test_cofactor2(t_matrix m, t_matrix expected)
{
	int	i;
	int	j;
	float	cofac;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			cofac = cofactor(m, j, i);
			if (cofac != expected.raw[i][j])
				fprintf(stderr, "error: wrong cofactor: %f; expected: %f\n"
					, cofac, expected.raw[i][j]);
		}
	}
}

