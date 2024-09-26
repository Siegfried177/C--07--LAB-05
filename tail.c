#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int n, c = 0;
	if (argc == 1) n = 10;
	else n = atoi(argv[1]) ? atoi(argv[1]) : 10;
	size_t tam = 0;
	char *tail[n], *aux;
	for(int i = 0; i < n; i++)
		tail[i] = NULL;
    
	puts("Ingrese un texto:");
	while(getline(&aux, &tam, stdin) != 1){
		if(c == n){
			c = n - 1;
			free(tail[0]);
			for(int i = 0; i < n - 1; i++)
				tail[i] = tail[i + 1];
		}
		tail[c++] = aux;
		aux = NULL;
	}
    
	printf("Las ultimas %d lineas son:\n", n);
	for(int i = 0; i < n && tail[i]; i++)
		printf("%s", tail[i]);
	return 0;
}
