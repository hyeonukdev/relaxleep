#!/bin/sh
ps -ef | grep 'python playmusic1.py' | awk '{print $2}' | xargs kill -9