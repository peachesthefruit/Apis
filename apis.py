#!/usr/bin/env python3.5

import subprocess, sys

def usage():
    print('''Usage: apis.py [COMMAND] [ARGUMENTS]
    
        COMMANDS:
        serve:      launches server, run with --help for more options
        suggest:    runs suggestion engine, run with -h for more options
        scout:      runs scout webcrawler, run with -h for more options
        help:       show this help message
        ''')

def main():
    if not len(sys.argv):
        print('Please provide an argument')
        usage()
        sys.exit(1)

    command = sys.argv[1]

    if command == 'help':
        usage()
        sys.exit()
    elif command == 'serve':
        command = ['flask', 'run'] + sys.argv[2:]
        print('Serving the queen bee')
        subprocess.call(command)
        sys.exit()
    elif command == 'suggest':
        command = ['./honeybee'] + sys.argv[2:]
        print('Getting those sweet suggestions')
        subprocess.call(command)
        sys.exit()
    elif command == 'scout':
        command = ['python3.5', './scout.py'] + sys.argv[2:]
        print('Scouting for all that nectar')
        subprocess.call(command)
    else:
        print('Invalid command', command)
        usage()
        sys.exit(2)

if __name__ == '__main__':
    main()
