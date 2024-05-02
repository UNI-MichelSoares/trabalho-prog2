#include <stdio.h>

void exibirCalendario(int diaDaSemana, int bissexto, int agendamentos[], int escolha);
void preencherComZeros(int vetor[], int tamanho);
int converterParaDiasDoAno(int mes, int dia, int bissexto);
void agendarConsultas(int agendamentos[], int dia, int duracao);

int main(void) {

  // Declaração de variáveis.
  int mesAgendamento, diaAgendamento, duracaoAgendamento;
  int diaDaSemana, bissexto, escolhaExibicao;

  // Input do dia da semana que cai 1 de janeiro e se é bissexto:
  do {
    printf("Informe o dia da semana que cai 1° de janeiro:\n[1] Domingo, [2] Segunda, etc.\n- \n");
    scanf("%d", &diaDaSemana);

    // Tratamento de erro, impede o usuário de digitar uma data inválida.
    if (diaDaSemana > 7 || diaDaSemana < 1){
      printf("\nDia inválido, escolha de 1 à 7 (Domingo à sábado).\n");
    }
  }
  while(diaDaSemana > 7 || diaDaSemana < 1);

  do {
    printf("Informe se o ano é bissexto ou não.\n[1] É bissexto.\n[0] Não é bissexto\n- \n");
    scanf("%d", &bissexto);

    // Tratamento de erro, impede o usuário de digitar uma resposta inválida.
    if (bissexto != 1 && bissexto != 0){
      printf("\nResposta inválida.\n");
    }
  }
  while (bissexto != 1 && bissexto != 0);

  // Criando e preenchendo agendamentos com zero, tamanho baseado se é bissexto ou não.
  int qtdAgendamentos[365 + bissexto];
  preencherComZeros(qtdAgendamentos, 365 + bissexto);

  // Início do programa.

  do {
    // Menu principal:
    printf("\n|----------| MENU PRINCIPAL |----------|\n");
    printf("| 1 - Exibir o calendário\n| 2 - Exibir agendamentos\n| 3 - Agendar consultas\n| 4 - Encerrar programa\n| Opção:");
    scanf("%d", &escolhaExibicao);

    // Exibição baseada nas escolhas:
    switch (escolhaExibicao) {
      case 1:
        exibirCalendario(diaDaSemana, bissexto, qtdAgendamentos, 1);
        break;
      case 2:
        exibirCalendario(diaDaSemana, bissexto, qtdAgendamentos, 0);
        break;
      case 3:
        // Coleta de dados.
        printf("\nInforme o mês a ser agendado:\n[1] Janeiro, [2] Fevereiro, etc.\n- \n ");
        scanf("%d", &mesAgendamento);
        printf("\nInforme o dia do mês a ser agendado: ");
        scanf("%d", &diaAgendamento);
        printf("\nInforme quantos dias de tratamento: ");
        scanf("%d", &duracaoAgendamento);

        // Conversão de mes/dia para dias do ano e agendamento da consulta.
        diaAgendamento = converterParaDiasDoAno(mesAgendamento, diaAgendamento, bissexto);
        agendarConsultas(qtdAgendamentos, diaAgendamento, duracaoAgendamento);

        break;
      case 4:
        printf("\nEncerrando programa...");
        break;
      default:
        printf("\nOpção inválida.\n");
    }
  }
  while(escolhaExibicao != 4);

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
  char meses[12][10] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

  // Último dia da semana de cada mês, começa com o valor do 1° dia da semana do ano.
  int ultimo = diaDaSemana - 1;

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
        printf("%-2d  ", agendamentos[converterParaDiasDoAno(i + 1, j, bissexto) - 1]);
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
Função que recebe um vetor e seu tamanho e o preenche com zeros.

vetor: O vetor que será preenchido.
tamanho: O tamanho do vetor.

Não retorna nada em especifíco, apenas preenche o vetor.
*/
void preencherComZeros(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = 0;
  }
}

/*
Função que converte um par de variáveis representando o mês e o dia em dias do ano.

mes: O mês desejado (1-12).
dia: O dia do mês (1-31).
bissexto: Indica se o ano é bissexto (1 para sim, 0 para não).

Retorna o número de dias do ano correspondente ao mês e dia fornecidos.
*/
int converterParaDiasDoAno(int mes, int dia, int bissexto) {
  int diasEmCadaMes[12] = {31, 28 + bissexto, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int diasDoAno = 0;

  // Adiciona os dias de cada mês até o mês anterior ao fornecido
  for (int i = 0; i < mes - 1; i++) {
      diasDoAno += diasEmCadaMes[i];
  }

  // Adiciona os dias do mês fornecido
  return diasDoAno += dia;
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
