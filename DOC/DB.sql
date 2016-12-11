create database Jobs;
use Jobs;

drop table job;

create table user (
	userID     INT unsigned AUTO_INCREMENT,
	username   VARCHAR(20) UNIQUE,
	passwd     VARCHAR(20),
	signupdate DATE,
	PRIMARY KEY (userID)
);

create table graph(
	graphID 	INT unsigned AUTO_INCREMENT,
    userID	 	INT unsigned, 
    graphName	varchar(256),
    graph		blob,
    PRIMARY KEY (graphID),
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table gif(
	gifID 	INT unsigned AUTO_INCREMENT,
    userID	INT unsigned, 
    gifName	varchar(256),
    gif 	blob,
    PRIMARY KEY (gifID),
	FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table blackList (
	username   VARCHAR(20),
	PRIMARY KEY (username)
);

create table job (
	jobID		INT unsigned AUTO_INCREMENT,
    userID		INT unsigned,
	PRIMARY KEY (jobID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE
);

create table jobAttrbute (
	jobID		INT unsigned AUTO_INCREMENT,
	jobName   	VARCHAR(20) UNIQUE not null,
    commitTime	smallint unsigned not null,
    lastTime	smallint unsigned not null,
    startTime	smallint unsigned,
    runTime		smallint unsigned,
    needTime	smallint unsigned,
    PrioOrSlice	smallint unsigned,
	PRIMARY KEY (jobID),
    FOREIGN KEY (jobID) REFERENCES job (jobID) ON DELETE CASCADE  
);

create table jobFinished (
	jobID		INT unsigned AUTO_INCREMENT,
    userID		INT unsigned,
	PRIMARY KEY (jobID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);

create table jobFailed (
	jobID		INT unsigned AUTO_INCREMENT,
    userID		INT unsigned,
	PRIMARY KEY (jobID),
    FOREIGN KEY (userID) REFERENCES user (userID) ON DELETE CASCADE, 
    FOREIGN KEY (jobID) REFERENCES  job (jobID) ON DELETE CASCADE
);
