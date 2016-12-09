#!/bin/bash
# benchmarks honeybee for both BFS and random walk at different levels
echo "RANDOM WALKING:"
String=$(./measure ./honeybee -r cnn.com -s 100 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -r cnn.com -s 1000 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -r cnn.com -s 10000 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -r cnn.com -s 100000 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -r cnn.com -s 1000000 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -b cnn.com -n 1 < nectar.txt)
echo "BREADTH-FIRST SEARCH:"
echo "$String"
String=$(./measure ./honeybee -b cnn.com -n 2 < nectar.txt)
echo "$String"
String=$(./measure ./honeybee -b cnn.com -n 3 < nectar.txt)
echo "$String"

