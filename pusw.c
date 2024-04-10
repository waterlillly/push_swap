#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef	struct	s_list t_list;

typedef	struct	s_list
{
	int		data;
	t_list	*next;
	t_list	*prev;
}				t_list;

char	**ft_split(char const *s, char c);
static int	ft_place(char const *s, char c, int last_pos);
static int	ft_countstrs(char const *s, char c);
int	ft_isdigit(int n);
int	stack_size(t_list **stack);
int	is_valid(char *str);
void	parse_and_fill(t_list **stack_a, int ac, char **av);
void	print_stack(t_list **stack);
t_list	**fill_stack_a(int ac, char **av);
void	add_node(t_list **stack, int value);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *d);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	s;

	srclen = ft_strlen(src);
	s = 0;
	if (size == 0)
		return (srclen);
	while (src[s] != '\0' && s < size - 1)
	{
		dst[s] = src[s];
		s++;
	}
	dst[s] = '\0';
	return (srclen);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *d)
{
	size_t	b;
	char	*duplo;

	b = ft_strlen(d) + 1;
	duplo = (char *)malloc((sizeof(char) * b));
	if (!duplo)
		return (NULL);
	ft_strlcpy(duplo, d, b);
	return (duplo);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*src;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	src = (char *)s;
	size = ft_strlen(s) - start;
	if (len > size)
		len = size;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (src[i] && i < len)
	{
		sub[i] = src[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	else
		return (0);
}

static int	ft_countstrs(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static int	ft_place(char const *s, char c, int last_pos)
{
	while (s[last_pos] != '\0' && s[last_pos] != c)
		last_pos++;
	return (last_pos);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		x;
	int		last_pos;

	last_pos = 0;
	result = malloc((ft_countstrs(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	x = 0;
	while (x < ft_countstrs(s, c))
	{
		while (s[last_pos] == c)
			last_pos++;
		result[x] = ft_substr(s, last_pos, ft_place(s, c, last_pos) - last_pos);
		if (!result[x++])
		{
			while (x > 0)
				free(result[--x]);
			free(result);
			return (NULL);
		}
		last_pos = ft_place(s, c, last_pos + 1);
	}
	result[x] = NULL;
	return (result);
}

void	add_node(t_list **stack, int value)
{
	t_list	*node;
	t_list	*s;

	s = *stack;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = value;
	node->next = NULL;
	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		while (s->next)
			s = s->next;
		node->prev = s;
		s->next = node;
	}
}

t_list	**fill_stack_a(int ac, char **av)
{
	t_list	**stack_a;
	//t_list	*a;
	char	**tokens;
	int		i;
	
	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		return (NULL);
	//a = NULL;
	*stack_a = NULL;
	tokens = NULL;
	i = 0;
	if (ac == 2 && is_valid(av[1]))
	{
		tokens = ft_split(av[1], ' ');
		if (!tokens)
			return (NULL);
		while (tokens[i])
		{
			add_node(stack_a, atoi(tokens[i]));
			//a = a->next;
			i++;
		}
	}
	else
		parse_and_fill(stack_a, ac, av);
	return (stack_a);
}

void	print_stack(t_list **stack)
{
	t_list	*s;

	s = *stack;
	if (!s)
	{
		printf("error\n");
		return ;
	}
	while (s != NULL)
	{
		printf("%d\n", s->data);
		s = s->next;
	}
}

void	parse_and_fill(t_list **stack_a, int ac, char **av)
{
	int		i;
	int		value;
	t_list	*a;

	i = 1;
	a = *stack_a;
	while (i < ac)
	{
		value = atoi(av[i]);
		add_node(stack_a, value);
		i++;
	}
	stack_a = &a;
}

int	is_valid(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*str++)))
			str++;
		else if (*str == ' ' && (*str++ == '-' || ft_isdigit(*str++)))
			str++;
		else
			return (0);
	}
	return (1);
}

int	stack_size(t_list **stack)
{
	int		x;
	t_list	*s;

	x = 0;
	s = *stack;
	while (s)
	{
		x++;
		s = s->next;
	}
	return (x);
}


int	main(int ac, char **av)
{
	t_list	**stack_a;
	
	stack_a = NULL;
	if (ac < 2)
		return (0);
	stack_a = fill_stack_a(ac, av);
	printf("%d elements in stack\n", stack_size(stack_a));
	print_stack(stack_a);
	return (0);
}
