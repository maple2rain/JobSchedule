#all job info records view
create view jobRecords (userID, jobNum, failedJobNum, finishedJobNum)
As
select jobRecord.userID, jobrecord.jobNum, jobRecordFail.failedJobNum, jobRecordFinished.finishedJobNum
from jobRecord, jobRecordFail, jobRecordFinished;

#job record view
create view jobRecord(userID, jobNum)
As
select userID, count(*)
from job;

#failed job record view
create view jobRecordFail(userID, failedJobNum)
As
select userID, count(*)
from jobRecordFail;

#finished job record view
create view jobRecordFinished(userID, finishedJobNum)
As
select userID, count(*)
from jobRecordFinished;

#finished job turnover time view
create view overTime
As
select userID, (sum(turnoverTime) / count(*)) as averTurnover, 
		(sum(weightTurnoverTime) / count(*)) as averWTurnOver 
from job
where needTime = 0
group by userID;
