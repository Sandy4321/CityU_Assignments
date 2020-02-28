# CS3343_2019_HRLeave_System
CS3343 project 

## Pre-requisite
1. MySQL Server
	- on mac: `brew services start mysql`
	- on windows: `C:\Program Files\MySQL\MySQL Server 8.0\bin\mysqld`  # your version could be different change accordingly; If you have path setup then use `mysqld`
	- database data is on: `SQL/database`
	- `mysqldump` is a command to export this data into the sql file. E.g. `mysqldump -u root -p cs3343db > ./SQL/database/cs3343db.sql` # your username might not be root, change accordingly. And cs3343db is the database of this project.
	- to insert: `mysql -u root -p cs3343db < ./SQL/database/cs3343db.sql`
2. Java installed
3. Java MySQL Lib:
   1. download and unzip https://dev.mysql.com/downloads/connector/j/ (Choose `Platform Independent`)
   2. in eclipse right click project and add to library `Build Path` > `Add External Archives...`;
   3. choose the `.jar` file.
4. JavaFX installation: (JDK >= 11)
   1. download and unzip https://openjfx.io/ 
   2. in eclipse right click project and add to library `Build Path` > `Add External Archives...`;
   3. choose all `.jar` file.