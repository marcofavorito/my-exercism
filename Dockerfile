FROM ubuntu:18.04

ARG EXERCISM_TOKEN

RUN apt-get update && apt-get upgrade -y

RUN mkdir /work
WORKDIR /work

# install exercism
RUN apt-get install wget -y
RUN wget https://github.com/exercism/cli/releases/download/v3.0.11/exercism-linux-64bit.tgz
RUN tar -xf exercism-linux-64bit.tgz
RUN ln -s /work/exercism /usr/local/bin

RUN exercism configure --token=$EXERCISM_TOKEN
