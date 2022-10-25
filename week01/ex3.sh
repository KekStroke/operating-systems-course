mkdir new_folder1
touch new_folder1/root.txt
ls -tr / > new_folder1/root.txt
date
sleep 3
mkdir new_folder2
touch new_folder2/home.txt
ls -tr ~ > new_folder2/home.txt
cat new_folder1/root.txt
cat new_folder2/home.txt
