# generates testcases for specified problem path
# usage: sh gen.sh path/to/folder
rm -rf $1/in
rm -rf $1/out

cpp=$(ls $1 | grep cpp$)
if [ ! -z "$cpp" ]; then
  echo "> C++ generator found"
  g++ $1/generator.cpp -o generator
  ./generator
  rm ./generator
  exit
fi

py=$(ls $1 | grep py$)
if [ ! -z "$py" ]; then
  echo "> Python generator found"
  python3 $1/generator.py $1
  exit
fi

echo "! No generator found"