var=1
while [ $var -eq 1 ] 
do
	echo "1.CREATE 2.INSERT 3.VIEW 4.SEARCH 5.UPDATE 6.DELETE 7.EXIT"
	read choice
	
	case $choice in
		1)  touch record.txt
                    echo "File Created";;
			
		2)  echo "REGNO TO INSERT:"	
		    read regno
		    grep $regno record.txt  > temp
		    if [ -s temp ]
                        then 
			   	    echo "Duplicate Data Found"
 			else
                                    read -p "NAME" name
                                    read -p "CITY" city
		 		    read -p "MOBILE" mobile
		 		    grep -v "$regno" record.txt > new.txt
		 		    mv new.txt record.txt
		 		    echo "$regno $name $city $mobile" >> record.txt 	
 					
 			fi
 			;;
		   	
		3)  echo "REG NAME CITY MOBILE"
			cat record.txt;;
			
		4)  echo "REGNO TO SEARCH:"	
		    read regno
		    grep -w $regno record.txt  > temp
		    if [ -s temp ]
                        then 
 					cat temp
 			else
 					echo "No data found with the particular reg no"
 			fi;;
		   
		   
		5)  echo "REGNO TO UPDATE:"	
		    read regno
		    grep $regno record.txt  > temp
		    if [ -s temp ]
                        then 
			   	    read -p "NAME" name
					read -p "CITY" city
		 		    read -p "MOBILE" mobile
		 		    grep -v "$regno" record.txt > new.txt
		 		    mv new.txt record.txt
		 		    echo "$regno $name $city $mobile" >> record.txt 	
 			else
 					echo "No data found with the particular reg no"
 			fi
 			
 			
		;;
		6) echo "REGNO TO DELETE:"	
		    read regno
		    grep $regno record.txt  > temp
		    if [ -s temp ]
                        then 
					grep -v "$regno" record.txt > new.txt
		 		    mv new.txt record.txt
		 		    echo "record Deleted"
		 	else
 					echo "No data found with the particular reg no"
 			fi
		;;
		7) break;;	
		*) ;;
	esac


echo "Press 1 to Continue"
read var
done
