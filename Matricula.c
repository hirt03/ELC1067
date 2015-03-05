#include <stdio.h>

main()
{
    int matricula;
    char nome[50];
    FILE *f;
    printf("Digite o numero da matricula\n");
    scanf("%d", &matricula);
    printf("Digite o nome\n");
    scanf("%s", nome);
    f = fopen("saida.txt", "w");
    fprintf(f,"%d  %s\n", matricula, nome);
    fclose(f);
}
