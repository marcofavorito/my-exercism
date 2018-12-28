import argparse
import os
import json

IGNORE_DIRS={".git"}

TRACKS = set(next(os.walk("."))[1])
TRACKS.difference_update(IGNORE_DIRS)


parser = argparse.ArgumentParser(prog="build-images", description="Build Docker images for my-exercism repository.")

parser.add_argument("--force", action="store_true", default=False)

exercism_builder_group = parser.add_mutually_exclusive_group(required=False)
exercism_builder_group.add_argument("--token", type=str)
exercism_builder_group.add_argument("--config", type=str, default="config.json")

subimage_group = parser.add_mutually_exclusive_group(required=False)
subimage_group.add_argument("--all",  action='store_true')
subimage_group.add_argument("--subimages", type=str, nargs="+", choices=TRACKS)


def _build_docker_exercism(token, force=False):
    os.system("docker build {1} -t exercism . --build-arg EXERCISM_TOKEN={0}"
            .format(token, "--no-cache" if force else ""))

def _build_docker_subdirs(subdirs, force=False):
    for subdir in subdirs:
        if subdir in IGNORE_DIRS: continue
        os.system(" docker build {1} -t exercism-{0} -f {0}/Dockerfile {0}"
            .format(subdir, "--no-cache" if force else ""))

def _read_token_from_config_file(config_file):
    return json.loads(open("config.json").read())["token"]

if __name__ == "__main__":
    
    try:
        token = None
        args = parser.parse_args()
        if args.token:
            token = args.token
        elif args.config:
            token = _read_token_from_config_file(args.config)
        
        if token:
            print("Configuring exercism with token={}".format(token))
            _build_docker_exercism(token, force=args.token is not None)
        
        images = None
        if args.all:
            images = TRACKS
        elif args.subimages:
            images = args.subimages
        else:
          exit(0)

        _build_docker_subdirs(images, force=args.force)

    except Exception as e:
        print(str(e))
        parser.print_help()
        exit(1)

