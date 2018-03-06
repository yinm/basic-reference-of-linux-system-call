FROM ubuntu:latest
RUN mkdir /workspace
ADD . /workspace
WORKDIR /workspace

RUN apt-get update
RUN apt-get -y install sudo && \
    sudo apt-get -y install build-essential && \
    sudo apt-get -y install man && \
    sudo apt-get -y install manpages-dev && \
    sudo apt-get -y install strace
