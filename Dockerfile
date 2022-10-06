# syntax=docker/dockerfile:1
FROM ubuntu:latest

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install build-essential wget git

RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/boost_1_80_0.tar.bz2
RUN tar --bzip2 -xf boost_1_80_0.tar.bz2

WORKDIR "/boost_1_80_0"
RUN ./bootstrap.sh --prefix=/usr/local --with-python=python3
RUN ./b2 stage -j8 threading=multi
RUN ./b2 install threading=multi

WORKDIR "/"
RUN rm -r boost_1_80_0*

CMD ["/bin/bash"]

# W: Get-Content Dockerfile | docker build -t efde_build - 
# L: docker build - < Dockerfile 