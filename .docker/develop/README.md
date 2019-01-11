General-purpose image for software development.

## Commands 

To build:

    ./scripts/docker-build.sh

Command to run the image ([credits](https://stackoverflow.com/a/46676868/7150172))

    ./scripts/docker-run.sh --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -- /bin/bash

