# Петя кормит котов
Мама подарила мальчику Пете n кошек.  
  
Что бы кошки могли спокойно кушать, Петя завел n мисок для корма. Миска с номером j принадлежит кошке с номером j. Изначально миски пустые.  
  
Существует 3 вида событий:
1. Кошка с номером i решила пообедать и съела из свей миски k кусочков мяса. Если в миске не хватает мяса, то кошка просто съедает все, что там есть и остается голодной.
2. Петя может в миску с номером i положить k кусочков мяса.
3. Мама, для учета расходов, решила спросить сколько кусочков мяса в сумме лежат в мисках с номерами от L до R.

## Входные данные
В первой строке дается 1 <= N <= 5*10^5 и 1 <= Q <= 10^5 - количество кошек и событий. В следующих Q строчках идет описание событий:
1. \+ i k добавить в миску под номером i k кусочков мяса.
2. \- i k кошка под номером i скушала k кусочков мяса из своей миски.
3. ? L R мама спросила у Пети сколько кусочков мяса в сумме лежит в мисках от L до R (включительно).

1 <= i, L, R <= n; 1 <= k <= 1000.

## Выходные данные
На каждый запрос мамы выведите в новой строке одно число - сумму кусочков мяса в интересующих её мисках.

### STDIN
7 5  
\+ 1 5  
\+ 3 4  
? 1 5  
\- 1 2  
? 1 2

### STDOUT
9  
3

## Примечание
Задача на 2 дополнительных балла!
