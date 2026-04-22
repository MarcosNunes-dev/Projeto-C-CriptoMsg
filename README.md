# CriptoMsg - Sistema de Mensagens Cifradas em C

Aplicação de terminal desenvolvida para a UC607 (Linguagem C). O objetivo do projeto é a gestão de mensagens com uma camada de segurança baseada em chave mestra e algoritmos de cifragem.

## 📸 Demonstração
Aqui podes ver o fluxo de funcionamento do programa:

### Menu Principal
![Menu Principal](img/print1.png)

### Adicionar Mensagens
![Adicionar Mensagens](img/print2.png)

### Processo de Encriptação
![Processo de Encriptação](img/print3.png)

## 🛠️ Funcionalidades
* **Gestão de Memória:** Criação e listagem de mensagens dinâmicas.
* **Chave Mestra:** Sistema de autenticação para validar processos de criptografia.
* **Criptografia:** Algoritmos para cifrar e decifrar as mensagens guardadas.
* **Persistência:** Suporte para gravação de dados em ficheiros.

## 📁 Estrutura do Código
A lógica está dividida de forma modular para facilitar a manutenção:
* `CriptoMsg.c`: Ponto de entrada, contém o menu e a navegação.
* `encriptar.c`: Implementação das funções de cifragem e lógica de segurança.
* `Encriptar.h`: Definições de protótipos e estruturas.

## 🚀 Como Executar
Basta compilar os ficheiros `.c` utilizando o GCC:

```bash
# Compilação
gcc CriptoMsg.c encriptar.c -o criptomsg

# Execução
./criptomsg
