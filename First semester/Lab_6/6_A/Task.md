# Проверка сбалансированности
АВЛ-дерево является сбалансированным в следующем смысле: для любой вершины высота ее левого поддерева отличается от высоты ее правого поддерева не больше, чем на единицу.  
  
Введем понятие баланса вершины: для вершины дерева V ее баланс B(V) равен разности высоты правого поддерева и высоты левого поддерева.  

Таким образом, свойство АВЛ-дерева, приведенное выше, можно сормулировать следующим образом: для любой ее вершины V выполняется следующее неравенство: −1≤B(V)≤1.  

Дано двоичное дерево поиска. Для каждой его вершины требуется определить ее баланс.

## Входные данные
Входные данные содержат описание двоичного дерева.  

В первой строке файла находится число n (1<=n<=2*10^5 - число вершин в дереве. В последующих n строках файла находятся описания вершин дерева. В (i+1)-ой строке айла
(1<=i<=n) находится описание i-ой вершины, состоящее из трех чисел Ki, Li, Ri, разделенных пробелами ключа в i-ой вершине (\|Ki\|<=10^9), номера левого ребенка i-ой вершины
(i<Li<=n или Li=0, если левого ребенка нет) и номера правого ребенка i-ой вершины (i<Ri<=n или Ri=0, если правого ребенка нет).  

Все ключи различны. Гарантируется, что данное дерево является деревом поиска.

## Выходные данные
Для i-ой вершины в i-ой строке выведите одно число - баланс данной вершины.

### STDIN
6  
-2 0 2  
8 4 3  
9 0 0  
3 5 6  
0 0 0  
6 0 0

### STDOUT
3  
-1  
0  
0  
0  
0