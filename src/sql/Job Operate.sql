#insert job instance
Insert Into job
(jobID, userID, jobName, joinTime, lastTime, startTime, runTime,
	needTime, deadline, PrioOrSlice, turnoverTime, weightTurnoverTime, finishedTime)
Values(
		1, 1, 'jobName', 1, 2, 2, 2,
		0, 9, 0, 2, 2, 4);
        
#delete job instance
Delete From job Where jobID = 1 and userID = 1;

#get fail job instance
Select *
From job left outer join jobfailed 
Using (userID, jobID)
Where userID = 1 
	and job.jobID = jobfailed.jobID;
  
#get finished job instance
Select *
From job left outer join jobfinished
Using (userID, jobID)
Where userID = 1 
	and job.jobID = jobfinished.jobID;
    
#get max job ID
Select Max(jobID) 
From job 
where userID = 1;

#view operate, select averTurnover, averWTurnOver instance
Select averTurnover, averWTurnOver 
From overTime 
where userID = 1;