FROM exercism:latest

###########################################################
# LISP
RUN sudo apt-get install -y sbcl rlwrap
# to enhance the REPL
RUN rlwrap sbcl
RUN wget https://beta.quicklisp.org/quicklisp.lisp
RUN sbcl --no-sysinit --no-userinit --load ~/quicklisp.lisp \
     --eval '(quicklisp-quickstart:install)' \
     --quit

RUN echo '#-quicklisp \n\
(let ((quicklisp-init (merge-pathnames "quicklisp/setup.lisp"  \n\
                                       (user-homedir-pathname)))) \n\
  (when (probe-file quicklisp-init) \n\
    (load quicklisp-init)))'  > ~/.sbclrc

###########################################################

