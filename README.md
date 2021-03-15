# Biggest_square
Final team task on piscine school 21(42 ecole).

Objective: Given a map and its legend (in the first line of the map file), 
you have to find the biggest square that you can make without encountering any obstacle. 
In case of multiplous squares of the same size it choses the most upper one and then the one which is most left.
Program should accept multiple arguments. In this case, result will be divided by "\n". 
In case zero arguments program has to read from standart input.

Example: map.txt 8 - height, o - obstacle, x - square

8.ox
........
ooo..... 
....o.oo
...o...o
.......o
........
oo.o....
o.......

Result: ./bsq map.txt

........
ooo.....
....o.oo
...o...o
.......o
....xxxx
oo.oxxxx
o...xxxx
