#include <stdio.h>
#include <string.h>

void exibirCalendario(int diaDaSemana, int bissexto, int agendamentos[12][31], int escolha);

int main(void) {
  


  return 0;
}

void exibirCalendario(int diaDaSemana, int bissexto, int agendamentos[12][31], int escolha) {

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
        printf("%-2d  ",agendamentos[i][j]);
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
