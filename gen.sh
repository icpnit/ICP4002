# generates testcases for specified problem path
# usaage: sh gen.sh path/to/folder
cd $1

g++ generator.cpp

./a.out

rm ./a.out
