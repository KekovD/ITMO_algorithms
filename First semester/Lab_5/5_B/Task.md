# Проверка корректности
Свойство двоичного дерева поиска можно сормулировать следующим образом: для каждой вершины дерева V выполняется следующее условие:
- все ключи вершин из левого поддерева меньше ключа вершины V;
- все ключи вершин из правого поддерева больше ключа вершины V.

Дано двоичное дерево. Проверьте, выполняется ли для него свойство двоичного дерева поиска.

## Входные данные
В первой строке находится число n (0≤n≤200000) - число вершин в дереве.  

В последующих n строках находятся описания вершин дерева. В (i+1)-ой строке айла (1≤i≤N) находится описание i-ой вершины, состоящее из трех чисел Ki, Li, Ri, 
разделенных пробелами - ключа в i-ой вершине (\|Ki\|<=10^9) , номера левого ребенка i-ой вершины (i<=Li<=N или Li = 0, если левого ребенка нет) и 
номера правого ребенка i-ой вершины (i<Ri<=N или Ri=0, если правого ребенка нет).

## Выходные данные
Выведите YES, если данное на входе дерево является двоичным деревом поиска, и NO, если не является.

### STDIN
6  
-2 0 2  
8 4 3  
9 0 0  
3 5 6  
0 0 0  
6 0 0

### STDOUT
YES

## Примечание
Решение данной задачи поможет Вам в дальнейшем проверять корректность построенных деревьев при отладке более сложных алгоритмов.