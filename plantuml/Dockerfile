FROM develop

RUN sudo apt-get install -y default-jre default-jdk
RUN sudo apt-get install -y graphviz

RUN sudo pip install --upgrade pip
RUN sudo pip install Sphinx
RUN sudo pip install sphinxcontrib-plantuml
RUN sudo pip install Pillow

RUN echo '#!/bin/bash -e \n\
java -jar /home/default/plantuml.jar "$@"' | sudo tee /usr/local/bin/plantuml 

RUN sudo chmod +x /usr/local/bin/plantuml

COPY home/* /home/default

