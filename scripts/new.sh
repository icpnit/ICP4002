# make a problem direcroty and copy the generator template into it
mkdir -p ./src/$1
cp ./tests/problems/aplusb/generator.cpp ./src/$1
touch ./src/$1/README.md
