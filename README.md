# Agenda de Compromissos.
## Trabalho de Programação de Computadores II.

Esse trabalho tem como objetivo a criação de uma agenda de compromissos para um fisioterapeuta, em C. Essa agenda deve exibir um calendário, permitir agendamentos e exibir o calendário com os agendamentos realizados.

## Funcionamento do programa

1. **Main Function (Função Principal):**
   - Começa solicitando informações ao usuário: o dia da semana em que cai o primeiro dia do ano (domingo a sábado) e se o ano é bissexto ou não.
   - Em seguida, cria um array de agendamentos e o preenche com zeros com base na duração do ano, levando em conta se o ano é bissexto ou não.
   - Oferece um menu principal com quatro opções: exibir o calendário, exibir agendamentos, agendar consultas e encerrar o programa.
   - A escolha do usuário é processada por meio de um loop `do-while` até que o usuário opte por encerrar o programa.

2. **Funções:**
   - **exibirCalendario:** Mostra o calendário para cada mês, considerando o primeiro dia do ano fornecido pelo usuário. Também pode exibir os agendamentos, se solicitado.
   - **preencherComZeros:** Preenche um vetor com zeros.
   - **converterParaDiasDoAno:** Converte um par de variáveis representando o mês e o dia em dias do ano.
   - **agendarConsultas:** Verifica a disponibilidade para agendar uma consulta e, se possível, agenda-a.

O programa é interativo e permite ao usuário visualizar o calendário mensal, agendar consultas e verificar os agendamentos já feitos. Ele garante que os agendamentos não ultrapassem o limite do ano e que não haja conflitos de agendamento para um mesmo dia.

## Dificuldades ao longo do desenvolvimento

  - **Formatação:** O modo como foi desenvolvido o programa, usando vetor de agendamentos ao invés de matriz e a exibição do calendário através de formatação com prints, ao invés de também utilizar uma matriz.
  - **Agendamentos:** Confusão ao printar o vetor de agendamentos em múltiplas áreas do código, inclusive com momentos onde a exibição não funcionava devido a forma anterior de printar dias na função `exibirCalendario` (que limitava o print de dias ao índice 31).
  - **Integração:** Dificuldade ao integrar as diferentes formas de exibição, formatos de data e tipo de valores.

## ✒️ Autores

* **Michel Soares** - [GitHub](https://github.com/UNI-MichelSoares)
* **Isabella Rocha** - [GitHub](https://github.com/Iswb04)
* **Breno Guimarães** - [GitHub](https://github.com/bgpereiraS)
