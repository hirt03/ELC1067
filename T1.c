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

void le_notas(int* medias, int n)
{
    FILE *f(fopen("notas.txt", "r"));
    int i = 0, mat;
    float nota1, nota2, media;
    while(i != n)
    {
        scanf("%d %f %f", &mat, &nota1, &nota2);
        medias[i] = (nota1+nota2)/2;
        i++;
    }
    fclose(f);

}



int main(int argc, char **argv)
{
    int matriculas[50], medias[50];
    char nomes[50][50], nome[50];
    int n, i, mat = 0, aux = 0;
    float media;
    le_alunos(matriculas, nomes, &n);
    le_notas(medias, n); //ler o arquivo de notas e salvar a matricula relacionada com a media (abrir e fechar arquivo na funcao
    printf("Escreva o nome a ser buscado:\n");
    scanf("%s", &nome); //alterar para argv, para passar como argumento
    for(i=0;i<n;i++)
    {
        mat = verifica_mat(i, matriculas, nome);
        if(mat != aux)
        {
            media = busca_media(i, medias);
            imprime(media, i);
            aux = mat;
        }

    }


}


// fopen/fclose
// fgetc = le caracter por caracter
// feof verifica final do arquivo e retorna 0 se for if(feof(f) == 0) é final do arquivo
// fscanf
// strcmp compara string(letras, lexicamente) retorna 1 se o primeiro argumento for maior que o outro
// strstr(s1, s2) se s2 esta contido em s1 retorna diferente de NULL
