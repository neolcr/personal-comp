#!/bin/zsh

./comp.sh
if [ $? -eq 0 ]; then
    ./out
    echo $?
fi

