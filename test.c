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