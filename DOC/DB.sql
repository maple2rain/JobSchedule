create database Jobs;
use Jobs;

drop table gif;

create table user (
	userID     INT unsigned AUTO_INCREMENT,
	username   VARCHAR(20) UNIQUE,
	passwd     VARCHAR(20),
	signupdate DATE,
	PRIMARY KEY (userID)
);

create table graph(
	graphID 	INT unsigned AUTO_INCREMENT,
    username   	VARCHAR(20) UNIQUE, 
    graphName	varchar(256),
    graphType	varchar(20),
    graph		blob,
    PRIMARY KEY (graphID),
	FOREIGN KEY (username) REFERENCES user (username) ON DELETE CASCADE
);

create table gif(
	gifID 	INT unsigned AUTO_INCREMENT,
	username   VARCHAR(20) UNIQUE,
    gifName	varchar(256),
    PRIMARY KEY (gifID),
	FOREIGN KEY (username) REFERENCES user (username) ON DELETE CASCADE
);

create table blackList (
	username   VARCHAR(20),
	PRIMARY KEY (username)
);

create table job (
	jobID		INT unsigned AUTO_INCREMENT,
    username   VARCHAR(20) UNIQUE,
	PRIMARY KEY (jobID),
    FOREIGN KEY (username) REFERENCES user (username) ON DELETE CASCADE
);

create table jobAttribute (
	jobID				INT unsigned AUTO_INCREMENT,
	jobName   			VARCHAR(20) UNIQUE not null,
    commitTime			smallint unsigned not null,
    lastTime			smallint unsigned not null,
    startTime			smallint unsigned,
    runTime				smallint unsigned,
    needTime			smallint unsigned,
    deadline			smallint unsigned,
    PrioOrSlice			smallint unsigned,
    turnoverTime		float,
    weightTurnoverTime	float,
	PRIMARY KEY (jobID),
    FOREIGN KEY (jobID) REFERENCES job (jobID) ON DELETE CASCADE  
);

create table jobFinished (
	jobID		INT unsigned AUTO_INCREMENT,
    username   VARCHAR(20) UNIQUE,
	PRIMARY KEY (jobID),
    FOREIGN KEY (username) REFERENCES user (username) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);

create table jobFailed (
	jobID		INT unsigned AUTO_INCREMENT,
    username   VARCHAR(20) UNIQUE,
	PRIMARY KEY (jobID),
    FOREIGN KEY (username) REFERENCES user (username) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);

alter table gif drop gif;
select * from user;
insert into user (username, passwd, signupdate) values('maple', '123456', '2016-12-10');
#unsigned id = select userID from user where username = 'maple';
insert into job(userID) values(1);
insert into jobAttribute(jobID, jobName, committime, lasttime) values(1, 1, 1, 1);
select distinct *  from job left outer Join jobAttribute using (jobID);