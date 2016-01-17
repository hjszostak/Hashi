# Hashi
A command line tool to solve the [Hashiwokakero](https://en.wikipedia.org/wiki/Hashiwokakero) logic puzzle.

## Usage
To use, simply enter, into standard input, the width, the height, then the puzzle (using numbers for islands and spaces to
separate them. The program may take a few minutes to run for larger puzzles

## Example
test0.txt
```
20 28
  2  3       3 3 1
1      1  4 2   2  2
   2           1
 1    1 2 3  5  4 2
   4          1  1
2       3   1
             3    2
              2
        3         2
            2
                  1
   4  2 2        3 4

   4 4    2 3 2   1
       3 3
            3
  2  4 3 2
   2             2
  2     1
   2
       1 1       2
  1         4
 2 3 4  3         2
4         3      1
 1 2   2    3 2 3 2

2            4     4
```

```
$ ./hashi < test0.txt
  2--3-------3-3-1  
1 |  | 1--4=2| |2--2
| |2 |    |  | 1|  |
|1|H |1 2-3--5--4-2|
|||4 || |    H1 |1||
2||H || 3   1H| ||||
|||H || H   |3| ||2|
|||H || H   ||2 ||||
|||H || 3   ||| ||2|
|||H || |   2|| ||||
|||H || |   ||| ||1|
|||4 |2-2   ||| |3-4
|||H |      ||| || H
|||4-4    2-3|2 ||1H
|||| H 3=3| ||| |||H
|||| H | || 3|| |||H
||2| 4-3 2| H|| |||H
|||2 | | || H|| |2|H
||2| | |1|| H|| |||H
|||2 | |||| H|| |||H
|||| | 1|1| H|| |2|H
||1| |  | | 4|| |||H
|2-3-4==3 | H|| ||2H
4=========3 H|| |1|H
|1-2---2----3|2-3-2H
|            |     H
2------------4=====4
```
