# Похожие массивы
Назовем два массива похожими, если они состоят из одних и тех же элементов (без учета кратности). По двум данным массивам выясните, похожие они или нет.

## Входные данные
В первой строке содержится число n (1≤n≤10^5) – размер первого массива. Во второй строке идет n целых чисел, не превосходящих по модулю 10^9 – элементы массива. Далее аналогично задается второй массив.

## Выходные данные
Программа должна вывести слово YES, если массивы похожи, и слово NO в противном случае.

### STDIN
3  
1 7 9  
4  
9 7 7 1  

### STDOUT
YES

## Примечание
Это задача на использование сортировок, поэтому при её решении запрещено использовать структуры данных, помогающие искать элементы в неупорядоченных наборах (сеты, мапы, хеш-таблицы, деревья поиска и прочие).