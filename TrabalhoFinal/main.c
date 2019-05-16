#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tipo_funcionarios
{
   char nome[100];
   char cargo;
   float salario;
   char vinculo_emprego;
   int idade;

}funcionarios[20], aux, j;

int i=0;

int Cadastrar () {

    int y = 0;
    printf("Insira aqui os dados do funcionario:\n ");
    fflush(stdin);
    printf("* Nome:");
    scanf("%[^\n]", &funcionarios[i].nome);
    fflush(stdin);

    printf("Digite \n E - Engenheiro \n S - Estagiario \n M - Mestre de Obras \n P - Pedreiro \n O - Outros Servicos \n");
    printf("* Cargo:\n");
    scanf("%c", &funcionarios[i].cargo);
    fflush(stdin);

    /*printf("CARGO: %c", funcionarios[i].cargo);*/

    if (funcionarios[i].cargo =='E'|| funcionarios[i].cargo == 'e')
        /*printf("CARGO: %c \n", funcionarios[i].cargo);*/
        funcionarios[i].salario = 4740;
        /*printf("CARGO: %f \n", funcionarios[i].salario);*/
    if (funcionarios[i].cargo == 'S'|| funcionarios[i].cargo == 's')
        funcionarios[i].salario = 1303;
    if (funcionarios[i].cargo == 'M'|| funcionarios[i].cargo == 'm')
        funcionarios[i].salario = 2500;
    if (funcionarios[i].cargo == 'P'|| funcionarios[i].cargo == 'p')
        funcionarios[i].salario = 1500;
    if (funcionarios[i].cargo == '0'|| funcionarios[i].cargo == 'o') {
        printf("Digite o salario:");
        scanf("%f", &funcionarios[i].salario);
        fflush(stdin);
    }

    printf("* Vinculo Empregaticio:\n ");
    printf("Digite \n E- Efetivo \n T - Terceirizado \n P - Prestador de Servico \n");
    printf("Obs.: Outros Servicos - Prestador de Servico. \n");
    scanf("%c", &funcionarios[i].vinculo_emprego);
    fflush(stdin);

    printf("VINCULO: %c \n", funcionarios[i].vinculo_emprego);

    printf("* Idade:");
    scanf("%d", &funcionarios[i].idade);
    fflush(stdin);

    /*printf("IDADE: %d \n", funcionarios[i].idade);*/

    printf("\n Dados Inseridos com Sucesso!\n");

   y++;
   i++;
   return y;
   system("pause");
  }

void Ordem_Alfabetica () {

int i,j,x;


for (j=20; j>=1;j--)
{
    for (i=0; i<j; i++)
    {
       x = strcmp(funcionarios[i].nome, funcionarios[i+1].nome);
       if ( x == 1)
            {
                aux = funcionarios[i];
                funcionarios[i]= funcionarios[i+1];
                funcionarios[i+1] = aux;
            }
    }
}
    for (i=0; i<19; i++)
    {
        printf("%s \n",funcionarios[i].nome);
        printf("%.2f \n",funcionarios[i].salario);
    }


}

void Consultar () {

  int i;
  int encontrado = 0;
  char funcionario[20];

  printf("Insira o nome do funcionario que deseja consultar: \n");
  fflush(stdin);
  scanf("%[^\n]",&funcionario);
  fflush(stdin);
  /*printf("Salario: %f \n", funcionarios[0].salario);
  printf("Funcionario que sera alterado: %s \n", funcionario);*/
  for (i=0;i<20;i++) {
    /*printf("Funcionario: %s \n", funcionarios[i].nome);*/
    if (strcmp(funcionarios[i].nome,funcionario)==0) {

        printf("Salario: %f \n", funcionarios[i].salario);

        if (funcionarios[i].cargo =='E'|| funcionarios[i].cargo == 'e')
        printf("Cargo: Engenheiro(a) \n");
        if (funcionarios[i].cargo == 'S'|| funcionarios[i].cargo == 's')
        printf("Cargo: Estagiario(a) \n");
        if (funcionarios[i].cargo == 'M'|| funcionarios[i].cargo == 'm')
        printf("Cargo: Mestre de Obras \n");
        if (funcionarios[i].cargo == 'P'|| funcionarios[i].cargo == 'p')
        printf("Cargo: Pedreiro(a) \n");
        if (funcionarios[i].cargo == '0'|| funcionarios[i].cargo == 'o')
        printf("Cargo: Outros Servicos\n");

        if (funcionarios[i].vinculo_emprego == 'E'|| funcionarios[i].vinculo_emprego == 'e')
        printf("Vinculo: Efetivo \n", funcionarios[i].vinculo_emprego);
        if (funcionarios[i].vinculo_emprego =='T'|| funcionarios[i].vinculo_emprego == 't')
        printf("Vinculo: Efetivo \n", funcionarios[i].vinculo_emprego);
        if (funcionarios[i].vinculo_emprego =='P'|| funcionarios[i].vinculo_emprego == 'p')
        printf("Vinculo: Prestador de Servicos \n", funcionarios[i].vinculo_emprego);

        printf("Idade: %d \n", funcionarios[i].idade);
        encontrado = 1;
    }
  }

  if(encontrado == 0)
        printf("Nome nao encontrado!\n");
}

void Alterar() {
  int i;
  char funcionario[100];
  char confirma;

  printf("Digite o nome do funcionario para alteracao: \n");
  fflush(stdin);
  scanf("%[^\n]",&funcionario);
  fflush(stdin);
  /*printf("Nome consultado: %s \n", funcionario);*/

  printf("Tem certeza que deseja alterar funcionario %s ? (s/n)\n",funcionario);
  scanf("%c",&confirma);
  fflush(stdin);

  if (confirma == 'S' || confirma == 's') {
      for (i=0;i<20;i++){
            printf ("I: %i \n", i);
            printf ("FUNCIONARIO: %s \n", funcionarios[i].nome);
            printf ("FUNC: %s \n", funcionario);
        if (strcmp(funcionarios[i].nome,funcionario)==0) {
            printf ("I: %i \n", i);
            printf ("FUNCIONARIO: %s \n", funcionarios[i].nome);
            printf("Novo Nome: \n");
            fflush(stdin);
            scanf("%[^\n]",&funcionarios[i].nome);
            fflush(stdin);

            printf("Novo Cargo: \n");
            printf("Digite \n E - Engenheiro \n S - Estagiario \n M - Mestre de Obras \n P - Pedreiro \n O - Outros Servicos \n");
            scanf("%c",&funcionarios[i].cargo);
            fflush(stdin);

            if (funcionarios[i].cargo =='E'|| funcionarios[i].cargo == 'e')
            /*printf("CARGO: %c \n", funcionarios[i].cargo);*/
            funcionarios[i].salario = 4740;
            /*printf("CARGO: %f \n", funcionarios[i].salario);*/
            if (funcionarios[i].cargo == 'S'|| funcionarios[i].cargo == 's')
                funcionarios[i].salario = 1303;
            if (funcionarios[i].cargo == 'M'|| funcionarios[i].cargo == 'm')
                funcionarios[i].salario = 2500;
            if (funcionarios[i].cargo == 'P'|| funcionarios[i].cargo == 'p')
                funcionarios[i].salario = 1500;
            if (funcionarios[i].cargo == '0'|| funcionarios[i].cargo == 'o') {
                printf("Digite o salario:");
                scanf("%f", &funcionarios[i].salario);
                fflush(stdin);
            }
            printf("Novo vinculo: \n");
            printf("Digite \n E- Efetivo \n T - Terceirizado \n P - Prestador de Servico \n");
            printf("Obs.: Outros Servicos - Prestador de Servico. \n");
            scanf("%c", &funcionarios[i].vinculo_emprego);
            fflush(stdin);

            printf("Nova Idade: \n");
            scanf("%d",&funcionarios[i].idade);
            fflush(stdin);

            printf("Novo nome: %s \n", funcionarios[i].nome);
            printf("Novo cargo: %c \n", funcionarios[i].cargo);
            printf("Novo vinculo: %c \n", funcionarios[i].vinculo_emprego);
            printf("Novo idade: %d \n", funcionarios[i].idade);

            break;
        }
      }
  }
  printf("Dados alterados com sucesso! \n");
}

void Excluir (int y){

 int i,j;
 char funcionario[20];
 char confirma;

 printf("Digite o nome do funcionario que deseja excluir:\n");
 fflush(stdin);
 scanf("%[^\n]",&funcionario);
 fflush(stdin);
 /*printf("FUNCIONARIO: %s", funcionario);*/

 printf("Tem certeza que deseja excluir funcionario %s ? (s/n)\n",funcionario);
 scanf("%c",&confirma);
 fflush(stdin);

 /*printf("confirma: %c \n", confirma);*/
 /*printf("FUNCIONARIO: %s \n", funcionario);*/
 if (confirma == 'S' || confirma == 's') {
    /*printf("FUNCIONARIO: %s \n", funcionario);*/

    for(i = 0; i <20; i++){
    /*printf("FUNCIONARIO: %s \n", funcionarios[i].nome);
    printf("FUNCIONARIO: %s \n", funcionario);
    printf("I: %i \n", i);
    printf("Y: %i \n", y);*/
        if (strcmp(funcionarios[i].nome,funcionario)==0){
                /*printf("333333333333333333333\n");
                printf("I: %i\n", i);
                printf("Y: %i\n", y);*/
            for (j = i; j < 19; j++){
                /*printf("J: %i \n", j);
                printf("333333333333333333333\n");*/
                funcionarios[j]= funcionarios[j+1];
            }
         }
    }
  }
    /*for(i=0;i<=y;i++){
        if (strcmp(funcionarios[i].nome,funcionario)==0){

        }

    for (j = i; j <= y-1; j++){
                    funcionarios[j] = funcionarios[j+1];}
        }
    }*/

    printf("Usuario excluido! \n");

}

void Salvar_Arquivo ()
{
    int i,j;

    FILE *x;

    x = fopen("arquivo.txt", "w");

    if(x == NULL)
        printf("Arquivo.txt nao pode ser aberto.\n");

    else printf("Arquivo.txt aberto com sucesso!\n");

    for(j=20;j>=1;j--)
        {
          for(i=0; i<j; i++)
         {
            if(strcmp(funcionarios[i].nome,funcionarios[i+1].nome)==1)
            {
                aux = funcionarios[i];
                funcionarios[i]= funcionarios[i+1];
                funcionarios[i+1]= aux;
            }
        }
    }
    for (i=0;i<20;i++)
    {
        fprintf(x,"Nome:%s \n", funcionarios[i].nome);
        fprintf(x,"Salario: %.2f \n", funcionarios[i].salario);

        if (funcionarios[i].cargo =='E'|| funcionarios[i].cargo == 'e')
        fprintf(x,"Cargo: Engenheiro(a) \n");
        if (funcionarios[i].cargo == 'S'|| funcionarios[i].cargo == 's')
       fprintf(x,"Cargo: Estagiario(a) \n");
        if (funcionarios[i].cargo == 'M'|| funcionarios[i].cargo == 'm')
        fprintf(x,"Cargo: Mestre de Obras \n");
        if (funcionarios[i].cargo == 'P'|| funcionarios[i].cargo == 'p')
        fprintf(x,"Cargo: Pedreiro(a) \n");
        if (funcionarios[i].cargo == '0'|| funcionarios[i].cargo == 'o')
        fprintf(x,"Cargo: Outros Servicos\n");

        if (funcionarios[i].vinculo_emprego == 'E'|| funcionarios[i].vinculo_emprego == 'e')
        fprintf(x,"Vinculo: Efetivo \n", funcionarios[i].vinculo_emprego);
        if (funcionarios[i].vinculo_emprego =='T'|| funcionarios[i].vinculo_emprego == 't')
        fprintf(x,"Vinculo: Efetivo \n", funcionarios[i].vinculo_emprego);
        if (funcionarios[i].vinculo_emprego =='P'|| funcionarios[i].vinculo_emprego == 'p')
        fprintf(x,"Vinculo: Prestador de Servicos \n", funcionarios[i].vinculo_emprego);

        fprintf(x,"Idade: %.d \n", funcionarios[i].idade);
    }

    fclose(x);

    return 0;
}



int main()
{
    int op=0;
    int y;

    do {
        printf("\n--- Escolha uma opcao ----\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Ordem Alfabetica\n");
        printf("5 - Excluir\n");
        printf("6 - Salvar Arquivo\n");
        printf("7 - Sair\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &op);
         switch(op) {
                  case 1: y = Cadastrar(); break;
                  case 2: Consultar(); break;
                  case 3: Alterar(); break;
                  case 4: Ordem_Alfabetica(); break;
                  case 5: Excluir(y); break;
                  case 6: Salvar_Arquivo;
                  case 7: break;
                  default: printf("Opcao errada");
      }
    } while (op !=6);

    return 0;
}


