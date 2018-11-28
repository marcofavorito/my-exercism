#!/usr/bin/env bash

TRACK=$(ls -1 -d */ | sed "s/\(.*\)\//\1/g" | grep -E "^$1$")

if [ "$TRACK" != "" ]; then
  docker run -it -w /work -v "$(pwd)/${TRACK}:/work" exercism-$TRACK /bin/bash
  exit 0
else
  echo "Track not available."
  exit 1
fi
