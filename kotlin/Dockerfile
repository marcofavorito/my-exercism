FROM exercism:latest

RUN sudo apt-get update &&\
    sudo apt-get install -y software-properties-common &&\
    sudo add-apt-repository ppa:webupd8team/java &&\ 
    sudo apt-get update &&\
    echo debconf shared/accepted-oracle-license-v1-1 select true | sudo debconf-set-selections &&\
    echo debconf shared/accepted-oracle-license-v1-1 seen true | sudo debconf-set-selections &&\
    sudo apt-get install -y oracle-java8-installer &&\ 
    sudo apt install -y oracle-java8-set-default 

RUN sudo add-apt-repository ppa:cwchien/gradle &&\
    sudo apt-get update &&\
    sudo apt-get install -y gradle
 

