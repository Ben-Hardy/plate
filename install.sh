#!/bin/sh

make
sudo chmod 777 plate
sudo mv plate /usr/local/bin/
rm plate.o
