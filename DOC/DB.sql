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


create table user (
	userID     INT unsigned AUTO_INCREMENT,
	username   VARCHAR(20) UNIQUE,
	passwd     VARCHAR(20),
	signupdate DATE,
	PRIMARY KEY (userID)
)Engine = InnoDB;

create table graph(
	graphID 	char(32), #MD5
    graphType	varchar(20),
    graph		longblob,
    PRIMARY KEY (graphID)
)Engine = InnoDB;

alter table graph modify graph longblob;

truncate table jobs.user_graph;

create table user_graph(
	userID    	INT unsigned,
    graphID 	char(32),
    primary key (userID),
	FOREIGN KEY (graphID) REFERENCES graph (graphID) ON DELETE CASCADE,
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
)Engine = InnoDB;

create table user_gif(
	userID    	INT unsigned,
	gifID 		INT unsigned Unique,
    primary key (userID),
	FOREIGN KEY (gifID) REFERENCES gif (gifID) ON DELETE CASCADE,
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
)Engine = InnoDB;

create table gif(
	gifID 	INT unsigned AUTO_INCREMENT, 
    gifName	varchar(256),
    PRIMARY KEY (gifID)
)Engine = InnoDB;

alter table gif
add unique(gifName);

create table blackList (
	username   VARCHAR(20),
	PRIMARY KEY (username)
);

create table job (
	jobID				INT unsigned,
    userID  			INT unsigned, 
    joinTime   			VARCHAR(20) 	  not null,
    commitTime			smallint unsigned not null,
    lastTime			smallint unsigned not null,
    startTime			smallint unsigned,
    finishedTime 		smallint unsigned,
    runTime				smallint unsigned,
    needTime			smallint unsigned,
    deadline			smallint unsigned,
    PrioOrSlice			smallint unsigned,
    turnoverTime		float,
    weightTurnoverTime	float,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
)Engine = InnoDB;

alter table job add finishedTime smallint unsigned;
alter table job change column commitTime joinTime  smallint unsigned not null;

create table jobFinished (
	jobID		INT unsigned,
    userID  	INT unsigned,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
)Engine = InnoDB;

create table jobFailed (
	jobID		INT unsigned,
    userID  	INT unsigned,
	PRIMARY KEY (jobID, userID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
)Engine = InnoDB;

#view
create view jobRecords (userID, jobNum, failedJobNum, finishedJobNum)
As
select jobRecord.userID, jobrecord.jobNum, jobRecordFail.failedJobNum, jobRecordFinished.finishedJobNum
from jobRecord, jobRecordFail, jobRecordFinished;

create view jobRecord(userID, jobNum)
As
select userID, count(*)
from job;

drop view jobRecords;

delete from jobs.job where userID = 3;
select * from job;

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

delete from user_graph where user_graph.graphID = graph.graphID;