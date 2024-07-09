# Libft

## 

### ft_isalpha

Parametros: int chr 

Se busca verificar si el valor de chr es una letra del alfabeto
Se comrpueba si el valor de chr se encuentra entre los valores `'a - 97'` y `'z - 122'` o entre `'A - 65'` y `'Z - 90'` 

Return: Si esto es correcto retorna 1, de lo contrario se retorna 0

```c
int	ft_isalpha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	return (0);
}
```

### ft_isdigit

Parametros: int chr

Se busca verificar si el valor de chr es un digito
Se comrpueba si el valor de chr se encuentra entre los valores `'0 - 48'` y `'9 - 57'`

Return: Si esto es correcto retorna 1, de lo contrario se retorna 0

```c
int	ft_isdigit(int chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}
```

### ft_isalnum

Parametros: int chr

Se busca verificar si el valor de chr es un digito o una letra del alfabeto

Return: Si esto es correcto retorna 1, de lo contrario se retorna 0

```c

int	ft_isalnum(int chr)
{
	if (ft_isalpha(chr) || ft_isdigit(chr))
		return (1);
	return (0);
}
```

### ft_isascii

Parametros: int chr

Se busca verificar si el valor de chr es un caracter ASCII (0 - 127)

Return: Si esto es correcto retorna 1, de lo contrario se retorna 0

```c
int	ft_isascii(int chr)
{
	if (chr >= 0 && chr <= 127)
		return (1);
	return (0);
}
```

### ft_isprint

Parametros: int chr

Se busca verificar si el valor de chr es un caracter imprimible (32 - 126)

Return: Si esto es correcto retorna 1, de lo contrario se retorna 0

```c
int	ft_isprint(int chr)
{
	if (chr >= 32 && chr <= 126)
		return (1);
	return (0);
}
```

### ft_strlen

Parametros: const char *str

Se busca obtener la longitud de la cadena de caracteres str

Return: La longitud de la cadena de caracteres str

```c
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
```

### ft_toupper

Parametros: int chr

Se busca convertir el caracter chr a mayuscula
Se comprueba si el valor de chr se encuentra entre los valores `'a - 97'` y `'z - 122'` y se le resta 32 para convertirlo a mayuscula
Restar 32 a un caracter en minuscula lo convierte en mayuscula
a = 97 | A = 65
b = 98 | B = 66
...

Return: El caracter chr en mayuscula

```c
int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		chr -= 32;
	return (chr);
}
```

### ft_tolower

Parametros: int chr

Se busca convertir el caracter chr a minuscula
Se comprueba si el valor de chr se encuentra entre los valores `'A - 65'` y `'Z - 90'` y se le suma 32 para convertirlo a minuscula

Return: El caracter chr en minuscula

```c
int	ft_tolower(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
		chr += 32;
	return (chr);
}
```

### ft_strchr

Parametros: const char *str, int chr
- const char *str: Cadena de caracteres en la que se va a buscar el caracter chr
- int chr: Caracter que se va a buscar en la cadena de caracteres str

Se busca encontrar la primera ocurrencia del caracter chr en la cadena de caracteres str

Recorre la cadena de caracteres
`while (*str)`
Comrpueba si el caracter actual es igual a chr
`if (*str == (char)chr)`
Si es igual retorna un puntero a la primera ocurrencia de chr en str
`return ((char *)str)`
Si no es igual se continua recorriendo la cadena de caracteres
`str++`
Se comprueba si el caracter actual es igual a chr para el caso en que chr sea el caracter nulo
`if (*str == (char)chr)`
Si es igual retorna un puntero a la primera ocurrencia de chr en str
`return ((char *)str)`
Si no es igual se retorna NULL
`return (0)`

```c
char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == (char)chr)
			return ((char *)str);
		str++;
	}
	if (*str == (char)chr)
		return ((char *)str);
	return (0);
}
```

### ft_strrchr

Parametros: const char *str, int chr

- str Cadena de caracteres sobre la que se va a buscar chr
- chr Caracter que se va a buscar en str

```c

```