#!/bin/bash
# Used to run all benchmarks
echo "Setting permissions..."
chmod 775 benchmarkhoneybee.sh
chmod 775 benchmarkscout.sh
echo "Making executables..."
make
echo "Running honeybee benchmarking..."
./benchmarkhoneybee.sh > honeybeemetrics.txt
echo "Running scout benchmarking..."
./benchmarkscout.sh > scoutmetrics.txt
echo "Bencmarking complete!"
