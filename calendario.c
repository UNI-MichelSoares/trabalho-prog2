#include <stdio.h>

void exibirCalendario(int diaDaSemana, int bissexto, int agendamentos[], int escolha);
void agendarConsultas(int agendamentos[], int dia, int duracao);

int main(void) {
  


  return 0;
}

/*
Função para exibir um calendário mensal.
 
diaDaSemana: O dia da semana para o primeiro dia do ano (1 para domingo, 2 para segunda-feira, etc.).
bissexto: Indica se o ano é bissexto (1 para sim, 0 para não).
agendamentos: Um array de agendamentos para exibir no calendário, se escolha for 0.
escolha: Um indicador para exibir o calendário normal (1) ou os agendamentos (0).
 
Nenhum retorno específico, apenas exibe o calendário ou agendamentos na saída padrão.
*/

void exibirCalendario(int diaDaSemana, int bissexto, int agendamentos[], int escolha) {

  int diasEmCadaMes[12] = {31, 28 + bissexto, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char meses[12][20] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

  // Último dia da semana de cada mês, começa com o valor do 1° dia da semana do ano.
  int ultimo = diaDaSemana;

  for (int i = 0; i < 12; i++) {
    // Printa o nome do mês.
    printf("\n\n%s\n", meses[i]);
    printf("Dom Seg Ter Qua Qui Sex Sab\n");

    // Preenche o calendário até o primeiro dia do mês.
    for (int k = 0; k < ultimo; k++) {
      printf("-   ");
    }

    // Printa os dias de cada mês e atualiza o último dia da semana do mês anterior.
    // Caso o usuário queira, pode printar o calendário de agendamentos.
    for (int j = 1; j <= diasEmCadaMes[i]; j++) {
      if (escolha == 1){
        printf("%-2d  ", j);
      }
      else{
        printf("%-2d  ",agendamentos[j]);
      }

      // Atualiza o último dia da semana do mês anterior.
      ultimo = (ultimo + 1) % 7;

      // Quebra a linha a cada sábado (sétimo dia) ou no último dia do mês.
      if (ultimo == 0 || j == diasEmCadaMes[i]) {
        printf("\n");
      }
    }
  }
}

/*
Função que verifica a possibilidade de marcar uma consulta e, se possível, a agenda.

agendamentos: O vetor que armazena as consultas marcadas.
dia: O dia do ano que será agendada a consulta.
duracao: Por quantos dias se deve agendar a consulta.

Nenhum retorno especifíco, apenas agenda ou não a consulta.
*/

void agendarConsultas(int agendamentos[], int dia, int duracao) {
  // Verifica se o dia escolhido está dentro do limite do array.
  if (dia <= 0 || dia > 365 || dia + duracao - 1 > 365) {
    printf("Data inválida para agendar consultas.\n");
    return;
  }

  // Verifica a disponibilidade para todos os dias da duração da consulta.
  for (int i = dia - 1; i < dia - 1 + duracao; i++) {
    if (agendamentos[i] >= 5) {
      printf("Dia %d indisponível para agendar consultas.\n", i + 1);
      return;
    }
  }

  // Aumenta o número de agendamentos para todos os dias da duração da consulta.
  for (int i = dia - 1; i < dia - 1 + duracao; i++) {
    agendamentos[i]++;
  }

  printf("Consulta agendada com sucesso!\n");
}
