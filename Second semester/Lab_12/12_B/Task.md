# Весеннее наводнение 2
На этот раз весеннее наводнение затронуло не только город мостов, но и всю страну мостов целиком!  
  
Теперь Вы должны помочь президенту данной страны определить, какие мосты нужно восстановить, чтобы все города вновь стали связаны друг с 
другом в кратчайшие сроки.

## Входные данные
В первой строке даны два натуральных числа N и M – количество городов и количество мостов, соединяющих города (3≤N≤10^5,M≤10^6)  
  
В каждой из последующих M строк находятся по три целых числа: Ai,Bi,Ci, где Ci – время на восстановление моста,
соединяющего город Ai с городом Bi (1≤Ci≤100000;i=1,2,…,N).

## Выходные данные
Выведите одно число - минимальное время, необходимое для восстановления связи между всеми городами в стране мостов.

### STDIN
4 4  
1 2 1  
2 3 2  
3 4 5  
4 1 4

### STDOUT
7
