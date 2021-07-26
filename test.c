/* void	change_t(char *t, int size, char *buf) //t, size, buf
{

	char	*p; 
	if (!t && size > 0)
		t = ft_strdup(buf);
	else if (t && size > 0)
	{
		p = ft_strdup(t);
		free (t);
		t = ft_strjoin(p, buf);
		free (p);
	}
} */