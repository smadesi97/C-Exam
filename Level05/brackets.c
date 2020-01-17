#include "brackets.h"

static int	match_brackets(int a, int b)
{
	return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

static int	check_brackets(char *str)
{
	int i = 0;
	int top = 0;
	int stack[BUFF_SIZE];

	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			stack[++top] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!match_brackets(stack[top--], str[i]))
				return (0);
		i++;
	}
	return (!top);
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 1)
		write (1, "\n", 1);
	while (--argc)
	{
		if (check_brackets(argv[++i]))
			write (1, "OK\n", 3);
		else
			write (1, "Error\n", 6);
	}
	return (0);
}
