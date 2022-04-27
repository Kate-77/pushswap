
#include <stdio.h>
#include <stdlib.h>

typedef	struct	array
{
	int	*arr;
	int	size;
} t_array;

typedef	struct	s_list
{
	int	content;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*new_elmnt;

	new_elmnt = (t_list *)malloc(sizeof(t_list));
	if (!new_elmnt)
		return (new_elmnt);
	new_elmnt -> content = content;
	new_elmnt -> next = NULL;
	return (new_elmnt);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	lst_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static int	ft_convert(const char *str, int i, int result, int sign)
{
	while (ft_isdigit(str[i]))
	{
		if ((((unsigned long)result * 10) + (str[i] - '0'))
			> (unsigned long)9223372036854775807 && sign > 0)
			return (-1);
		if ((((unsigned long)result * 10) + (str[i] - '0'))
			> (unsigned long)9223372036854775807 + 1 && sign < 0)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;
	int	repeat;

	repeat = 0;
	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_convert(str, i, result, sign);
	return (result);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (*lst == NULL)
		*lst = new;
	else
	{
		head = *lst;
		while (head -> next != NULL)
			head = head -> next;
		head -> next = new;
	}
	return ;
}

void	create(t_array *array, t_list *stack)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		printf("s : %d\n", stack->content);
		array->arr[i] = stack->content;
		printf("a : %d\n", array->arr[i]);
		i++;
		stack = stack->next;
	}
	return ;
}

void	swap_arr(t_array *array, int i, int j)
{
	int	tmp;

	tmp = array->arr[i];
	array->arr[i] = array->arr[j];
	array->arr[j] = tmp;
	return ;
}

void	sort_arr(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (array->arr[j] < array->arr[i])
				swap_arr(array, i, j);
			j++;
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_array	*array;
	int	i;

	stack = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	array->size = lst_size(stack);
	array->arr = (int *)malloc(sizeof(int) * array->size);
	create(array, stack);
	sort_arr(array);
	i = 0;
	while (i < array->size)
	{
		printf("%d\n", array->arr[i]);
		i++;
	}
}
