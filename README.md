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

1. Use `setup.sh`, only works for bash/sh:
    ```bash
    $ source setup.sh # Will run pip3.5 to install python modules and will set necessary environment variables, as well as build C++ code
    ```

2. Manually install and configure:
    ```bash
    # Install dependencies
    $ pip3.5 install -r requirements.txt # Might require sudo if not in virtualenv
    # Configure flask
    $ export FLASK_APP=hive.py #
    # Build C++ code
    $ make
    ```
    
Code Execution:
---------------
- Run scout.py webcrawler (use `-h` flag for full usage instructions):
    ```bash
    $ ./scout.py -w [NUM_WORKERS] -l [NUM_LINKS] -o [OUTPUT_FILE]
    ```

- Run honeybee suggestion engine (use `-h` flag for full usage instructions):

    ```bash
    $ ./honeybee -b cnn.com -n 2 < nectar.txt # Use Breadth-First Traversal algorithm
    $ ./honeybee -r cnn.com -s 100 < nectar.txt # Use Random Walk algorithm
    ```
    

- Run hive.py, a Flask server for the suggestion engine:

    ```bash
    $ flask run # FLASK_APP environment variable should be set to hive.py if setup correctly above
    ```

Testing and Benchmarking
------------------------
- To benchmark honeybee run:

    ```bash
    $ ./benchmark.sh
    ```
- To test honeybee run:
    ```bash
    $ make test
    ```

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
