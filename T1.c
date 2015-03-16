#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int le_alunos(int matriculas[], char nomes[][50])
{
    FILE *f = fopen("alunos.txt", "r");
    int mat, i, linha = 0, aux;
    char c = ' ', nome[50];
    while(c != EOF)
    {
        fscanf(f, "%d", &mat);
        c = fgetc(f);
        i = 0;
        while(c == ' ')
        {
            c = fgetc(f);
        }
        while(c != '\n' && c != EOF)
        {
            nome[i] = c;
            c = fgetc(f);
             i++;
        }
        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    fclose(f);
    return (linha-1);
}

void le_notas(float medias[], int n)
{
    FILE *f = (fopen("notas.txt", "r"));
    int i = 0, mat;
    float nota1, nota2, media;
    while(i<n)
    {
        fscanf(f, "%d %f %f\n", &mat, &nota1, &nota2);
        medias[i] = (nota1+nota2)/2;
        i++;
    }
    fclose(f);

}

int busca_mat(int n,float medias[50],char nomes[][50],char nome[50])
{
    int i;
    for(i=0;i<n;i++)
    {
        if((strstr(nomes[i], nome)) != NULL)
        {
            printf("%s %.2f\n", nomes[i], medias[i]);
        }
    }
}


main(int argc, char *argv[])
{
    int matriculas[50];
    char nomes[50][50], nome[50];
    int n, mat = 0, aux = 0;
    float media, medias[50];
    n = le_alunos(matriculas, nomes);
    le_notas(medias, n);
    busca_mat(n, medias, nomes, argv[1]);
    }
