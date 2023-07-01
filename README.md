# Writing-aid-system

## O problema

<p style = "text-align = justify">
A publicação dos resultados de pesquisa é uma etapa crucial do trabalho científico. Geralmente, esses resultados são compartilhados na forma de artigos em congressos e periódicos,
após passarem por uma revisão rigorosa quanto à forma e conteúdo. Infelizmente, é comum
encontrar artigos na academia que apresentam dificuldades de leitura, além de conter erros de
ortografia e gramática.
Para lidar com a questão acima apresentada, existem diversas ferramentas de auxílio disponíveis.
Por exemplo, no Unix, o utilitário "ispell" pode ser utilizado para verificar a ortografia de textos
em inglês. Já para outras línguas e ambientes, há outras opções de ferramentas específicas.
Além disso, existem ferramentas comerciais baseadas em técnicas de inteligência artificial, que
buscam detectar erros gramaticais, analisar o estilo literário e fornecer estatísticas sobre parágrafos. O grammarly e o chatgpt são dois exemplos disso.
</p>
<p style = "text-align = justify">
Sabendo disso foi proposto a criação de um sistema, o qual seja capaz de análisar um texto de entrada especificar, projetar e implementar um algoritmo que ajude no processo de redação.
</p>

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
sua ocorrência e a distância entre elas incluindo as stop words?

3 - Como demonstrar a ocorrência de certas expressões sendo que para cada expressão deve ser indicado a
linha no arquivo fonte onde aparece?

<p style = "text-align = justify">
A principio é necessário extrair os dados do arquivo de entrada e inseri-los na memória do computador, para que se torne possível
manipular tais dados com o propósito de conseguir as informações requiridas para auxiliar na correção de um texto, para tal foi utilizado o modo de leitura binário assim lendo caracter por caracter do arquivo de entrada, assim foi possível averiguar onde se esta no texto, se esta entre duas palavras ou no final da frase o que é essencial para a análise do texto. 
</p>

<p style = "text-align = justify">
Usando essa forma de extração de dados é possível determinar o final de cada linha dentro do arquivo, já que cada linha é terminada com um "\n" basta contar as linhas a partir de quando o ponteiro usado para percorrer cada caracter do arquivo de entrada estiver lendo o "\n".
</p>

<p style = "text-align = justify">
Todas as sentenças do arquivo de entrada terão a terminação com "." ou "!" ou "?", com isso sendo que esta sendo lido caracter por caracter assim que se chega com o ponteiro ao ponto onde se tem um desses caracteres foi contabilizado uma sentença a mais.
</p>

<p style = "text-align = justify">
No que se refere as stop words, todas as palavras que foram sendo identificadas do arquivo de entrada ao mesmo tempo se analisou se tal palavra se enquandrava no grupo das palavras que estavão no arquivo de entrada dentro do dataset que contem todas as stop words, com isso foi se contando e identificando e armazenando tais palavras.
</p>

<p style = "text-align = justify">
No texto de entrada toda palavra é separada por espaços, e todas as sentenças terminam com "." ou "!" ou "?". Para que fosse possível identificar o número de palavras por sentença foi utilizado desvios condicionais, para identificar onde se terminava ou iniciava uma palavra sendo eles um espaço vazio ou "." ou "\n" ou "!" ou "?", a cada vez que o ponteiro que percorria o arquivo de entrada.
</p>


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
Pode-se dizer que o código cumpriu com todos os objetivos propostos, tendo resultados satisfatórios alcançados como ler, processar e análisar, diversos dados associados a palavras contidas em um texto, com isso ao se observar a análise de resultados, vemos que os resultados apresentadados foram condizentes com os resultados esperados. Após a conclusão do código, calculamos uma média depois de 10 execuções em três computadores diferentes chegamos a COLOCAR TEMPO MEDIO como resultado de tempo médio. Também deve-se ressaltar outro fator crucial sendo ele a complexidade do algoritmo apresentado, tendo custo quadrático (O(n^2)), uma vez que a função de maior custo do programa é quadrática. Apartir desses dados, pode-se dizer que a decisção de retirar os dados da memória segundária para a memória principal todo o texto de uma vez ao invés de sequêncialmente se mostrou uma otmização relevante para evitar a velocidade mais lenta da memória segundária e minimizar as chamadas ao sistema operacional.

Durante o processo de desenvolvimento, foram destacados possíveis pontos de melhora como o alinhamento da saída, algo que não influência diretamente no custo computacional e nem no tempo de execução do algorítmo, sendo afetasa apenas a estética da saída.(VOLTAR AQUI)



alinhamento
Decisões que podem influenciar no algoritmo, 

## Instruções para compilação

<p style = "text-align = justify">
Este projeto contem um arquivo com um conjunto de diretivas de compilação que podem ser executadas em terminal, as quais são:
</p>

<table border="1">
      <tr><td><u>gcc (nome dos arquivos) -o  (nome do executável)</u></td></tr>
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

## Autores

<p style = "text-align = justify">
Frank Leite Lemos Costa, Leandro Sousa Costa, João Pedro Freitas, Getúlio Santos Mendes e Rafael Guimarães Gontijo. Alunos de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 3° período.
</p>
