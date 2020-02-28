for file in ./SQL/database/*
do
	filename=${file#./SQL/database/}
	echo ${filename%.sql}
	mysqldump -u root ${filename%.sql} > filename
done