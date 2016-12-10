#!/bin/bash
# Used to run all benchmarks
echo "Setting permissions..."
chmod +x benchmarkhoneybee.sh
chmod +x benchmarkscout.sh
echo "Making executables..."
make
echo "Running honeybee benchmarking..."
./benchmarkhoneybee.sh > honeybeemetrics.txt
echo "Running scout benchmarking..."
./benchmarkscout.sh > scoutmetrics.txt
echo "Bencmarking complete!"
