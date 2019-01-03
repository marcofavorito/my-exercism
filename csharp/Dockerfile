FROM exercism:latest



RUN wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.asc.gpg &&\
    sudo mv microsoft.asc.gpg /etc/apt/trusted.gpg.d/ &&\
    wget -q https://packages.microsoft.com/config/ubuntu/18.04/prod.list &&\   
    sudo mv prod.list /etc/apt/sources.list.d/microsoft-prod.list

RUN sudo apt-get install -y apt-transport-https &&\
    sudo apt-get update  &&\
    sudo apt-get install -y dotnet-sdk-2.1

