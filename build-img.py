import argparse
import os
import json

IGNORE_DIRS={".git"}

TRACKS = set(next(os.walk("."))[1])
TRACKS.difference_update(IGNORE_DIRS)


parser = argparse.ArgumentParser(prog="build-images", description="Build Docker images for my-exercism repository.")
exercism_builder_group = parser.add_mutually_exclusive_group(required=False)
exercism_builder_group.add_argument("--token", type=str)
exercism_builder_group.add_argument("--config-file", type=str, default="config.json")

subimage_group = parser.add_mutually_exclusive_group(required=True)
subimage_group.add_argument("--all",  action='store_true')
subimage_group.add_argument("--subimages", type=str, nargs="+", choices=TRACKS)


def _build_docker_exercism(token):
    os.system("docker build -t exercism . --build-arg EXERCISM_TOKEN={}"
            .format(token))

def _build_docker_subdirs(subdirs):
    for subdir in subdirs:
        if subdir in IGNORE_DIRS: continue
        os.system(" docker build -t exercism-{0} -f {0}/Dockerfile {0}".format(subdir))

def _read_token_from_config_file(config_file):
    return json.loads(open("config.json").read())["token"]

if __name__ == "__main__":
    
    try:
        token = None
        args = parser.parse_args()
        if args.token:
            token = args.token
        elif args.config_file:
            token = _read_token_from_config_file(args.config_file)
        
        if token:
            print("Configuring exercism with token={}".format(token))
            _build_docker_exercism(token)

        if args.all:
            _build_docker_subdirs(TRACKS)
        elif args.subimages:
            _build_docker_subdirs(args.subimages)

    except Exception as e:
        print(str(e))
        parser.print_help()
        exit(1)

