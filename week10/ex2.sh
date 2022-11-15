rm -rf week01 _ex2.txt ex2.txt
mkdir week01
touch week01/file.txt
echo "Anvar Iskhakov" > week01/file.txt
link week01/file.txt _ex2.txt
find ./ -inum $(ls week01/file.txt -i | awk '{print $1}') >> ex2.txt
find ./ -inum $(ls week01/file.txt -i | awk '{print $1}') -exec rm {} \; >> ex2.txt