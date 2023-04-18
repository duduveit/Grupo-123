<html>

<body> 

<h2 align="center">Instruções detalhadas para a execução do programa</h2>

<h3> 1. Como compilar o programa</h3>

```
gcc nomeArquivo.c -o nomeArquivo
```

<h3> 2. Como executar o programa</h3>

<h4>Serial</h4>

```
time ./serial linha coluna
```

<h4>Paralela</h4>

<h4>É recomendado usar o número de threads na mesma quantidade de linhas da matriz.</h4>

```
time ./paralela linha coluna thread
```

<h3> 3. Como comprovar que os resultados propostos foram alcançados</h3>

```
A execução do programa deve imprimir a matriz A, matrizB e o resultado da multiplicação de ambas matrizes. 
```

<table border="4", style="width:100%", align="center">
    <tr>
        <th>N linhas x colunas</th>
        <th>3x3</th>
        <th>10x10</th>
        <th>100x100</th>
        <th>1000x1000</th>
    </tr>
    <tr>
        <td>1 thread</td>
        <td>0,001s</td>
        <td>0,003s</td>
        <td>0,010s</td>
        <td>0,678s</td>
    </tr>
    <tr>
        <td>N threads</td>
        <td>0,002s</td>
        <td>0,003s</td>
        <td>0,009s</td>
        <td>0,652s</td>
    </tr>
    <tr>
        <td>Speedup</td>
        <td>0,5</td>
        <td>1</td>
        <td>1,1111</td>
        <td>1,0399</td>
    </tr>
</table>

</body>
</html>
