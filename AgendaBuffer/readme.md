1.Tudo em um único bloco de memória (pBuffer), ou seja, um malloc onde todos os ponteiros fazem referencia a ele:
Esse bloco será usado como:
  Área de controle (armazenar índices, ponteiros, contadores).
  Área para os dados (lista de pessoas: nome, idade, email).

2.Gerenciamento manual de memória: Como não pode usar struct, você precisa calcular manualmente para acessar dados.
3. Uso de Lista encadeada Para armazenar várias pessoas, onde cada nó contém: Nome , Idade   Email ,  Ponteiro para próximo.
4. Precisa de um Menu, porém como não pode struct ou variavel. a solução seria usar o pBuffer para armazenar temporariamente o input do usuário.

