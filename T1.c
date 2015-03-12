#include <stdio.h>
#include <string.h>

/*int main(int argc, char **argv)        EXEMPLO VERIFICAÇÃO DE ARGUMENTO
{
    char *nome;
    if(argc>1)
    {
        nome = argv[1];
    }
    printf("%s\n", nome);
    return 0;
}*/

/* mximo 50 nomes por arquivo */

void le_alunos(int* matriculas, char** nomes, int* n)
{
    FILE *f = fopen("alunos.txt", "r");
    int mat, i = 0, linha = 0;
    char c, nome[50];
    while(feof(f) != 0)
    {
        fscanf(f, "%d", &mat);
        c = fgetc(f);
        while(c == ' ')
        {
            c = fgetc(f);
        }
        while(c != '\n')
        {
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\o';
        matriculas[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
    }
    n = linha;
    fclose(f);
}


int main(int argc, char **argv)
{
    int matriculas[50];
    char nomes[50][50];
    int n;
    le_alunos(matriculas, nomes, &n);
}


// fopen/fclose
// fgetc = le caracter por caracter
// feof verifica final do arquivo e retorna 0 se for if(feof(f) == 0) é final do arquivo
// fscanf
// strcmp compara string(letras, lexicamente) retorna 1 se o primeiro argumento for maior que o outro
