#test operate in this file

create database Jobs;
use Jobs;

drop table gif;
drop table graph;
drop table jobFailed;
drop table jobFinished;
drop table job;
drop table user_graph;
drop table user_gif;
drop table user;

insert into jobs.blacklist values('black');

select * from overtime;
select * from job;

drop view jobRecords;

delete from jobs.job where userID = 3;
select * from job;

select * from user;
insert into user (username, passwd, signupdate) values('maple', '123456', '2016-12-10');
#unsigned id = select userID from user where username = 'maple';
insert into job(jobID, userID, jobName, commitTime, lastTime) values(1, 2, 1, 1, 1);
insert into jobFailed values(1, 1);
insert into jobFinished values(2, 1);
update user set username = '1', passwd = '1' where username = '1';
select distinct *  from job left outer Join jobAttribute using (jobID);

delete from user_graph where user_graph.graphID = graph.graphID;