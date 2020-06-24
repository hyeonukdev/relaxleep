#!/bin/sh
ps -ef | grep 'python playmusic2.py' | awk '{print $2}' | xargs kill -9