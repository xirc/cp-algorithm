FROM xirc/cp-algorithm

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get -y install \
        python3 \
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Make g++ alias
# Use -D_GLIBCXX_DEBUG (https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_macros.html)
# Use -fsanitize=undefined (https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
RUN echo "alias g++='g++ -std=c++14 -D_GLIBCXX_DEBUG -fsanitize=undefined'" >> $HOME/.bashrc

ENV DEBIAN_FRONTEND=dialog