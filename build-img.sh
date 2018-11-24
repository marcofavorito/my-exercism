if [ "$#" -ne 1 ]; then
    echo "Usage: build-img.sh <your-exercism-token>"
    echo "Please provide your Exercism token."
    exit 1;
fi

docker build -t exercism . --build-arg EXERCISM_TOKEN=$1
exit 0;
