#!/bin/bash
# Used to benchmark scout.py
echo "SCOUT:"
String=$(./measure ./scout.py -l 100 -w 10)
echo "$String"
String=$(./measure ./scout.py -l 100 -w 25)
echo "$String"
String=$(./measure ./scout.py -l 100 -w 50)
echo "$String"
String=$(./measure ./scout.py -l 100 -w 100)
echo "$String"
String=$(./measure ./scout.py -l 1000 -w 10)
echo "$String"
String=$(./measure ./scout.py -l 1000 -w 25)
echo "$String"
String=$(./measure ./scout.py -l 1000 -w 50)
echo "$String"
String=$(./measure ./scout.py -l 1000 -w 100)
echo "$String"
String=$(./measure ./scout.py -l 10000 -w 100)
echo "$String"
String=$(./measure ./scout.py -l 10000 -w 250)
echo "$String"

