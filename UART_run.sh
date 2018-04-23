#!/bin/bash
./run.sh
dmesg | grep tty
PORT=ACM0
sudo chmod o+rw /dev/tty$PORT
gnome-terminal -- /bin/bash -c 'cat -v /dev/tty'$PORT'; sleep infinity'
echo -ne 'y' > /dev/tty$PORT
echo "echo -ne 'y' > /dev/tty$PORT"
echo "echo -ne 'n' > /dev/tty$PORT"
