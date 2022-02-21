# tests the solution with generated input and outpu files
# usaage: sh tst.sh path/to/folder
N=$(ls $1/in | wc -l)

i=1
wrong=0
while [ "$i" -lt "$N" ]; do
  cat "$1/in/input$i.txt" | python3 "$1/solution.py" > tmp.txt
  out=$(cat tmp.txt)

  if [ -z "$out" ]; then
    wrong=1;
    echo "> $i-th testcase failed"
  fi
  
  if [ ! -z "$out" ]; then
    rst=$(cmp tmp.txt "./$1/out/output$i.txt");
  fi
  
  if [ ! -z "$out" ] && [ ! -z "$rst" ]; then
    echo "> $i-th testcase failed"; wrong=1;
  fi
  i=$((i+1))
done

if [ $wrong -lt 1 ]; then echo "Tests passed"; fi

rm -rf tmp.txt