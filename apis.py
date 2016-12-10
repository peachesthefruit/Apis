#!/usr/bin/env python3.5

# CLI for Apis project
# Allows many commands in project to be easily executed

import subprocess, sys

def usage():
    print('''Usage: apis.py [COMMAND] [ARGUMENTS]
    
        COMMANDS:
        serve:      launches server, run with --help for more options
        suggest:    runs suggestion engine, run with -h for more options
        scout:      runs scout webcrawler, run with -h for more options
        test:       run tests for honeybee
        benchmark   run benchmark for honeybee
        help:       show this help message
        ''')

def main():
    if  len(sys.argv) == 1:
        print('Please provide an argument')
        usage()
        sys.exit(1)

    command = sys.argv[1]

    try:
        if command == 'help':
            usage()
        elif command == 'serve':
            command = ['flask', 'run'] + sys.argv[2:]
            print('Serving the queen bee')
            subprocess.call(command)
        elif command == 'suggest':
            command = ['./honeybee'] + sys.argv[2:]
            print('Getting those sweet suggestions')
            subprocess.call(command)
        elif command == 'scout':
            command = ['python3.5', './scout.py'] + sys.argv[2:]
            print('Scouting for all that nectar')
            subprocess.call(command)
        elif command == 'test':
            command = ['make', 'test']
            print('Testing')
            subprocess.call(command)
        elif command == 'benchmark':
            command = ['sh', 'benchmark.sh']
            print('Benchmarking')
            subprocess.call(command)
        else:
            print('Invalid command', command)
            usage()
            sys.exit(2)
    except KeyboardInterrupt:
        print('\nExiting gracefully like a bee')
        sys.exit()

if __name__ == '__main__':
    main()
