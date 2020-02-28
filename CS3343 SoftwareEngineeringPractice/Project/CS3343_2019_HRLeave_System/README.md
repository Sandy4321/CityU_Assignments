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


INSERT INTO Session VALUES (0,"dfbb7ef7f0f71962ecb5d2b58b59b6591fe04507d97d15a9f7f669dd428a83c31cd5d8cfeed3c3685819aea4dd2a9e38863b65ced01fdae59d4296525c1790d1b29aad2607cbcfbcc4a7486fa25bb80d2c62c108bbf4c9b4f4c7de9813e3b67dd94e7ff95056f13e9fc40d9d54e5e3a4fd5ece81b7fadbf464364f1bdf81f62c68da48b1e4c9002fb7e50384dccfb6054e12451c34ee734fcc2b554e58a973440c36f8ef8b3f586eeed6615777169648e2795958a04df74636953adde2842cfcc402afae335ef1ff7463dfe09f830c249f89c0ba2fb8838e3e20adcebaf99b551b9731a217c621670a038e08a8e42f172eb41163d9ca3187d5b201916c16a0ae63aa7498","2019-12-07");