# festinha-junina-ueg
Esse é um sistema que simula a compra de ingressos de uma festa junina.

## Contexto

Uma festa junina será realizada no dia 28 de Maio.
Esse sistema tem por objetivo atender as demandas de venda de ingressos, alimento, controle de estoque, etc.

## Regras de negócio

### Venda de ingressos

#### Venda antes do dia 28

Os ingressos podem ser vendidos antes do dia 28 somente para alunos. Cada aluno pode comprar no máximo 3 ingressos(um para uso próprio e 2 para convidados) Alunos podem fazer uso de um sistema de crédito, que funciona como forma de pagamento dentro da festa. O aluno pode "atribuir um saldo" ao seu crédito
exclusivamente no momento da compra do ingresso e usar esse saldo para pagar por pro:?dutos durante a festa. O aluno não é obrigado a gastar todos os seus créditos, e ele pode até mesmo gastar mais do que seus créditos permitem, ficando em débito e sendo obrigado a pagar esse débito ao sair da festa.

Ao sair da festa, o aluno deve pagar o seu débito(caso necessário), ou receber de volta o valor que não foi gasto(caso ele não tenha gastado todos os seus créditos)

#### Venda no dia 28

No dia da festa será necessário implementar uma fila de espera para a venda de ingressos.

A fila tem um sistema de prioridade que separa os indivíduos em três grupos: idosos, xxx e xxx.

No dia da festa os alunos ainda podem usar o sistema de créditos e ainda podem comprar ingressos extras para convidados.

##### Observação: 

É importante verificar se a pessoa já não possui um ingresso. Se um aluno já comprou um ingresso pro indivíduo X, o indivíduo X não pode comprar um novo ingresso.


