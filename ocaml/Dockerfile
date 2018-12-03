FROM exercism:latest

###########################################################
# OCAML 

RUN sudo apt-get update
RUN sudo apt-get install -y curl build-essential m4 zlib1g-dev libssl-dev ocaml ocaml-native-compilers opam 

# from source
#RUN curl -OL https://github.com/ocaml/ocaml/archive/4.01.tar.gz
#RUN tar -zxvf 4.01.tar.gz
#RUN cd ocaml-4.01 &&\
#    ./configure   &&\
#    make world world.opt &&\
#    sudo make install
#

RUN opam init

RUN opam switch 4.07.0
RUN echo "eval `opam config env`" >> ~/.bashrc
#RUN printenv OCAML_TOPLEVEL_PATH

RUN opam install core utop
RUN opam install base core_kernel ounit 
#RUN opam install async yojson core_extended core_bench cohttp async_graphics cryptokit menhir

RUN echo $'#use "topfind";;\n\
\#thread;;\n\
\#require "core.top";;\n\
\#require "core.syntax";;' > /home/default/.ocamlinit << EOF



###########################################################

