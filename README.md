# my-exercism
My Exercism solutions.

## Using the Docker image

- build the Exercism image with token:

      python build-img.py --token <your-token>

- build the Exercism image with configuration file:

      python build-img.py --config <path-to-config.json>

- build all the subimages:

      python build-img.py --all

- build subimages for specific tracks:

      python build-img.py --subimages <track-1> <track2> ... <track-n>

- run the Exercism container:

      ./run-img.sh


- run the Exercism container for a specific track:

      ./run-img.sh <track>

