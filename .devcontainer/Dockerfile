FROM debian

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get -y install \
        build-essential \
        cmake \
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

ENV DEBIAN_FRONTEND=dialog