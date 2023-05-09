#!/bin/sh

./metronome 100 2 4 &

sleep 2

echo "pause 4" > /dev/local/metronome
