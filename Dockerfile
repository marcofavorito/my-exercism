FROM ubuntu:18.04

ARG EXERCISM_TOKEN

RUN apt-get update && apt-get upgrade -y

RUN mkdir /work
WORKDIR /work

# install exercism
RUN apt-get install nano vim wget -y
RUN wget https://github.com/exercism/cli/releases/download/v3.0.11/exercism-linux-64bit.tgz
RUN tar -xf exercism-linux-64bit.tgz
RUN cp /work/exercism /usr/local/bin

RUN exercism configure --token=$EXERCISM_TOKEN


# LISP
RUN apt-get install sbcl rlwrap -y
# to enhance the REPL
RUN rlwrap sbcl
RUN wget https://beta.quicklisp.org/quicklisp.lisp
RUN sbcl --no-sysinit --no-userinit --load /work/quicklisp.lisp \
     --eval '(quicklisp-quickstart:install)' \
     --quit

RUN echo '#-quicklisp \n\
(let ((quicklisp-init (merge-pathnames "quicklisp/setup.lisp"  \n\
                                       (user-homedir-pathname)))) \n\
  (when (probe-file quicklisp-init) \n\
    (load quicklisp-init)))'  > /root/.sbclrc
