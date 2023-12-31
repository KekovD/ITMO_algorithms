# Вставка в АВЛ-дерево
Вставка в АВЛ-дерево вершины V с ключом X при условии, что такой вершины в этом дереве нет, осуществляется следующим образом:
- находится вершина W , ребенком которой должна стать вершина V ;
- вершина V делается ребенком вершины W;
- производится подъем от вершины W к корню, при этом, если какая-то из вершин несбалансирована, производится, в зависимости от значения баланса, левый или правый поворот.

Первый этап нуждается в пояснении. Спуск до будущего родителя вершины V осуществляется, начиная от корня, следующим образом:  
Пусть ключ текущей вершины равен Y.  
- Если X<Y и у текущей вершины есть левый ребенок, переходим к левому ребенку.
- Если X<Y и у текущей вершины нет левого ребенка, то останавливаемся, текущая вершина будет родителем новой вершины.
- Если X>Y и у текущей вершины есть правый ребенок, переходим к правому ребенку.
- Если X>Y и у текущей вершины нет правого ребенка, то останавливаемся, текущая вершина будет родителем новой вершины.

- Отдельно рассматривается следующий крайний случай если до вставки дерево было пустым, то вставка новой вершины осуществляется проще: новая вершина
- становится корнем дерева.

## Входные данные
Входные данные содержат описание двоичного дерева.

В первой строке файла находится число n (1<=n<=2*10^5 - число вершин в дереве. В последующих n строках файла находятся описания вершин дерева. В (i+1)-ой строке айла
(1<=i<=n) находится описание i-ой вершины, состоящее из трех чисел Ki, Li, Ri, разделенных пробелами ключа в i-ой вершине (\|Ki\|<=10^9), номера левого ребенка i-ой вершины
(i<Li<=n или Li=0, если левого ребенка нет) и номера правого ребенка i-ой вершины (i<Ri<=n или Ri=0, если правого ребенка нет).  

Все ключи различны. Гарантируется, что данное дерево является корректным АВЛ-деревом.  

В последней строке содержится число X (\|X\|<=10^9) ключ вершины, которую требуется вставить в дерево. Гарантируется, что такой вершины в дереве нет.

## Выходные данные
Выведите в том же формате дерево после осуществления левого поворота. Нумерация вершин может быть произвольной при условии соблюдения формата. 
Так, номер вершины должен быть меньше номера ее детей.

### STDIN
2  
3 0 2  
4 0 0  
5

### STDOUT
3  
4 2 3  
3 0 0
5 0 0
