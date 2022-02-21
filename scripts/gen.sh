# generates testcases for specified problem path
# usaage: sh gen.sh path/to/folder
rm -rf $1/in
rm -rf $1/out

cd $1

g++ generator.cpp

./a.out

rm ./a.out
