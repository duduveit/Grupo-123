<html>

<body> 

<h2 align="center">Instruções detalhadas dos códigos</h2>

<h3> 1. Um código foi criado utilizando técnicas de paralelização</h3>
<h4> 
   <div> 
     <ul> 1. paralela.c -> Código em C que calcula o número de euler com 10000 casas precisas
   </div>
</h4>

<h2 align="center">Instruções detalhadas para a execução do programa</h2>

<h3> 1. Como compilar o programa</h3>

<h4> Compiladores instalados </h4>

```
sudo apt-get install gcc
   
sudo apt-get install libomp-dev
```

```
gcc −o paralela paralela.c -lgmp -fopenmp
```

<h3> 2. Como executar o programa</h3>

```
./paralela X    // Sendo X o número de iterações
```

<h3> 3. Como comprovar que os resultados propostos foram alcançados</h3>

```
O resultado imprime o valor da constante de euler
```
![image](https://github.com/duduveit/Grupo-123/assets/84543379/4e833c9e-322b-4797-b31a-17e7f58791f9)
![image](https://github.com/duduveit/Grupo-123/assets/84543379/9c657b7f-ff55-4646-863a-bbe44c82ee76)





</body>
</html>
