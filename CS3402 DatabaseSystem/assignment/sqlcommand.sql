create table CUSTOMER(
	EMAIL VARCHAR(255) not null,
	NAME VARCHAR(35) not null,
	PRIMARY KEY(EMAIL)
);

create table CINEMA(
	HOUSE char(1) not null, 
	SEAT_ROW char(1) not null,
	SEAT_COL number(1) not null,
	PRIMARY KEY(HOUSE,SEAT_ROW,SEAT_COL)
);

create table orders(
	CUSTOMER_EMAIL VARCHAR(255) not null REFERENCES Customer(EMAIL),
	HOUSE char(1) not null,
	SEAT_ROW char(1) not null ,
	SEAT_COL number(1) not null,
	UNIQUE (house,seat_row,seat_col),
	foreign key (house,seat_row,seat_col) REFERENCES CINEMA(house,seat_row,SEAT_COL)
);
insert into orders values ('asdasdasd','A','C',0);
insert into orders values ('asdasdasd','A','B',0);
insert into orders values ('asdasdasd','A','B',1);
insert into orders values ('asdasdasd','A','B',2);
insert into orders values ('asdasdasd','A','B',3);
insert into orders values ('asdasdasd','A','B',4);
insert into orders values ('asdasdasd','A','C',1);
insert into orders values ('asdasdasd','A','E',1);
insert into orders values ('asdasdasd','A','D',1);
insert into orders values ('asdasdasd','A','A',1);
select seat_row, COUNT(seat_col) from orders where house='A' group by seat_row order by seat_row;
delete from orders;
