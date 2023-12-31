# Writing-aid-system

## O problema

<p style = "text-align = justify">
A publicação dos resultados de pesquisa é uma etapa crucial do trabalho científico. Geralmente, esses resultados são compartilhados  a forma de artigos em congressos e periódicos, após passarem por uma revisão rigorosa quanto à forma e conteúdo. Infelizmente, é comum
encontrar artigos na academia que apresentam dificuldades de leitura, além de conter erros de ortografia e gramática.
</p>

<p style = "text-align = justify">
Para lidar com a questão acima apresentada, existem diversas ferramentas de auxílio disponíveis. Por exemplo, no Unix, o utilitário "ispell" pode ser utilizado para verificar a ortografia de textos em inglês. Já para outras línguas e ambientes, há outras opções de ferramentas específicas. Além disso, existem ferramentas comerciais baseadas em técnicas de inteligência artificial, que
buscam detectar erros gramaticais, analisar o estilo literário e fornecer estatísticas sobre parágrafos. O grammarly e o chatgpt são 
 dois exemplos disso.
</p>

<p style = "text-align = justify">
O objetivo deste trabalho é especificar, projetar e implementar um sistema que ajude no processo de redação. Para realizar essa tarefa, é essencial que se faça um projeto cuidadoso das estruturas de dados e dos respectivos algoritmos, visando a utilização eficiente do sistema na prática.
</p>

## Principais considerações

* Este programa deverá ler um arquivo contento um texto sem nenhuma formatação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".", "?", "!"");

* Cada parágrafo é separado por pelo menos uma linha em branco;

* Desconsirou-se, na análise a ser feita pelo seu programa, as "stop words", como artigos (a, o, as, os) e conjunções (e, ou) que não possuem conteúdo semântico. A lista de "stop words" deve ser fornecida através de um arquivo (stopwords.txt) na pasta dataset;

* A saída do programa faz referência ao arquivo de entrada. A primeira linha do arquivo de entrada como "1", a segunda como "2" e assim por diante;

* Uma palavra é uma sequência de letras delimitada por espaço em branco, "coluna da esquerda", "coluna da direita" e símbolos de pontuação;

* O programa foi construído para ser legível, utilizando-se de mais de uma linha para imprimir as informações de uma palavra, caso necessário;

* Os arquivos de entrada são "input.data", "stopwords.txt" e "expressoes.txt";

* A saída é o arquivo denominado "output.data".

## Desenvolvimento do problema

<p style = "text-align = justify">
Para construção de tal sistema foi necessário trazer alguns questionamentos e resolve-los um por um, até chegar a versão final, aqui estão tais questionamentos: 
</p>

1 - Para cada parágrafo do texto:
* Como identificar o número da linha no arquivo fonte onde o parágrafo inicializa e termina?.
* O que fazer para identificar o número de sentenças existentes no parágrafo?.
* O que fazer para identificar o número de palavras de cada sentença incluindo e descartando as "stop words"?.

2 - Para cada palavra que não é stop word:

* Como identificar cada palavra listada em ordem alfabética com a frequência de sua ocorrência no
texto, indicando as linhas do arquivo onde essas surgem?.
* O que fazer caso uma palavra apareça mais de uma vez em um mesmo parágrafo, indicar a
sua ocorrência e a distância entre elas incluindo as stop words?.

3 - Como demonstrar a ocorrência de certas expressões sendo que para cada expressão deve ser indicado a
linha no arquivo fonte onde aparece?

<p style = "text-align = justify">
A principio é necessário extrair os dados do arquivo de entrada e inseri-los na memória volátil do computador, para que se torne possível manipular tais dados com o propósito de conseguir as informações requiridas para auxiliar na correção de um texto, para tal foi utilizado o modo de leitura binário assim lendo caracter por caracter do arquivo de entrada, com isso foi possível averiguar onde se esta no texto, se esta entre duas palavras ou no final da frase, o que é essencial para a análise do texto. 
</p>

<p style = "text-align = justify">
A codificação do texto e a presença de caracteres especiais podem complicar a leitura do arquivo em ASCII. Se o texto estiver em uma codificação específica, é importante garantir que a leitura esteja tratando corretamente esses caracteres. Portanto, adotou-se, para realizar a leitura dos carateres especiais, utilizou-se a codificação UTF-8.
</p>

<p style = "text-align = justify">
A leitura do arquivo pode ser sensível a maiúsculas e minúsculas, fazendo com que diferenças na capitalização resultem em falhas na correspondência. Por exemplo, uma busca por "casa" não encontraria a substring "Casa" em um texto sensível a maiúsculas e minúsculas. Portanto, foi utilizada a função tolower() para todos os caracteres, de forma a considerar todos estes como letras minúsculas, evitando assim diferenciação entre letras maiúsculas e minúsculas.
</p>

<p style = "text-align = justify">
Usando essa forma de extração de dados é possível determinar o final de cada linha dentro do arquivo, já que cada linha é terminada com um "\n" basta contar as linhas a partir de quando o ponteiro usado para percorrer cada caracter do arquivo de entrada estiver lendo o "\n".
</p>

<p style = "text-align = justify">
Alem disso todas as sentenças do arquivo de entrada terão a terminação com "." ou "!" ou "?", com isso sendo que esta sendo lido caracter por caracter, no momento que se chega com o ponteiro ao ponto onde se tem um desses caracteres foi sendo contabilizado uma sentença a mais, e assim sucessivamente.
</p>

<p style = "text-align = justify">
Além dos espaços, sinais de pontuação e new lines, outros caracteres não foram considerados como sendo parte das palavras. São eles:
</p>

* `:`
* `;`
* `(`
* `)`
* `"`
* `/`

<p style = "text-align = justify">
No que se refere as stop words, todas as palavras que foram sendo identificadas do arquivo de entrada, ao mesmo tempo que se analisou demais ocorrencias como o fim de uma palavra qualquer, de uma sentença ou de um paragrafo, era averiguado se tal palavra se enquandrava no grupo das palavras que estavão no arquivo de stop words contido dentro do dataset que contem todas as stop words, com isso foi se contando e identificando e armazenando tais palavras.
</p>

<p style = "text-align = justify">
No texto de entrada toda palavra é separada por espaços, e todas as sentenças terminam com "." ou "!" ou "?". Para que fosse possível identificar o número de palavras por sentença foi utilizado desvios condicionais, para identificar onde se terminava ou iniciava uma palavra sendo eles um espaço vazio ou "." ou "\n" ou "!" ou "?", a cada vez que o ponteiro que percorria o arquivo de entrada.
</p>

<p style = "text-align = justify">
para tal foi utilizado um mapa ordenado que funciona a com a lógica de uma função hash que já ordena as palavras em ordem alfabética, o mapa tem uma chave um valor associado a uma chave, sendo que a chave é a própria string extraida no arquivo de entrada, e o valor é uma struct a respeito daquela palavra, como paragrafo, linha em qual sentença ele apareceu, sendo o valor do map um set o qual é uma função dos arquivos internos do C++
</p>

<p style = "text-align = justify">
dentro das informações contidas no map ou seja o valor associado a cada chave foi inserido em qual sentença a palavra estava e quantas vezes essa mesma palavra apareceu em uma mesma setença, alem da distancia entre elas, alem da posição dentro de uma sentença, e ainda se houver apenas uma ocorrência .
</p>

<p style = "text-align = justify">
Durante a procura por expressões, o algoritmo começa uma iteração cada vez que o início de uma nova palavra é encontra. Então, o programa começa a comparar, caractere a caractere, todas as expressões com aquele texto. O algoritmo possui um "if" condicional que, caso um caractere seja diferente do encontrado no texto, ele sai da iteração. Com isso, é possível verificar se naquela parte do texto existe alguma expressão, verificando se o número de iterações realizadas é igual ao tamanho da expressão. Caso seja, significa que nenhum caractere daquela parte do texto é diferente da expressão verificada.
</p>

<p style = "text-align = justify">
Para todos os casos houve o uso de uma estrutura auxiliar denominada de set, sendo um set para guardar os dados do stop word, outro para as expresssões. E para o texto de entrada foi utilizado um map para o armazenamento e processamento de dados.
</p>

<p style = "text-align = justify">
Existe um caso especial não tratado na procura de expressões. Em algumas ocasiões, as expressões podem estar sobrepostas umas às outras. Por exemplo, se existirem duas expressões denominadas "para" e "para tanto" e, em uma parte do texto contenha uma expressão "para tanto", o programa irá identificar as duas expressões nesta mesma ocorrência.
</p>

# Análise de tempo de Execução e exemplo de entrada e saída

<p style = "text-align = justify">
A velocidade de execução é um fator importante em muitos contextos, principalmente na área da computação e desenvolvimento de software. Um programa ou algoritmo que é executado mais rapidamente permite que as tarefas sejam concluídas em menos tempo. A eficiência de execução é particularmente crucial em aplicações que envolvem grandes quantidades de dados, processamento em tempo real ou recursos limitados. Com isso, é possível afirmar que uma resposta rápida é essencial para oferecer uma boa experiência ao usuário. Se o tempo de resposta for lento, pode resultar em atrasos perceptíveis, latência e até mesmo em uma experiência frustrante para os usuários.
</p>

<p style = "text-align = justify">
A fim de verificar se o tempo de execução está dentro do desejável, foram feitos 10 testes em duas máquinas distintas o primeiro print mostra o tempo de execução na máquina mais performática
</p>
<img src="./img/testenamaquinafrankinho.png" width = 80% alt="teste realizados com um i5">

<p style = "text-align = justify">
Este segundo teste foi realizado em uma máquina de um desempenho um pouco inferior. As especificações de configurações de ambas as máquinas foram destacadas aqui neste projeto. É possível observar que, para a mesma entrada, tem se sete digitos no algarismo que representa o tempo na segunda máquina e na primeira temos apenas 6 dígitos, provando o quão expressivo é a diferença de tempo entre uma máquina de um processador arquitetado e construido em 2020 e outro construído em 2014.
</p>

<p style = "text-align = justify">
Em apenas 6 anos o avanço de performace de hardware foi significativa, porém, não se faz uma verdade absoluta tais argumentos, visto que os dados aqui apresentados podem ser imprecisos, devido a fatos como os processos concorrentes que estavam a ser executadas ao mesmo tempo que se executava o algoritmo, e os sistemas operacionais serem distintos, apesar de serem ambos sistemas linux ambos são versões distintas, sendo a versão ubuntu mais instável que a versão debiam. Veja o tempo do segundo teste na segunta máquina:
</p>

<img src="./img/testemaquinarafael.png" width = 100% alt="testes com processador amd atlhon">

<p style = "text-align = justify">
input:
</p>

<img src="./img/input.png" width = 100% alt="exemplo de entrada de dados">

<p style = "text-align = justify">
Output:
</p>

<img src="./img/OUTPUT.png" width = 100% alt="exemplo de saída de dados">


## Máquina de teste

<table style="width: 100%;" border="1">
        <tr align="center" >
            <td colspan="2">
                <div>
                        <br>
                        <p class="sizeText color">Notebook 550XDA Sansung</p>
                        <br>        
                </div>
            </td>
        <tr>
        <tr align="center">
            <td>
               <div>
                    <br>
                    <p class="sizeText color">RAM</p>
                    <br>
               </div> 
            </td>
            <td >
                <br>
                    <p class="sizeText color">8Gb DDR4</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <p class="sizeText color">
                    <br>
                    <p class="sizeText color">SO</p>
                    <br>
                </p>
            </td>
            <td >
                <br>
                    <p class="sizeText color">Linux Ubuntu v22.04, 64bits</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <br>
                    <p class="sizeText color">    
                        CPU
                    </p>
                <br>
            </td>
            <td >
                <br>
                    <p class="sizeText color">Intel core i5 11° geração 2,40GHz</p>
                <br>
            </td>
        </tr>
    </table>

<table style="width: 100%;" border="1">
        <tr align="center" >
            <td colspan="2">
                <div>
                        <br>
                        <p class="sizeText color">Computador Dedicado</p>
                        <br>        
                </div>
            </td>
        <tr>
        <tr align="center">
            <td>
               <div>
                    <br>
                    <p class="sizeText color">RAM</p>
                    <br>
               </div> 
            </td>
            <td >
                <br>
                    <p class="sizeText color">8Gb DDR3</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <p class="sizeText color">
                    <br>
                    <p class="sizeText color">SO</p>
                    <br>
                </p>
            </td>
            <td >
                <br>
                    <p class="sizeText color">Linux Debian v11(bullseye), 64bits</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <br>
                    <p class="sizeText color">    
                        CPU
                    </p>
                <br>
            </td>
            <td >
                <br>
                    <p class="sizeText color">AMD Athlon 5150 APU with Radeon R3 1,60GHz</p>
                <br>
            </td>
        </tr>
    </table>



## Conclusão

<p style = "text-align = justify">
Em conclusão, o desenvolvimento e implementação de um programa auxiliar de redação provaram ser uma iniciativa valiosa para facilitar e aprimorar o processo de escrita. Pode-se dizer que o código cumpriu com todos os objetivos propostos, tendo resultados satisfatórios alcançados como ler, processar e análisar, diversos dados associados a palavras contidas em um texto, com isso ao se observar a análise de resultados, vemos que os resultados apresentadados foram condizentes com os resultados esperados. 
</p>

<p style = "text-align = justify">
Após a conclusão do código, calculou-se uma média de 10 execuções em dois computadores diferentes. Chegou-se a 341396,8 microssegundos na primeira máquina e 1305626,3 microssegundos na segunda máquina como resultado de tempo médio. Com base nisso, é possível afirmar que o programa alcançou o objetivo de fazer a varredura do arquivo em um pequeno intervalo de tempo. Também deve-se ressaltar outro fator crucial, sendo ele a complexidade do algoritmo apresentado, tendo custo quadrático O(n²), uma vez que a função de maior custo do programa é quadrática.
</p>

<p style = "text-align = justify">
Tal metrica embasa-se na quantidade de operações realizadas com a entrada se faz mais realista e generalista, que é o objetivo deste trabalho, pois como dito por <a href="https://kupdf.net/download/projeto-de-algoritmos-com-implementa-ccedil-otilde-es-em-java-e-c-nivio-ziviani_5b0c78cce2b6f5a878171c61_pdf">Nivio Ziviane em seu livro Projeto de Algoritmos</a> onde ele argumenta possibilidades como o fato de arquiteturas distintas apresentarem performaces distintas podem mascarar uma comparação mais correlata e condizente, apesar de ser o mesmo código pode haver distinção no tempo com relação ao tamanho da entrada de dados, em casos onde a mesma se faz grande como neste projeto, podem haver conflitos de armazenamento de informações com o sistema operacional que trabalha para manter seus processos ao mesmo tempo que o código é executado podendo atrasar, perder ou impossibilitar a execução do código.  
</p>

<p style = "text-align = justify">
A partir das modificações realizadas no código-fonte durante a construção do programa, pode-se dizer que a decisão de retirar os dados da memória segundária para a memória principal todo o texto de uma vez ao invés de sequêncialmente se mostrou uma otmização relevante para evitar a velocidade mais lenta da memória segundária e minimizar as chamadas ao sistema operacional, alem de outros evitar outros problemas. Durante o processo de desenvolvimento, foram destacados possíveis pontos de melhora como o alinhamento da saída, algo que não influência diretamente no custo computacional e nem no tempo de execução do algorítmo, sendo afetada apenas a estética da saída.
</p>

<p style = "text-align = justify">
Quando o texto a ser lido é muito grande, é possível que um tempo considerável seja gasto para percorrer todo o texto em busca das expressões. Quanto maior o texto, maior será o tempo de processamento necessário para a busca. Para tanto, uma possível melhora do programa seria utilizar, de alguma forma, o algoritmo do comando de linha "grep". Este comando tem como uma de suas funções mostrar em quais linhas do arquivo, determinado pelo usuário, as substrings fornecidas aparecem. Outra opção seria a utilização do algoritmo de Aho-Corasick, que tem como objetivo localizar todas as palavras chaves em textos e possui um custo linear.
</p>

<p style = "text-align = justify">
Em geral, podemos considerar o trabalho como um sucesso, já que todos os objetivos propostos foram atingidos de modo suficientemente satisfatório e com performance que torna nosso sistema auxiliar viável para quase qualquer tamanho de entrada em máquinas modernas. Os objetivos didáticos também foram atingidos já que tivemos uma experiência completada do planejamente e análise de diversas estruturas de dados a fim de resolver o problema proposto.
</p>

## Instruções para compilação e obtenção do projeto

<p style = "text-align = justify">
Para obter este projeto em sua máquina basta usar o comando no terminal: git clone "link https no topo do repositóiro", tal link esta no topo da página na tag code como mostra a imagem abaixo:
</p>



<img src="./img/protocoloHTTP.png" width = 80% alt="onde esta o link">


<p style = "text-align = justify">
Este projeto contem um arquivo com um conjunto de diretivas de compilação que podem ser executadas em terminal, as quais são:
</p>

<table border="1">
      <tr><td><u>g++ (nome dos arquivos) -o  (nome do executável)</u></td></tr>
      <tr><td><u>rm -rf (nome do executável)</u></td></tr>
      <tr><td><u>./(nome do executável)</u></td></tr>
</table>


<p style = "text-align = justify">
    <i>As diretrizes de execução deste Make file são:<i>
    <table border="1">
      <tr><td><u>make clean</u></td> <td>Apaga a última compilação realizada contida na pasta objects</td></tr>
      <tr><td><u>make</u></td> <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta objects que esta dentro do repositório build.</td></tr>
      <tr><td><u>make run</u></td> <td>Executa o programa da pasta objects após o programa já estar compilado </td></tr>
    </table>
    <i>Para a execução do programa utilize <u>make</u> para realizar a compilação e logo após utilize <u>make run</u> para executar o programa</i>
</p>

## Referências
<p style = "text-align = justify">
CORMEN, Thomas H. Algoritmos: Teoria e Prática. 3. ed. Rio de Janeiro: Editora Elsevier, 2012.<br>
N.Ziviane,Projeto de Algoritmos: com implementação em Java e C++,São Paulo,Thonson Learning,2007.
</p>

## Autores

<p style = "text-align = justify">
Frank Leite Lemos Costa, Leandro Sousa Costa, João Pedro Freitas, Getúlio Santos Mendes e Rafael Guimarães Gontijo. Alunos de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 3° período.
</p>
