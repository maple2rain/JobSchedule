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
    gifName	varchar(256) unique,
    PRIMARY KEY (gifID)
)Engine = InnoDB;

create table blackList (
	username   VARCHAR(20),
	PRIMARY KEY (username)
);

create table job (
	jobID				INT unsigned,
    userID  			INT unsigned, 
    joinTime   			VARCHAR(20) 	  not null,
    joinTime			smallint unsigned not null,
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