# 🌸✨ AGENDA BUFFER ✨🌸

## O que esta agenda simula?

Este projeto simula a **criação de uma agenda com lista encadeada**, utilizando apenas um bloco de memória(`pBuffer`).
Nada de `structs`, variáveis ou parâmetros comuns. 
O controle da memória é **100% manual**, simulando o que o sistema operacional faz nos bastidores.

---

## Como funciona?

### 1️⃣ Tudo em um único bloco de memória (`pBuffer`)
Esse bloco é um `malloc` central onde todos os ponteiros fazem referência a ele:

🌸 Área de controle:  
- Armazena índices, ponteiros e contadores  
- Também guarda temporariamente dados de entrada do usuário  

🌸 Área de dados:  
- Contém a lista de pessoas (nome, idade, email)

### 2️⃣ Gerenciamento manual de memória 
Como o uso de `struct` é proibido, **todos os acessos à memória são feitos por meio de ponteiros e offsets**.  
Você precisa calcular manualmente onde começa cada campo da estrutura de dados.

### 3️⃣ Uso de Lista Encadeada  
A lista de pessoas é armazenada como uma **lista encadeada** onde cada nó contém:

- Nome  
- Idade  
- Email  
- Ponteiro para o próximo nó

### 4️⃣ Menu interativo sem variáveis!  
Mesmo o menu e as opções digitadas pelo usuário são armazenadas dentro do `pBuffer`.  
Não há variáveis nem structs, apenas ponteiros e muito controle de memória!

### Feito com paciência, empenho e muitos ponteiros! 🌷🎀


