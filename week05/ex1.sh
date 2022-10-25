# !/bin/bash

# gcc channels.c -o channels
# ./channels

gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

for ((i = 0; i < $1; ++i)) do
    gnome-terminal -- "./subscriber"
done

gnome-terminal -- "./publisher" $1

rm publisher
rm subscriber