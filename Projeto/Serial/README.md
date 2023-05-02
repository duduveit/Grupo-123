<html>

<body> 

<h2 align="center">Instruções detalhadas dos códigos</h2>

<h3> 1. Três códigos foram criados para utilizar no trabalho</h3>
<h4> 
   <div> 
     <ul> 1. serial.f90 -> Código em fortran que calcula o numero de euler com 35 casas decimais, com 7 casas precisas
     </ul>
     <ul> 2. serial2.c -> Código em C que calcula o número de euler com 60 casas decimais, com 20 casas precisas
     </ul>
     <ul> 3. serial_prec.c -> Código em C que calcula o número de euler com 10000 casas decimais, com todas casas precisas
     </ul>
   </div>
</h4>

<h2 align="center">Instruções detalhadas para a execução do programa</h2>

<h3> 1. Como compilar o programa</h3>

<h4> Compiladores instalados </h4>

```
sudo apt install gfortran
sudo apt-get install gcc
sudo apt-get install libmpfr-dev
```

```
gfortran -o serial serial.f90
gcc  serial2.c -o  serialc 
gcc  serial_prec.c -o serial_prec -lgmp
```

<h3> 2. Como executar o programa</h3>

<h4>Serial</h4>

```
./serial
./serialc
./serial_prec 4000
```

<h3> 3. Como comprovar que os resultados propostos foram alcançados</h3>

```
O resultado imprime o valor da constante de euler
```



</body>
</html>
