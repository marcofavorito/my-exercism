FROM ubuntu:18.04

USER root

RUN apt-get update
RUN apt-get install -y sudo && \
    apt-get install -y apt-utils

RUN HOME=/home/default && \
    mkdir -p ${HOME} && \
    GROUP_ID=1000 && \
    USER_ID=1000 && \
    groupadd -r default -f -g "$GROUP_ID" && \
    useradd -u "$USER_ID" -r -g default -d "$HOME" -s /sbin/nologin \
            -c "Default Application User" default && \
    chown -R "$USER_ID:$GROUP_ID" ${HOME} && \
    usermod -a -G sudo default && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers


USER default

RUN sudo apt-get update && sudo apt-get upgrade -y

WORKDIR /home/default

# install exercism
ARG EXERCISM_TOKEN
RUN sudo apt-get install -y wget
RUN mkdir exercism && \
    cd exercism && \
    wget https://github.com/exercism/cli/releases/download/v3.0.11/exercism-linux-64bit.tgz && \
    tar -xf exercism-linux-64bit.tgz
RUN sudo cp /home/default/exercism/exercism /usr/local/bin

RUN exercism configure --token=$EXERCISM_TOKEN --workspace /work

RUN sudo apt-get install -y nano vim curl gcc cmake tmux gnupg2

