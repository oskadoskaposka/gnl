/* char return_temp (char *t, int size, char *buf)
{	
	char *p;

	if (!*t && size > 0)
		t = ft_strdup(buf);
	else if (t && size > 0)
	{
		p = ft_strdup(t);
		free (t);
		t = ft_strjoin(p, buf);
		free (p);
	}
	return (t);
} */

/* 
char *has_break(char **t)
{
	char *p[3];

	p[2] = ft_strchr(*t, '\n');
	p[0] = ft_substr(*t, 0, (p[2] - *t + 1));
	p[1] = ft_substr(*t, (p[2] - *t + 1), (ft_strlen(*t) + 1));
	free (*t);
	*t = ft_strdup(p[1]);
	free(p[1]);
	p[1] = 0;
	return (p[0]);

} */