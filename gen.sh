# generates testcases for specified problem path
# it use mkdir wisely in the cpp file so don't worry
# usaage: sh gen.sh path/to/folder
cd $1

g++ generator.cpp

./a.out

rm ./a.out
