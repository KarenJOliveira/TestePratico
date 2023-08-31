Teste Prático 
Karen Jardim Oliveira
karen.jardim13@gmail.com

Premissas: 
- Para calcular o valor exato, é necessário encontrar qual dia da semana da data especificada.
- Para encontrar o valor total dos banhos em cada PetShop, primeiro deve-se analisar o dia da semana encontrado. Tendo isto, multiplica-se o preço relativo ao dia da semana e ao porte do cão à quantidade de cães desse porte. Soma-se o valor total relativo aos cães pequenos com o valor total relativo aos cães grandes.
- Compara-se os preços totais de cada PetShop. O menor preço é o ideal. Caso haja valores iguais, o PetShop de menor distância do canil é o escolhido. 


Decisões de Projeto:
- Ler o input do usuário, que é instruído por uma mensagem que indica a maneira que as informações devem ser inseridas.
- Guardar os dados em variáveis. Para a data, uma variável do tipo string que guarda o formato completo. Para as quantidades de cães, variáveis do tipo int.
- Implementar uma função responsável por identificar o dia da semana para a data recebida. Para isso, foi utilizado o algoritmo “Congruência de Zeller”. 
- Criar uma classe para guardar os atributos de cada PetShop, como o nome, a distância, e o preço de cada banho. Também foram criados métodos para atribuir e retornar os respectivos valores, e para calcular o preço total dados a quantia de cães de cada porte e o dia da semana.
- No arquivo principal, foram utilizadas variáveis do tipo float para armazenar o preço total obtido para cada PetShop. 
- Foi criada uma função que compara os preços totais obtidos por parâmetro, juntamente com ponteiros para cada objeto PetShop, e retorna uma mensagem para o usuário informando o nome e o valor total do estabelecimento de menor preço.
- Uma função para remover zeros à esquerda na data foi implementada para passar a data corretamente para o algoritmo do dia da semana.

Instruções para executar o projeto
- Executar o arquivo main.cpp na IDE. No console, o programa imprimirá uma mensagem indicando a sequência que as informações devem ser digitadas, inclusive o formato da data. O programa responderá com uma mensagem indicando o melhor petshop para a situação e o valor total calculado. 
