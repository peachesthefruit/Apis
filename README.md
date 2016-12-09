DS Final Project - Apis
=======================

Apis:
-----

Use a web crawler to make a graph of the internet based on links, then use this web crawler to make suggestions about what sites one should visit when given a list of favorite sites. We will implement the suggestions in two ways: first by executing a number of random walks from the original urls and counting how many times we finish at each site, and secondly by executing a breadth-first traversal and counting the number of occurrences for each site a given number of links away from the original. The suggestion engine will be able to be accessed from a served html page.

Project Dependencies:
---------------------

Set-up & Installation:
----------------------

Code Execution:
---------------
- **To make**:

> make

- **To test**:

> make test

- **To run scout.py and create nectar.txt**:

> ./scout.py -o nectar.txt

- **To run honeybee's usage (and learn how to run BFS and random step versions)**:

> ./honeybee -h

- **To run the server, hyve.py**:

>

- **To benchmark everything, do**:

> chmod 775 benchmark.sh

> ./benchmark.sh

Other Relevant Information:
---------------------------

- For member contributions, please see `CONTRIBUTORS.md`.

- No bees were harmed in the making of this project

Members:
--------
- Kylie Hausch (khausch)

- Shelby Lem (slem)

- John Johnson (jjohns48)

- Nikolas Dean Brooks (nbrooks3)