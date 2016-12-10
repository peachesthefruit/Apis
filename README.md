DS Final Project - Apis
=======================

Apis:
-----
Apis analyzes the internet to give you recommendations based on your favorite sites.
The project can be broken down into three parts: scouting, suggesting, and serving.
The scouting portion is based on an asynchronous, Python3.5 webcrawler. `scout.py`
crawls the web, and records all links between unique domans (i.e. a link between
google.com and google.com/images is not counted). This graph can then be consumed
by `honeybee`, to make suggestion based on one of two algorithms. The first is a
breadth-first traversal, where a count of each site is kept. The second is based
on random walks, where the program executes multiple random walks, and keeps a 
cummulative count for sites during each. At the end of each algorithm, 5 suggested
sites are outputed. The serving portion is based on a Flask server `hive.py` and
ReactJS frontend. When a user gives the web interface a link, the server calls
`honeybee` and returns the results to the user.

Project Dependencies:
---------------------
**Python Version**: 3.5

Python Dependencies:
- aiohttp v1.1.6
- beautifulsoup4 v4.4.1
- Flask v0.11.1
- lxml v3.6.4 (Note: might need to install lxml or lxml2 outside of pip first with Homebrew, apt-get, pacman, etc.)
- urllib3 v1.13.1

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
    
    # Add permissions
    $ chmod +x apis.py scout.py benchmark.sh
    
    # Build C++ code
    $ make
    ```
    
Code Execution:
---------------
We have included a CLI in the form of `apis.py`. Run `$ ./apis.py help for full list of options`.
Here we show how to run each file directly or with the CLI.
- Run scout.py webcrawler (use `-h` flag for full usage instructions):
    ```bash
    $ ./scout.py -w [NUM_WORKERS] -l [NUM_LINKS] -o [OUTPUT_FILE]
    
    # CLI
    $ ./apis.py scout -w [NUM_WORKERS] -l [NUM_LINKS] -o [OUTPUT_FILE]
    ```

- Run honeybee suggestion engine (use `-h` flag for full usage instructions):

    ```bash
    $ ./honeybee -b cnn.com -n 2 < nectar.txt # Use Breadth-First Traversal algorithm
    $ ./honeybee -r cnn.com -s 100 < nectar.txt # Use Random Walk algorithm
    
    # CLI
    $ ./apis.py suggest -b cnn.com -n 2 < nectar.txt
    $ ./apis.py suggest -r cnn.com -s 100
    ```
    

- Run hive.py, a Flask server for the suggestion engine:

    ```bash
    $ flask run # FLASK_APP environment variable should be set to hive.py if setup correctly above
    
    # CLI
    $ ./apis.py serve
    ```

Testing and Benchmarking
------------------------
- To benchmark honeybee and scout run:

    ```bash
    $ ./benchmark.sh
    
    # CLI
    $ ./apis.py benchmark
    ```
    Results are in `RESULTS.md`

- To test honeybee run:
    ```bash
    $ make test
    
    # CLI
    $ ./apis.py test
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
