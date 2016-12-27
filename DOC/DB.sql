create database Jobs;
use Jobs;

drop table gif;
drop table graph;
drop table jobFailed;
drop table jobFinished;
drop table job;
drop table user_graph;
drop table user_gif;


create table user (
	userID     INT unsigned AUTO_INCREMENT,
	username   VARCHAR(20) UNIQUE,
	passwd     VARCHAR(20),
	signupdate DATE,
	PRIMARY KEY (userID)
);

create table graph(
	graphID 	char(32), #MD5
    graphType	varchar(20),
    graph		longblob,
    PRIMARY KEY (graphID)
);

alter table graph modify graph longblob;

delete from jobs.graph where graphType = '.jpg';

create table user_graph(
	userID    	INT unsigned,
    graphID 	char(32),
    primary key (graphID),
	FOREIGN KEY (graphID) REFERENCES graph (graphID) ON DELETE CASCADE,
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table user_gif(
	userID    	INT unsigned,
	gifID 		INT unsigned,
    primary key (gifID),
	FOREIGN KEY (gifID) REFERENCES gif (gifID) ON DELETE CASCADE,
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table gif(
	gifID 	INT unsigned AUTO_INCREMENT, 
    gifName	varchar(256),
    PRIMARY KEY (gifID)
);

create table blackList (
	username   VARCHAR(20),
	PRIMARY KEY (username)
);

create table job (
	jobID				INT unsigned,
    userID  			INT unsigned, 
    jobName   			VARCHAR(20) 	  not null,
    commitTime			smallint unsigned not null,
    lastTime			smallint unsigned not null,
    startTime			smallint unsigned,
    runTime				smallint unsigned,
    needTime			smallint unsigned,
    deadline			smallint unsigned,
    PrioOrSlice			smallint unsigned,
    turnoverTime		float,
    weightTurnoverTime	float,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table jobFinished (
	jobID		INT unsigned,
    userID  	INT unsigned,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);

create table jobFailed (
	jobID		INT unsigned,
    userID  	INT unsigned,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);

#view
create view jobRecords (userID, jobNum, failedJobNum, finishedJobNum)
As
select jobRecord.userID, jobrecord.jobNum, jobRecordFail.failedJobNum, jobRecordFinished.finishedJobNum
from jobRecord, jobRecordFail, jobRecordFinished;

create view jobRecordFail (userID, failedJobNum)
As
select userID, count(*)
from jobfailed;
create view jobRecordFinished (userID, finishedJobNum)
As
select userID, count(*)
from jobfinished;

drop view jobRecords;


drop table jobRecord;
alter table gif drop gif;
select * from user;
insert into user (username, passwd, signupdate) values('maple', '123456', '2016-12-10');
#unsigned id = select userID from user where username = 'maple';
insert into job(jobID, userID, jobName, commitTime, lastTime) values(1, 2, 1, 1, 1);
insert into jobFailed values(1, 1);
insert into jobFinished values(2, 1);
update user set username = '1', passwd = '1' where username = '1';
select distinct *  from job left outer Join jobAttribute using (jobID);