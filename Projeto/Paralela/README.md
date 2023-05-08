<html>

<body> 

<h2 align="center">Instruções detalhadas dos códigos</h2>

<h3> 1. Um código foi criado utilizando técnicas de paralelização</h3>
<h4> 
   <div> 
     <ul> 1. paralela.c -> Código em C que calcula o número de euler com 62 casas decimais, com 18 casas precisas
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
gcc −g −Wall −fopenmp −o paralela paralela.c
```

<h3> 2. Como executar o programa</h3>

```
./paralela X    // Sendo X o número de threads
```

<h3> 3. Como comprovar que os resultados propostos foram alcançados</h3>

```
O resultado imprime o valor da constante de euler
```
![image](https://user-images.githubusercontent.com/83614505/236920897-e8a73fdf-7260-4148-bd2e-0a824691ade7.png)
![image](https://user-images.githubusercontent.com/83614505/236920945-4cc38eac-2e3f-4f92-b97f-29e1935c2de7.png)





</body>
</html>
