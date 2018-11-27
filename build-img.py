import argparse
import os

parser = argparse.ArgumentParser(prog="build-images", description="Build Docker images for my-exercism repository.")

parser.add_argument("--build-exercism", type=str, required=False)

subimages = parser.add_mutually_exclusive_group(required=False)
subimages.add_argument("--all",  action='store_true')
subimages.add_argument("--subimages", type=list, default=[])

IGNORE_DIRS={".git"}

def _build_docker_subdirs(subdirs):
    for subdir in subdirs:
        if subdir in IGNORE_DIRS: continue
        os.system(" docker build -t exercism-{0} -f {0}/Dockerfile {0}".format(subdir))


if __name__ == "__main__":
    try:
        args = parser.parse_args()
        if args.build_exercism:
            os.system("docker build -t exercism . --build-arg EXERCISM_TOKEN={}"
                    .format(args.build_exercism))
        
        subdirs = next(os.walk("."))[1]
        if args.all:
            _build_docker_subdirs(subdirs)
        elif args.subimages:
            subdirs = set(args.subimages).intersection(set(subdirs))
            _build_docker_subdirs(subdirs)
    except:
        parser.print_help()
        exit(1)



