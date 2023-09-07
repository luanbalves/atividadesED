#include <stdio.h>
#include <string.h>

struct Aluno
{
  char nome[99];
  char telefone[99];
  char curso[99];
  float nota1;
  float nota2;
  float media;
  char aprovacao[99];
};

int
main ()
{
  FILE *file;
  char linha[100];
  struct Aluno alunos[99];

  file = fopen ("DadosEntrada.txt", "r");

  if (file == NULL)
    {
      perror ("Erro ao abrir o arquivo");
      return 1;
    }

  int i = 0;

  while (fgets (linha, sizeof (linha), file))
    {
      sscanf (linha, "%99[^,],%99[^,],%99[^,],%f,%f",
	      alunos[i].nome, alunos[i].telefone, alunos[i].curso,
	      &alunos[i].nota1, &alunos[i].nota2);
      i++;
    }

  fclose (file);

  FILE *finalFile;
  finalFile = fopen ("SituacaoFinal.txt", "a");

  if (finalFile == NULL)
    {
      perror ("Erro ao abrir o arquivo");
      return 1;
    }

  for (int j = 1; j < i; j++)
    {
      alunos[j].media = (alunos[j].nota1 + alunos[j].nota2) / 2;
      if (alunos[j].media >= 7)
	{
	  strcpy (alunos[j].aprovacao, "APROVADO");
	}
      else
	{
	  strcpy (alunos[j].aprovacao, "REPROVADO");
	}
      /*              BLOCO DE TESTES
         printf ("Nome: %s\n", alunos[j].nome);
         printf ("Telefone: %s\n", alunos[j].telefone);
         printf ("Curso: %s\n", alunos[j].curso);
         printf ("Nota 1: %.1f\n", alunos[j].nota1);
         printf ("Nota 2: %.1f\n", alunos[j].nota2);
         printf ("Media: %.2f\n", alunos[j].media);
         printf ("Aprovacao: %s\n", alunos[j].aprovacao);
         printf ("\n");
       */
      fprintf (finalFile, "%s, %.2f, %s\n", alunos[j].nome, alunos[j].media,
	       alunos[j].aprovacao);

    }

  fclose (finalFile);

  return 0;
}
