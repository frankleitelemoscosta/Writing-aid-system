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
* Como identificar o número da linha no arquivo fonte onde o parágrafo inicializa e termina?
* O que fazer para identificar o número de sentenças existentes no parágrafo?
* O que fazer para identificar o número de palavras de cada sentença incluindo e descartando as "stop words"?

2 - Para cada palavra que não é stop word:

* Como identificar cada palavra listada em ordem alfabética com a frequência de sua ocorrência no
texto, indicando as linhas do arquivo onde essas surgem?
* O que fazer caso uma palavra apareça mais de uma vez em um mesmo parágrafo, indicar a
sua ocorrência e a distância entre elas incluindo as stop words?

3 - Como demonstrar a ocorrência de certas expressões sendo que para cada expressão deve ser indicado a
linha no arquivo fonte onde aparece?

<p style = "text-align = justify">

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


## Conclusão

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
      <tr><td><u>make</u></td> <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta objects que esta dentro do repositório build.</td></tr>
      <tr><td><u>make run</u></td> <td>Executa o programa da pasta objects após o programa já estar compilado </td></tr>
    </table>
    <i>Para a execução do programa utilize <u>make</u> para realizar a compilação e logo após utilize <u>make run</u> para executar o programa</i>
</p>

## Autores