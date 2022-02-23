#!/bin/bash
docker build  -t shapeshifter-test .devcontainer/

docker run \
  -it \
  --rm \
  -host\
  -v $(pwd):/workspaces/shapeshifter-test \
  -u=$UID\
  -w="/workspaces/shapeshifter-test"\
  shapeshifter-test \
  ./build.sh

