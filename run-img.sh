#!/usr/bin/env bash

if [ $# == 0 ]; then
  docker run -it -w /work -v "$(pwd):/work" exercism /bin/bash  
  exit 0
fi

TRACK=$(ls -1 -d */ | sed "s/\(.*\)\//\1/g" | grep -E "^$1$")

if [ "$TRACK" != "" ]; then
  docker run -it -w /work -v "$(pwd):/work" exercism-$TRACK /bin/bash
  exit 0
else
  echo "Track not available."
  exit 1
fi

