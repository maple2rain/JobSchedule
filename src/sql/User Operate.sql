#get userID instance
Select userID 
From uer 
Where username = 'maple' 
Limit 1;

#insert new user instance
insert into user 
(username, passwd, signupdate) 
values('maple', '123456', '2016-12-10');

#update user info instance
update user 
set username = 'maple2', passwd = '123' 
where username = 'maple';

#get user Info to check if user valid
Select username, passwd 
From user 
Where username = 'maple' 
Limit 1;
