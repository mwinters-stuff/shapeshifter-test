#!/bin/bash

for FILE in ?.txt 
do
  docker run \
    -it \
    --rm \
    -host\
    -v $(pwd):/workspaces/shapeshifter-test \
    -u=$UID\
    -w="/workspaces/shapeshifter-test" \
    shapeshifter-test \
    ./build/shapeshifter-test $FILE

done
