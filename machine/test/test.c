//gcc test.c ../inc/libft/libft.a
#include "../inc/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *line = NULL;
	int fd;
	int is_er;

	int n_byte = 4;

	unsigned int buf;

	// buf = ft_strnew(n_byte + 1);
	fd = open(argv[1], O_RDONLY);
	if ((is_er = read(fd, &buf, n_byte)) == -1)
	{
		printf("read error\n");
		exit(1);
	}







	int j = 0;
	int i = 0;
	printf("%3u ", buf);
		// ++i;

		// if (i % 8 == 0)
		// {
		// 	printf("\n");
		// 	++j;
		// }

		
	// }
	printf("\nread %d lines\n", j);
	return 0;
}
// 4085508608

// 15369203