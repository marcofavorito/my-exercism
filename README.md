# my-exercism
My Exercism solutions.

## Using the Docker image

- build the image:

    docker build -t exercism . --build-arg EXERCISM_TOKEN=<your-token>

- run the container:

    docker run -it -w /work -v "$(pwd):/work" exercism /bin/bash

