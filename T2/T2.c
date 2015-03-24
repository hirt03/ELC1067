#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcula_linhas()
{
    char cont;
    int linhas = 0;
    FILE *f = fopen("alunos.txt", "r");
    while(cont != EOF)
    {
        if(cont != EOF)
        {
            cont = fgetc(f);
            if(cont == '\n')
            {
                linhas++;
            }
        }
    }
    fclose(f);
    return linhas;

}

void salva_nomes(int linhas, char** nomes, int mat_n[])
{
    int cont = 0, i, mat;
    char letra, nome[50];
    FILE *alunos = fopen("alunos.txt", "r");
    while(cont < linhas)
    {
        fscanf(alunos, "%d", &mat);
        letra = fgetc(alunos);
        i = 0;
        while(letra == ' ')
        {
            letra = fgetc(alunos);
        }
        while(letra != '\n')
        {
            nome[i] = letra;
            letra = fgetc(alunos);
            i++;
        }
        nome[i] = '\0';
        mat_n[cont] = mat;
        strcpy(nomes[cont], nome);
        cont++;
    }
    fclose(alunos);
}

void salva_media(int linhas, float medias[], int mat_m[])
{
    int cont = 0, mat;
    float nota1, nota2, media;
    FILE *notas = fopen("notas.txt", "r");
    while(cont < linhas)
    {
        fscanf(notas, "%d %f %f", &mat, &nota1, &nota2);
        media = (nota1+nota2)/2;
        medias[cont] = media;
        mat_m[cont] = mat;
        cont++;
    }
    fclose(notas);
}

void busca_imprime(int linhas, char **nomes, float medias[], int mat_n[], int mat_m[], char nome[])
{
    int i,j;
    for(i=0; i<linhas; i++)
    {
        if(strstr(nomes[i], nome) != NULL)
        {
            for(j=0; j<linhas; j++)
            {
                if(mat_n[i] == mat_m[j])
                {
                    printf("%s %.2f\n", nomes[i], medias[j]);
                }
            }
        }

    }
}

char alocar_nomes(int linhas)
{
    char **nomes;
    int i;
    nomes = (char**)malloc(linhas * sizeof(char*));
    for(i=0;i<linhas;i++)
    {
        nomes[i] = (char*)malloc(50 * sizeof(char));
    }
    if(nomes == NULL)
    {
        printf("ta errado isso");
    }
    return nomes;
}

main()
{
    int linhas, *mat_n, *mat_m, i;
    char **nomes;
    linhas = calcula_linhas();
    mat_n = (int*)malloc(linhas*sizeof(int));
    mat_m = (int*)malloc(linhas*sizeof(int));
    float *medias = (float*)malloc(linhas*sizeof(float));
    nomes = (char**)malloc(linhas * sizeof(char*));
    for(i=0;i<linhas;i++)
    {
        nomes[i] = (char*)malloc(50 * sizeof(char));
    }
    salva_nomes(linhas, nomes, mat_n);
    salva_media(linhas, medias, mat_m);
    char nome[50];
    scanf("%s", &nome);
    busca_imprime(linhas, nomes, medias, mat_n, mat_m, nome);
    for(i=0;i<linhas;i++)
    {
        free(nomes[i]);
    }
    free(nomes);
    free(mat_n);
    free(mat_m);
    free(medias);
}
