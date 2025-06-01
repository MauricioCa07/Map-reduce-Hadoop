#!/bin/bash
curl -L -o ./10000-movies-letterboxd-data.zip\
  https://www.kaggle.com/api/v1/datasets/download/ky1338/10000-movies-letterboxd-data

unzip 10000-movies-letterboxd-data.zip

scp -i "$1" ./*.py hadoop@"$2":~
scp -i "$1" ./Movie_Data_File.csv hadoop@"$2":~

