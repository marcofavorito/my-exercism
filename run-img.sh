#!/usr/bin/env bash

DOCKER_IMAGES_HOME="./.dotfiles/docker"
RUN_SCRIPT="scripts/docker-run.sh"

if [ $# == 0 ]; then
  "${DOCKER_IMAGES_HOME}"/my-exercism/"${RUN_SCRIPT}"
  exit 0
fi

TRACK=$(ls -1 -d */ | sed "s/\(.*\)\//\1/g" | grep -E "^$1$")

if [ "$TRACK" != "" ]; then
  "${DOCKER_IMAGES_HOME}"/"${TRACK}"/"${RUN_SCRIPT}"
  exit 0
else
  echo "Track not available."
  exit 1
fi

