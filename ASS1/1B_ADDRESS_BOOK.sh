#!/bin/sh
CreateBook(){ 
	echo 
		if [ -e addressbook.txt ] 
	then 
 		echo "Address Book is already Created..." 
 	else 
 		touch addressbook.txt 
 		echo "Address Book Created..." 
 	fi 
} 

insertBook(){ 
	while true 
 	do 
 		echo "Enter your full name: " 
 		read record 
 		if [ "$record" == "q" ]
 		then 
 			break 
 		fi 
		echo $record >> addressbook.txt 
		echo "Record Inserted Successfully" 
		echo -e "\n" 
	break 
 		done 
}

displayBook(){ 
	if [ ! -e addressbook.txt ]
	then 
 		echo "Address Book Does not Exit"
 	else 
 		cat addressbook.txt 
 	fi 
}

searchBook(){ 
	echo "Enter Data For Search: "
	read data 
 	if [ -f addressbook.txt ] 
	then 
		result=$(grep -i "$data" addressbook.txt) 
 	if [ "$result" ] 
 	then 
		echo "$result" 
		echo "found successfully"
	else 
		echo "record not found" 
	fi 
	else 
		echo "record not found" 
	fi 
}

deleteBook(){ 
	echo "Enter Data For Delete:"
	read data 
		if [ -f addressbook.txt ] 
	then 
		sed -i "/$data/d" addressbook.txt 
		sed -i "/^[[:space:]]*$/d" addressbook.txt 
		echo "deleted succesfully" 
	else 
		echo "file not found"
	fi 
}

modifyBook(){ 
	echo "Enter Full Name which you want to modify: "
	read actual 
 	result=$(grep -i "$actual" addressbook.txt) 
 	if [ "$result" ] 
 	then 
		echo "Enter data which you want to modify: " 
		read modified 
		sed -i "s/$actual/$modified/" addressbook.txt 
		echo "Record modified successfully..." 
 	else 
		echo "record not found"
 	fi
}

while true 
do 
	echo "Welcome To Menu" 
	echo "1.Create Address Book" 
	echo "2.Insert Data In Book" 
	echo "3.Display Data From Book" 
	echo "4.Search Data From Book" 
	echo "5.Delete Data From Book" 
	echo "6.Modify data From Book" 
	echo "7.Exit"
	echo "Enter your Choice: " 
	read ch 
 	case $ch in 
		1)createBook;; 
		2)insertBook;; 
		3)displayBook;; 
		4)searchBook;; 
		5)deleteBook;; 
		6)modifyBook;; 
		7)exit;; 
 	esac
done