#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CAD {
	char nome[20];
	float nota_1, nota_2, nota_3;
	int matricula;

	struct CAD *proxCAD;
} CAD;


void cadastrar_aluno ( CAD ** p, char name[20], int num_matri, float n1, float n2, float n3) {
    
	CAD *p1, *p2;

	p1 = *p;

	if (p1 == NULL) {

		p1 = (CAD *) malloc (sizeof (CAD));
		strcpy(p1->nome, name);
		p1-> nota_1 = n1;
		p1-> nota_2 = n2;
		p1-> nota_3 = n3;
		p1-> matricula = num_matri;

		*p = p1; 
	} else {

	while (p1 != NULL)

		p1 = p1->proxCAD;
		p2 = (CAD *) malloc (sizeof (CAD));

		if (p2 != NULL) {

		strcpy(p2-> nome, name);
		p2-> nota_1 = n1;
		p2-> nota_2 = n2;
		p2-> nota_3 = n3;
		p2-> matricula = num_matri;
		p2->proxCAD = NULL;
		p1->proxCAD = p2;

		}
	}
}

//Mostrar Lista.
 void mostrar_lista (CAD *p) {
     
  	float media;

    media = (p->nota_1+p->nota_2+p->nota_3) / 3;

  	while (p != NULL) {
 
  		printf (" ------ CADASTRO é: ------\n");
  		printf ("Aluno: %s \n", p->nome);
  		printf ("Matricula: %d \n", p->matricula);
  		printf ("Notas: %f \n %f \n %f \n", p->nota_1, p->nota_2, p->nota_3);
  		printf ("Media do aluno: %f \n", media);

  		p = p->proxCAD;
  		
	  }
  }

 int main () { 
  
  CAD *px;
  char name[20];
  int num_matri;
  float n1, n2, n3;
  int num_menu;

 
  do {
     cadastrar_aluno(&px,name, num_matri, n1, n2, n3);   
     printf ("Insira o nome do aluno.\n");
     fgets(name, 20, stdin);
     printf ("Matricula: \n");
     scanf ("%d", &num_matri);
     printf ("Notas: \n");
     scanf ("%f", & n1);
     scanf ("%f", & n2);
     scanf ("%f", & n3);
    
	printf ("Deseja cadastrar outro aluno? \n");
    printf ("1 - sim \n");
    printf("2 - sair \n");
    scanf ("%d", &num_menu);
  } while (num_menu == 1);

   system("cls || clear");

   mostrar_lista (px);
 }
