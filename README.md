DS Final Project - Apis
=======================

Apis:
-----

Apis is a system that anaylzes a network of specific links in order to provide the user with suggestions of links that they may be interested in visiting, based off of the provided link(s).

Project Dependencies:
---------------------
**Python Version**: 3.5

Python Dependencies:
- aiohttp==1.1.6
- beautifulsoup4==4.4.1
- Flask==0.11.1
- lxml==3.6.4 (Note: might need to install lxml or lxml2 outside of pip first with Homebrew, apt-get, pacman, etc.)
- urllib3==1.13.1

Set-up & Installation:
----------------------
All of our dependencies and their dependencies are in the requirements.txt file.
We recommend setting up a virtual environment to avoid having to deal with root
permissions for pip, and to avoid conflicting modules between Python3.5 and your
default version. There are a few ways to set up the application:

1. Use `setup.sh`:
     ```$ source setup.sh # Will run pip3.5 to install python modules and will set necessary environment variable, as well as build C++ code```

2. Manually install and configure:
3.   ```$ # Install dependencies
3.      $ pip3.5 install -r requirements.txt # Might require sudo if not in virtualenv
4.      $ # Configure flask
5.      $ export FLASK_APP=hive.py
6.      $ # Build C++ code
7.      $ make```

Code Execution:
---------------
- **To make honeybee**:

> make

- **To test honeybee**:

> make test

- **To run scout.py and create nectar.txt (default output is output.txt, use -h tag for more usage information)**:

> ./scout.py -o nectar.txt

- **To run honeybee's usage (and learn how to run BFS and random step versions)**:

> ./honeybee -h

- **To run the server, hive.py**:

> # Set FLASK_APP environment variable to hive.py 
> export FLASK_APP=hive.py # bash syntax
> flask run

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