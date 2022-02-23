#!/bin/bash

docker run \
  -it \
  --rm \
  -host\
  -v $(pwd):/workspaces/shapeshifter-test \
  -u=$UID\
  -w="/workspaces/shapeshifter-test" \
  shapeshifter-test \
  ./build/shapeshifter-test-tests

